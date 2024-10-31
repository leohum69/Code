using System.Data.SqlClient;

namespace i221749_Lab10
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            SqlConnection conn = new SqlConnection("Data Source=.;Initial Catalog=Insta;Integrated Security=True;");
            conn.Open();
            MessageBox.Show("Data Added Successfully");
            SqlCommand cm;
            string fn1 = textBox1.Text;
            string ln1 = textBox2.Text;
            string un1 = textBox3.Text;
            string ps1 = textBox4.Text;

            string query = "Insert into [user](fn,ln,un,ps) values ('" + fn1 + "','" + ln1 + "','" + un1 + "','" + ps1 + "')";
            cm = new SqlCommand(query, conn);
            cm.ExecuteNonQuery();
            cm.Dispose();
            conn.Close();
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Form2 form2 = new Form2();
            form2.Show();

            // Hide the current form
            this.Hide();
        }
    }
}
