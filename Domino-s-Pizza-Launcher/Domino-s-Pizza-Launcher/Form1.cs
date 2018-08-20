using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Domino_s_Pizza_Launcher
{
    public partial class Form1 : Form
    {
        string Gamepath;
        string actualVersion = "Domino-s-Pizza-Vanilla";
        
        public Form1()
        {
            InitializeComponent();
            modBox.Text = actualVersion;
        }

        private void btn_play_Click(object sender, EventArgs e)
        {
            Gamepath = System.IO.Path.GetFullPath("../Domino-s-Pizza-C/" + actualVersion + "/Game.exe");
            Console.Write(Gamepath);
            System.Diagnostics.Process.Start(Gamepath);
        }

        private void btn_mod_Click(object sender, EventArgs e)
        {
            actualVersion = modBox.Text;
            MessageBox.Show("Mod " + actualVersion + " selecionado.");
        }
    }
}
