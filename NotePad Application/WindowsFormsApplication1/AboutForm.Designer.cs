namespace WindowsFormsApplication1
{
    partial class AboutForm
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
            this.lblProduct = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.lblVersion = new System.Windows.Forms.Label();
            this.lblCopyright = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // lblProduct
            // 
            this.lblProduct.AutoSize = true;
            this.lblProduct.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblProduct.Location = new System.Drawing.Point(52, 59);
            this.lblProduct.Name = "lblProduct";
            this.lblProduct.Size = new System.Drawing.Size(66, 24);
            this.lblProduct.TabIndex = 0;
            this.lblProduct.Text = "label1";
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(154, 321);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(84, 39);
            this.button1.TabIndex = 1;
            this.button1.Text = "&OK";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // lblVersion
            // 
            this.lblVersion.AutoSize = true;
            this.lblVersion.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblVersion.Location = new System.Drawing.Point(52, 147);
            this.lblVersion.Name = "lblVersion";
            this.lblVersion.Size = new System.Drawing.Size(66, 24);
            this.lblVersion.TabIndex = 2;
            this.lblVersion.Text = "label1";
            // 
            // lblCopyright
            // 
            this.lblCopyright.AutoSize = true;
            this.lblCopyright.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCopyright.Location = new System.Drawing.Point(52, 235);
            this.lblCopyright.Name = "lblCopyright";
            this.lblCopyright.Size = new System.Drawing.Size(66, 24);
            this.lblCopyright.TabIndex = 3;
            this.lblCopyright.Text = "label1";
            // 
            // AboutForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(422, 372);
            this.Controls.Add(this.lblCopyright);
            this.Controls.Add(this.lblVersion);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.lblProduct);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Name = "AboutForm";
            this.RightToLeftLayout = true;
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "About";
            this.Load += new System.EventHandler(this.AboutForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblProduct;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label lblVersion;
        private System.Windows.Forms.Label lblCopyright;
    }
}