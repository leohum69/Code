using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace i221749_Lab10
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SqlConnection conn = new SqlConnection("Data Source=.;Initial Catalog=Insta;Integrated Security=True;");
            conn.Open();
            SqlCommand cm;
            string un1 = textBox1.Text;
            string ps1 = textBox2.Text;


            string query = "SELECT COUNT(*) FROM [user] WHERE CONVERT(NVARCHAR(MAX), un) = @un AND CONVERT(NVARCHAR(MAX), ps) = @ps";
            cm = new SqlCommand(query, conn);

            // Use parameters to safely pass the values for un1 and ps1
            cm.Parameters.AddWithValue("@un", un1);
            cm.Parameters.AddWithValue("@ps", ps1);

            int count = (int)cm.ExecuteScalar();

            if (count > 0)
            {
                MessageBox.Show("User exists.");
            }
            else
            {
                MessageBox.Show("Invalid username or password.");
            }
            cm.Dispose();
            conn.Close();
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Form1 form1 = new Form1();
            form1.Show();

            // Hide the current form
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Environment.Exit(0);
        }
    }
}
