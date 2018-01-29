 /******************** *********************************************************
 * 作者   ：ahou
 * 文件名  ：N_Poem.h
 * 描述    ：Night_Poetry上位机通信协议
**********************************************************************************/
  
#ifndef _N_POEM_H_
#define _N_POEM_H_
  
#include "UART.h"
#include <string .h>
  //////////////串口数据发送函数，使用时只需用用户的串口发送函数替换即可
#define send_OneByte(ch) UARTB_Send(ch);

//////////////帧头0x8888 示波器十二通道int32   校验和 u8 sum
//////////////      2   +        48         +       1         =51
#define SEND_DATASIZE   51
#define RECEIVE_DATASIZE   51
  
  typedef struct
  {
	  unsigned char send_DataBuff[SEND_DATASIZE];
	  unsigned char receive_DataBuff[RECEIVE_DATASIZE];
	  unsigned char Rx_State;
	  unsigned char Rx_Cnt;
	  unsigned char Rx_Sum;
	  unsigned char Rx_Data_Ready;
	  float Debug_Data[12];
  } NP_Struct;
  
  extern NP_Struct NP_Data;
  
  void NP_push(unsigned char channel,int32 value);
  void DATA_To_NP(void);
  void IMAGE_To_NP(void);

  void DATA_From_NP(unsigned char value);
  void get_Data(void);
  void debug_Channel(void);

  #endif
