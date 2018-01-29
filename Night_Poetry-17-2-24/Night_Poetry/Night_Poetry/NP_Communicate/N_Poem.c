 /******************** *********************************************************
 * 作者   ：郑康华
 * 文件名  ：N_Poem.c
 * 描述    ：Night_Poetry上位机通信协议
 * 使用方法：
 
     使用时将N_Poem.c和N_Poem.h添加进工程
	 
	 用工程中的串口发送函数代替h文件宏定义中的UARTB_Send(ch)（只能有一个参数）
	 #define send_OneByte(ch) UARTB_Send(ch);
	 
	 发送数据时先将要发送的数据（支持32位有符号数）
	 通过NP_push()填入发送缓冲相映通道  然后通过DATA_To_NP()统一发送至上位机
	 
	 调试时在串口接收中断中调用DATA_From_NP()
	 并在debug_Channel()中填写需要调试的变量即可
**********************************************************************************/
#include "N_Poem.h"

////////////////////////////////////////////////////////////////////////////////////
//数据拆分宏定义，在发送大于1字节的数据类型时，比如int16、float等，需要把数据拆分成单独字节进行发送
#define BYTE0(dwTemp)       (char)((dwTemp)&0xff)
#define BYTE1(dwTemp)       (char)((dwTemp>>8)&0xff)
#define BYTE2(dwTemp)       (char)((dwTemp>>16)&0xff)
#define BYTE3(dwTemp)       (char)((dwTemp>>24)&0xff)

NP_Struct NP_Data;

/////////将数据填充到发送缓冲区，通过DATA_To_NP()统一发送
void NP_push(unsigned char channel,int32 value)
{
	channel -= 1 ;
	NP_Data.send_DataBuff[1+channel*4+1] = BYTE3(value);
	NP_Data.send_DataBuff[1+channel*4+2] = BYTE2(value);
	NP_Data.send_DataBuff[1+channel*4+3] = BYTE1(value);
	NP_Data.send_DataBuff[1+channel*4+4] = BYTE0(value);
}

/////////发送一帧数据至上位机示波器
void DATA_To_NP()
{
	unsigned char sum=0;
	unsigned char i;
	NP_Data.send_DataBuff[0] = 0x88;  /////帧头
    NP_Data.send_DataBuff[1] = 0x88;
	
	for (i=0;i<SEND_DATASIZE-1;i++)   /////对发送帧的数据求和，用于校验
	{		
		sum += NP_Data.send_DataBuff[i];
	}
	
    NP_Data.send_DataBuff[SEND_DATASIZE-1] = sum;
	
    for (i=0;i<SEND_DATASIZE;i++)
	{		
		send_OneByte(NP_Data.send_DataBuff[i]);
	}
}

/////////发送一帧图像至上位机图片显示
void IMAGE_To_NP()
{
	unsigned char sum=0;
	unsigned char i,j;
	unsigned char data;
    int offset=0;
	
	send_OneByte (0x88);  /////帧头
    send_OneByte (0x87); 

	sum = (unsigned char)(Image_Height+Image_Width);
	
    send_OneByte (BYTE1(Image_Height));
    send_OneByte (BYTE0(Image_Height));
    send_OneByte (BYTE1(Image_Width));
    send_OneByte (BYTE0(Image_Width));
    send_OneByte (sum);
	

    for (i=0;i<Image_Height;i++)
	{		
		offset=i*Image_Width;	
       for(j=0;j<Image_Width;j++)
	   {
		//灰度图像数据发送格式	
		data = Image_Name[offset+j)];	
		if(data > 0xFE) data = 0xFE;   		
		send_OneByte(data);			

/* 		//彩色RGB565图像数据发送格式
        data = Image_Name[(offset+j)*2];	//包含R
		if(data > 0xFE) data = 0xFE;   		
		send_OneByte(data);	
		
        data = Image_Name[(offset+j)*2+1];	//包含B
		if(data > 0xFE) data = 0xFE;   		
		send_OneByte(data);	 */	
			   
	   }
	}
	send_OneByte (0xFF);  /////帧尾
}

/////////从上位机接收数据
void DATA_From_NP(char value)
{
	if(NP_Data.Rx_State==0&&value==0x88)
	{
		NP_Data.Rx_State=1;
		NP_Data.receive_DataBuff[0]=0x88;
	}
	else if(NP_Data.Rx_State==1&&value==0x88)
	{
		NP_Data.Rx_State=2;
		NP_Data.receive_DataBuff[1]=0x88;
	}
	else if(NP_Data.Rx_State==2)
	{
		NP_Data.Rx_State=3;
		NP_Data.Rx_Cnt ++;
		NP_Data.receive_DataBuff[1+NP_Data.Rx_Cnt]=value;
	}
	else if(NP_Data.Rx_State==3&&NP_Data.Rx_Cnt < 48)
	{
		NP_Data.Rx_Cnt ++;
		NP_Data.receive_DataBuff[1+NP_Data.Rx_Cnt]=value;

	}
	else if(NP_Data.Rx_State==3&&NP_Data.Rx_Cnt >= 48)
	{
		NP_Data.receive_DataBuff[RECEIVE_DATASIZE-1]=value;
		NP_Data.Rx_Data_Ready=1;
		NP_Data.Rx_State=0;
		NP_Data.Rx_Cnt=0;
		NP_Data.Rx_Sum=0;
	}

	if(NP_Data.Rx_Data_Ready==1)
	{
		NP_Data.Rx_Data_Ready=0;
		get_Data();
	}
}
/////////从上位机接收数据的数据中获取调试值
void get_Data()
{
	unsigned char arr[4]={0};
	char i=0;
	for(i=0;i<12;i++)
	{
		NP_Data.Rx_Sum += NP_Data.receive_DataBuff[5+i*4];
	}
	if(NP_Data.Rx_Sum != NP_Data.receive_DataBuff[RECEIVE_DATASIZE-1])
	{
		return;
	}
	for(i=0;i<12;i++)
	{
		//arr[0]=NP_Data.receive_DataBuff[3+4*i]<<8|NP_Data.receive_DataBuff[2+4*i];
		//arr[1]=NP_Data.receive_DataBuff[5+4*i]<<8|NP_Data.receive_DataBuff[4+4*i];
	    arr[0]=NP_Data.receive_DataBuff[2+4*i];
		arr[1]=NP_Data.receive_DataBuff[3+4*i];
		arr[2]=NP_Data.receive_DataBuff[4+4*i];
		arr[3]=NP_Data.receive_DataBuff[5+4*i];
	    memcpy((void *)&(NP_Data.Debug_Data[i]),arr,4);
	}

	debug_Channel();
}
//////////将从上位机获取的值赋给调试的变量
void debug_Channel()
{
//  num1=NP_Data.Debug_Data[0];
//  num2=NP_Data.Debug_Data[1];
}
