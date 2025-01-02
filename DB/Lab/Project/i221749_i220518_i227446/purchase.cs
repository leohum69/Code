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
    public partial class purchase : Form
    {
        SqlConnection con = new SqlConnection(@"Data Source=.;Initial Catalog=project;Integrated Security=True;");
        public purchase()
        {
            InitializeComponent();
        }

        private void purchase_Load(object sender, EventArgs e)
        {
            try
            {
                if (con.State == ConnectionState.Open)
                {
                    con.Close();
                }
                con.Open();
                //display();
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred while connecting to the database: " + ex.Message, "Connection Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            fill_productname();
            fill_dealername();
        }

        private void fill_productname()
        {
            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from product";
            cmd.ExecuteNonQuery();

            DataTable dt = new DataTable();
            SqlDataAdapter adap = new SqlDataAdapter(cmd);
            adap.Fill(dt);
            foreach (DataRow dr in dt.Rows)
            {
                comboBox1.Items.Add(dr["p_name"].ToString());
            }

        }
        private void fill_dealername()
        {
            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from dealer";
            cmd.ExecuteNonQuery();

            DataTable dt = new DataTable();
            SqlDataAdapter adap = new SqlDataAdapter(cmd);
            adap.Fill(dt);
            foreach (DataRow dr in dt.Rows)
            {
                comboBox2.Items.Add(dr["d_name"].ToString());
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from product where p_name = '" + comboBox1.Text + "'";
            cmd.ExecuteNonQuery();

            DataTable dt = new DataTable();
            SqlDataAdapter adap = new SqlDataAdapter(cmd);
            adap.Fill(dt);
            foreach (DataRow dr in dt.Rows)
            {
                label1.Text = dr["units"].ToString();
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox4_Leave(object sender, EventArgs e)
        {
            int val1 = Convert.ToInt32(textBox3.Text);
            int val2 = Convert.ToInt32(textBox4.Text);
            int res = val1 * val2;
            if (res != 0)
            {
                textBox7.Text = res.ToString();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;


            int i = 0;
            cmd.CommandText = "select * from stock where p_name = '" + comboBox1.Text + "'";
            cmd.ExecuteNonQuery();
            DataTable dt = new DataTable();
            SqlDataAdapter adap = new SqlDataAdapter(cmd);
            adap.Fill(dt);
            i = Convert.ToInt32(dt.Rows.Count.ToString());
            if (i == 0)
            {
                cmd.CommandText = "insert into purchase values('" + comboBox1.Text + "','" + label1.Text + "','" + textBox4.Text + "','" + textBox7.Text + "','" + dateTimePicker1.Value.ToString("dd-MM-yyyy") + "','" + textBox1.Text + "','" + comboBox3.Text + "','" + dateTimePicker2.Value.ToString("dd-MM-yyyy") + "','" + textBox8.Text + "','" + textBox3.Text + "')";
                cmd.ExecuteNonQuery();

                cmd.CommandText = "insert into stock values('" + comboBox1.Text + "','" + textBox3.Text + "','" + label1.Text + "')";
                cmd.ExecuteNonQuery();

            }
            else
            {
                cmd.CommandText = "update stock set p_quantity= p_quantity+ '" + textBox3.Text + "'";
                cmd.ExecuteNonQuery();
            }



            MessageBox.Show("Record Inserted.");
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}
