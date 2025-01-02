namespace DBLabProjectV2
{
    partial class MDIParent1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            menuStrip = new MenuStrip();
            toolStripMenuItem1 = new ToolStripMenuItem();
            addUserToolStripMenuItem = new ToolStripMenuItem();
            productsToolStripMenuItem = new ToolStripMenuItem();
            addProductsToolStripMenuItem = new ToolStripMenuItem();
            updateProductToolStripMenuItem = new ToolStripMenuItem();
            queriesToolStripMenuItem = new ToolStripMenuItem();
            unorderedProductsToolStripMenuItem = new ToolStripMenuItem();
            shipmentDetailsToolStripMenuItem = new ToolStripMenuItem();
            mostPopularProductToolStripMenuItem = new ToolStripMenuItem();
            topCustomersToolStripMenuItem = new ToolStripMenuItem();
            pendingShipmentsToolStripMenuItem = new ToolStripMenuItem();
            dealerToolStripMenuItem = new ToolStripMenuItem();
            addDealersToolStripMenuItem = new ToolStripMenuItem();
            quriesToolStripMenuItem = new ToolStripMenuItem();
            dealerSuppliesToolStripMenuItem = new ToolStripMenuItem();
            frequentDealerPurchasesToolStripMenuItem = new ToolStripMenuItem();
            categoryToolStripMenuItem = new ToolStripMenuItem();
            addCategoryToolStripMenuItem = new ToolStripMenuItem();
            queriesToolStripMenuItem1 = new ToolStripMenuItem();
            categorySalesToolStripMenuItem = new ToolStripMenuItem();
            averagePriceByCategoryToolStripMenuItem = new ToolStripMenuItem();
            stockToolStripMenuItem = new ToolStripMenuItem();
            showStockToolStripMenuItem = new ToolStripMenuItem();
            logOutToolStripMenuItem = new ToolStripMenuItem();
            toolTip = new ToolTip(components);
            menuStrip.SuspendLayout();
            SuspendLayout();
            // 
            // menuStrip
            // 
            menuStrip.ImageScalingSize = new Size(20, 20);
            menuStrip.Items.AddRange(new ToolStripItem[] { toolStripMenuItem1, productsToolStripMenuItem, dealerToolStripMenuItem, categoryToolStripMenuItem, stockToolStripMenuItem, logOutToolStripMenuItem });
            menuStrip.Location = new Point(0, 0);
            menuStrip.Name = "menuStrip";
            menuStrip.Padding = new Padding(8, 3, 0, 3);
            menuStrip.Size = new Size(1481, 30);
            menuStrip.TabIndex = 0;
            menuStrip.Text = "MenuStrip";
            // 
            // toolStripMenuItem1
            // 
            toolStripMenuItem1.DropDownItems.AddRange(new ToolStripItem[] { addUserToolStripMenuItem });
            toolStripMenuItem1.Name = "toolStripMenuItem1";
            toolStripMenuItem1.Size = new Size(52, 24);
            toolStripMenuItem1.Text = "User";
            toolStripMenuItem1.Click += toolStripMenuItem1_Click;
            // 
            // addUserToolStripMenuItem
            // 
            addUserToolStripMenuItem.Name = "addUserToolStripMenuItem";
            addUserToolStripMenuItem.Size = new Size(153, 26);
            addUserToolStripMenuItem.Text = "Add User";
            addUserToolStripMenuItem.Click += addUserToolStripMenuItem_Click;
            // 
            // productsToolStripMenuItem
            // 
            productsToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { addProductsToolStripMenuItem, updateProductToolStripMenuItem, queriesToolStripMenuItem });
            productsToolStripMenuItem.Name = "productsToolStripMenuItem";
            productsToolStripMenuItem.Size = new Size(74, 24);
            productsToolStripMenuItem.Text = "Product";
            // 
            // addProductsToolStripMenuItem
            // 
            addProductsToolStripMenuItem.Name = "addProductsToolStripMenuItem";
            addProductsToolStripMenuItem.Size = new Size(196, 26);
            addProductsToolStripMenuItem.Text = "Add Products";
            addProductsToolStripMenuItem.Click += addProductsToolStripMenuItem_Click;
            // 
            // updateProductToolStripMenuItem
            // 
            updateProductToolStripMenuItem.Name = "updateProductToolStripMenuItem";
            updateProductToolStripMenuItem.Size = new Size(196, 26);
            updateProductToolStripMenuItem.Text = "Update Product";
            updateProductToolStripMenuItem.Click += updateProductToolStripMenuItem_Click;
            // 
            // queriesToolStripMenuItem
            // 
            queriesToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { unorderedProductsToolStripMenuItem, shipmentDetailsToolStripMenuItem, mostPopularProductToolStripMenuItem, topCustomersToolStripMenuItem, pendingShipmentsToolStripMenuItem });
            queriesToolStripMenuItem.Name = "queriesToolStripMenuItem";
            queriesToolStripMenuItem.Size = new Size(196, 26);
            queriesToolStripMenuItem.Text = "Queries";
            // 
            // unorderedProductsToolStripMenuItem
            // 
            unorderedProductsToolStripMenuItem.Name = "unorderedProductsToolStripMenuItem";
            unorderedProductsToolStripMenuItem.Size = new Size(234, 26);
            unorderedProductsToolStripMenuItem.Text = "Unordered Products";
            unorderedProductsToolStripMenuItem.Click += unorderedProductsToolStripMenuItem_Click;
            // 
            // shipmentDetailsToolStripMenuItem
            // 
            shipmentDetailsToolStripMenuItem.Name = "shipmentDetailsToolStripMenuItem";
            shipmentDetailsToolStripMenuItem.Size = new Size(234, 26);
            shipmentDetailsToolStripMenuItem.Text = "Shipment Details";
            shipmentDetailsToolStripMenuItem.Click += shipmentDetailsToolStripMenuItem_Click;
            // 
            // mostPopularProductToolStripMenuItem
            // 
            mostPopularProductToolStripMenuItem.Name = "mostPopularProductToolStripMenuItem";
            mostPopularProductToolStripMenuItem.Size = new Size(234, 26);
            mostPopularProductToolStripMenuItem.Text = "Most Popular Product";
            mostPopularProductToolStripMenuItem.Click += mostPopularProductToolStripMenuItem_Click;
            // 
            // topCustomersToolStripMenuItem
            // 
            topCustomersToolStripMenuItem.Name = "topCustomersToolStripMenuItem";
            topCustomersToolStripMenuItem.Size = new Size(234, 26);
            topCustomersToolStripMenuItem.Text = "Top Customers";
            topCustomersToolStripMenuItem.Click += topCustomersToolStripMenuItem_Click;
            // 
            // pendingShipmentsToolStripMenuItem
            // 
            pendingShipmentsToolStripMenuItem.Name = "pendingShipmentsToolStripMenuItem";
            pendingShipmentsToolStripMenuItem.Size = new Size(234, 26);
            pendingShipmentsToolStripMenuItem.Text = "Pending Shipments";
            pendingShipmentsToolStripMenuItem.Click += pendingShipmentsToolStripMenuItem_Click;
            // 
            // dealerToolStripMenuItem
            // 
            dealerToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { addDealersToolStripMenuItem, quriesToolStripMenuItem });
            dealerToolStripMenuItem.Name = "dealerToolStripMenuItem";
            dealerToolStripMenuItem.Size = new Size(67, 24);
            dealerToolStripMenuItem.Text = "Dealer";
            // 
            // addDealersToolStripMenuItem
            // 
            addDealersToolStripMenuItem.Name = "addDealersToolStripMenuItem";
            addDealersToolStripMenuItem.Size = new Size(174, 26);
            addDealersToolStripMenuItem.Text = "Add Dealers";
            addDealersToolStripMenuItem.Click += addDealersToolStripMenuItem_Click;
            // 
            // quriesToolStripMenuItem
            // 
            quriesToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { dealerSuppliesToolStripMenuItem, frequentDealerPurchasesToolStripMenuItem });
            quriesToolStripMenuItem.Name = "quriesToolStripMenuItem";
            quriesToolStripMenuItem.Size = new Size(174, 26);
            quriesToolStripMenuItem.Text = "Queries";
            quriesToolStripMenuItem.Click += quriesToolStripMenuItem_Click;
            // 
            // dealerSuppliesToolStripMenuItem
            // 
            dealerSuppliesToolStripMenuItem.Name = "dealerSuppliesToolStripMenuItem";
            dealerSuppliesToolStripMenuItem.Size = new Size(266, 26);
            dealerSuppliesToolStripMenuItem.Text = "Dealer Supplies";
            dealerSuppliesToolStripMenuItem.Click += dealerSuppliesToolStripMenuItem_Click;
            // 
            // frequentDealerPurchasesToolStripMenuItem
            // 
            frequentDealerPurchasesToolStripMenuItem.Name = "frequentDealerPurchasesToolStripMenuItem";
            frequentDealerPurchasesToolStripMenuItem.Size = new Size(266, 26);
            frequentDealerPurchasesToolStripMenuItem.Text = "Frequent Dealer Purchases";
            frequentDealerPurchasesToolStripMenuItem.Click += frequentDealerPurchasesToolStripMenuItem_Click;
            // 
            // categoryToolStripMenuItem
            // 
            categoryToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { addCategoryToolStripMenuItem, queriesToolStripMenuItem1 });
            categoryToolStripMenuItem.Name = "categoryToolStripMenuItem";
            categoryToolStripMenuItem.Size = new Size(83, 24);
            categoryToolStripMenuItem.Text = "Category";
            // 
            // addCategoryToolStripMenuItem
            // 
            addCategoryToolStripMenuItem.Name = "addCategoryToolStripMenuItem";
            addCategoryToolStripMenuItem.Size = new Size(224, 26);
            addCategoryToolStripMenuItem.Text = "Add Category";
            addCategoryToolStripMenuItem.Click += addCategoryToolStripMenuItem_Click;
            // 
            // queriesToolStripMenuItem1
            // 
            queriesToolStripMenuItem1.DropDownItems.AddRange(new ToolStripItem[] { categorySalesToolStripMenuItem, averagePriceByCategoryToolStripMenuItem });
            queriesToolStripMenuItem1.Name = "queriesToolStripMenuItem1";
            queriesToolStripMenuItem1.Size = new Size(224, 26);
            queriesToolStripMenuItem1.Text = "Queries";
            queriesToolStripMenuItem1.Click += queriesToolStripMenuItem1_Click;
            // 
            // categorySalesToolStripMenuItem
            // 
            categorySalesToolStripMenuItem.Name = "categorySalesToolStripMenuItem";
            categorySalesToolStripMenuItem.Size = new Size(267, 26);
            categorySalesToolStripMenuItem.Text = "Category Sales";
            categorySalesToolStripMenuItem.Click += categorySalesToolStripMenuItem_Click;
            // 
            // averagePriceByCategoryToolStripMenuItem
            // 
            averagePriceByCategoryToolStripMenuItem.Name = "averagePriceByCategoryToolStripMenuItem";
            averagePriceByCategoryToolStripMenuItem.Size = new Size(267, 26);
            averagePriceByCategoryToolStripMenuItem.Text = "Average Price by Category";
            averagePriceByCategoryToolStripMenuItem.Click += averagePriceByCategoryToolStripMenuItem_Click;
            // 
            // stockToolStripMenuItem
            // 
            stockToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { showStockToolStripMenuItem });
            stockToolStripMenuItem.Name = "stockToolStripMenuItem";
            stockToolStripMenuItem.Size = new Size(59, 24);
            stockToolStripMenuItem.Text = "Stock";
            // 
            // showStockToolStripMenuItem
            // 
            showStockToolStripMenuItem.Name = "showStockToolStripMenuItem";
            showStockToolStripMenuItem.Size = new Size(168, 26);
            showStockToolStripMenuItem.Text = "Show Stock";
            showStockToolStripMenuItem.Click += showStockToolStripMenuItem_Click;
            // 
            // logOutToolStripMenuItem
            // 
            logOutToolStripMenuItem.Name = "logOutToolStripMenuItem";
            logOutToolStripMenuItem.Size = new Size(76, 24);
            logOutToolStripMenuItem.Text = "Log Out";
            logOutToolStripMenuItem.Click += logOutToolStripMenuItem_Click;
            // 
            // MDIParent1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1481, 473);
            Controls.Add(menuStrip);
            IsMdiContainer = true;
            MainMenuStrip = menuStrip;
            Margin = new Padding(4, 5, 4, 5);
            Name = "MDIParent1";
            Text = "MDIParent1";
            WindowState = FormWindowState.Maximized;
            Load += MDIParent1_Load;
            menuStrip.ResumeLayout(false);
            menuStrip.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }
        #endregion


        private System.Windows.Forms.MenuStrip menuStrip;
        private System.Windows.Forms.ToolTip toolTip;
        private ToolStripMenuItem toolStripMenuItem1;
        private ToolStripMenuItem addUserToolStripMenuItem;
        private ToolStripMenuItem productsToolStripMenuItem;
        private ToolStripMenuItem addProductsToolStripMenuItem;
        private ToolStripMenuItem dealerToolStripMenuItem;
        private ToolStripMenuItem addDealersToolStripMenuItem;
        private ToolStripMenuItem categoryToolStripMenuItem;
        private ToolStripMenuItem addCategoryToolStripMenuItem;
        private ToolStripMenuItem updateProductToolStripMenuItem;
        private ToolStripMenuItem stockToolStripMenuItem;
        private ToolStripMenuItem showStockToolStripMenuItem;
        private ToolStripMenuItem logOutToolStripMenuItem;
        private ToolStripMenuItem queriesToolStripMenuItem;
        private ToolStripMenuItem unorderedProductsToolStripMenuItem;
        private ToolStripMenuItem shipmentDetailsToolStripMenuItem;
        private ToolStripMenuItem quriesToolStripMenuItem;
        private ToolStripMenuItem mostPopularProductToolStripMenuItem;
        private ToolStripMenuItem topCustomersToolStripMenuItem;
        private ToolStripMenuItem pendingShipmentsToolStripMenuItem;
        private ToolStripMenuItem dealerSuppliesToolStripMenuItem;
        private ToolStripMenuItem frequentDealerPurchasesToolStripMenuItem;
        private ToolStripMenuItem queriesToolStripMenuItem1;
        private ToolStripMenuItem categorySalesToolStripMenuItem;
        private ToolStripMenuItem averagePriceByCategoryToolStripMenuItem;
    }
}



