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
    public partial class vieworder : Form
    {
        SqlConnection con = new SqlConnection(@"Data Source=.;Initial Catalog=project;Integrated Security=True;");
        public vieworder()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "") 
            {
                MessageBox.Show("Enter Username First");
                return;
            }

            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;

            cmd.CommandText = "select * from users where username='" + textBox1.Text + "'";

            DataTable dt = new DataTable();
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            da.Fill(dt);
            int i = dt.Rows.Count;

            if (i == 0)
            {
                MessageBox.Show("Username Not found");
                textBox1.Text = "";
                return;
            }
            int userID = Convert.ToInt32(dt.Rows[0]["id"]);
            cmd.CommandText = " select P.product_name,OI.quantity_ordered,P.unit_name,OI.purchased as TOTALCOST,O.customerName  from Orders as O join Order_Item as OI on O.orderID = OI.orderID join Product as P on OI.ProductID = P.ProductID where O.userID = "+userID;
            cmd.ExecuteNonQuery();

            DataTable dt2 = new DataTable();
            SqlDataAdapter adap2 = new SqlDataAdapter(cmd);
            adap2.Fill(dt2);
            dataGridView1.DataSource = dt2;

        }

        private void vieworder_Load(object sender, EventArgs e)
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
    }
}
