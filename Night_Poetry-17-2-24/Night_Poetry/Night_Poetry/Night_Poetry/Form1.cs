using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.IO.Ports;
using System.Text.RegularExpressions;
using System.Drawing.Imaging;
using System.Threading;
using System.Diagnostics;
namespace Night_Poetry
{
    public partial class main_Form : Form
    {

        #region 变量定义
        private Size Form_Size =  new Size();                    //窗体大小
        Point form_Position = new Point();
        Point mouse_Position = new Point();
        #endregion
        
        
        #region 主窗体处理


        public main_Form()
        {
            InitializeComponent();

            Form_Size = this.Size;
            get_AvailablePort();
            baud_comboBox.SelectedIndex = 6;
            data_comboBox.SelectedIndex = 3;
            stop_comboBox.SelectedIndex = 1;
            checkout_comboBox.SelectedIndex = 0;

            main_tabControl.SelectedIndex = 0;


            scope_Init();
            Image_Init();
        }

        private void main_Form_Load(object sender, EventArgs e)
        {

        }

        private void top_tableLayoutPanel_MouseDown(object sender, MouseEventArgs e)
        {
            form_Position = this.Location;
            mouse_Position = this.PointToScreen(e.Location);
        }

        private void top_tableLayoutPanel_MouseMove(object sender, MouseEventArgs e)
        {
            Point move = new Point();
            move.X = this.PointToScreen(e.Location).X - mouse_Position.X;
            move.Y = this.PointToScreen(e.Location).Y - mouse_Position.Y;

            if (e.Button == MouseButtons.Left || e.Button == MouseButtons.Right)
            {
                Point temp_Point = new Point();
                temp_Point.X = form_Position.X + move.X;
                temp_Point.Y = form_Position.Y + move.Y;
                this.Location = temp_Point;
            }
        }

        private void main_Form_Resize(object sender, EventArgs e)
        {
            send_richTextBox.Height = send_groupBox.Size.Height - UART_Set_groupBox.Size.Height - sendButton_panel.Size.Height - 40;

            window_Size = panel_Image1.Size;
            image1_Graphics = panel_Image1.CreateGraphics();
            image2_Graphics = panel_Image2.CreateGraphics();

            scope_panel.Height = scope_tableLayoutPanel.Size.Height - channel_groupBox.Height - 15;
            if (channel_groupBox.Size.Width > channel_groupBox_Size.Width)
            {
                float width_Add = (float)channel_groupBox.Size.Width / channel_groupBox_Size.Width;

                checkBox2.Location = new Point((int)(checkBox_Position.X * width_Add), checkBox2.Location.Y);
                checkBox3.Location = new Point((int)((checkBox_Position.X + 100) * width_Add), checkBox3.Location.Y);
                checkBox4.Location = new Point((int)((checkBox_Position.X + 200) * width_Add), checkBox4.Location.Y);
                checkBox5.Location = new Point((int)((checkBox_Position.X + 300) * width_Add), checkBox5.Location.Y);
                checkBox6.Location = new Point((int)((checkBox_Position.X + 400) * width_Add), checkBox6.Location.Y);
                checkBox8.Location = new Point((int)(checkBox_Position.X * width_Add), checkBox8.Location.Y);
                checkBox9.Location = new Point((int)((checkBox_Position.X + 100) * width_Add), checkBox9.Location.Y);
                checkBox10.Location = new Point((int)((checkBox_Position.X + 200) * width_Add), checkBox10.Location.Y);
                checkBox11.Location = new Point((int)((checkBox_Position.X + 300) * width_Add), checkBox11.Location.Y);
                checkBox12.Location = new Point((int)((checkBox_Position.X + 400) * width_Add), checkBox12.Location.Y);


                ch2_label.Location = new Point(checkBox2.Location.X, checkBox2.Location.Y + 21);
                ch3_label.Location = new Point(checkBox3.Location.X, checkBox3.Location.Y + 21);
                ch4_label.Location = new Point(checkBox4.Location.X, checkBox4.Location.Y + 21);
                ch5_label.Location = new Point(checkBox5.Location.X, checkBox5.Location.Y + 21);
                ch6_label.Location = new Point(checkBox6.Location.X, checkBox6.Location.Y + 21);
                ch8_label.Location = new Point(checkBox8.Location.X, checkBox8.Location.Y + 21);
                ch9_label.Location = new Point(checkBox9.Location.X, checkBox9.Location.Y + 21);
                ch10_label.Location = new Point(checkBox10.Location.X, checkBox10.Location.Y + 21);
                ch11_label.Location = new Point(checkBox11.Location.X, checkBox11.Location.Y + 21);
                ch12_label.Location = new Point(checkBox12.Location.X, checkBox12.Location.Y + 21);

            }

            draw_Scope(X_MinNum, X_Step, Y_MinNum, Y_Step);
            Form_Size = this.Size;
            scopePanel_Size = scope_panel.Size;
            if (this.WindowState == FormWindowState.Maximized || this.WindowState == FormWindowState.Normal)
            {
                draw_Scope(X_MinNum, X_Step, Y_MinNum, Y_Step);
                float width_Add = (float)channel_groupBox.Size.Width / channel_groupBox_Size.Width;

                checkBox2.Location = new Point((int)(checkBox_Position.X * width_Add), checkBox2.Location.Y);
                checkBox3.Location = new Point((int)((checkBox_Position.X + 100) * width_Add), checkBox3.Location.Y);
                checkBox4.Location = new Point((int)((checkBox_Position.X + 200) * width_Add), checkBox4.Location.Y);
                checkBox5.Location = new Point((int)((checkBox_Position.X + 300) * width_Add), checkBox5.Location.Y);
                checkBox6.Location = new Point((int)((checkBox_Position.X + 400) * width_Add), checkBox6.Location.Y);
                checkBox8.Location = new Point((int)(checkBox_Position.X * width_Add), checkBox8.Location.Y);
                checkBox9.Location = new Point((int)((checkBox_Position.X + 100) * width_Add), checkBox9.Location.Y);
                checkBox10.Location = new Point((int)((checkBox_Position.X + 200) * width_Add), checkBox10.Location.Y);
                checkBox11.Location = new Point((int)((checkBox_Position.X + 300) * width_Add), checkBox11.Location.Y);
                checkBox12.Location = new Point((int)((checkBox_Position.X + 400) * width_Add), checkBox12.Location.Y);


                ch2_label.Location = new Point(checkBox2.Location.X, checkBox2.Location.Y + 21);
                ch3_label.Location = new Point(checkBox3.Location.X, checkBox3.Location.Y + 21);
                ch4_label.Location = new Point(checkBox4.Location.X, checkBox4.Location.Y + 21);
                ch5_label.Location = new Point(checkBox5.Location.X, checkBox5.Location.Y + 21);
                ch6_label.Location = new Point(checkBox6.Location.X, checkBox6.Location.Y + 21);
                ch8_label.Location = new Point(checkBox8.Location.X, checkBox8.Location.Y + 21);
                ch9_label.Location = new Point(checkBox9.Location.X, checkBox9.Location.Y + 21);
                ch10_label.Location = new Point(checkBox10.Location.X, checkBox10.Location.Y + 21);
                ch11_label.Location = new Point(checkBox11.Location.X, checkBox11.Location.Y + 21);
                ch12_label.Location = new Point(checkBox12.Location.X, checkBox12.Location.Y + 21);
            }
        }

        private void main_tabControl_SelectedIndexChanged(object sender, EventArgs e)
        {
            

            if (main_tabControl.SelectedIndex == 1)
            {
                 scopePanel_Size = scope_panel.Size;
                draw_Scope(X_MinNum, X_Step, Y_MinNum, Y_Step);
            }
            else if (main_tabControl.SelectedIndex == 2)
            {              

            }

        }

        private void panel3_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("确定退出?", "Night Poetry", MessageBoxButtons.OKCancel, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) == DialogResult.OK)
            {
                try
                {
                    Environment.Exit(0);
                }
                catch
                {
                    Environment.Exit(0);
                }

            }

        }

        private void max_panel_Click(object sender, EventArgs e)
        {
            if (WindowState != FormWindowState.Maximized)
            {
                WindowState = FormWindowState.Maximized;
            }
            else
            {
                WindowState = FormWindowState.Normal;
            }

        }

        private void min_panel_Click(object sender, EventArgs e)
        {
            WindowState = FormWindowState.Minimized;
        }

        private void main_Form_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (MessageBox.Show("确定退出?", "Night Poetry", MessageBoxButtons.OKCancel, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) == DialogResult.OK)
            {
                e.Cancel = false;
                try
                {
                    Environment.Exit(0);
                }
                catch
                {
                    Environment.Exit(0);
                }

            }
            else
            {
                e.Cancel = true;
            }
        }

        #endregion 


        #region 第一部分 ：串口助手

        #region  串口助手变量定义
        private StringBuilder strbuilder = new StringBuilder();  //接收串口数据

        enum DATA_FOR
        {
           none,
           scope_Data,
           image_Data      
        };
        DATA_FOR data_For = DATA_FOR.scope_Data;
        bool UART_Enable = false;

        const Byte RECEIVE_DATASIZE = 51;                         //接收缓存区大小
        Byte[] RxBuffer = new Byte[RECEIVE_DATASIZE];             //接收缓存
        Byte receive_State = 0;                                   //接收状态，提取帧内容时记录步奏
        Byte data_cnt = 0;                                        //接收帧中的数据数
        Byte sum = 0;                                             //用于数据和校验
        bool scope_data_Ready = false;                                   //一帧数据是否提取完毕
        bool get_FirstData = false;

        const Byte SEND_DATASIZE = 51;                         //发送缓存区大小
        Byte[] TxBuffer = new Byte[SEND_DATASIZE];             //发送缓存

        Stopwatch watch = new Stopwatch();                     //计时器，用于判断示波器帧率
        long  watch_Time = new long();
        int frame_Time = new int();

        #endregion


        #region 端口参数修改
        private void port_comboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            data_serialPort.PortName = port_comboBox.SelectedItem.ToString ();
        }

        private void baud_comboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            data_serialPort.BaudRate =Convert .ToInt32(baud_comboBox.SelectedItem);
        }

        private void data_comboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            data_serialPort.DataBits = Convert.ToInt16(data_comboBox.SelectedItem);
        }

        private void stop_comboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (stop_comboBox.SelectedIndex )
            { 
                case 0:
                    data_serialPort.StopBits = System.IO.Ports.StopBits.None ;
                    break;
                case 1:
                    data_serialPort.StopBits = System.IO.Ports.StopBits.One ;
                    break;
                case 2:
                    data_serialPort.StopBits = System.IO.Ports.StopBits.OnePointFive ;
                    break;
                case 3:
                    data_serialPort.StopBits = System.IO.Ports.StopBits.Two ;
                    break;
            }
            
        }

        private void checkout_comboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (checkout_comboBox.SelectedIndex)
            {
                case 0:
                    data_serialPort.Parity = System.IO.Ports.Parity.None;
                    break;
                case 1:
                    data_serialPort.Parity = System.IO.Ports.Parity.Odd ;
                    break;
                case 2:
                    data_serialPort.Parity = System.IO.Ports.Parity.Even ;                    
                    break;
                case 3:
                    data_serialPort.Parity = System.IO.Ports.Parity.Mark ;                   
                    break;
                case 4:
                    data_serialPort.Parity = System.IO.Ports.Parity.Space ;
                    break;
            }
        }
        #endregion  


        #region 串口基本操作

        /// <summary>
        /// 获取当前可用端口号
        /// </summary>
        public void get_AvailablePort()
        {
            string[] port_String = SerialPort.GetPortNames();
            foreach (string port in port_String)
            {
                port_comboBox.Items.Add(port);
            }
            if (port_String.GetLength(0) != 0)
            {
                port_comboBox.SelectedIndex = 0;
                data_serialPort.PortName = port_comboBox.Items[0].ToString();
            }

        }


        /// 串口数据接收函数
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void data_serialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            int n = data_serialPort.BytesToRead;  //先记录下来，避免某种原因，人为的原因，操作几次之间时间长，缓存不一致  
            byte[] buf = new byte[n];             //声明一个临时数组存储当前来的串口数据  
            data_serialPort.Read(buf, 0, n);      //读取缓冲数据  

            strbuilder.Clear();                   //清除字符串构造器的内容  
                                                  //因为要访问ui资源，所以需要使用invoke方式同步ui。  
            this.Invoke((EventHandler)(delegate
            {
                if (UART_Enable)                  //如果使能串口助手，则读取数据并显示在数据接收区
                {
                    if (char_radioButton.Checked == true)
                    {
                        strbuilder.Append(Encoding.ASCII.GetString(buf));      //直接按ASCII规则转换成字符串          
                    }
                    else if (dec_radioButton.Checked == true)
                    {
                        for (UInt16 i = 0; i < n; i++)
                        {
                            strbuilder.Append(((int)buf[i]).ToString("D") + " ");      //转化为两位的十进制数                   
                        }
                    }
                    else if (hex_radioButton.Checked == true)
                    {
                        for (UInt16 i = 0; i < n; i++)
                        {
                            strbuilder.Append("0x" + ((int)buf[i]).ToString("X2") + " ");   //转化为两位的十六进制数                   
                        }
                    }

                    this.receive_richTextBox.AppendText(strbuilder.ToString());        //追加的形式添加到文本框末端，并滚动到最后。  
                }
                else                               //若串口助手失能，接收帧数据到示波器并显示
                {
                    DataGet(buf,n );
                }
            }));
        }


        /// <summary>
        /// 取出接收到的一帧中的数据
        /// </summary>
        /// <param name="buffer"></param>
        /// <param name="count"></param>
        private void DataGet(Byte[] buffer, int count)
        {

            for (int i = 0; i < count; i++)
            {
                if (receive_State == 0 && buffer[i] == 0x88)       //判断帧头
                {
                    receive_State = 1;
                    RxBuffer[0] = buffer[i];
                }
                else if (receive_State == 1 )  
                {
                    if (buffer[i] == 0x88)
                    {
                        receive_State = 2;
                        data_For = DATA_FOR.scope_Data;
                        RxBuffer[1] = buffer[i];
                    }
                    else if (buffer[i] == 0x87)
                    {
                        receive_State = 2;
                        data_For = DATA_FOR.image_Data;
                    }

                    continue;
                }

                if (data_For == DATA_FOR.scope_Data)     //开始读取示波器数据
                {
                    if (receive_State == 2)                      
                    {
                        receive_State = 3;
                        RxBuffer[1 + (++data_cnt)] = buffer[i];
                    }
                    else if (receive_State == 3 && data_cnt < (channel_Num * 4))
                    {
                        RxBuffer[1 + (++data_cnt)] = buffer[i];
                    }
                    else if (receive_State == 3 && data_cnt >= (channel_Num * 4))
                    {
                        receive_State = 0;
                        data_cnt = 0;
                        scope_data_Ready = true;                            //一帧数据读取完毕
                        data_For = DATA_FOR.none;
                        RxBuffer[RECEIVE_DATASIZE - 1] = buffer[i];
                    }
                }
                else if (data_For == DATA_FOR.image_Data) //开始读取图像数据
                {
                    if (receive_State == 2)               //接收图像大小阶段
                    {
                        image_ByteSize[0]++;
                        image_ByteSize[image_ByteSize[0]] = buffer[i];
                        if (image_ByteSize[0] >= 4)
                        {
                            receive_State = 3;
                            image_ByteSize[0] = 0;
                        }
                    }
                    else if (receive_State == 3)         //图像大小校验阶段   
                    {
                        Byte image_RXsum = 0;
                        image_Size.Height = (Int16)(image_ByteSize[2] | (image_ByteSize[1] << 8));
                        image_Size.Width = (Int16)(image_ByteSize[4] | (image_ByteSize[3] << 8));
                        image_RXsum = (Byte)(image_Size.Height + image_Size.Width);
                        if (image_RXsum == buffer[i])   //图像校验成功
                        {
                            receive_State = 4;

                            label_Width.Text = image_Size.Width.ToString();
                            label_Height.Text = image_Size.Height.ToString();
                            progressBar_Image.Maximum = (int)(image_Size.Height/1.3);

                            image_Height_K = (float)window_Size .Height / image_Size.Height;

                            Bitmap image_Temp3 = new Bitmap(image_Size.Width, 1, PixelFormat.Format24bppRgb);
                            Bitmap image_Temp4 = new Bitmap(image_Size.Width, 1, PixelFormat.Format24bppRgb);
                            image_Line1 = image_Temp3;
                            image_Line2 = image_Temp4;

                            if (save_Pic == true)      //是否保存图像
                            {
                                set_NewPic = true;
                                Bitmap image_temp5= new Bitmap(image_Size.Width, image_Size.Height, PixelFormat.Format24bppRgb);
                                image_ForSave = image_temp5;
                            }

                            image_State = IMAGE_STATE.ongoing;
                            label_ImageState.Text = image_State.ToString();
                        }
                        else
                        {
                            receive_State = 0;
                            data_For = DATA_FOR.none;
                            return;
                        }
                    }
                    else if (receive_State == 4)     //正式接收一帧图像数据
                    {
                        get_Image(buffer [i]);
                    }
                }

                if (scope_data_Ready)
                {
                    scope_data_Ready = false;
                    for (int j = 0; j < RECEIVE_DATASIZE - 1; j++)
                    {
                        sum += RxBuffer[j];
                    }
                    if (sum != RxBuffer[RECEIVE_DATASIZE - 1])   //数据和校验
                    {
                        return;
                    }
                    sum = 0;

                    /////////帧间计时，判断帧率
                    /////////为防止程序卡顿，帧率过高时显示限制在50帧每秒
                    frame_Time++;
                    if (watch.IsRunning == false)
                    {
                        watch.Start();
                    }
                    else
                    {
                        watch.Stop();
                        if (watch.ElapsedMilliseconds < 1000 / max_Frame)
                        {
                            watch_Time += watch.ElapsedMilliseconds;
                            if (watch_Time < 1000 / max_Frame)
                            {
                                watch.Reset();
                                watch.Start();
                                return;
                            }
                            else
                            {
                                watch_Time = 0;
                            }
                            
                        }

                        watch.Reset();
                        watch.Start();
                    }


                    Int32[] value = new int[channel_Num];
                    for (int j = 0; j < channel_Num; j++)       //组装数据并添加到示波器窗口
                    {
                        value[j] = (Int32)(RxBuffer[1 + j * 4 + 1] << 24 | RxBuffer[1 + j * 4 + 2] << 16 | RxBuffer[1 + j * 4 + 3] << 8 | RxBuffer[1 + j * 4 + 4]);
                    }
                    if (get_FirstData == false)
                    {
                        get_FirstData = true;
                        pause_Status = false;
                        pause_button.ImageIndex  = 4;
                    }

                    if (pause_Status == false)
                    {
                        Add_Point(value);
                    }
                   
                }

            }


        }

        #endregion


        #region    按键响应

        /// <summary>
        /// 端口打开 关闭操作按钮
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void port_button_Click(object sender, EventArgs e)
        {
            if (port_button.Text == "打开端口")
            {

                try
                {
                    if (port_comboBox.Items.Count == 0)
                    {
                        MessageBox.Show("当前无可用串口!!", "错误提示", MessageBoxButtons.OK ,MessageBoxIcon.Question);
                        return;
                    }
                    else
                    {
                        data_serialPort.Open();
                        clean_Scope();
                    }
                }
                catch (Exception ex)
                {
                    if (ex.ToString().Contains("不存在"))
                    {
                        MessageBox.Show("串口" + data_serialPort.PortName.ToString() + "不存在!!", "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Error );
                    }
                    else if (ex.ToString().Contains("访问被拒"))
                    {
                        MessageBox.Show("串口" + data_serialPort.PortName.ToString() + "已被占用!!", "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Error );
                    }
                    else
                    {
                        MessageBox.Show(ex.ToString(), "异常", MessageBoxButtons.OK, MessageBoxIcon.Question);
                    }
                    return;
                }
                port_button.Text = "关闭端口";
                power_button.ImageIndex = 3;

            }
            else
            {
                try
                {
                    data_serialPort.Close();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.ToString());
                    return;
                }
                port_button.Text = "打开端口";
                power_button.ImageIndex = 2;
            }

        }



        /// <summary>
        /// 清空接收区  按键响应函数
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void clear_button_Click(object sender, EventArgs e)
        {
            this.receive_richTextBox.Clear();
        }



        /// <summary>
        /// 发送数据    按键响应函数
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void send_button_Click(object sender, EventArgs e)
        {
            if (data_serialPort.IsOpen)
            {
                if (check_SendArea() == 1)
                {
                    MessageBox.Show("发送区不可为空！", "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Error );
                }
                else
                {
                    data_serialPort.Write(send_richTextBox.Text);
                }

            }
            else
            {
                MessageBox.Show("串口未打开！", "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }


        /// <summary>
        /// 使能串口助手    按键响应函数
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_Click(object sender, EventArgs e)
        {
            if (UART_Enable == false)
            {
                if (data_serialPort.IsOpen)
                {
                    UART_Enable = true;
                    switch_button.ImageIndex = 1;
                }
                else
                {
                    MessageBox.Show("串口未打开！", "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }

            }
            else
            {
                UART_Enable = false;
                data_For    = DATA_FOR .none  ;
                switch_button.ImageIndex = 0;
            }
        }

        #endregion


        #region   发送区数据循环发送部分


        /// <summary>
        ///  循环发送选中
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void circalSend_checkBox_Click(object sender, EventArgs e)
        {
            if (circalSend_checkBox.Checked == true)       ////循环发送选中
            {
                if (check_SendArea() == 1)                  ////检查发送区数据是否为空
                {
                    circalSend_checkBox.Checked = false;
                    MessageBox.Show("发送区内容为空", "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Question);
                    return;
                }
                else                                        ////发送区不为空，判断是否打开定时器定时发送
                {
                    send_timer.Interval = Convert.ToInt16(sendPeriod_textBox.Text);
                    send_timer.Start();
                }
            }
            else 
            {
                send_timer.Stop();
            }
        }


        /// <summary>
        /// 循环发送定时器中断
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void send_timer_Tick(object sender, EventArgs e)  ////定时时间到，发送数据
        {
            if (data_serialPort.IsOpen)
            {
                data_serialPort.Write(send_richTextBox.Text);
            }
        }


        /// <summary>
        /// 循环发送定时器周期改变
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void sendPeriod_textBox_TextChanged(object sender, EventArgs e)  ////定时器中断周期改变
        {
            if (sendPeriod_textBox.Text.Length != 0)
            {
                send_timer.Interval = Convert.ToInt16(sendPeriod_textBox.Text);           
            }
        }


        #endregion 


        #region  各种状态检查函数

        /// <summary>
        /// 串口发送区数据检查 
        /// </summary>
        /// <returns 0：发送区数据非空>
        /// <returns 1：发送区数据为空>
        UInt16 check_SendArea()
        {
            if (send_richTextBox .Text .Length ==0)
            {
                return 1;
            }
           return 0;
        }


        #endregion

        #endregion


        #region   第二部分 ：示波器

        #region   示波器变量定义
        Size channel_groupBox_Size = new Size();
        Point checkBox_Position = new Point();
        Size scopePanel_Size = new Size();

        /////////////// XY轴显示的最大最小值,步长和步数
        public static float  X_MinNum = 0, X_MaxNum = 0;
        public static float Y_MinNum = 0, Y_MaxNum = 0;
        public static float X_Step = 8;
        public static float Y_Step = 8;
        uint step_Num = 10;

       ///////////////面板上XY轴与边界的空白距离
        const UInt16 X_Blank = 20;
        const UInt16 Y_Blank = 45;
        public static UInt16 channel_Num = 12;                 //示波器通道数
        List <List <Int32 >> ch_Value=new List<List<int>>() ;  //示波器各通道接收值
        List<Int32> ch1_Value = new List<Int32>();
        List<Int32> ch2_Value = new List<Int32>();
        List<Int32> ch3_Value = new List<Int32>();
        List<Int32> ch4_Value = new List<Int32>();
        List<Int32> ch5_Value = new List<Int32>();
        List<Int32> ch6_Value = new List<Int32>();
        List<Int32> ch7_Value = new List<Int32>();
        List<Int32> ch8_Value = new List<Int32>();
        List<Int32> ch9_Value = new List<Int32>();
        List<Int32> ch10_Value = new List<Int32>();
        List<Int32> ch11_Value = new List<Int32>();
        List<Int32> ch12_Value = new List<Int32>();

        /////////////鼠标是否按下和按下位置，用于波形拖动
        bool mouse_Down = new bool();
        Point mouse_DownPosition = new Point();

        UInt32 X_Position = 0;                   //示波器接收到的值个数
        Int32 Y_Scope_MinNum, Y_Scope_MaxNum;    //示波器接收到的值的极值，用于Y轴长度调整


        public static CheckBox[] checkBox_Arr = new CheckBox[channel_Num];  //示波器通道勾选框
        Label[] lable_Arr = new Label[channel_Num];                         //示波器通道数据显示
        public static Pen[] ch_Pen = new Pen[channel_Num];                  //波形绘制画笔
        public static bool vertical_checkBox = true;                        //竖直栅格使能
        public static bool Horizontal_checkBox = true;                      //水平栅格使能
        public static Pen X_dash_Pen = new Pen(Color.White, 0.3F);          //竖直栅格间断线
        public static Pen Y_dash_Pen = new Pen(Color.White, 0.3F);          //水平栅格间断线

        string work_Mode = "工作模式";   //示波器工作模式
        bool pause_Status = true ;       //示波器的暂停状态

        bool filter_Enable = false;      //滤波器使能
        public static List<Byte> filter_Ch = new List<Byte>();              //记录滤波器使能的滤波通道
        List<List<Int32>> filter_Value = new List<List<int>>();             //滤波器滤波模板内的值
        public static int  smooth_Length=0;                                 //滤波器模板长度
        public static string filter_Style = null  ;                         //滤波器类型


        public static bool stepTo_send = false;                               //步进后是否立即发送
        public static TextBox[] textBox_Arr = new TextBox[12];  //调试通道值
        public static Label[] label_Arr = new Label[12];        //调试通道名
        public static CheckBox[] db_CheckBox_Arr = new CheckBox[12];//调试通道选择


        public static int max_Frame = 20;
        #endregion


        #region 示波器初始化设置
        /// <summary>
        ///  示波器初始化
        /// </summary>
        public void scope_Init()
        {

            channel_groupBox_Size = channel_groupBox.Size;
            checkBox_Position = checkBox2.Location;         
            mode_comboBox.SelectedIndex = 0;                //默认选中工作模式

            checkBox_Arr[0] = checkBox1;
            checkBox_Arr[1] = checkBox2;
            checkBox_Arr[2] = checkBox3;
            checkBox_Arr[3] = checkBox4;
            checkBox_Arr[4] = checkBox5;
            checkBox_Arr[5] = checkBox6;
            checkBox_Arr[6] = checkBox7;        
            checkBox_Arr[7] = checkBox8;
            checkBox_Arr[8] = checkBox9;
            checkBox_Arr[9] = checkBox10;
            checkBox_Arr[10] = checkBox11;
            checkBox_Arr[11] = checkBox12;

            lable_Arr[0] = ch1_label;
            lable_Arr[1] = ch2_label;
            lable_Arr[2] = ch3_label;
            lable_Arr[3] = ch4_label;
            lable_Arr[4] = ch5_label;
            lable_Arr[5] = ch6_label;
            lable_Arr[6] = ch7_label;
            lable_Arr[7] = ch8_label;
            lable_Arr[8] = ch9_label;
            lable_Arr[9] = ch10_label;
            lable_Arr[10] = ch11_label;
            lable_Arr[11] = ch12_label;

            textBox_Arr[0] = db1_textBox;
            textBox_Arr[1] = db2_textBox;
            textBox_Arr[2] = db3_textBox;
            textBox_Arr[3] = db4_textBox;
            textBox_Arr[4] = db5_textBox;
            textBox_Arr[5] = db6_textBox;
            textBox_Arr[6] = db7_textBox;
            textBox_Arr[7] = db8_textBox;
            textBox_Arr[8] = db9_textBox;
            textBox_Arr[9] = db10_textBox;
            textBox_Arr[10] = db11_textBox;
            textBox_Arr[11] = db12_textBox;

            label_Arr[0] = db1_label;
            label_Arr[1] = db2_label;
            label_Arr[2] = db3_label;
            label_Arr[3] = db4_label;
            label_Arr[4] = db5_label;
            label_Arr[5] = db6_label;
            label_Arr[6] = db7_label;
            label_Arr[7] = db8_label;
            label_Arr[8] = db9_label;
            label_Arr[9] = db10_label;
            label_Arr[10] = db11_label;
            label_Arr[11] = db12_label;

            db_CheckBox_Arr[0] = db1_checkBox;
            db_CheckBox_Arr[1] = db2_checkBox;
            db_CheckBox_Arr[2] = db3_checkBox;
            db_CheckBox_Arr[3] = db4_checkBox;
            db_CheckBox_Arr[4] = db5_checkBox;
            db_CheckBox_Arr[5] = db6_checkBox;
            db_CheckBox_Arr[6] = db7_checkBox;
            db_CheckBox_Arr[7] = db8_checkBox;
            db_CheckBox_Arr[8] = db9_checkBox;
            db_CheckBox_Arr[9] = db10_checkBox;
            db_CheckBox_Arr[10] = db11_checkBox;
            db_CheckBox_Arr[11] = db12_checkBox;

            for (int  i = 0; i < channel_Num; i++)
            {
                List<Int32> temp_List = new List<int>();
                Pen temp_Pen = new Pen(checkBox_Arr[i].ForeColor,1.5F);
                lable_Arr[i].ForeColor = checkBox_Arr[i].ForeColor;
                ch_Pen[i] = temp_Pen ;
                ch_Value.Add(temp_List);
                filter_Value.Add(temp_List);
            }

            draw_Background();
        }          
        /// <summary>
        /// 初始背景绘制
        /// </summary>
        public void draw_Background()
        {
            Graphics draw_Background_Gra = scope_panel.CreateGraphics();
            Pen line_Pen = new Pen(Color.White);

            Pen lable_Pen = new Pen(Color.White);
            Font lable_Font = new Font("宋体", 9); 
          
            scopePanel_Size = scope_panel.Size;

            /////绘制XY轴坐标系
            draw_X_Axis(draw_Background_Gra,new Point(Y_Blank, scopePanel_Size.Height - X_Blank), new Point(scopePanel_Size.Width, scopePanel_Size.Height - X_Blank ), 0, X_Step );
            draw_Y_Axis(draw_Background_Gra,new Point(Y_Blank, scopePanel_Size.Height - X_Blank), new Point(Y_Blank, X_Blank), 0, Y_Step );

        }    
        #endregion


        #region 坐标轴与栅格绘制

        /// <summary>
        /// ///////////////绘制完整XY轴坐标轴，包括轴线和轴上的值
        /// <param name="startPoint"></param>  坐标轴起始点
        /// <param name="endPoint"></param>    坐标轴结束点
        /// <param name="minNum"></param>      坐标轴起始值
        /// <param name="step_Length"></param> 坐标轴步长
        private void draw_X_Axis(Graphics draw_Background_Gra, Point startPoint, Point endPoint, float minNum, float step_Length)
        {
            float maxNum = minNum + step_Length * step_Num ;
            X_MinNum = minNum;
            X_MaxNum = maxNum;
            int X_Length = endPoint.X - startPoint.X;
            uint X_SliceLength = (uint)X_Length / step_Num;
            float num_Slice = step_Length;

            StringFormat stringFormat = new StringFormat();
            stringFormat.Alignment = StringAlignment.Center;

            Pen line_Pen = new Pen(Color.White);



            Pen lable_Pen = new Pen(Color.White);
            Font lable_Font = new Font("宋体", 9);


            /////绘制X轴线
            draw_Background_Gra.DrawLine(line_Pen, new PointF(startPoint.X, startPoint.Y  ), new PointF(endPoint.X ,endPoint .Y ));
            /////清楚X轴下方空间
            draw_Background_Gra.FillRectangle(new SolidBrush(scope_panel.BackColor), 0 , scope_panel.Height - X_Blank+1, scope_panel.Width , X_Blank );

            /////绘制X轴各段及坐标值
            for (int i = 0; i < step_Num + 1; i++)
            { 
                PointF  temp_Poi=new PointF ();
                temp_Poi.X  = startPoint.X +i*X_SliceLength;
                temp_Poi.Y = startPoint.Y ;
                if (temp_Poi.X > scope_panel.Width)
                    temp_Poi.X = scope_panel.Width ;

                draw_Background_Gra.DrawLine(new Pen(line_Pen.Color ,2), new PointF(temp_Poi.X, temp_Poi.Y +4), new PointF(temp_Poi.X, temp_Poi.Y));

                draw_Background_Gra.DrawString((minNum + i * num_Slice).ToString("F0"), lable_Font, new SolidBrush(Color.White), new PointF(temp_Poi.X+3, temp_Poi.Y+4),stringFormat );
                if (i < step_Num)
                for (int j = 1; j < 4; j++)
                {
                    temp_Poi.X = temp_Poi.X +  X_SliceLength /4;
                    if (temp_Poi.X > scope_panel.Width)
                        temp_Poi.X = scope_panel.Width;
                    draw_Background_Gra.DrawLine(line_Pen, new PointF(temp_Poi.X, temp_Poi.Y+3), new PointF(temp_Poi.X, temp_Poi.Y));
                }
               
            }

        }
        private void draw_Y_Axis(Graphics draw_Background_Gra, Point startPoint, Point endPoint, float minNum, float step_Length)
        {
            float maxNum = minNum + step_Length * step_Num;
            Y_MinNum = minNum;
            Y_MaxNum = maxNum;

            int Y_Length = startPoint.Y - endPoint.Y;
            uint Y_SliceLength = (uint)Y_Length / step_Num;
            float num_Slice = step_Length;


            Pen line_Pen = new Pen(Color.White);
            Pen lable_Pen = new Pen(Color.White);
            Font lable_Font = new Font("宋体", 9);
            StringFormat stringFormat = new StringFormat();
            stringFormat.Alignment = StringAlignment.Center;

            /////绘制Y轴轴线
            draw_Background_Gra.DrawLine(line_Pen, startPoint, endPoint);
            draw_Background_Gra.DrawLine(line_Pen, endPoint,new Point (endPoint .X ,endPoint .Y-X_Blank )  );
            /////清楚Y轴左方区域
            draw_Background_Gra.FillRectangle(new SolidBrush (scope_panel .BackColor ),0,0,Y_Blank ,scope_panel .Height-X_Blank  );

            /////绘制Y轴各段及坐标值
            for (int i = 0; i < step_Num + 1; i++)
            {
                PointF temp_Poi = new PointF();
                temp_Poi.X = startPoint.X;
                temp_Poi.Y = startPoint.Y - i * Y_SliceLength;

                if (temp_Poi.Y < 0)
                    temp_Poi.Y = 0;

                draw_Background_Gra.DrawLine(new Pen(line_Pen.Color, 2), new PointF(temp_Poi.X-4, temp_Poi.Y), new PointF(temp_Poi.X, temp_Poi.Y));
                draw_Background_Gra.DrawString((minNum + i * num_Slice).ToString("F0"), lable_Font, new SolidBrush(Color.White), new PointF(temp_Poi.X - Y_Blank/2, temp_Poi.Y - 10), stringFormat);

                if (i < step_Num)
                for (int j = 1; j < 4; j++)
                {
                    temp_Poi.Y = temp_Poi.Y - Y_SliceLength / 4;
                    if (temp_Poi.Y < 0)
                        temp_Poi.Y = 0;

                    draw_Background_Gra.DrawLine(line_Pen, new PointF(temp_Poi.X - 2, temp_Poi.Y), new PointF(temp_Poi.X, temp_Poi.Y));

                }

            }
        }


        /// <summary>
        /// ///////////////绘制完整XY坐标平面内栅格
        /// <param name="startPoint"></param>  坐标轴起始点
        /// <param name="endPoint"></param>    坐标轴结束点
        /// <param name="minNum"></param>      坐标轴起始值
        /// <param name="step_Length"></param> 坐标轴步长
        private void draw_X_Net(Graphics draw_Background_Gra, Point startPoint, Point endPoint, float minNum, float step_Length)
        {
            float maxNum = minNum + step_Length * step_Num;

            int X_Length = endPoint.X - startPoint.X;
            uint X_SliceLength = (uint)X_Length / step_Num;
            float num_Slice = step_Length;

            X_dash_Pen.DashStyle = System.Drawing.Drawing2D.DashStyle.Custom;
            X_dash_Pen.DashPattern = new float[] { 1, 5 };

            if (vertical_checkBox)
            {
                for (int i = 0; i < step_Num + 1; i++)
                {
                    PointF temp_Poi = new PointF();
                    temp_Poi.X = startPoint.X + i * X_SliceLength;
                    temp_Poi.Y = startPoint.Y;
                    if (temp_Poi.X > scope_panel.Width)
                        temp_Poi.X = scope_panel.Width;


                        draw_Background_Gra.DrawLine(X_dash_Pen, new PointF(temp_Poi.X, 0), new PointF(temp_Poi.X, temp_Poi.Y));              
                }
            }
        }
        private void draw_Y_Net(Graphics draw_Background_Gra, Point startPoint, Point endPoint, float minNum, float step_Length)
        {
            float maxNum = minNum + step_Length * step_Num;

            int Y_Length = startPoint.Y - endPoint.Y;
            uint Y_SliceLength = (uint)Y_Length / step_Num;
            float num_Slice = step_Length;

            Y_dash_Pen.DashStyle = System.Drawing.Drawing2D.DashStyle.Custom;
            Y_dash_Pen.DashPattern = new float[] { 1, 5 };
            if (Horizontal_checkBox)
            {
                for (int i = 0; i < step_Num + 1; i++)
                {
                    PointF temp_Poi = new PointF();
                    temp_Poi.X = startPoint.X;
                    temp_Poi.Y = startPoint.Y - i * Y_SliceLength;

                    if (temp_Poi.Y < 0)
                        temp_Poi.Y = 0;

                    draw_Background_Gra.DrawLine(Y_dash_Pen, new PointF(scope_panel.Width, temp_Poi.Y), new PointF(temp_Poi.X, temp_Poi.Y));

                }
            }
        }


        /// <summary>
        /// /////////////只绘制坐标轴上的值，快速更新用
        /// <param name="startPoint"></param>  坐标轴起始点
        /// <param name="endPoint"></param>    坐标轴结束点
        /// <param name="minNum"></param>      坐标轴起始值
        /// <param name="step_Length"></param> 坐标轴步长
        private void draw_X_AxisString(Graphics draw_Background_Gra, Point startPoint, Point endPoint, float minNum, float step_Length)
        {
            uint slice = 10;
            float maxNum = minNum + step_Length * slice;
            X_MinNum = minNum;
            X_MaxNum = maxNum;
            int X_Length = endPoint.X - startPoint.X;
            uint X_SliceLength = (uint)X_Length / slice;
            float num_Slice = step_Length;

            StringFormat stringFormat = new StringFormat();
            stringFormat.Alignment = StringAlignment.Center;

            Pen lable_Pen = new Pen(Color.White);
            Font lable_Font = new Font("宋体", 9);

            draw_Background_Gra.FillRectangle(new SolidBrush(scope_panel.BackColor), 0, scope_panel.Height - X_Blank + 4, scope_panel.Width, X_Blank);
            
            for (int i = 0; i < slice + 1; i++)
            {
                PointF temp_Poi = new PointF();
                temp_Poi.X = startPoint.X + i * X_SliceLength;
                temp_Poi.Y = startPoint.Y;
                if (temp_Poi.X > scope_panel.Width)
                    temp_Poi.X = scope_panel.Width;
                draw_Background_Gra.DrawString((minNum + i * num_Slice).ToString("F0"), lable_Font, new SolidBrush(Color.White), new PointF(temp_Poi.X + 3, temp_Poi.Y+4), stringFormat);
            }
        }
        private void draw_Y_AxisString(Graphics draw_Background_Gra,Point startPoint, Point endPoint, float minNum, float step_Length)
        {
            uint slice = 10;
            float maxNum = minNum + step_Length * slice;
            Y_MinNum = minNum;
            Y_MaxNum = maxNum;
            int Y_Length = startPoint.Y - endPoint.Y;
            uint Y_SliceLength = (uint)Y_Length / slice;
            float num_Slice = step_Length;


            Pen lable_Pen = new Pen(Color.White);
            Font lable_Font = new Font("宋体", 9);
            StringFormat stringFormat = new StringFormat();
            stringFormat.Alignment = StringAlignment.Center;

            draw_Background_Gra.FillRectangle(new SolidBrush(scope_panel.BackColor), 0, 0, Y_Blank-4, scope_panel.Height - X_Blank+5);
            for (int i = 0; i < slice + 1; i++)
            {
                PointF temp_Poi = new PointF();
                temp_Poi.X = startPoint.X;
                temp_Poi.Y = startPoint.Y - i * Y_SliceLength;

                if (temp_Poi.Y < 0)
                    temp_Poi.Y = 0;

                draw_Background_Gra.DrawString((minNum + i * num_Slice).ToString("F0"), lable_Font, new SolidBrush(Color.White), new PointF(temp_Poi.X - Y_Blank / 2, temp_Poi.Y - 10), stringFormat);

            }
        }


        /// <summary>
        ///////////////只绘制两条轴线，快速更新用
        /// <param name="startPoint"></param>  坐标轴起始点
        /// <param name="endPoint"></param>    坐标轴结束点
        private void draw_X_AxisLine(Graphics draw_Background_Gra, Point startPoint, Point endPoint)
        {
            Pen line_Pen = new Pen(Color.White);
          draw_Background_Gra.DrawLine(line_Pen, startPoint , endPoint );
        }
        private void draw_Y_AxisLine(Graphics draw_Background_Gra, Point startPoint, Point endPoint)
        {
            Pen line_Pen = new Pen(Color.White);
            draw_Background_Gra.DrawLine(line_Pen, startPoint, endPoint);
        }
        #endregion


        #region  定时器中断
        /// <summary>
        /// 解决从设置界面更改示波器背景后无波形问题
        /// 设置界面关闭后打开定时器中断扫描一次示波器
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void set_Back_timer_Tick(object sender, EventArgs e)
        {
            set_Back_timer.Stop();
            draw_Scope(X_MinNum, X_Step, Y_MinNum, Y_Step);
        }

        float num = 0;
        /// <summary>
        /// 示波器演示模式计时器，产生正弦波到各通道
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void scope_timer_Tick(object sender, EventArgs e)
        {
            Int32[] value = new int[channel_Num];
            int temp_Num = (int)(Math.Sin(num) * 5000);
            for (int i = 0; i < channel_Num; i++)
            {
                value[channel_Num - i - 1] = temp_Num * i / channel_Num;
            }
            Add_Point(value);
            num += 0.05F;
        }
        /// <summary>
        /// 系统定时器中断，
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void system_timer_Tick(object sender, EventArgs e)
        {
            if (work_Mode == "工作模式")
            {
                label_Frame_Num.Text = frame_Time.ToString();
                frame_Time = 0;         
            }

        }
        #endregion


        #region  波形绘制

       
        /// <summary>
        /// 示波器各通道添加值并显示到示波器
        /// <param name="channel"></通道>
        /// <param name="value"></值>
        private void Add_Point(Int32[] value)
        {
            if (filter_Enable)     /////////若滤波器使能，对输入数据进行滤波
            {
                if (filter_Style =="average")
                {
                    for (Byte i = 0; i < filter_Ch.Count(); i++)
                    {
                        value[filter_Ch[i] - 1] = filter_Average(filter_Ch[i],value[filter_Ch[i] - 1]);
                    }
                }
                else if(filter_Style =="middle" )
                {
                    for (Byte i = 0; i < filter_Ch.Count(); i++)
                    {
                        value[filter_Ch[i] - 1] = filter_Middle(filter_Ch[i],value[filter_Ch[i] - 1]);
                    }
                }
                else if (filter_Style =="mid_Ave")
                {
                    for (Byte i = 0; i < filter_Ch.Count; i++)
                    {
                        value[filter_Ch[i] - 1] = filter_Mid_Ave(filter_Ch[i],value[filter_Ch[i] - 1]);
                    }
                }
            }

            ///////////////更新示波器极值并显示各通道接收值
            int max_Value=0  , min_Value=0 ;

            for (int i = 0; i < channel_Num; i++) //确定使用已勾选的通道作为最值的基值
            {
                if (checkBox_Arr[i].Checked == true)
                {
                    max_Value = value[i];
                    min_Value = value[i];
                    break;
                }
            }

            for (int i = 0; i < channel_Num; i++)
            {
                lable_Arr[i].Text = value[i].ToString();

                if (checkBox_Arr[i].Checked == false)
                {
                    continue;
                }
                if (value[i] > max_Value)
                {
                    max_Value = value[i];
                }
                if (value[i] < min_Value)
                {
                    min_Value = value[i];
                }

                //if (value[i] > Y_Scope_MaxNum)
                //    Y_Scope_MaxNum = value[i];
                //if (value[i] < Y_Scope_MinNum)
                //    Y_Scope_MinNum = value[i];
                //if ((Y_Scope_MaxNum - Y_Scope_MinNum) > (step_Num  * Y_Step))
                //    Y_Step = (Y_Scope_MaxNum - Y_Scope_MinNum) / step_Num;
            }
            Y_Scope_MaxNum = max_Value;
            Y_Scope_MinNum = min_Value;
            if ((Y_Scope_MaxNum - Y_Scope_MinNum) > (step_Num  * Y_Step))
                Y_Step = (Y_Scope_MaxNum - Y_Scope_MinNum) / step_Num;
            //if (max_Value > Y_Scope_MaxNum)
            //    Y_Scope_MaxNum = max_Value;
            //if (min_Value < Y_Scope_MinNum)
            //    Y_Scope_MinNum = min_Value;
            //if ((Y_Scope_MaxNum - Y_Scope_MinNum) > (step_Num * Y_Step))
            //    Y_Step = (Y_Scope_MaxNum - Y_Scope_MinNum) / step_Num;

            //////////////更新示波器显示窗口极值
            if (Y_Scope_MaxNum > Y_MaxNum)
            {
                Y_MinNum = Y_Scope_MaxNum - step_Num * Y_Step;
            }
            if (Y_Scope_MinNum < Y_MinNum)
            {
                Y_MinNum = Y_Scope_MinNum;
            }

            /////////////X轴显示向前滑动
            X_Position++;
            if (X_Position >= X_MaxNum)
            {
                X_MinNum += 1;
            }

            ch1_Value.Add(value[0]);
            ch2_Value.Add(value[1]);
            ch3_Value.Add(value[2]); 
            ch4_Value.Add(value[3]);
            ch5_Value.Add(value[4]);
            ch6_Value.Add(value[5]);
            ch7_Value.Add(value[6]);
            ch8_Value.Add(value[7]);
            ch9_Value.Add(value[8]);
            ch10_Value.Add(value[9]);
            ch11_Value.Add(value[10]);
            ch12_Value.Add(value[11]);

            ch_Value[0] = ch1_Value;
            ch_Value[1] = ch2_Value;
            ch_Value[2] = ch3_Value;
            ch_Value[3] = ch4_Value;
            ch_Value[4] = ch5_Value;
            ch_Value[5] = ch6_Value;
            ch_Value[6] = ch7_Value;
            ch_Value[7] = ch8_Value;
            ch_Value[8] = ch9_Value;
            ch_Value[9] = ch10_Value;
            ch_Value[10] = ch11_Value;
            ch_Value[11] = ch12_Value;

            ///////////绘制波形图
            draw_Scope(X_MinNum ,X_Step,Y_MinNum ,Y_Step );
        }


        /// <summary>
        /// 绘制示波器各通道波形
        /// </summary>
        /// <param name="temp_X_MinNum"></param>
        /// <param name="temp_X_Step"></param>
        /// <param name="temp_Y_MinNum"></param>
        /// <param name="temp_Y_Step"></param>
        public void draw_Scope(float temp_X_MinNum, float temp_X_Step, float temp_Y_MinNum, float temp_Y_Step)
        {
            ///////////////////双缓冲绘制示波器波形
            Bitmap image = new Bitmap(scope_panel.Width, scope_panel.Height);
            Graphics Graw_Wave = Graphics.FromImage(image);
            Graphics scope_Gra = scope_panel.CreateGraphics();

            Int32 offset_Point = 0;
            Int32 arr_Length;

            ///////////////////XY轴绘制
            draw_X_Axis(Graw_Wave, new Point(Y_Blank, scopePanel_Size.Height - X_Blank), new Point(scopePanel_Size.Width, scopePanel_Size.Height - X_Blank), temp_X_MinNum, temp_X_Step);
            draw_Y_Axis(Graw_Wave, new Point(Y_Blank, scopePanel_Size.Height - X_Blank), new Point(Y_Blank, X_Blank), temp_Y_MinNum, temp_Y_Step);
            
            ///////////////////鼠标所在位置更新
            mouse_LocationUpdata();

            //////////////////确定示波器波形绘制缓存数组的长度
            if (X_MinNum < 0)
            {
                arr_Length = ch_Value[0].Count;
            }
            else
            {
                arr_Length = ch_Value[0].Count - (Int32)X_MinNum;
                if (arr_Length < 0)
                    arr_Length = 0;
            }

            ////////////////示波器显示点数组
            Point[][] ch_arr = new Point[channel_Num][];
            for (int i = 0; i < channel_Num; i++)
            {
                ch_arr[i] = new Point[arr_Length];
            }    


            ////////////////从示波器各通道原始值转换到屏幕坐标点并绘制波形
            if (ch_Value[0].Count > 1 && arr_Length > 1)
            {
                if (X_MinNum < 0)
                    offset_Point = 0;
                else
                    offset_Point = (Int32)X_MinNum;
                Graw_Wave.FillRectangle(new SolidBrush(scope_panel.BackColor), Y_Blank + 1, 0, scope_panel.Width - Y_Blank, scope_panel.Height - X_Blank);
               
                for (int j = 0; j < channel_Num ; j++)
                {
                   if (checkBox_Arr[j].Checked == true)
                    {
                        for (Int32 i = 0; i < arr_Length; i++)
                        {
                            ch_arr[j][i] = get_PannelPosition(new Point(i + offset_Point, ch_Value[j][i + offset_Point]));
                        }
                        Graw_Wave.DrawLines(ch_Pen[j], ch_arr[j]);
                    }
                }
            }
            else
            {
                Graw_Wave.FillRectangle(new SolidBrush(scope_panel.BackColor), Y_Blank + 1, 0, scope_panel.Width - Y_Blank, scope_panel.Height - X_Blank);
            }

            ///////////示波器栅格绘制
            draw_X_Net(Graw_Wave, new Point(Y_Blank, scopePanel_Size.Height - X_Blank), new Point(scopePanel_Size.Width, scopePanel_Size.Height - X_Blank), temp_X_MinNum, temp_X_Step);
            draw_Y_Net(Graw_Wave, new Point(Y_Blank, scopePanel_Size.Height - X_Blank), new Point(Y_Blank, X_Blank), temp_Y_MinNum, temp_Y_Step);
            //////////更新图像到示波器面板
            scope_Gra.DrawImage(image, 0, 0);

            scope_Gra.Dispose();
            image.Dispose();
        }


        /// <summary>
        /// 清除示波器波形缓存值
        /// </summary>
        private void clean_Scope()
        {
            ch1_Value.Clear();
            ch2_Value.Clear();
            ch3_Value.Clear();
            ch4_Value.Clear();
            ch5_Value.Clear();
            ch6_Value.Clear();
            ch7_Value.Clear();
            ch8_Value.Clear();
            ch9_Value.Clear();
            ch10_Value.Clear();
            ch11_Value.Clear();
            ch12_Value.Clear();

        }

        #endregion


        #region  常用滤波器
        private void button1_Click_1(object sender, EventArgs e)
        {
            if (filter_Enable)
            {
                filter_Enable = false;
                filter_button.ImageIndex = 0;
                filter_Style = null ;
                for (Byte i = 0; i < channel_Num; i++)
                {
                    filter_Value[i].Clear();
                }
                smooth_Length = 0;
            }
            else
            {
                filter_Enable = true;
                filter_button.ImageIndex = 1;
                filter_Set set_Form = new filter_Set();
                set_Form.Owner = this;

                set_Form.Show();
            }
        }
        /// <summary>
        /// 滑动均值滤波
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        private Int32  filter_Average(Byte ch ,Int32 value)
        {
            List<Int32> temp_List = new List<int>();

            if (filter_Value[ch-1].Count() < smooth_Length)
            {
                filter_Value[ch-1].Add(value);
                return value;
            }
            else
            {
                filter_Value[ch - 1].RemoveAt(0);
                filter_Value[ch - 1].Add(value);
                return ((int)(filter_Value[ch - 1].Average()));
            }
        }


        /// <summary>
        /// 滑动中值滤波
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        private Int32 filter_Middle(Byte ch, Int32 value)
        {
            if (filter_Value[ch - 1].Count() < smooth_Length)
            {
                filter_Value[ch - 1].Add(value);
                return value;
            }
            else
            {
                List<Int32> temp_List = new List<int>();
                filter_Value[ch - 1].RemoveAt(0);
                filter_Value[ch - 1].Add(value);

                temp_List = filter_Value[ch - 1].ToArray ().ToList ();
                temp_List.Sort ();
                return (temp_List[(smooth_Length - 1) / 2]);
            }
        }


        /// <summary>
        /// 滑动中位值平均滤波
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        private Int32 filter_Mid_Ave(Byte ch, Int32 value)
        {
            if (filter_Value[ch - 1].Count() < smooth_Length)
            {
                filter_Value[ch - 1].Add(value);
                return value;
            }
            else
            {
                float sum=0;
                List<Int32> temp_List = new List<int>();
                filter_Value[ch - 1].RemoveAt(0);
                filter_Value[ch - 1].Add(value);
                temp_List = filter_Value[ch - 1].ToArray().ToList();
                temp_List.Sort();
                for (int i=1;i<smooth_Length-1;i++)
                {
                    sum += temp_List[i];
                }
                return ((int)(sum / (smooth_Length-2)));
            }
        }

        #endregion 


        #region  坐标系坐标变换
        /// <summary>
        ///由面板位置坐标获得坐标系XY轴坐标
        /// </summary>
        /// <param name="form_Point"></param>
        /// <returns></returns>
        private Point get_CoordinatePosition(Point pannel_Point)
        {
            Point temp_poi = new Point();

            temp_poi.X = pannel_Point.X - Y_Blank;
            temp_poi.Y = scope_panel.Size.Height - pannel_Point.Y - X_Blank;

            temp_poi.X = (int)(X_MinNum + temp_poi.X * (X_MaxNum - X_MinNum) / (scope_panel.Size.Width - Y_Blank));
            temp_poi.Y = (int)(Y_MinNum + temp_poi.Y * (Y_MaxNum - Y_MinNum) / (scope_panel.Size.Height - 2 * X_Blank));

            return temp_poi;

        }

        /// <summary>
        /// 由坐标系XY轴坐标获得面板坐标
        /// </summary>
        private Point get_PannelPosition(Point Coordinate_Point)
        {
            Point temp_poi = new Point();

            temp_poi.X = (int )((Coordinate_Point.X-X_MinNum ) / (X_MaxNum - X_MinNum) *( scope_panel.Width - Y_Blank));
            temp_poi .Y =(int )(( Coordinate_Point .Y -Y_MinNum )/(Y_MaxNum-Y_MinNum )* (scope_panel.Height-2*X_Blank)); 

            temp_poi.X += Y_Blank;
            temp_poi.Y = scope_panel.Height - X_Blank - temp_poi.Y;
            if (temp_poi.X < Y_Blank)
            {
                temp_poi.X = Y_Blank+1;
            }
            if (temp_poi.Y > scope_panel.Height - X_Blank)
            {
                temp_poi.Y = scope_panel.Height - X_Blank;
            }

            return temp_poi;
        }
        #endregion


        #region  模式设置
        private void mode_comboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (mode_comboBox.SelectedIndex == 0)
            {
                work_Mode = "工作模式";
                clean_Scope();
                scope_timer.Stop();
                label_Frame_Num.Text = "0";
            }
            else if (mode_comboBox.SelectedIndex == 1)
            {
                work_Mode = "演示模式";
                scope_timer.Start();
                pause_Status = false;
                pause_button.ImageIndex = 4;
                label_Frame_Num.Text = "20";
            }
        }

        #endregion


        #region  调试通道

        private void send_db_button_Click(object sender, EventArgs e)
        {
            send_Data();
        }
        public void send_Data()
        {
            TxBuffer[0] = 0x88;
            TxBuffer[1] = 0x88;
            Byte  sum =0;

            for (int i = 0; i < 12; i++)
            {
                if (db_CheckBox_Arr[i].Checked == true)
                {
                    byte[] float_Byte = new Byte[4];
                    try
                    {
                        float_Byte = BitConverter.GetBytes(Convert.ToSingle(textBox_Arr[i].Text));
                    }
                    catch(Exception ex)
                    {
                        if (ex.ToString().Contains("格式不正确"))
                        {
                            MessageBox.Show("输入格式不正确", "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Error );
                        }
                        textBox_Arr[i].Clear();
                    }
                    TxBuffer[1 + i * 4 + 1] = float_Byte[0];
                    TxBuffer[1 + i * 4 + 2] = float_Byte[1];
                    TxBuffer[1 + i * 4 + 3] = float_Byte[2];
                    TxBuffer[1 + i * 4 + 4] = float_Byte[3];

                    sum += float_Byte[3];
                }
                else
                {
                    TxBuffer[1 + i * 4 + 1] = 0;
                    TxBuffer[1 + i * 4 + 2] = 0;
                    TxBuffer[1 + i * 4 + 3] = 0;
                    TxBuffer[1 + i * 4 + 4] = 0;
                }
            }
            TxBuffer[50] = sum;

            if (data_serialPort.IsOpen)
            {
                data_serialPort.Write(TxBuffer,0,51);
            }
        }

        #endregion


        #region 按键与CheckBox响应
        /// <summary>
        /// 通道设置按键响应
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void set_button_Click(object sender, EventArgs e)
        {
            channel_Set set_Form = new channel_Set();
            set_Form.Owner = this;

            set_Form.Show();
        }


        /// <summary>
        /// 调试通道设置按键响应
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void set_db_button_Click(object sender, EventArgs e)
        {
            debug_Ch_Set set_Form = new debug_Ch_Set();
            set_Form.Owner = this;

            set_Form.Show();
        }


        /// <summary>
        /// 暂停按键响应
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void pause_button_Click(object sender, EventArgs e)
        {
            if (work_Mode == "演示模式")
            {
                if (pause_Status)
                {
                    pause_Status = false;
                    scope_timer.Start();
                    pause_button.ImageIndex = 4;
                }
                else
                {
                    pause_Status = true ;
                    scope_timer.Stop();
                    pause_button.ImageIndex = 5;
                }
            }
            else if (work_Mode == "工作模式")
            {
                if (pause_Status)      /////暂停状态
                {
                    pause_Status = false;
                    pause_button.ImageIndex = 4;
                }
                else
                {
                    pause_Status = true;
                    pause_button.ImageIndex = 5;
                }
            }
        }


        /// <summary>
        /// 调试通道向上步进按键响应
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void up_button_Click(object sender, EventArgs e)
        {

            if (ch_comboBox.SelectedIndex < 0)
            {
                MessageBox.Show("请选择步进通道！", "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            if (step_textBox.Text.Length == 0)
            {
                MessageBox.Show("请输入步进值！", "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            else
            {
                try
                {
                    textBox_Arr[ch_comboBox.SelectedIndex].Text = (Convert.ToSingle(textBox_Arr[ch_comboBox.SelectedIndex].Text) + Convert.ToSingle(step_textBox.Text)).ToString();
                }
                catch (Exception ex)
                {
                    if (ex.ToString().Contains("格式不正确"))
                    {
                        MessageBox.Show("输入格式不正确", "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                    step_textBox.Clear();
                }
            }

            if (stepTo_send)
            {
                send_Data();
            }
        }


        /// <summary>
        /// 调试通道向上步进按键响应
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void down_button_Click(object sender, EventArgs e)
        {
            if (ch_comboBox.SelectedIndex < 0)
            {
                MessageBox.Show("请选择步进通道！", "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            if (step_textBox.Text.Length == 0)
            {
                MessageBox.Show("请输入步进值！", "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            else
            {
                try
                {
                    textBox_Arr[ch_comboBox.SelectedIndex].Text = (Convert.ToSingle(textBox_Arr[ch_comboBox.SelectedIndex].Text) - Convert.ToSingle(step_textBox.Text)).ToString();
                }
                catch (Exception ex)
                {
                    if (ex.ToString().Contains("格式不正确"))
                    {
                        MessageBox.Show("输入格式不正确", "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                    step_textBox.Clear();
                }
            }
            if (stepTo_send)
            {
                send_Data();
            }
        }


        private void checkBox_Click(object sender, EventArgs e)
        {
                draw_Scope(X_MinNum, X_Step, Y_MinNum, Y_Step);
        }

        #endregion


        #region  鼠标事件响应
        private void mouse_LocationUpdata()
        {
            Point mouse_Location = new Point();
            mouse_Location = get_CoordinatePosition(MousePosition);
            XValue_label.Text = mouse_Location.X.ToString();
            YValue_label.Text = mouse_Location.Y.ToString();
        }
        private void scope_panel_MouseDown(object sender, MouseEventArgs e)
        {
            mouse_Down = true;
            mouse_DownPosition = get_CoordinatePosition(e.Location);
        }

        private void scope_panel_MouseUp(object sender, MouseEventArgs e)
        {
            mouse_Down = false;
        }
        private void scope_panel_MouseMove(object sender, MouseEventArgs e)
        {
            Point mouse_Location = new Point();
            Point mouse_Move = new Point();
            mouse_Location = get_CoordinatePosition(e.Location);

            if (mouse_Down == false)
            {
                XValue_label.Text = mouse_Location.X.ToString();
                YValue_label.Text = mouse_Location.Y.ToString();
            }
            else
            {
                mouse_Move.X = mouse_Location.X - mouse_DownPosition.X;
                mouse_Move.Y = mouse_Location.Y - mouse_DownPosition.Y;
                draw_Scope( (X_MinNum - mouse_Move.X), X_Step,(Y_MinNum - mouse_Move.Y), Y_Step);
            }

        }


        Int32 scroll_Angle = 0;   //滚轮滑动一圈24格
        /// <summary>
        /// 滚轮控制坐标轴缩放
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void scope_panel_MouseWheel(object sender, MouseEventArgs e)
        {

            Graphics mm = scope_panel.CreateGraphics();

            Point mouse_Location = new Point();
            mouse_Location = get_CoordinatePosition(e.Location);

            XValue_label.Text = mouse_Location.X.ToString();
            YValue_label.Text = mouse_Location.Y.ToString();

            float X_Min, Y_Min;
            scroll_Angle++;
            if (e.Delta > 0)  //滑轮向上
            {

                if (XZoom_radioButton.Checked == true)
                {
                    if (X_Step > 1)
                    {
                        X_Step /= 2;
                        X_Min = mouse_Location.X - (mouse_Location.X - X_MinNum) / 2;
                        draw_Scope(X_Min, X_Step, Y_MinNum , Y_Step);
                    }
                }
                else if (YZoom_radioButton.Checked == true)
                {
                    if (Y_Step > 1)
                    {
                        Y_Step /= 2;
                        Y_Min = mouse_Location.Y - (mouse_Location.Y - Y_MinNum) / 2;
                        draw_Scope(X_MinNum, X_Step, Y_Min, Y_Step);
                    }
                }
                else if (zoom_radioButton.Checked == true)
                {
                    if (X_Step > 1)
                    {
                        X_Step /= 2;
                        X_Min = mouse_Location.X - (mouse_Location.X - X_MinNum) / 2;
                        draw_Scope(X_Min, X_Step, Y_MinNum, Y_Step);
                    }
                    if (Y_Step > 1)
                    {
                        Y_Step /= 2;
                        Y_Min = mouse_Location.Y - (mouse_Location.Y - Y_MinNum) / 2;
                        draw_Scope(X_MinNum, X_Step, Y_Min, Y_Step);

                    }
                }

            }
            else if (e.Delta < 0)           //滑轮向下
            {
                if (XZoom_radioButton.Checked == true)
                {
                    X_Step *= 2;
                    X_Min = mouse_Location.X - (mouse_Location.X - X_MinNum) * 2;
                    draw_Scope(X_Min, X_Step, Y_MinNum, Y_Step);
                }
                else if (YZoom_radioButton.Checked == true)
                {
                    Y_Step *= 2;
                    Y_Min = mouse_Location.Y - (mouse_Location.Y - Y_MinNum) * 2;
                    draw_Scope(X_MinNum, X_Step, Y_Min, Y_Step);
                }
                else if (zoom_radioButton.Checked == true)
                {
                    X_Step *= 2;
                    Y_Step *= 2;

                    X_Min = mouse_Location.X - (mouse_Location.X - X_MinNum) * 2;
                    Y_Min = mouse_Location.Y - (mouse_Location.Y - Y_MinNum) * 2;

                    draw_Scope(X_Min, X_Step, Y_MinNum, Y_Step);
                    draw_Scope(X_MinNum, X_Step, Y_Min, Y_Step);
                }
            }
        }
        #endregion


        #region  鼠标悬停时控件提示

        private void pause_button_MouseHover(object sender, EventArgs e)
        {
            if (pause_button.ImageIndex == 5)
            {
                control_toolTip.Show("运行", pause_button);
            }
            else
            {
                control_toolTip.Show("暂停", pause_button);
            }

        }

        #endregion


        #endregion


        #region 第三部分 ：图像显示

        #region 图像显示变量定义
        Graphics image1_Graphics;
        Graphics image2_Graphics;

        Bitmap image1;
        Bitmap image2;

        Bitmap image_Line1;
        Bitmap image_Line2;

        Bitmap image_ForSave;

        Int32  image_RGB_Index = 0;
        Byte[] RGB_Data = new Byte[3];
        Byte[] RGB565_Data = new Byte[2];
        float[] RGB_K = new float[3]; 
        bool RGB_ToGray = false;

        Byte bin_Threshold = 100;
        bool auto_Bin = true;

        Byte[] image_ByteSize=new Byte [5];     //用于存储串口接收到的图像大小数值
        Byte[] image_Data = new Byte[500*500*2];

        Size image_Size = new Size ();          //接收到的图像大小
        Size window_Size = new Size();          //显示图像的面板大小
        Point image_Place = new Point(0, 0);    //串口接收图像时用

        String image_Style;                     //图像形式  灰度 彩色

        String image_Align;                     //图像对齐方式  适应屏幕 原始比例
        float image_Height_K;                   //图像适应屏幕时高度比例

        string eagle_DataOrder = "先高后低";
        Byte[] color_Table = new Byte[2];

        bool save_Pic = false;                  //是否保存图像标志
        bool set_NewPic = false;                
        enum IMAGE_STATE
        {
            idle,   //闲置，无图像接收中
            ready,  //接收到一帧图像
            wrong,  //图像错误
            ongoing //正在接收图像
        };
        IMAGE_STATE image_State = IMAGE_STATE.idle;

        #endregion


        #region 图像显示初始化设置
        void Image_Init()
        {
            //变量初始化
            Bitmap image_Temp1 = new Bitmap(panel_Image1.Width, panel_Image1.Height,PixelFormat .Format24bppRgb);
            Bitmap image_Temp2 = new Bitmap(panel_Image2.Width, panel_Image2.Height, PixelFormat.Format24bppRgb);
            image1 = image_Temp1;
            image2 = image_Temp2;

            window_Size = panel_Image1.Size;

            image1_Graphics = panel_Image1.CreateGraphics();
            image2_Graphics = panel_Image2.CreateGraphics();

            //控件属性初始化
            comboBox_ImageStyle.SelectedIndex  = 0;
            comboBox_Threshold.SelectedIndex   = 0;
            comboBox_ImageAlign.SelectedIndex  = 0;

            image_ByteSize[0] = 0;

            RGB_K[0] = 1;
            RGB_K[1] = 1;
            RGB_K[2] = 1;

            color_Table[0] = 0;
            color_Table[1] = 255;
        }


        #endregion


        #region 图像刷新部分

        ///  刷新一行
        public void show_Line()
        {
            if (image_Place.Y < image_Size.Height)   //防止图像溢出画图面板
            {
                if (image_Align == "适应屏幕")
                {
                    Rectangle win_Rec = new Rectangle();
                    win_Rec.Width = window_Size.Width;
                    win_Rec.X = 0;
                    win_Rec.Y = (int)(image_Place.Y * image_Height_K);
                    win_Rec.Height = 1;
                    for (Byte m = 0; m < ((int)((image_Place.Y + 1) * image_Height_K) - (int)(image_Place.Y * image_Height_K)); m++, win_Rec.Y++)
                    {
                        image1_Graphics.DrawImage(image_Line1, win_Rec);
                        image2_Graphics.DrawImage(image_Line2, win_Rec);
                    }

                }
                else if (image_Align == "原始尺寸")
                {
                    image1_Graphics.DrawImage(image_Line1, 0, image_Place.Y);
                    image2_Graphics.DrawImage(image_Line2, 0, image_Place.Y);
                }
            }
        }


        /// 对收到的像素根据图像模式解压
        /// <param name="pix"></param>
        public void get_Image(Byte pix)
        {
            if ((pix == 0xff && (image_Style == "灰度图像" || image_Style == "彩色图像")) || (pix == 0xAA && image_Style == "二值图像"))       //已到帧尾
            {
                receive_State = 0;
                image_RGB_Index = 0;
                data_For = DATA_FOR.none;

                if ((image_Place.Y == image_Size.Height) && (image_Place.X == 0))
                {
                    image_State = IMAGE_STATE.ready;
                    label_ImageState.Text = image_State.ToString();
                    if (auto_Bin == true && image_Style == "灰度图像")
                    {
                        bin_Threshold = CalculateThreshold();
                        textBox_Threshold.Text = bin_Threshold.ToString();
                        trackBar_Threshold.Value = bin_Threshold;
                    }

                    if (save_Pic == true)
                    {
                        string pic_Name = DateTime.Now.ToFileTimeUtc().ToString();
                        string file_Path = @"../../../" + @"pic/"+ DateTime.Now.ToShortDateString().ToString();
                        string file_Name = file_Path + @"/" + pic_Name + ".bmp";
                        if (Directory.Exists(file_Path))
                        {
                            try
                            {
                                image_ForSave.Save(file_Name, System.Drawing.Imaging.ImageFormat.Bmp);
                            }
                            catch
                            {
                                MessageBox.Show("图像保存失败!");
                            }
                        }
                        else
                        {
                            Directory.CreateDirectory(file_Path);
                            try
                            {
                                image_ForSave.Save(file_Name, System.Drawing.Imaging.ImageFormat.Bmp);
                            }
                            catch
                            {
                                MessageBox.Show("图像保存失败!");
                            }
                        }

                        set_NewPic = false;
              
                    }



                }
                else
                {
                    image_State = IMAGE_STATE.wrong;
                    label_ImageState.Text = image_State.ToString();
                }
                image_Place.X = 0;
                image_Place.Y = 0;
            }
            else
            {

                if (image_Style == "灰度图像")
                {
//                    image_Data[image_Place.X + image_Place.Y * image_Size.Width] = pix; //存储图像数据

                    image_Line1.SetPixel(image_Place.X, 0, Color.FromArgb(pix, pix, pix));

                    if (save_Pic == true && set_NewPic == true)
                    {
                        image_ForSave.SetPixel(image_Place.X, image_Place.Y, Color.FromArgb(pix, pix, pix));
                    }

                    if (pix > bin_Threshold)
                    {
                        image_Line2.SetPixel(image_Place.X++, 0, Color.FromArgb(255, 255, 255));
                    }
                    else
                    {
                        image_Line2.SetPixel(image_Place.X++, 0, Color.FromArgb(0, 0, 0));
                    }

                    if (image_Place.X >= image_Size.Width)
                    {
                        show_Line();

                        if (image_Place.Y <= image_Size.Height)
                        {
                            label_Row.Text = image_Place.Y.ToString();
                            if (image_Place.Y < progressBar_Image.Maximum)
                                progressBar_Image.Value = image_Place.Y;
                        }
                        image_Place.X = 0;
                        image_Place.Y++;
                    }
                }
                else if (image_Style == "彩色图像")
                {
                    //                    image_Data[(image_Place.X + image_Place.Y * image_Size.Width)+image_RGB_Index%2] = pix; //存储图像，二值化用
                    RGB565_Data[image_RGB_Index % 2] = pix;
                    if (image_RGB_Index % 2 == 1)
                    {
                        RGB_Data[0] = (Byte)(RGB565_Data[0] & 0xf8);
                        RGB_Data[1] = (Byte)((RGB565_Data[0] << 5) | ((RGB565_Data[1] >> 3) & 0xfC));
                        RGB_Data[2] = (Byte)(RGB565_Data[1] << 3);

                        Color color_Temp1, color_Temp2;
                        if (RGB_ToGray)   //彩色图转灰度显示
                        {
                            Byte gray_Num;
                            gray_Num = (Byte)(RGB_Data[0] * 0.3 + RGB_Data[1] * 0.59 + RGB_Data[2] * 0.11);
                            color_Temp1 = Color.FromArgb(gray_Num, gray_Num, gray_Num);
                        }
                        else
                        {
                            color_Temp1 = Color.FromArgb(RGB_Data[0], RGB_Data[1], RGB_Data[2]);
                        }
                        image_Line1.SetPixel(image_Place.X, 0, color_Temp1);

                        if (save_Pic == true && set_NewPic == true)
                        {
                            image_ForSave.SetPixel(image_Place.X, image_Place.Y, color_Temp1);
                        }

                        if (checkBox_RGB_bin.Checked == false)
                        {
                            color_Temp2 = Color.FromArgb((Byte)(RGB_Data[0] * RGB_K[0]), (Byte)(RGB_Data[1] * RGB_K[1]), (Byte)(RGB_Data[2] * RGB_K[2]));
                            image_Line2.SetPixel(image_Place.X, 0, color_Temp2);
                        }
                        else
                        {
                            int RGB_Ave = (int)(RGB_Data[0] * RGB_K[0] + RGB_Data[1] * RGB_K[1] + RGB_Data[2] * RGB_K[2]) / 3;
                            if (RGB_Ave > bin_Threshold)
                            {
                                image_Line2.SetPixel(image_Place.X, 0, Color.FromArgb(255, 255, 255));
                            }
                            else
                            {
                                image_Line2.SetPixel(image_Place.X, 0, Color.FromArgb(0, 0, 0));
                            }
                        }
                        image_Place.X++;
                    }
                    image_RGB_Index++;
                    if (image_Place.X >= image_Size.Width)
                    {
                        show_Line();
                        if (image_Place.Y <= image_Size.Height)
                        {
                            label_Row.Text = image_Place.Y.ToString();
                            if (image_Place.Y < progressBar_Image.Maximum)
                                progressBar_Image.Value = image_Place.Y;
                        }
                        image_Place.X = 0;
                        image_Place.Y++;
                    }
                }
                else if (image_Style == "二值图像")
                {
                    for (Byte i = 0; i < 8; i++)
                    {
                        Byte pix_Temp;
                        if (eagle_DataOrder == "先高后低")
                        {
                             pix_Temp = color_Table[(pix >> (7 - i)) & 0x01];
                        }
                        else
                        {
                             pix_Temp = color_Table[(pix >> i) & 0x01];                       
                        }
                        image_Data[image_Place.X + image_Place.Y * image_Size.Width] = pix_Temp; //存储图像数据 

                        if (save_Pic == true && set_NewPic == true)
                        {
                            image_ForSave.SetPixel(image_Place.X, image_Place.Y, Color.FromArgb(pix, pix, pix));
                        }

                        image_Line1.SetPixel(image_Place.X, 0, Color.FromArgb(pix, pix, pix));
                        image_Line2.SetPixel(image_Place.X++, 0, Color.FromArgb(pix, pix, pix));


                        if (image_Place.X >= image_Size.Width)
                        {
                            show_Line();
                            if (image_Place.Y <= image_Size.Height)
                            {
                                label_Row.Text = image_Place.Y.ToString();
                                if (image_Place.Y < progressBar_Image.Maximum)
                                    progressBar_Image.Value = image_Place.Y;
                            }
                            image_Place.X = 0;
                            image_Place.Y++;
                        }
                    }
                }
                else
                {
                    image_State = IMAGE_STATE.wrong;
                    label_ImageState.Text = image_State.ToString();
                    receive_State = 0;
                }
            }
        }

        /// <summary>
        /// 动态阈值计算
        /// </summary>
        /// <returns></returns>
        public Byte CalculateThreshold()
        {
            int pixel;
            UInt16[] PixelNum = new UInt16[256];
            Int16 Thr = 100;
            Int16 line, column;

            Int32 p;
            Int32 total;
            Int32 TotalWeight = 0, ForeWeight = 0;
            Int32 TotalPixels = 0;

            Int32 BackPixNum = 0, ForePixNum = 0;
            double BackAvgGry, ForeAvgGry;
            double fmax = -1;
            double sb;

            for (line = 0; line < image_Size.Height; line++)
            {
                pixel = line * image_Size.Width;
                for (column = 0; column < image_Size.Width; column += 4)
                {
                    PixelNum[image_Data[pixel + column]]++;
                }
                line += 3;
            }

            for (line = 0; line < 256; line++)
            {
                total = 0;
                for (column = -2; column < 3; column++)
                {
                    p = line + column;
                    if (p < 0) p = 0;
                    else
                        if (p > 255) p = 255;
                    total += PixelNum[p];
                }
                PixelNum[line] = (Byte)((float)total / 5 + 0.5);
            }

            for (line = 0; line < 256; line++)
            {
                TotalWeight += line * PixelNum[line];
                TotalPixels += PixelNum[line];
            }

            for (line = 0; line < 256; line++)
            {
                ForePixNum += PixelNum[line];
                if (ForePixNum == 0) continue;
                BackPixNum = TotalPixels - ForePixNum;
                if (BackPixNum == 0) break;
                ForeWeight += line * PixelNum[line];
                ForeAvgGry = ((double)(ForeWeight)) / ForePixNum;
                BackAvgGry = ((double)(TotalWeight - ForeWeight)) / BackPixNum;
                sb = ForePixNum * BackPixNum * (ForeAvgGry - BackAvgGry) * (ForeAvgGry - BackAvgGry);
                if (sb > fmax)
                {
                    fmax = sb;
                    Thr = line;
                }
            }
            return (Byte)Thr;

        }

        #endregion


        #region  显示参数修改控件响应
        private void trackBar_Threshold_Scroll(object sender, EventArgs e)
        {
            textBox_Threshold.Text = trackBar_Threshold.Value.ToString();
        }

        private void comboBox_ImageStyle_SelectedIndexChanged(object sender, EventArgs e)
        {
            image_Style = comboBox_ImageStyle.SelectedItem.ToString();
            if (image_Style == "彩色图像")
            {
                checkBox_ToGray.Visible = true;
                groupBox_RGB.Visible = true;
                groupBox_eagle.Visible = false;
            }
            else if (image_Style == "灰度图像")
            {
                checkBox_ToGray.Visible = false;
                groupBox_RGB.Visible = false;
                groupBox_eagle.Visible = false;
            }
            else if (image_Style == "二值图像")
            {
                checkBox_ToGray.Visible = false;
                groupBox_RGB.Visible = false;
                groupBox_eagle.Visible = true;
            }
        }

        private void comboBox_ImageAlign_SelectedIndexChanged(object sender, EventArgs e)
        {
            image1_Graphics.Clear(panel_Image1.BackColor);
            image2_Graphics.Clear(panel_Image2.BackColor);
            image_Align = comboBox_ImageAlign.SelectedItem.ToString();
        }
        private void comboBox_Threshold_TextChanged(object sender, EventArgs e)
        {
            if (comboBox_Threshold.SelectedIndex == 0)
            {
                auto_Bin = true;
            }
            else
            {
                auto_Bin = false;
            }
        }

        private void checkBox_ToGray_CheckedChanged(object sender, EventArgs e)
        {
            RGB_ToGray = checkBox_ToGray.Checked;
        }

        private void trackBar_RGB_Scroll(object sender, EventArgs e)
        {
            if (radioButton_R.Checked == true)
            {
                RGB_K[0] = (float)trackBar_RGB.Value / 100;
                label_R.Text = RGB_K[0].ToString();
            }
            else if (radioButton_G.Checked == true)
            {
                RGB_K[1] = (float)trackBar_RGB.Value / 100;
                label_G.Text = RGB_K[1].ToString();
            }
            else if (radioButton_B.Checked == true)
            {
                RGB_K[2] = (float)trackBar_RGB.Value / 100;
                label_B.Text = RGB_K[2].ToString();
            }
        }

        private void radioButton_R_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton_R.Checked == true)
            {
                trackBar_RGB.Value = (int)(RGB_K[0] * 100);
            }
        }

        private void radioButton_G_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton_G.Checked == true)
            {
                trackBar_RGB.Value = (int)(RGB_K[1] * 100);
            }
        }

        private void radioButton_B_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton_B.Checked == true)
            {
                trackBar_RGB.Value = (int)(RGB_K[2] * 100);
            }
        }
        private void textBox_Threshold_TextChanged(object sender, EventArgs e)
        {
            try
            {
                bin_Threshold = Convert.ToByte(textBox_Threshold.Text);
            }
            catch
            {
                bin_Threshold = 255;
                textBox_Threshold.Text = "255";
            }
        }

        private void radioButton_BW_MouseClick(object sender, MouseEventArgs e)
        {
            if (radioButton_BW.Checked == false)
            {
                color_Table[0] = 255; color_Table[1] = 0;
                radioButton_BW.Checked = true;

                radioButton_WB.Checked = false;
            }
        }
        private void radioButton_WB_MouseClick(object sender, MouseEventArgs e)
        {
            if (radioButton_WB.Checked == false)
            {
                color_Table[0] = 0; color_Table[1] = 255;
                radioButton_WB.Checked = true;

                radioButton_BW.Checked = false;
            }
        }
        private void radioButton_FHLL_MouseClick(object sender, MouseEventArgs e)
        {
            if (radioButton_FHLL.Checked == false)
            {
                eagle_DataOrder = radioButton_FHLL.Text;
                radioButton_FHLL.Checked = true;

                radioButton_FLLH.Checked = false;
            }
        }
        private void radioButton_FLLH_MouseClick(object sender, MouseEventArgs e)
        {
            if (radioButton_FLLH.Checked == false)
            {
                eagle_DataOrder = radioButton_FLLH.Text;
                radioButton_FLLH.Checked = true;

                radioButton_FHLL.Checked = false;
            }
        }

        private void checkBox_SavePic_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox_SavePic.Checked == true)
            {
                save_Pic = true;
            }
            else
            {
                save_Pic = false;
            }

        }

        #endregion


        #endregion



    }
}
