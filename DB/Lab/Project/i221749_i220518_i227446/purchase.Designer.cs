namespace DBLabProjectV2
{
    partial class purchase
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
            button1 = new Button();
            label6 = new Label();
            label5 = new Label();
            label4 = new Label();
            label3 = new Label();
            label2 = new Label();
            label7 = new Label();
            textBox3 = new TextBox();
            textBox4 = new TextBox();
            textBox7 = new TextBox();
            label9 = new Label();
            label10 = new Label();
            label12 = new Label();
            textBox8 = new TextBox();
            dateTimePicker1 = new DateTimePicker();
            dateTimePicker2 = new DateTimePicker();
            comboBox1 = new ComboBox();
            comboBox2 = new ComboBox();
            comboBox3 = new ComboBox();
            label1 = new Label();
            label8 = new Label();
            textBox1 = new TextBox();
            SuspendLayout();
            // 
            // button1
            // 
            button1.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            button1.Location = new Point(66, 268);
            button1.Name = "button1";
            button1.Size = new Size(191, 44);
            button1.TabIndex = 26;
            button1.Text = "Purchase";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            label6.Location = new Point(546, 111);
            label6.Name = "label6";
            label6.Size = new Size(152, 29);
            label6.TabIndex = 25;
            label6.Text = "Purchase Date";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            label5.Location = new Point(66, 157);
            label5.Name = "label5";
            label5.Size = new Size(145, 29);
            label5.TabIndex = 24;
            label5.Text = "Product Total";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            label4.Location = new Point(546, 67);
            label4.Name = "label4";
            label4.Size = new Size(154, 29);
            label4.TabIndex = 23;
            label4.Text = "Purchase Type";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            label3.Location = new Point(546, 23);
            label3.Name = "label3";
            label3.Size = new Size(138, 29);
            label3.TabIndex = 22;
            label3.Text = "Dealer Name";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            label2.Location = new Point(66, 68);
            label2.Name = "label2";
            label2.Size = new Size(179, 29);
            label2.TabIndex = 21;
            label2.Text = "Product Quantity";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            label7.Location = new Point(66, 25);
            label7.Name = "label7";
            label7.Size = new Size(149, 29);
            label7.TabIndex = 14;
            label7.Text = "Product Name";
            // 
            // textBox3
            // 
            textBox3.Location = new Point(250, 72);
            textBox3.Name = "textBox3";
            textBox3.Size = new Size(203, 27);
            textBox3.TabIndex = 16;
            // 
            // textBox4
            // 
            textBox4.Location = new Point(250, 115);
            textBox4.Name = "textBox4";
            textBox4.Size = new Size(270, 27);
            textBox4.TabIndex = 17;
            textBox4.TextChanged += textBox4_TextChanged;
            textBox4.Leave += textBox4_Leave;
            // 
            // textBox7
            // 
            textBox7.Location = new Point(250, 159);
            textBox7.Name = "textBox7";
            textBox7.Size = new Size(270, 27);
            textBox7.TabIndex = 19;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            label9.Location = new Point(546, 155);
            label9.Name = "label9";
            label9.Size = new Size(129, 29);
            label9.TabIndex = 36;
            label9.Text = "Expiry Date";
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            label10.Location = new Point(66, 109);
            label10.Name = "label10";
            label10.Size = new Size(143, 29);
            label10.TabIndex = 35;
            label10.Text = "Product Price";
            // 
            // label12
            // 
            label12.AutoSize = true;
            label12.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            label12.Location = new Point(66, 195);
            label12.Name = "label12";
            label12.Size = new Size(95, 29);
            label12.TabIndex = 27;
            label12.Text = "Profit %";
            // 
            // textBox8
            // 
            textBox8.Location = new Point(250, 199);
            textBox8.Name = "textBox8";
            textBox8.Size = new Size(270, 27);
            textBox8.TabIndex = 28;
            // 
            // dateTimePicker1
            // 
            dateTimePicker1.Location = new Point(730, 113);
            dateTimePicker1.Name = "dateTimePicker1";
            dateTimePicker1.Size = new Size(270, 27);
            dateTimePicker1.TabIndex = 37;
            dateTimePicker1.ValueChanged += dateTimePicker1_ValueChanged;
            // 
            // dateTimePicker2
            // 
            dateTimePicker2.Location = new Point(730, 155);
            dateTimePicker2.Name = "dateTimePicker2";
            dateTimePicker2.Size = new Size(270, 27);
            dateTimePicker2.TabIndex = 38;
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Location = new Point(250, 29);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(270, 28);
            comboBox1.TabIndex = 39;
            comboBox1.SelectedIndexChanged += comboBox1_SelectedIndexChanged;
            // 
            // comboBox2
            // 
            comboBox2.FormattingEnabled = true;
            comboBox2.Location = new Point(730, 29);
            comboBox2.Name = "comboBox2";
            comboBox2.Size = new Size(270, 28);
            comboBox2.TabIndex = 40;
            // 
            // comboBox3
            // 
            comboBox3.FormattingEnabled = true;
            comboBox3.Items.AddRange(new object[] { "Cash", "Debit", "Credit", "Gpay" });
            comboBox3.Location = new Point(730, 72);
            comboBox3.Name = "comboBox3";
            comboBox3.Size = new Size(270, 28);
            comboBox3.TabIndex = 41;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            label1.Location = new Point(459, 70);
            label1.Name = "label1";
            label1.Size = new Size(53, 29);
            label1.TabIndex = 42;
            label1.Text = "Unit";
            label1.Click += label1_Click;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            label8.Location = new Point(546, 195);
            label8.Name = "label8";
            label8.Size = new Size(165, 29);
            label8.TabIndex = 43;
            label8.Text = "Customer Name";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(730, 199);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(270, 27);
            textBox1.TabIndex = 44;
            // 
            // purchase
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ActiveCaption;
            ClientSize = new Size(1385, 575);
            Controls.Add(label8);
            Controls.Add(textBox1);
            Controls.Add(label1);
            Controls.Add(comboBox3);
            Controls.Add(comboBox2);
            Controls.Add(comboBox1);
            Controls.Add(dateTimePicker2);
            Controls.Add(dateTimePicker1);
            Controls.Add(label9);
            Controls.Add(label10);
            Controls.Add(label12);
            Controls.Add(textBox8);
            Controls.Add(button1);
            Controls.Add(label6);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label7);
            Controls.Add(textBox3);
            Controls.Add(textBox4);
            Controls.Add(textBox7);
            Name = "purchase";
            Text = "purchase";
            Load += purchase_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button button1;
        private Label label6;
        private Label label5;
        private Label label4;
        private Label label3;
        private Label label2;
        private Label label7;
        private TextBox textBox3;
        private TextBox textBox4;
        private TextBox textBox7;
        private Label label9;
        private Label label10;
        private Label label12;
        private TextBox textBox8;
        private DateTimePicker dateTimePicker1;
        private DateTimePicker dateTimePicker2;
        private ComboBox comboBox1;
        private ComboBox comboBox2;
        private ComboBox comboBox3;
        private Label label1;
        private Label label8;
        private TextBox textBox1;
    }
}