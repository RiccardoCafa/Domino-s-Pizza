namespace Domino_s_Pizza_Launcher
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.btn_play = new System.Windows.Forms.Button();
            this.btn_mod = new System.Windows.Forms.Button();
            this.modBox = new System.Windows.Forms.TextBox();
            this.Titulo = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // btn_play
            // 
            this.btn_play.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btn_play.Font = new System.Drawing.Font("Microsoft Sans Serif", 38F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_play.Image = ((System.Drawing.Image)(resources.GetObject("btn_play.Image")));
            this.btn_play.Location = new System.Drawing.Point(193, 315);
            this.btn_play.Name = "btn_play";
            this.btn_play.Size = new System.Drawing.Size(250, 150);
            this.btn_play.TabIndex = 0;
            this.btn_play.UseVisualStyleBackColor = true;
            this.btn_play.Click += new System.EventHandler(this.btn_play_Click);
            // 
            // btn_mod
            // 
            this.btn_mod.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btn_mod.Font = new System.Drawing.Font("Microsoft Sans Serif", 38F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_mod.Image = ((System.Drawing.Image)(resources.GetObject("btn_mod.Image")));
            this.btn_mod.Location = new System.Drawing.Point(553, 315);
            this.btn_mod.Name = "btn_mod";
            this.btn_mod.Size = new System.Drawing.Size(250, 150);
            this.btn_mod.TabIndex = 1;
            this.btn_mod.UseVisualStyleBackColor = true;
            this.btn_mod.Click += new System.EventHandler(this.btn_mod_Click);
            // 
            // modBox
            // 
            this.modBox.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.modBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.modBox.Location = new System.Drawing.Point(551, 266);
            this.modBox.Name = "modBox";
            this.modBox.Size = new System.Drawing.Size(252, 26);
            this.modBox.TabIndex = 2;
            this.modBox.Text = "Domino-s-Pizza-C";
            // 
            // Titulo
            // 
            this.Titulo.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.Titulo.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.Titulo.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Titulo.Location = new System.Drawing.Point(551, 170);
            this.Titulo.Multiline = true;
            this.Titulo.Name = "Titulo";
            this.Titulo.ReadOnly = true;
            this.Titulo.Size = new System.Drawing.Size(252, 72);
            this.Titulo.TabIndex = 3;
            this.Titulo.Text = "Introduza o mod:\r\nJogo sem modificações:\r\nDomino-s-Pizza-Vanilla";
            this.Titulo.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(1025, 575);
            this.Controls.Add(this.Titulo);
            this.Controls.Add(this.modBox);
            this.Controls.Add(this.btn_mod);
            this.Controls.Add(this.btn_play);
            this.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "Domino\'s Pizza";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_play;
        private System.Windows.Forms.Button btn_mod;
        private System.Windows.Forms.TextBox modBox;
        private System.Windows.Forms.TextBox Titulo;
    }
}

