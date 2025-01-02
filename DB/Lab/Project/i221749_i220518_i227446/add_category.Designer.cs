namespace DBLabProjectV2
{
    partial class add_category
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
            dataGridView1 = new DataGridView();
            panel1 = new Panel();
            textBox2 = new TextBox();
            label2 = new Label();
            button2 = new Button();
            button1 = new Button();
            label1 = new Label();
            textBox1 = new TextBox();
            label3 = new Label();
            ((System.ComponentModel.ISupportInitialize)dataGridView1).BeginInit();
            panel1.SuspendLayout();
            SuspendLayout();
            // 
            // dataGridView1
            // 
            dataGridView1.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView1.Location = new Point(629, 114);
            dataGridView1.Name = "dataGridView1";
            dataGridView1.RowHeadersWidth = 51;
            dataGridView1.Size = new Size(460, 390);
            dataGridView1.TabIndex = 18;
            // 
            // panel1
            // 
            panel1.Controls.Add(textBox2);
            panel1.Controls.Add(label2);
            panel1.Controls.Add(button2);
            panel1.Controls.Add(button1);
            panel1.Controls.Add(label1);
            panel1.Controls.Add(textBox1);
            panel1.Location = new Point(35, 61);
            panel1.Name = "panel1";
            panel1.Size = new Size(479, 443);
            panel1.TabIndex = 19;
            // 
            // textBox2
            // 
            textBox2.Location = new Point(22, 199);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(435, 27);
            textBox2.TabIndex = 20;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            label2.Location = new Point(122, 137);
            label2.Name = "label2";
            label2.Size = new Size(216, 29);
            label2.TabIndex = 19;
            label2.Text = "Category Description";
            // 
            // button2
            // 
            button2.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            button2.Location = new Point(69, 348);
            button2.Name = "button2";
            button2.Size = new Size(331, 44);
            button2.TabIndex = 18;
            button2.Text = "Delete Selected Category";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // button1
            // 
            button1.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            button1.Location = new Point(123, 264);
            button1.Name = "button1";
            button1.Size = new Size(191, 44);
            button1.TabIndex = 13;
            button1.Text = "Add Category";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            label1.Location = new Point(152, 38);
            label1.Name = "label1";
            label1.Size = new Size(162, 29);
            label1.TabIndex = 1;
            label1.Text = "Category Name";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(84, 86);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(300, 27);
            textBox1.TabIndex = 1;
            textBox1.TextChanged += textBox1_TextChanged;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Comic Sans MS", 16.2F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label3.Location = new Point(784, 61);
            label3.Name = "label3";
            label3.Size = new Size(160, 39);
            label3.TabIndex = 21;
            label3.Text = "Categories";
            // 
            // add_category
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1134, 548);
            Controls.Add(label3);
            Controls.Add(panel1);
            Controls.Add(dataGridView1);
            Name = "add_category";
            Text = "Form1";
            Load += add_category_Load;
            ((System.ComponentModel.ISupportInitialize)dataGridView1).EndInit();
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private DataGridView dataGridView1;
        private Panel panel1;
        private TextBox textBox2;
        private Label label2;
        private Button button2;
        private Button button1;
        private Label label1;
        private TextBox textBox1;
        private Label label3;
    }
}