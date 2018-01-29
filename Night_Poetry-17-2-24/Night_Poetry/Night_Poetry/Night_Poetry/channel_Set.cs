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
namespace Night_Poetry
{
    public partial class channel_Set : Form
    {
        
        public channel_Set()
        {
            InitializeComponent();
        }

        private void channel_Set_Load(object sender, EventArgs e)
        {
            main_Form main_form = (main_Form)this.Owner;
            ch1_button.BackColor = main_form.checkBox1.ForeColor;
            ch2_button.BackColor = main_form.checkBox2.ForeColor;
            ch3_button.BackColor = main_form.checkBox3.ForeColor;
            ch4_button.BackColor = main_form.checkBox4.ForeColor;
            ch5_button.BackColor = main_form.checkBox5.ForeColor;
            ch6_button.BackColor = main_form.checkBox6.ForeColor;
            ch7_button.BackColor = main_form.checkBox7.ForeColor;
            ch8_button.BackColor = main_form.checkBox8.ForeColor;
            ch9_button.BackColor = main_form.checkBox9.ForeColor;
            ch10_button.BackColor = main_form.checkBox10.ForeColor;
            ch11_button.BackColor = main_form.checkBox11.ForeColor;
            ch12_button.BackColor = main_form.checkBox12.ForeColor;
            back_button.BackColor = main_form.scope_panel.BackColor;

            vertical_button.BackColor = main_Form.X_dash_Pen.Color;
            Horizontal_button.BackColor = main_Form.Y_dash_Pen.Color;

            vertical_checkBox.Checked = main_Form.vertical_checkBox;
            Horizontal_checkBox.Checked = main_Form.Horizontal_checkBox;

            ch1_textBox.Text = main_form.checkBox1.Text;
            ch2_textBox.Text = main_form.checkBox2.Text;
            ch3_textBox.Text = main_form.checkBox3.Text;
            ch4_textBox.Text = main_form.checkBox4.Text;
            ch5_textBox.Text = main_form.checkBox5.Text;
            ch6_textBox.Text = main_form.checkBox6.Text;
            ch7_textBox.Text = main_form.checkBox7.Text;
            ch8_textBox.Text = main_form.checkBox8.Text;
            ch9_textBox.Text = main_form.checkBox9.Text;
            ch10_textBox.Text = main_form.checkBox10.Text;
            ch11_textBox.Text = main_form.checkBox11.Text;
            ch12_textBox.Text = main_form.checkBox12.Text;

            textBox_MaxFrame.Text = main_Form.max_Frame.ToString();
        }

        private void colorChange_button_Click(object sender, EventArgs e)
        {
            if (ch_colorDialog.ShowDialog() == DialogResult.OK)
            {
                Button sender_Button = sender as Button;
                sender_Button.BackColor = ch_colorDialog.Color;
            }
        }

        private void ok_button_Click(object sender, EventArgs e)
        {
            main_Form main_form = (main_Form)this.Owner ;

            main_form.checkBox1.ForeColor = ch1_button.BackColor;
            main_form.checkBox2.ForeColor = ch2_button.BackColor;
            main_form.checkBox3.ForeColor = ch3_button.BackColor;
            main_form.checkBox4.ForeColor = ch4_button.BackColor;
            main_form.checkBox5.ForeColor = ch5_button.BackColor;
            main_form.checkBox6.ForeColor = ch6_button.BackColor;
            main_form.checkBox7.ForeColor = ch7_button.BackColor;
            main_form.checkBox8.ForeColor = ch8_button.BackColor;
            main_form.checkBox9.ForeColor = ch9_button.BackColor;
            main_form.checkBox10.ForeColor = ch10_button.BackColor;
            main_form.checkBox11.ForeColor = ch11_button.BackColor;
            main_form.checkBox12.ForeColor = ch12_button.BackColor;
            main_form.scope_panel.BackColor = back_button.BackColor;

            main_Form.X_dash_Pen.Color = vertical_button.BackColor;
            main_Form.Y_dash_Pen.Color = Horizontal_button.BackColor;

            main_form.checkBox1.Text = ch1_textBox.Text;
            main_form.checkBox2.Text = ch2_textBox.Text;
            main_form.checkBox3.Text = ch3_textBox.Text;
            main_form.checkBox4.Text = ch4_textBox.Text;
            main_form.checkBox5.Text = ch5_textBox.Text;
            main_form.checkBox6.Text = ch6_textBox.Text;
            main_form.checkBox7.Text = ch7_textBox.Text;
            main_form.checkBox8.Text = ch8_textBox.Text;
            main_form.checkBox9.Text = ch9_textBox.Text;
            main_form.checkBox10.Text = ch10_textBox.Text;
            main_form.checkBox11.Text = ch11_textBox.Text;
            main_form.checkBox12.Text = ch12_textBox.Text;

            for (int i = 0; i < main_Form.channel_Num; i++)
            {
                main_Form.ch_Pen[i].Color = main_Form.checkBox_Arr[i].ForeColor;
            }
            main_form.draw_Scope(main_Form.X_MinNum, main_Form.X_Step, main_Form.Y_MinNum, main_Form.Y_Step);
            main_form.set_Back_timer.Start();
            this.Close();
        }

        private void vertical_checkBox_CheckedChanged(object sender, EventArgs e)
        {
            if (vertical_checkBox.Checked == true)
            {
                main_Form.vertical_checkBox = true;
            }
            else
            {
                main_Form.vertical_checkBox = false;
            }
        }

        private void Horizontal_checkBox_CheckedChanged(object sender, EventArgs e)
        {
            if (Horizontal_checkBox.Checked == true)
            {
                main_Form.Horizontal_checkBox = true;
            }
            else
            {
                main_Form.Horizontal_checkBox = false;
            }
        }


        /// <summary>
        /// 生成通信协议文件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_Click(object sender, EventArgs e)
        {
            if (my_folderBrowserDialog.ShowDialog() == DialogResult.OK)
            {
                string dest_Path = my_folderBrowserDialog.SelectedPath + "/NP_Communicate";
                try
                {
                    Directory.CreateDirectory(dest_Path);
                }
                catch(Exception  ex)
                {
                    if (ex.ToString().Contains("目录已存在"))
                    {
                        MessageBox.Show("目录已存在!!");
                    }
                    return;
                }
                try
                {
                    //File.Copy(@"/NP_Communicate/N_Poem.c", dest_Path + "/N_Poem.c", true);
                    //File.Copy(@"/NP_Communicate/N_Poem.h", dest_Path + "/N_Poem.h", true);
                    File.Copy(@"../../../NP_Communicate/N_Poem.c", dest_Path + "/N_Poem.c", true);
                    File.Copy(@"../../../NP_Communicate/N_Poem.h", dest_Path + "/N_Poem.h", true);
                }
                catch
                {
                    
                    MessageBox.Show("文件生成失败!!");
                    return;
                }


                MessageBox.Show("通信协议文件复制完毕!!");
            }
        }


        Point form_Position = new Point();
        Point mouse_Position = new Point();
        private void channel_Set_MouseDown(object sender, MouseEventArgs e)
        {
            form_Position = this.Location;
            mouse_Position = this.PointToScreen(e.Location);
        }

        private void channel_Set_MouseMove(object sender, MouseEventArgs e)
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

        private void textBox_MaxFrame_TextChanged(object sender, EventArgs e)
        {
            try
            {
                if (Convert.ToInt16(textBox_MaxFrame.Text) != 0)
                {
                    main_Form.max_Frame = Convert.ToInt16(textBox_MaxFrame.Text);
                }
            }
            catch
            {

            }


        }

    }
}
