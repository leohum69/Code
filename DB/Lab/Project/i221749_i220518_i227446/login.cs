using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
namespace DBLabProjectV2
{
    public partial class login : Form
    {
        SqlConnection con = new SqlConnection(@"Data Source=.;Initial Catalog=project;Integrated Security=True;");
        bool adm = false;
        public login()
        {
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (adm)
            {
                if(textBox2.Text == "admin" && textBox3.Text == "admin")
                {
                    this.Hide();
                    MDIParent1 mdi = new MDIParent1();
                    mdi.Show();
                }
                else
                {
                    MessageBox.Show("Login Failed, Username or Password not found.");
                    textBox2.Text = "";
                    textBox3.Text = "";
                }
                
            }
            else
            {
                int i = 0;
                SqlCommand cmd = con.CreateCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "select * from users where username='" + textBox2.Text + "' and password= '" + textBox3.Text + "'";

                cmd.ExecuteNonQuery();
                DataTable dt = new DataTable();
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                da.Fill(dt);
                i = dt.Rows.Count;

                if (i == 0)
                {
                    MessageBox.Show("Login Failed, Username or Password not found.");
                    textBox2.Text = "";
                    textBox3.Text = "";
                }
                else
                {
                    this.Hide();
                    MDIParent2 mdi = new MDIParent2();
                    mdi.Show();
                }
            }




        }

        private void login_Load(object sender, EventArgs e)
        {
            try
            {
                if (con.State == ConnectionState.Open)
                {
                    con.Close();
                }
                con.Open();
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred while connecting to the database: " + ex.Message, "Connection Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            adm = true;
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            adm = false;
        }
    }
}
