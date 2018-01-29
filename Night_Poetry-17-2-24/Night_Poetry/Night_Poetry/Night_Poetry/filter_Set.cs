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
    public partial class filter_Set : Form
    {


        Button[] button_Arr = new Button[12];
        Color chose_Color = Color.LightSkyBlue;
        Color notChose_Color = Color.LightSlateGray;
        public filter_Set()
        {
            InitializeComponent();
        }
        private void filter_Set_Load(object sender, EventArgs e)
        {
            button_Arr[0] = ch1_button;
            button_Arr[1] = ch2_button;
            button_Arr[2] = ch3_button;
            button_Arr[3] = ch4_button;
            button_Arr[4] = ch5_button;
            button_Arr[5] = ch6_button;
            button_Arr[6] = ch7_button;
            button_Arr[7] = ch8_button;
            button_Arr[8] = ch9_button;
            button_Arr[9] = ch10_button;
            button_Arr[10] = ch11_button;
            button_Arr[11] = ch12_button;
            length_comboBox.SelectedIndex = 0;

            for (Byte i = 0; i < main_Form.channel_Num; i++)
            {
                this.button_Arr[i].Click += new System.EventHandler(this.ch_button_Click);
            }

            for (Byte i = 0; i < main_Form.filter_Ch.Count(); i++)
            {
                button_Arr[main_Form.filter_Ch[i] - 1].BackColor = chose_Color;
            }
        }
        private void ch_button_Click(object sender, EventArgs e)
        {
            Button temp_Button = sender as Button;
            if (temp_Button.BackColor == chose_Color)
            {
                temp_Button.BackColor = notChose_Color;
            }
            else
            {
                temp_Button.BackColor = chose_Color;
            }

        }
        private void button14_Click(object sender, EventArgs e)
        {
            main_Form main_form = (main_Form)this.Owner;
            main_Form .filter_Ch .Clear ();
            for (Byte i = 0; i < main_Form.channel_Num; i++)
            {
                if (button_Arr[i].BackColor == chose_Color)
                {
                    main_Form.filter_Ch.Add((Byte )(i+1));
                }
            }
                this.Close();
        }

        private void all_button_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < main_Form.channel_Num; i++)
            {
                button_Arr[i].BackColor = chose_Color;
            }
        }

        private void allClean_button_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < main_Form.channel_Num; i++)
            {
                button_Arr[i].BackColor = notChose_Color;
            }
        }
        Point form_Position = new Point();
        Point mouse_Position = new Point();
        private void filter_Set_MouseDown(object sender, MouseEventArgs e)
        {
            form_Position = this.Location;
            mouse_Position = this.PointToScreen (e.Location);
        }

        private void filter_Set_MouseMove(object sender, MouseEventArgs e)
        {
            Point move=new Point ();
            move.X = this.PointToScreen (e.Location).X - mouse_Position.X;
            move.Y = this.PointToScreen (e.Location).Y - mouse_Position.Y;
            
            if (e.Button == MouseButtons.Left || e.Button == MouseButtons.Right )
            {
                Point temp_Point = new Point();
                temp_Point.X = form_Position.X + move.X ;
                temp_Point.Y = form_Position.Y + move.Y;
                this.Location = temp_Point;
            }
        }
        private void ave_radioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (ave_radioButton.Checked == Enabled)
            {
                main_Form.filter_Style = "average";
            }
        }
        private void mid_radioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (mid_radioButton.Checked == Enabled)
            {
                main_Form.filter_Style = "middle";
            }
        }

        private void midAve_radioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (midAve_radioButton.Checked == Enabled)
            {
                main_Form.filter_Style = "mid_Ave";
            }
        }

        private void length_comboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            main_Form.smooth_Length = Convert .ToInt32 ( length_comboBox.SelectedItem .ToString ());
        }


    }
}
