using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class AboutForm : Form
    {
        public AboutForm()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void AboutForm_Load(object sender, EventArgs e)
        {
            lblProduct.Text = string.Format(" Product name: {0}", Application.ProductName);
            lblVersion.Text = string.Format("Version: {0}", Application.ProductVersion);
            lblCopyright.Text = "Copyright © 2018 by SK";
        }
    }
}
