namespace Night_Poetry
{
    partial class filter_Set
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.filter_groupBox = new System.Windows.Forms.GroupBox();
            this.midAve_radioButton = new System.Windows.Forms.RadioButton();
            this.mid_radioButton = new System.Windows.Forms.RadioButton();
            this.ave_radioButton = new System.Windows.Forms.RadioButton();
            this.ch_groupBox = new System.Windows.Forms.GroupBox();
            this.allClean_button = new System.Windows.Forms.Button();
            this.all_button = new System.Windows.Forms.Button();
            this.ch2_button = new System.Windows.Forms.Button();
            this.ch3_button = new System.Windows.Forms.Button();
            this.ch12_button = new System.Windows.Forms.Button();
            this.ch4_button = new System.Windows.Forms.Button();
            this.ch7_button = new System.Windows.Forms.Button();
            this.ch11_button = new System.Windows.Forms.Button();
            this.ch10_button = new System.Windows.Forms.Button();
            this.ch6_button = new System.Windows.Forms.Button();
            this.ch9_button = new System.Windows.Forms.Button();
            this.ch8_button = new System.Windows.Forms.Button();
            this.ch5_button = new System.Windows.Forms.Button();
            this.ch1_button = new System.Windows.Forms.Button();
            this.length_groupBox = new System.Windows.Forms.GroupBox();
            this.length_comboBox = new System.Windows.Forms.ComboBox();
            this.OK_button = new System.Windows.Forms.Button();
            this.filter_groupBox.SuspendLayout();
            this.ch_groupBox.SuspendLayout();
            this.length_groupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // filter_groupBox
            // 
            this.filter_groupBox.BackColor = System.Drawing.Color.Silver;
            this.filter_groupBox.Controls.Add(this.midAve_radioButton);
            this.filter_groupBox.Controls.Add(this.mid_radioButton);
            this.filter_groupBox.Controls.Add(this.ave_radioButton);
            this.filter_groupBox.Font = new System.Drawing.Font("华文行楷", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.filter_groupBox.Location = new System.Drawing.Point(13, 13);
            this.filter_groupBox.Name = "filter_groupBox";
            this.filter_groupBox.Size = new System.Drawing.Size(135, 130);
            this.filter_groupBox.TabIndex = 0;
            this.filter_groupBox.TabStop = false;
            this.filter_groupBox.Text = "滑动滤波器";
            // 
            // midAve_radioButton
            // 
            this.midAve_radioButton.AutoSize = true;
            this.midAve_radioButton.Location = new System.Drawing.Point(0, 91);
            this.midAve_radioButton.Name = "midAve_radioButton";
            this.midAve_radioButton.Size = new System.Drawing.Size(138, 21);
            this.midAve_radioButton.TabIndex = 2;
            this.midAve_radioButton.TabStop = true;
            this.midAve_radioButton.Text = "中位值平均滤波";
            this.midAve_radioButton.UseVisualStyleBackColor = true;
            this.midAve_radioButton.CheckedChanged += new System.EventHandler(this.midAve_radioButton_CheckedChanged);
            // 
            // mid_radioButton
            // 
            this.mid_radioButton.AutoSize = true;
            this.mid_radioButton.Location = new System.Drawing.Point(0, 60);
            this.mid_radioButton.Name = "mid_radioButton";
            this.mid_radioButton.Size = new System.Drawing.Size(90, 21);
            this.mid_radioButton.TabIndex = 1;
            this.mid_radioButton.TabStop = true;
            this.mid_radioButton.Text = "中值滤波";
            this.mid_radioButton.UseVisualStyleBackColor = true;
            this.mid_radioButton.CheckedChanged += new System.EventHandler(this.mid_radioButton_CheckedChanged);
            // 
            // ave_radioButton
            // 
            this.ave_radioButton.AutoSize = true;
            this.ave_radioButton.Location = new System.Drawing.Point(0, 29);
            this.ave_radioButton.Name = "ave_radioButton";
            this.ave_radioButton.Size = new System.Drawing.Size(90, 21);
            this.ave_radioButton.TabIndex = 0;
            this.ave_radioButton.TabStop = true;
            this.ave_radioButton.Text = "均值滤波";
            this.ave_radioButton.UseVisualStyleBackColor = true;
            this.ave_radioButton.CheckedChanged += new System.EventHandler(this.ave_radioButton_CheckedChanged);
            // 
            // ch_groupBox
            // 
            this.ch_groupBox.BackColor = System.Drawing.Color.Silver;
            this.ch_groupBox.Controls.Add(this.allClean_button);
            this.ch_groupBox.Controls.Add(this.all_button);
            this.ch_groupBox.Controls.Add(this.ch2_button);
            this.ch_groupBox.Controls.Add(this.ch3_button);
            this.ch_groupBox.Controls.Add(this.ch12_button);
            this.ch_groupBox.Controls.Add(this.ch4_button);
            this.ch_groupBox.Controls.Add(this.ch7_button);
            this.ch_groupBox.Controls.Add(this.ch11_button);
            this.ch_groupBox.Controls.Add(this.ch10_button);
            this.ch_groupBox.Controls.Add(this.ch6_button);
            this.ch_groupBox.Controls.Add(this.ch9_button);
            this.ch_groupBox.Controls.Add(this.ch8_button);
            this.ch_groupBox.Controls.Add(this.ch5_button);
            this.ch_groupBox.Controls.Add(this.ch1_button);
            this.ch_groupBox.Font = new System.Drawing.Font("华文行楷", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ch_groupBox.Location = new System.Drawing.Point(157, 13);
            this.ch_groupBox.Name = "ch_groupBox";
            this.ch_groupBox.Size = new System.Drawing.Size(167, 248);
            this.ch_groupBox.TabIndex = 1;
            this.ch_groupBox.TabStop = false;
            this.ch_groupBox.Text = "滤波通道";
            // 
            // allClean_button
            // 
            this.allClean_button.BackColor = System.Drawing.Color.LightSlateGray;
            this.allClean_button.Location = new System.Drawing.Point(82, 206);
            this.allClean_button.Name = "allClean_button";
            this.allClean_button.Size = new System.Drawing.Size(70, 23);
            this.allClean_button.TabIndex = 13;
            this.allClean_button.Text = "全不选";
            this.allClean_button.UseVisualStyleBackColor = false;
            this.allClean_button.Click += new System.EventHandler(this.allClean_button_Click);
            // 
            // all_button
            // 
            this.all_button.BackColor = System.Drawing.Color.LightSkyBlue;
            this.all_button.Location = new System.Drawing.Point(20, 206);
            this.all_button.Name = "all_button";
            this.all_button.Size = new System.Drawing.Size(65, 23);
            this.all_button.TabIndex = 12;
            this.all_button.Text = "全选";
            this.all_button.UseVisualStyleBackColor = false;
            this.all_button.Click += new System.EventHandler(this.all_button_Click);
            // 
            // ch2_button
            // 
            this.ch2_button.BackColor = System.Drawing.Color.LightSlateGray;
            this.ch2_button.Location = new System.Drawing.Point(66, 21);
            this.ch2_button.Name = "ch2_button";
            this.ch2_button.Size = new System.Drawing.Size(40, 40);
            this.ch2_button.TabIndex = 11;
            this.ch2_button.Text = "2";
            this.ch2_button.UseVisualStyleBackColor = false;
            // 
            // ch3_button
            // 
            this.ch3_button.BackColor = System.Drawing.Color.LightSlateGray;
            this.ch3_button.Location = new System.Drawing.Point(112, 21);
            this.ch3_button.Name = "ch3_button";
            this.ch3_button.Size = new System.Drawing.Size(40, 40);
            this.ch3_button.TabIndex = 10;
            this.ch3_button.Text = "3";
            this.ch3_button.UseVisualStyleBackColor = false;
            // 
            // ch12_button
            // 
            this.ch12_button.BackColor = System.Drawing.Color.LightSlateGray;
            this.ch12_button.Location = new System.Drawing.Point(112, 159);
            this.ch12_button.Name = "ch12_button";
            this.ch12_button.Size = new System.Drawing.Size(40, 40);
            this.ch12_button.TabIndex = 9;
            this.ch12_button.Text = "12";
            this.ch12_button.UseVisualStyleBackColor = false;
            // 
            // ch4_button
            // 
            this.ch4_button.BackColor = System.Drawing.Color.LightSlateGray;
            this.ch4_button.Location = new System.Drawing.Point(20, 67);
            this.ch4_button.Name = "ch4_button";
            this.ch4_button.Size = new System.Drawing.Size(40, 40);
            this.ch4_button.TabIndex = 8;
            this.ch4_button.Text = "4";
            this.ch4_button.UseVisualStyleBackColor = false;
            // 
            // ch7_button
            // 
            this.ch7_button.BackColor = System.Drawing.Color.LightSlateGray;
            this.ch7_button.Location = new System.Drawing.Point(20, 113);
            this.ch7_button.Name = "ch7_button";
            this.ch7_button.Size = new System.Drawing.Size(40, 40);
            this.ch7_button.TabIndex = 7;
            this.ch7_button.Text = "7";
            this.ch7_button.UseVisualStyleBackColor = false;
            // 
            // ch11_button
            // 
            this.ch11_button.BackColor = System.Drawing.Color.LightSlateGray;
            this.ch11_button.Location = new System.Drawing.Point(66, 159);
            this.ch11_button.Name = "ch11_button";
            this.ch11_button.Size = new System.Drawing.Size(40, 40);
            this.ch11_button.TabIndex = 6;
            this.ch11_button.Text = "11";
            this.ch11_button.UseVisualStyleBackColor = false;
            // 
            // ch10_button
            // 
            this.ch10_button.BackColor = System.Drawing.Color.LightSlateGray;
            this.ch10_button.Location = new System.Drawing.Point(20, 159);
            this.ch10_button.Name = "ch10_button";
            this.ch10_button.Size = new System.Drawing.Size(40, 40);
            this.ch10_button.TabIndex = 5;
            this.ch10_button.Text = "10";
            this.ch10_button.UseVisualStyleBackColor = false;
            // 
            // ch6_button
            // 
            this.ch6_button.BackColor = System.Drawing.Color.LightSlateGray;
            this.ch6_button.Location = new System.Drawing.Point(112, 67);
            this.ch6_button.Name = "ch6_button";
            this.ch6_button.Size = new System.Drawing.Size(40, 40);
            this.ch6_button.TabIndex = 4;
            this.ch6_button.Text = "6";
            this.ch6_button.UseVisualStyleBackColor = false;
            // 
            // ch9_button
            // 
            this.ch9_button.BackColor = System.Drawing.Color.LightSlateGray;
            this.ch9_button.Location = new System.Drawing.Point(112, 113);
            this.ch9_button.Name = "ch9_button";
            this.ch9_button.Size = new System.Drawing.Size(40, 40);
            this.ch9_button.TabIndex = 3;
            this.ch9_button.Text = "9";
            this.ch9_button.UseVisualStyleBackColor = false;
            // 
            // ch8_button
            // 
            this.ch8_button.BackColor = System.Drawing.Color.LightSlateGray;
            this.ch8_button.Location = new System.Drawing.Point(66, 113);
            this.ch8_button.Name = "ch8_button";
            this.ch8_button.Size = new System.Drawing.Size(40, 40);
            this.ch8_button.TabIndex = 2;
            this.ch8_button.Text = "8";
            this.ch8_button.UseVisualStyleBackColor = false;
            // 
            // ch5_button
            // 
            this.ch5_button.BackColor = System.Drawing.Color.LightSlateGray;
            this.ch5_button.Location = new System.Drawing.Point(66, 67);
            this.ch5_button.Name = "ch5_button";
            this.ch5_button.Size = new System.Drawing.Size(40, 40);
            this.ch5_button.TabIndex = 1;
            this.ch5_button.Text = "5";
            this.ch5_button.UseVisualStyleBackColor = false;
            // 
            // ch1_button
            // 
            this.ch1_button.BackColor = System.Drawing.Color.LightSlateGray;
            this.ch1_button.Location = new System.Drawing.Point(20, 21);
            this.ch1_button.Name = "ch1_button";
            this.ch1_button.Size = new System.Drawing.Size(40, 40);
            this.ch1_button.TabIndex = 0;
            this.ch1_button.Text = "1";
            this.ch1_button.UseVisualStyleBackColor = false;
            // 
            // length_groupBox
            // 
            this.length_groupBox.BackColor = System.Drawing.Color.Silver;
            this.length_groupBox.Controls.Add(this.length_comboBox);
            this.length_groupBox.Font = new System.Drawing.Font("华文行楷", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.length_groupBox.Location = new System.Drawing.Point(13, 149);
            this.length_groupBox.Name = "length_groupBox";
            this.length_groupBox.Size = new System.Drawing.Size(135, 47);
            this.length_groupBox.TabIndex = 2;
            this.length_groupBox.TabStop = false;
            this.length_groupBox.Text = "模板长度";
            // 
            // length_comboBox
            // 
            this.length_comboBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.length_comboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.length_comboBox.FormattingEnabled = true;
            this.length_comboBox.Items.AddRange(new object[] {
            "3",
            "5",
            "7",
            "9",
            "11",
            "13"});
            this.length_comboBox.Location = new System.Drawing.Point(3, 21);
            this.length_comboBox.Name = "length_comboBox";
            this.length_comboBox.Size = new System.Drawing.Size(129, 25);
            this.length_comboBox.TabIndex = 0;
            this.length_comboBox.SelectedIndexChanged += new System.EventHandler(this.length_comboBox_SelectedIndexChanged);
            // 
            // OK_button
            // 
            this.OK_button.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.OK_button.FlatAppearance.BorderSize = 0;
            this.OK_button.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
            this.OK_button.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent;
            this.OK_button.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.OK_button.Font = new System.Drawing.Font("华文行楷", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.OK_button.Location = new System.Drawing.Point(115, 284);
            this.OK_button.Name = "OK_button";
            this.OK_button.Size = new System.Drawing.Size(75, 36);
            this.OK_button.TabIndex = 3;
            this.OK_button.Text = "确定";
            this.OK_button.UseVisualStyleBackColor = false;
            this.OK_button.Click += new System.EventHandler(this.button14_Click);
            // 
            // filter_Set
            // 
            this.AcceptButton = this.OK_button;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.ClientSize = new System.Drawing.Size(327, 332);
            this.Controls.Add(this.OK_button);
            this.Controls.Add(this.length_groupBox);
            this.Controls.Add(this.ch_groupBox);
            this.Controls.Add(this.filter_groupBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "filter_Set";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "filter_Set";
            this.Load += new System.EventHandler(this.filter_Set_Load);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.filter_Set_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.filter_Set_MouseMove);
            this.filter_groupBox.ResumeLayout(false);
            this.filter_groupBox.PerformLayout();
            this.ch_groupBox.ResumeLayout(false);
            this.length_groupBox.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox filter_groupBox;
        private System.Windows.Forms.RadioButton midAve_radioButton;
        private System.Windows.Forms.RadioButton mid_radioButton;
        private System.Windows.Forms.RadioButton ave_radioButton;
        private System.Windows.Forms.GroupBox ch_groupBox;
        private System.Windows.Forms.Button allClean_button;
        private System.Windows.Forms.Button all_button;
        private System.Windows.Forms.Button ch2_button;
        private System.Windows.Forms.Button ch3_button;
        private System.Windows.Forms.Button ch12_button;
        private System.Windows.Forms.Button ch4_button;
        private System.Windows.Forms.Button ch7_button;
        private System.Windows.Forms.Button ch11_button;
        private System.Windows.Forms.Button ch10_button;
        private System.Windows.Forms.Button ch6_button;
        private System.Windows.Forms.Button ch9_button;
        private System.Windows.Forms.Button ch8_button;
        private System.Windows.Forms.Button ch5_button;
        private System.Windows.Forms.Button ch1_button;
        private System.Windows.Forms.GroupBox length_groupBox;
        private System.Windows.Forms.ComboBox length_comboBox;
        private System.Windows.Forms.Button OK_button;
    }
}