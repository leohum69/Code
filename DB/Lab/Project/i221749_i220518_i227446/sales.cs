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
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;

namespace DBLabProjectV2
{
    public partial class sales : Form
    {
        SqlConnection con = new SqlConnection(@"Data Source=.;Initial Catalog=project;Integrated Security=True;");
        int tot = 0;
        public sales()
        {
            InitializeComponent();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void sales_Load(object sender, EventArgs e)
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

            comboBox4.Items.Clear();
            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select d_name from dealer";
            cmd.ExecuteNonQuery();

            DataTable dt = new DataTable();
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            da.Fill(dt);
            foreach (DataRow dr in dt.Rows)
            {
                comboBox4.Items.Add(dr["d_name"].ToString());
            }

            comboBox3.Items.Clear();
            cmd.CommandText = "select product_name from Product";
            DataTable dt2 = new DataTable();
            SqlDataAdapter da2 = new SqlDataAdapter(cmd);
            da2.Fill(dt2);
            foreach (DataRow dr2 in dt2.Rows)
            {
                comboBox3.Items.Add(dr2["product_name"].ToString());
            }
        }




        private void textBox5_Leave(object sender, EventArgs e)
        {
            string numberPart = label1.Text.Substring(0, label1.Text.Length - 1); 
            string symbolPart = label1.Text.Substring(label1.Text.Length - 1);

            Decimal val1 = Convert.ToDecimal(numberPart);
            if(textBox5.Text == "")
            {
                textBox5.Text = "0";
            }
            int val2 = Convert.ToInt32(textBox5.Text);
            Decimal res = val1 * val2;
            if (res != 0)
            {
                label2.Text = res.ToString()+symbolPart;
            }
        }



        private void button4_Click(object sender, EventArgs e)
        {

            if (textBox1.Text == "") {
                MessageBox.Show("Error, Enter Username Please");
                return;
            }
            if (textBox2.Text == "")
            {
                MessageBox.Show("Error, Enter Customer Name Please");
                return;
            }
            if (comboBox4.Text == "")
            {
                MessageBox.Show("Error, Enter Dealer Please");
                return;
            }
            if (comboBox1.Text == "")
            {
                MessageBox.Show("Error, Enter Payment Type Please");
                return;
            }
            if (comboBox3.Text == "")
            {
                MessageBox.Show("Error, Enter Product Please");
                return;
            }


            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;

            cmd.CommandText = "select * from users where username='" + textBox1.Text +"'";
            
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
            if (checkBox1.Checked)
            {
                if (comboBox2.Text == "")
                {
                    MessageBox.Show("Shipment method not selected");
                    return;
                }
            }

            int userID = Convert.ToInt32(dt.Rows[0]["id"]);


            cmd.CommandText = "select * from Product as P join Stock as S on P.ProductID = S.ProductID where P.product_name='" + comboBox3.Text + "'";

            DataTable dt2 = new DataTable();
            SqlDataAdapter da2 = new SqlDataAdapter(cmd);
            da2.Fill(dt2);

            int ProductID = (Convert.ToInt32(dt2.Rows[0]["ProductID"]));

            decimal price = (Convert.ToDecimal(dt2.Rows[0]["product_price"]));

            int valsinstock = (Convert.ToInt32(dt2.Rows[0]["quantity_in_stock"]));

            if((valsinstock - Convert.ToInt32(textBox5.Text))< 0)
            {
                MessageBox.Show("The Quantity is too much, The Quantity in stock is " + valsinstock);
                return;
            }


            int quantity = Convert.ToInt32(textBox5.Text);

            cmd.CommandText = "update Stock SET quantity_in_stock = " + (valsinstock - quantity) + " where stockID = "+ dt2.Rows[0]["stockID"] + ";";
            cmd.ExecuteNonQuery();

            string numberPart = label2.Text.Substring(0, label2.Text.Length - 1);
            decimal total = Convert.ToDecimal(numberPart);

            cmd.CommandText = "insert into orders values('" + dateTimePicker1.Value.ToString("dd-MM-yyyy") + "', '" + textBox2.Text + "', " + userID + ", " + total + ");SELECT SCOPE_IDENTITY();";

            object resev = cmd.ExecuteScalar();
            int orderID = Convert.ToInt32(resev);

            cmd.CommandText = "insert into Payment values(" + orderID + ", '" + comboBox1.SelectedText + "', '" + dateTimePicker1.Value.ToString("dd-MM-yyyy") + "', " + total + ");";

            cmd.ExecuteNonQuery();

            if (checkBox1.Checked)
            {

                SqlCommand cmd2 = con.CreateCommand();
                cmd2.CommandType = CommandType.Text;
                cmd2.CommandText = "insert into shipment values (" + orderID.ToString() + ",'" + dateTimePicker2.Value.ToString("dd-MM-yyyy") + "','" + comboBox2.Text + "')";
                cmd2.ExecuteNonQuery();
            }

            cmd.CommandText = "select * from dealer where d_name = '"+comboBox4.Text+"';";
            DataTable dt3 = new DataTable();
            SqlDataAdapter da3 = new SqlDataAdapter(cmd);
            da3.Fill(dt3);

            int dealerID = Convert.ToInt32(dt3.Rows[0]["Dealerid"]);


            cmd.CommandText = "insert into Purchase values('"+ dateTimePicker1.Value.ToString("dd-MM-yyyy") + "',"+ price +","+ textBox5.Text +","+ ProductID +","+ dealerID +","+ userID +","+ total+")";

            cmd.ExecuteNonQuery();

            cmd.CommandText = "insert into Order_Item values(" + orderID + "," + ProductID + "," + quantity + "," + total + ")";
            cmd.ExecuteNonQuery();





            MessageBox.Show("Record inserted successfully.");

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void label11_Click(object sender, EventArgs e)
        {

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            dateTimePicker2.Enabled = checkBox1.Checked;
            comboBox2.Enabled = checkBox1.Checked;
        }

        private void comboBox4_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void comboBox3_SelectedIndexChanged(object sender, EventArgs e)
        {
            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from Product where product_name = '" + comboBox3.SelectedItem.ToString() + "'";
            cmd.ExecuteNonQuery();
            DataTable dt = new DataTable();
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            da.Fill(dt);
            foreach (DataRow dr in dt.Rows)
            {
                label1.Text = dr["product_price"].ToString()+"$";
            }
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
