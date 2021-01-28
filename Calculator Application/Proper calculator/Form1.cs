using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Proper_calculator
{
    public partial class Form1 : Form
    {
        Double resultValue = 0;
        String operationPerformed = "";
        bool isoperationPerformed = false;

        public Form1()
        {
            InitializeComponent();
        }

        private void button_click(object sender, EventArgs e)
        {
            if ((textBox1.Text == "0") || (isoperationPerformed))
                textBox1.Clear();

            isoperationPerformed = false;
            Button button = (Button)sender;
            if (button.Text == ".") 
            {
                if (!textBox1.Text.Contains("."))
                    textBox1.Text = textBox1.Text + button.Text;
            }
            else
            textBox1.Text = textBox1.Text + button.Text;
        }

        private void operator_click(object sender, EventArgs e)
        {
            Button button = (Button)sender; 

                if(resultValue != 0)
            {
                button16.PerformClick();
                operationPerformed = button.Text;
                label1.Text = resultValue + " " + operationPerformed;
                isoperationPerformed = true;
            }
            else
            {

                operationPerformed = button.Text;
                resultValue = Double.Parse(textBox1.Text);
                label1.Text = resultValue + " " + operationPerformed;
                isoperationPerformed = true;
            }
        }
        private void button5_Click(object sender, EventArgs e)//This button controls the CE button which clears the textbox with the first number but doesn't clear the whole equation (temporary clear)
        {
            textBox1.Text = "0";
        }

        private void button6_Click(object sender, EventArgs e) //This logic controls the C button which fully resets textBox1 after equation is solved (fully clear equation as well as label1)
        {
            textBox1.Text = "0";
            resultValue = 0;
        }

        private void button16_Click(object sender, EventArgs e)
        {
            switch (operationPerformed) // This logic controls the = button (button 15) to follow basic mathmatic operations
            {
                case "+":
                    textBox1.Text = (resultValue + Double.Parse(textBox1.Text)).ToString();
                    break;
                case "-":
                    textBox1.Text = (resultValue - Double.Parse(textBox1.Text)).ToString();
                    break;
                case "x":
                    textBox1.Text = (resultValue * Double.Parse(textBox1.Text)).ToString();
                    break;
                case "÷":
                    textBox1.Text = (resultValue / Double.Parse(textBox1.Text)).ToString();
                    break;
                default:
                    break;
            }
            resultValue = Double.Parse(textBox1.Text); //This logic controls the label and updates it with each operation that occurs giving the sum to be used for next operation
            label1.Text = ""; 
        }
    }
}
    
