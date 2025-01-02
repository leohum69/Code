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
using Microsoft.IdentityModel.Tokens;
//using Microsoft.Data.SqlClient;

namespace DBLabProjectV2
{
    public partial class add_product : Form
    {
        SqlConnection con = new SqlConnection(@"Data Source=.;Initial Catalog=project;Integrated Security=True;");
        public add_product()
        {
            InitializeComponent();
        }

        private void add_product_Load(object sender, EventArgs e)
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
            fill_dd();
            fill_dg();
        }
        public void fill_dd()
        {
            comboBox1.Items.Clear();
            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select category_name from Category";
            cmd.ExecuteNonQuery();

            DataTable dt = new DataTable();
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            da.Fill(dt);
            foreach (DataRow dr in dt.Rows)
            {
                comboBox1.Items.Add(dr["category_name"].ToString());
            }
        }

        public void fill_dg()
        {
            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from product";
            cmd.ExecuteNonQuery();

            DataTable dt = new DataTable();
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            da.Fill(dt);
            dataGridView1.DataSource = dt;
        }



        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {




        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {

        }



        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }



        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(textBox1.Text))
            {
                MessageBox.Show("Please enter a product name.");
                return;
            }
            if (string.IsNullOrEmpty(textBox2.Text))
            {
                MessageBox.Show("Please enter a product Price.");
                return;
            }
            if (string.IsNullOrEmpty(textBox3.Text))
            {
                MessageBox.Show("Please enter a Unit Name.");
                return;
            }
            if (string.IsNullOrEmpty(textBox5.Text))
            {
                MessageBox.Show("Please enter a Amount.");
                return;
            }

            if (comboBox1.SelectedItem == null)
            {
                MessageBox.Show("Please select a Category.");
                return;
            }

            // Use parameterized query to prevent SQL injection
            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "SELECT * FROM Category WHERE category_name = @CategoryName";
            cmd.Parameters.AddWithValue("@CategoryName", comboBox1.SelectedItem.ToString());
            DataTable dt = new DataTable();
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            da.Fill(dt);
            int pew = Convert.ToInt32(dt.Rows[0][0]);
            cmd.CommandText = "insert into product values ('" + textBox1.Text + "','" + textBox2.Text + "','" + textBox3.Text + "','" + textBox4.Text + "'," + pew + ");SELECT SCOPE_IDENTITY();";
            object resev = cmd.ExecuteScalar();
            int ProductID = Convert.ToInt32(resev);

            cmd.CommandText = "insert into Stock values (" + ProductID +","+ textBox5.Text +")";

            cmd.ExecuteNonQuery();

            // Clear the input fields
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
            textBox5.Text = "";
            comboBox1.SelectedItem = null;
            fill_dg();

            MessageBox.Show("Record added successfully.");

            // Refresh the data grid
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            try
            {
                int id = Convert.ToInt32(dataGridView1.SelectedCells[0].Value.ToString());
                SqlCommand cmd = con.CreateCommand();
                //MessageBox.Show(id);
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "delete from Product where ProductID = " + id + ";";
                cmd.ExecuteNonQuery();
                fill_dg();
                MessageBox.Show("Deleted " + id + " Successfully.");
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred Deleting The dealer cuz a purchase is being done by this category.: " + ex.Message, "category Delete Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}

