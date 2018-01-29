using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Night_Poetry
{
    public partial class debug_Ch_Set : Form
    {

        TextBox[] textBox_Arr = new TextBox[12];
        public debug_Ch_Set()
        {
            InitializeComponent();
            textBox_Arr[0] = ch1_textBox;
            textBox_Arr[1] = ch2_textBox;
            textBox_Arr[2] = ch3_textBox;
            textBox_Arr[3] = ch4_textBox;
            textBox_Arr[4] = ch5_textBox;
            textBox_Arr[5] = ch6_textBox;
            textBox_Arr[6] = ch7_textBox;
            textBox_Arr[7] = ch8_textBox;
            textBox_Arr[8] = ch9_textBox;
            textBox_Arr[9] = ch10_textBox;
            textBox_Arr[10] = ch11_textBox;
            textBox_Arr[11] = ch12_textBox;

            checkBox1.Checked  = main_Form.stepTo_send; 

        }

        private void debug_Ch_Set_Load(object sender, EventArgs e)
        {
            main_Form main_form = (main_Form)this.Owner;
            for (int i=0; i < 12; i++)
            {
                textBox_Arr[i].Text = main_Form.label_Arr[i].Text ;
            }

        }



        Point form_Position = new Point();
        Point mouse_Position = new Point();
        private void debug_Ch_Set_MouseDown(object sender, MouseEventArgs e)
        {
            form_Position = this.Location;
            mouse_Position = this.PointToScreen(e.Location);
        }
        private void debug_Ch_Set_MouseMove(object sender, MouseEventArgs e)
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


        private void ok_button_Click(object sender, EventArgs e)
        {
            main_Form main_form=(main_Form ) this .Owner;
            for (int i = 0; i < 12; i++)
            {
                main_Form.label_Arr[i].Text = textBox_Arr[i].Text;
            }
            this.Close();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked == Enabled)
            {
                main_Form.stepTo_send = true;
            }
            else
            {
                main_Form.stepTo_send = false;
            }
        }
    }
}
