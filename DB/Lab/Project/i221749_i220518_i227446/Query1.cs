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
    public partial class Query1 : Form
    {
        SqlConnection con = new SqlConnection(@"Data Source=.;Initial Catalog=project;Integrated Security=True;");
        int querynum = -1;
        public Query1(int iden)
        {
            InitializeComponent();
            querynum = iden;
        }

        private void Query1_Load(object sender, EventArgs e)
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

            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;

            switch (querynum)
            {
                case 1:
                    cmd.CommandText = "SELECT p.ProductID, p.product_name,S.quantity_in_stock FROM Product p LEFT JOIN Order_Item oi ON p.ProductID = oi.ProductID join Stock S ON p.ProductID = S.ProductID WHERE oi.orderID IS NULL;";
                    label3.Text = "Products That not have been Ordered";
                    break;
                case 2:
                    cmd.CommandText = "SELECT SUM(order_total) AS total_revenue FROM Orders;";
                    label3.Text = "Total Revenue From Orders";
                    break;
                case 3:
                    cmd.CommandText = "SELECT s.shipmentID, s.orderID, o.order_date, s.shipment_date, s.shipment_method FROM Shipment s JOIN Orders o ON s.orderID = o.orderID;";
                    label3.Text = "Details of shipments for all orders";
                    break;
                case 4:
                    cmd.CommandText = "SELECT d.Dealerid, d.d_name, SUM(p.quantity_purchased) AS total_supplies FROM Dealer d JOIN Purchase p ON d.Dealerid = p.DealerID GROUP BY d.Dealerid, d.d_name;";
                    label3.Text = "List all dealers and their total supplies";
                    break;
                case 5:
                    cmd.CommandText = "SELECT TOP 1 p.ProductID, p.product_name, SUM(oi.quantity_ordered) AS total_ordered FROM Product p JOIN Order_Item oi ON p.ProductID = oi.ProductID GROUP BY p.ProductID, p.product_name ORDER BY total_ordered DESC;";
                    label3.Text = "Get the most popular product";
                    break;
                case 6:
                    cmd.CommandText = "SELECT TOP 5 o.customerName, SUM(o.order_total) AS total_spent FROM Orders o GROUP BY o.customerName ORDER BY total_spent DESC;";
                    label3.Text = "TOP 5 highest-paying customers";
                    break;
                case 7:
                    cmd.CommandText = "SELECT c.category_name, SUM(oi.purchased) AS total_sales FROM Category c JOIN Product p ON c.categoryID = p.categoryID JOIN Order_Item oi ON p.ProductID = oi.ProductID GROUP BY c.category_name;";
                    label3.Text = "Fetch total sales per category";
                    break;
                case 8:
                    cmd.CommandText = "SELECT o.orderID, o.order_date, o.order_total FROM Orders o LEFT JOIN Shipment s ON o.orderID = s.orderID WHERE s.shipmentID IS NULL;";
                    label3.Text = "Get all orders pending shipment";
                    break;
                case 9:
                    cmd.CommandText = "SELECT c.category_name, AVG(p.product_price) AS average_price FROM Category c JOIN Product p ON c.categoryID = p.categoryID GROUP BY c.category_name;";
                    label3.Text = "Calculate average product price per category";
                    break;
                case 10:
                    cmd.CommandText = "SELECT d.Dealerid, d.d_name, p.ProductID, pr.product_name, SUM(p.quantity_purchased) AS total_quantity_purchased FROM Dealer d JOIN Purchase p ON d.Dealerid = p.DealerID JOIN Product pr ON p.ProductID = pr.ProductID GROUP BY d.Dealerid, d.d_name, p.ProductID, pr.product_name ORDER BY d.Dealerid, total_quantity_purchased DESC;";
                    label3.Text = "Frequent purchase by dealer";
                    break;

                default:
                    MessageBox.Show("Unknown query!");
                    return;
            }

            cmd.ExecuteNonQuery();

            DataTable dt = new DataTable();
            SqlDataAdapter adap = new SqlDataAdapter(cmd);
            adap.Fill(dt);
            dataGridView1.DataSource = dt;
        }
    }
}
