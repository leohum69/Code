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
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace DBLabProjectV2
{
    public partial class add_dealer : Form
    {
        SqlConnection con = new SqlConnection(@"Data Source=.;Initial Catalog=project;Integrated Security=True;");
        public add_dealer()
        {
            InitializeComponent();
        }

        private void add_dealer_Load(object sender, EventArgs e)
        {
            try
            {
                if (con.State == ConnectionState.Open)
                {
                    con.Close();
                }
                con.Open();
                display();
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred while connecting to the database: " + ex.Message, "Connection Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from dealer where d_name ='" + textBox1.Text + "' and d_company = '" + textBox2.Text + "'";
            cmd.ExecuteNonQuery();

            DataTable dt = new DataTable();
            SqlDataAdapter adap = new SqlDataAdapter(cmd);
            adap.Fill(dt);
            int i = dt.Rows.Count;
            if (i > 0)
            {
                MessageBox.Show("Dealer already exists, Please use another.");
            }
            else
            {
                MessageBox.Show("Dealer added successfully.");

                SqlCommand cmd1 = con.CreateCommand();
                cmd1.CommandType = CommandType.Text;

                cmd1.CommandText = "INSERT INTO dealer VALUES ('" + textBox1.Text + "', '" + textBox2.Text + "', '" + textBox3.Text + "','" + textBox4.Text + "','" + textBox5.Text + "')";

                cmd1.ExecuteNonQuery();
                display();
                MessageBox.Show("Dealer record inserted successfully.");

                textBox1.Text = "";
                textBox2.Text = "";
                textBox3.Text = "";
                textBox4.Text = "";
                textBox5.Text = "";
            }
        }
        private void display()
        {
            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from Dealer";
            cmd.ExecuteNonQuery();

            DataTable dt = new DataTable();
            SqlDataAdapter adap = new SqlDataAdapter(cmd);
            adap.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                int id = Convert.ToInt32(dataGridView1.SelectedCells[0].Value.ToString());
                SqlCommand cmd = con.CreateCommand();
                //MessageBox.Show(id);
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "delete from dealer where Dealerid = " + id + ";";
                cmd.ExecuteNonQuery();
                display();
                MessageBox.Show("Deleted " + id + " Successfully.");
            }
            catch(Exception ex)
            {
                MessageBox.Show("An error occurred Deleting The dealer cuz a purchase is being done by this dealer.: " + ex.Message,"Dealer Delete Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from dealer where d_name ='" + textBox1.Text + "' and d_company = '" + textBox2.Text + "'";
            cmd.ExecuteNonQuery();

            DataTable dt = new DataTable();
            SqlDataAdapter adap = new SqlDataAdapter(cmd);
            adap.Fill(dt);
            int i = dt.Rows.Count;
            if (i > 0)
            {
                int id = Convert.ToInt32(dataGridView1.SelectedCells[0].Value.ToString());


                SqlCommand cmd2 = con.CreateCommand();
                cmd2.CommandType = CommandType.Text;
                cmd2.CommandText = "UPDATE dealer SET d_name = '" + textBox1.Text + "', d_company = '" + textBox2.Text + "', d_contact = '" + textBox3.Text + "', d_address = '" + textBox4.Text + "', d_city = '" + textBox5.Text + "' WHERE Dealerid = " + id;

                cmd2.ExecuteNonQuery();

                display();
                MessageBox.Show("Dealer record updated successfully.");

                textBox1.Text = "";
                textBox2.Text = "";
                textBox3.Text = "";
                textBox4.Text = "";
                textBox5.Text = "";
            }
            else
            {
                MessageBox.Show("Dealer doesn't exist, Please use another.");

            }
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            button3.Visible = true;
        }

        private void dataGridView1_RowEnter(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView1_Leave(object sender, EventArgs e)
        {
            button3.Visible = false;
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }

}
