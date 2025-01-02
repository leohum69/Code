using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DBLabProjectV2
{
    public partial class MDIParent1 : Form
    {
        private int childFormNumber = 0;

        public MDIParent1()
        {
            InitializeComponent();
        }

        private void ShowNewForm(object sender, EventArgs e)
        {
            Form childForm = new Form();
            childForm.MdiParent = this;
            childForm.Text = "Window " + childFormNumber++;
            childForm.Show();
        }

        private void OpenFile(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.Personal);
            openFileDialog.Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
            if (openFileDialog.ShowDialog(this) == DialogResult.OK)
            {
                string FileName = openFileDialog.FileName;
            }
        }

        private void SaveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.Personal);
            saveFileDialog.Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
            if (saveFileDialog.ShowDialog(this) == DialogResult.OK)
            {
                string FileName = saveFileDialog.FileName;
            }
        }

        private void ExitToolsStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void CutToolStripMenuItem_Click(object sender, EventArgs e)
        {
        }

        private void CopyToolStripMenuItem_Click(object sender, EventArgs e)
        {
        }

        private void PasteToolStripMenuItem_Click(object sender, EventArgs e)
        {
        }



        private void CascadeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.Cascade);
        }

        private void TileVerticalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileVertical);
        }

        private void TileHorizontalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileHorizontal);
        }

        private void ArrangeIconsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.ArrangeIcons);
        }

        private void CloseAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach (Form childForm in MdiChildren)
            {
                childForm.Close();
            }
        }

        private void MDIParent1_Load(object sender, EventArgs e)
        {

        }

        private void addUserToolStripMenuItem_Click(object sender, EventArgs e)
        {
            add_user au = new add_user();
            au.Show();
        }





        private void addProductsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            add_product ap = new add_product();
            ap.Show();
        }

        private void addDealersToolStripMenuItem_Click(object sender, EventArgs e)
        {
            add_dealer ap = new add_dealer();
            ap.Show();
        }

        private void purchaseProductsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            purchase p = new purchase();
            p.Show();
        }

        private void sellProductsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            sales s = new sales();
            s.Show();
        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {

        }

        private void addCategoryToolStripMenuItem_Click(object sender, EventArgs e)
        {
            add_category category = new add_category();
            category.Show();
        }

        private void updateProductToolStripMenuItem_Click(object sender, EventArgs e)
        {
            update_product up = new update_product();
            up.Show();
        }

        private void showStockToolStripMenuItem_Click(object sender, EventArgs e)
        {
            view_stock stock = new view_stock();
            stock.Show();
        }

        private void logOutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
            login login = new login();
            login.Show();
        }



        private void quriesToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void unorderedProductsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Query1 q = new Query1(1);
            q.Show();
        }

        private void shipmentDetailsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Query1 q = new Query1(3);
            q.Show();
        }

        private void mostPopularProductToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Query1 q = new Query1(5);
            q.Show();
        }

        private void topCustomersToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Query1 q = new Query1(6);
            q.Show();
        }

        private void pendingShipmentsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Query1 q = new Query1(8);
            q.Show();
        }

        private void dealerSuppliesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Query1 q = new Query1(4);
            q.Show();
        }

        private void frequentDealerPurchasesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Query1 q = new Query1(10);
            q.Show();
        }

        private void queriesToolStripMenuItem1_Click(object sender, EventArgs e)
        {

        }

        private void categorySalesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Query1 q = new Query1(7);
            q.Show();
        }

        private void averagePriceByCategoryToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Query1 q = new Query1(9);
            q.Show();
        }
    }
}
