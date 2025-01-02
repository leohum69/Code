namespace DBLabProjectV2
{
    partial class view_stock
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
            label3 = new Label();
            textBox2 = new TextBox();
            label1 = new Label();
            label2 = new Label();
            button1 = new Button();
            panel1 = new Panel();
            ((System.ComponentModel.ISupportInitialize)dataGridView1).BeginInit();
            panel1.SuspendLayout();
            SuspendLayout();
            // 
            // dataGridView1
            // 
            dataGridView1.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView1.Location = new Point(622, 105);
            dataGridView1.Name = "dataGridView1";
            dataGridView1.RowHeadersWidth = 51;
            dataGridView1.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            dataGridView1.Size = new Size(486, 441);
            dataGridView1.TabIndex = 0;
            dataGridView1.CellClick += dataGridView1_CellClick;
            dataGridView1.CellContentClick += dataGridView1_CellContentClick;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.BackColor = Color.Transparent;
            label3.Font = new Font("Comic Sans MS", 35F, FontStyle.Bold);
            label3.ForeColor = Color.Black;
            label3.Location = new Point(423, 9);
            label3.Name = "label3";
            label3.Size = new Size(226, 82);
            label3.TabIndex = 8;
            label3.Text = "Stocks";
            // 
            // textBox2
            // 
            textBox2.Location = new Point(242, 141);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(211, 27);
            textBox2.TabIndex = 22;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            label1.Location = new Point(44, 141);
            label1.Name = "label1";
            label1.Size = new Size(97, 29);
            label1.TabIndex = 21;
            label1.Text = "Quantity";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            label2.Location = new Point(157, 86);
            label2.Name = "label2";
            label2.Size = new Size(149, 29);
            label2.TabIndex = 20;
            label2.Text = "Product Name";
            // 
            // button1
            // 
            button1.Font = new Font("Comic Sans MS", 12F, FontStyle.Bold);
            button1.Location = new Point(122, 320);
            button1.Name = "button1";
            button1.Size = new Size(219, 57);
            button1.TabIndex = 23;
            button1.Text = "Update Stock";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click_1;
            // 
            // panel1
            // 
            panel1.Controls.Add(button1);
            panel1.Controls.Add(textBox2);
            panel1.Controls.Add(label1);
            panel1.Controls.Add(label2);
            panel1.Location = new Point(42, 105);
            panel1.Name = "panel1";
            panel1.Size = new Size(528, 441);
            panel1.TabIndex = 24;
            panel1.Visible = false;
            // 
            // view_stock
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1155, 577);
            Controls.Add(panel1);
            Controls.Add(label3);
            Controls.Add(dataGridView1);
            Name = "view_stock";
            Text = "view_stock";
            Load += view_stock_Load;
            ((System.ComponentModel.ISupportInitialize)dataGridView1).EndInit();
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private DataGridView dataGridView1;
        private Label label3;
        private TextBox textBox2;
        private Label label1;
        private Label label2;
        private Button button1;
        private Panel panel1;
    }
}