using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        string path = "";

        public Form1()
        {
            InitializeComponent();
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DialogResult dialog = MessageBox.Show("Are you sure you do not want to save your file?",
                "New File", MessageBoxButtons.YesNoCancel);
            if (dialog == DialogResult.Yes)
            {
                richTextBox1.Clear();
            }
            else if (dialog == DialogResult.No)
            {
                if (path == String.Empty)
                {
                    DialogResult saveResult = saveFileDialog1.ShowDialog();
                    if (saveResult == DialogResult.OK)
                    {
                        path = saveFileDialog1.FileName;

                        try
                        {
                            StreamWriter sw = new StreamWriter(path);
                            sw.Write(richTextBox1.Text);
                            sw.Close();
                        }
                        catch (IOException ioe)
                        {
                            MessageBox.Show("Error Saving File:" + ioe.Message);
                        }
                    }
                }
                else
                {
                    try
                    {
                        StreamWriter sw = new StreamWriter(path);
                        sw.Write(richTextBox1.Text);
                        sw.Close();
                    }
                    catch (IOException ioe)
                    {
                        MessageBox.Show("Error Saving File:" + ioe.Message);
                    }
                }
            }
            else if (dialog == DialogResult.Cancel)
            {
                this.Close();
            }
            else
            {
                richTextBox1.Clear();
            }


        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog sfd = new OpenFileDialog() { Filter = "Text Documents|*.txt", ValidateNames = true, Multiselect = false })
            {
                if (sfd.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        using (StreamReader sr = new StreamReader(sfd.FileName))
                        {
                            path = sfd.FileName;
                            Task<string> text = sr.ReadToEndAsync();
                            richTextBox1.Text = text.Result;
                        }
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message, "Message", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
            }

        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (path == String.Empty)
            {
                DialogResult saveResult = saveFileDialog1.ShowDialog();
                if (saveResult == DialogResult.OK)
                {
                    path = saveFileDialog1.FileName;

                    try
                    {
                        StreamWriter sw = new StreamWriter(path);
                        sw.Write(richTextBox1.Text);
                        sw.Close();
                    }
                    catch (IOException ioe)
                    {
                        MessageBox.Show("Error Saving File:" + ioe.Message);
                    }
                }
            }
            else
            {
                try
                {
                    StreamWriter sw = new StreamWriter(path);
                    sw.Write(richTextBox1.Text);
                    sw.Close();
                }
                catch (IOException ioe)
                {
                    MessageBox.Show("Error Saving File:" + ioe.Message);
                }
            }
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DialogResult dialog = MessageBox.Show("Exit - do you want to save your file?",
            "Exit", MessageBoxButtons.YesNoCancel);

            if (dialog == DialogResult.Yes)
            {
                if (path == String.Empty)
                {
                    DialogResult saveResult = saveFileDialog1.ShowDialog();
                    if (saveResult == DialogResult.OK)
                    {
                        path = saveFileDialog1.FileName;

                        try
                        {
                            StreamWriter sw = new StreamWriter(path);
                            sw.Write(richTextBox1.Text);
                            sw.Close();
                        }
                        catch (IOException ioe)
                        {
                            MessageBox.Show("Error Saving File:" + ioe.Message);
                        }
                    }
                }
                else
                {
                    try
                    {
                        StreamWriter sw = new StreamWriter(path);
                        sw.Write(richTextBox1.Text);
                        sw.Close();
                    }
                    catch (IOException ioe)
                    {
                        MessageBox.Show("Error Saving File:" + ioe.Message);
                    }
                }
            }

            else if (dialog == DialogResult.Cancel)
            {
                this.Close();
            }

            else if (dialog == DialogResult.No)
            {
                Application.Exit();
            }
        }


        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (AboutForm frm = new AboutForm())
            {
                frm.ShowDialog();
            }
        }

        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DialogResult saveResult = saveFileDialog1.ShowDialog();
            if (saveResult == DialogResult.OK)
            {
                path = saveFileDialog1.FileName;

                try
                {
                    StreamWriter sw = new StreamWriter(path);
                    sw.Write(richTextBox1.Text);
                    sw.Close();
                }
                catch (IOException ioe)
                {
                    MessageBox.Show("Error Saving File:" + ioe.Message);
                }
            }

        }

        private void undoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Undo();
        }

        private void redoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Redo();
        }

        private void copyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Copy();
        }

        private void cutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Cut();
        }

        private void pasteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Paste();
        }

        private void fontToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            FontDialog fd = new FontDialog();
            fd.Font = richTextBox1.SelectionFont;
            if (fd.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.SelectionFont = fd.Font;
            }
        }

        private void backgroundColourToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ColorDialog cr = new ColorDialog();
            if (cr.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.BackColor = cr.Color;
            }
        }

        private void fontSizeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ColorDialog fc = new ColorDialog();
            fc.Color = richTextBox1.ForeColor;
            if (fc.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.ForeColor = fc.Color;
            }
        }

        private void deleteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.SelectedText = "";
        }

        private void form1_formclosed(object sender, formclosedeventargs e)
        {
            DialogResult dialog = MessageBox.Show("close - do you want to save your file?",
            "close", MessageBoxButtons.YesNoCancel);

            if (dialog == DialogResult.Yes)
            {
                if (path == string.Empty)
                {
                    DialogResult saveresult = saveFileDialog1.ShowDialog();
                    if (saveresult == DialogResult.OK)
                    {
                        path = saveFileDialog1.Filename;

                        try
                        {
                            StreamWriter sw = new StreamWriter(path);
                            sw.Write(richTextBox1.Text);
                            sw.Close();
                        }
                        catch (IOException ioe)
                        {
                            MessageBox.Show("error saving file:" + ioe.Message);
                        }
                    }
                }
                else
                {
                    try
                    {
                        StreamWriter sw = new StreamWriter(path);
                        sw.Write(richTextBox1.Text);
                        sw.Close();
                    }
                    catch (IOException ioe)
                    {
                        MessageBox.Show("error saving file:" + ioe.Message);
                    }
                }
            }

            if (dialog == DialogResult.Cancel)
            {
                this.Close();
            }

            if (dialog == DialogResult.No)
            {
                Application.Exit();
            }
        }
            }
        }
    }
}
