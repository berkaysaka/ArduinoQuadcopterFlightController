namespace QuadCopterPidTuner
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
            this.components = new System.ComponentModel.Container();
            this.cmbComPorts = new System.Windows.Forms.ComboBox();
            this.btn_SET = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.txt_rollpitch_I_limit = new System.Windows.Forms.TextBox();
            this.txt_rollpitch_D = new System.Windows.Forms.TextBox();
            this.txt_rollpitch_I = new System.Windows.Forms.TextBox();
            this.txt_rollpitch_P = new System.Windows.Forms.TextBox();
            this.read_rollpitch_I_limit = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.read_rollpitch_D = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.read_rollpitch_I = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.read_rollpitch_P = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.txt_yaw_I_limit = new System.Windows.Forms.TextBox();
            this.txt_yaw_D = new System.Windows.Forms.TextBox();
            this.txt_yaw_I = new System.Windows.Forms.TextBox();
            this.txt_yaw_P = new System.Windows.Forms.TextBox();
            this.read_yaw_I_limit = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.read_yaw_D = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.read_yaw_I = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.read_yaw_P = new System.Windows.Forms.TextBox();
            this.btn_READ = new System.Windows.Forms.Button();
            this.txt_log = new System.Windows.Forms.TextBox();
            this.btnConnectComPort = new System.Windows.Forms.Button();
            this.btn_refreshComPorts = new System.Windows.Forms.Button();
            this.lblStatus = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.btnClearLogs = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.txt_ANGLE_DEGREE_LIMIT_YAW = new System.Windows.Forms.TextBox();
            this.label13 = new System.Windows.Forms.Label();
            this.read_ANGLE_DEGREE_LIMIT_YAW = new System.Windows.Forms.TextBox();
            this.txt_ANGLE_DEGREE_LIMIT_PITCH_ROLL = new System.Windows.Forms.TextBox();
            this.txt_MAX_YAW_CONTROL_GAIN = new System.Windows.Forms.TextBox();
            this.txt_MAX_ROLL_PITCH_CONTROL_GAIN = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.read_ANGLE_DEGREE_LIMIT_PITCH_ROLL = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.read_MAX_YAW_CONTROL_GAIN = new System.Windows.Forms.TextBox();
            this.label12 = new System.Windows.Forms.Label();
            this.read_MAX_ROLL_PITCH_CONTROL_GAIN = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // cmbComPorts
            // 
            this.cmbComPorts.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbComPorts.FormattingEnabled = true;
            this.cmbComPorts.Location = new System.Drawing.Point(165, 12);
            this.cmbComPorts.Name = "cmbComPorts";
            this.cmbComPorts.Size = new System.Drawing.Size(503, 24);
            this.cmbComPorts.TabIndex = 0;
            this.cmbComPorts.SelectedIndexChanged += new System.EventHandler(this.cmbComPorts_SelectedIndexChanged);
            // 
            // btn_SET
            // 
            this.btn_SET.Location = new System.Drawing.Point(495, 276);
            this.btn_SET.Name = "btn_SET";
            this.btn_SET.Size = new System.Drawing.Size(407, 45);
            this.btn_SET.TabIndex = 1;
            this.btn_SET.Text = "SET ALL VALUES";
            this.btn_SET.UseVisualStyleBackColor = true;
            this.btn_SET.Click += new System.EventHandler(this.bnt_SET_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.txt_rollpitch_I_limit);
            this.groupBox1.Controls.Add(this.txt_rollpitch_D);
            this.groupBox1.Controls.Add(this.txt_rollpitch_I);
            this.groupBox1.Controls.Add(this.txt_rollpitch_P);
            this.groupBox1.Controls.Add(this.read_rollpitch_I_limit);
            this.groupBox1.Controls.Add(this.label7);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.read_rollpitch_D);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.read_rollpitch_I);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.read_rollpitch_P);
            this.groupBox1.Location = new System.Drawing.Point(37, 99);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(221, 171);
            this.groupBox1.TabIndex = 14;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Roll / Pitch";
            // 
            // txt_rollpitch_I_limit
            // 
            this.txt_rollpitch_I_limit.Location = new System.Drawing.Point(135, 134);
            this.txt_rollpitch_I_limit.Name = "txt_rollpitch_I_limit";
            this.txt_rollpitch_I_limit.Size = new System.Drawing.Size(80, 22);
            this.txt_rollpitch_I_limit.TabIndex = 19;
            // 
            // txt_rollpitch_D
            // 
            this.txt_rollpitch_D.Location = new System.Drawing.Point(135, 85);
            this.txt_rollpitch_D.Name = "txt_rollpitch_D";
            this.txt_rollpitch_D.Size = new System.Drawing.Size(80, 22);
            this.txt_rollpitch_D.TabIndex = 18;
            // 
            // txt_rollpitch_I
            // 
            this.txt_rollpitch_I.Location = new System.Drawing.Point(135, 58);
            this.txt_rollpitch_I.Name = "txt_rollpitch_I";
            this.txt_rollpitch_I.Size = new System.Drawing.Size(80, 22);
            this.txt_rollpitch_I.TabIndex = 17;
            // 
            // txt_rollpitch_P
            // 
            this.txt_rollpitch_P.Location = new System.Drawing.Point(135, 30);
            this.txt_rollpitch_P.Name = "txt_rollpitch_P";
            this.txt_rollpitch_P.Size = new System.Drawing.Size(80, 22);
            this.txt_rollpitch_P.TabIndex = 16;
            // 
            // read_rollpitch_I_limit
            // 
            this.read_rollpitch_I_limit.Location = new System.Drawing.Point(49, 133);
            this.read_rollpitch_I_limit.Name = "read_rollpitch_I_limit";
            this.read_rollpitch_I_limit.ReadOnly = true;
            this.read_rollpitch_I_limit.Size = new System.Drawing.Size(80, 22);
            this.read_rollpitch_I_limit.TabIndex = 15;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(3, 135);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(44, 17);
            this.label7.TabIndex = 14;
            this.label7.Text = "I Limit";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(26, 88);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(18, 17);
            this.label3.TabIndex = 13;
            this.label3.Text = "D";
            // 
            // read_rollpitch_D
            // 
            this.read_rollpitch_D.Location = new System.Drawing.Point(49, 86);
            this.read_rollpitch_D.Name = "read_rollpitch_D";
            this.read_rollpitch_D.ReadOnly = true;
            this.read_rollpitch_D.Size = new System.Drawing.Size(80, 22);
            this.read_rollpitch_D.TabIndex = 12;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(28, 60);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(11, 17);
            this.label2.TabIndex = 11;
            this.label2.Text = "I";
            // 
            // read_rollpitch_I
            // 
            this.read_rollpitch_I.Location = new System.Drawing.Point(49, 58);
            this.read_rollpitch_I.Name = "read_rollpitch_I";
            this.read_rollpitch_I.ReadOnly = true;
            this.read_rollpitch_I.Size = new System.Drawing.Size(80, 22);
            this.read_rollpitch_I.TabIndex = 10;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(26, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(17, 17);
            this.label1.TabIndex = 9;
            this.label1.Text = "P";
            // 
            // read_rollpitch_P
            // 
            this.read_rollpitch_P.Location = new System.Drawing.Point(49, 30);
            this.read_rollpitch_P.Name = "read_rollpitch_P";
            this.read_rollpitch_P.ReadOnly = true;
            this.read_rollpitch_P.Size = new System.Drawing.Size(80, 22);
            this.read_rollpitch_P.TabIndex = 8;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.txt_yaw_I_limit);
            this.groupBox2.Controls.Add(this.txt_yaw_D);
            this.groupBox2.Controls.Add(this.txt_yaw_I);
            this.groupBox2.Controls.Add(this.txt_yaw_P);
            this.groupBox2.Controls.Add(this.read_yaw_I_limit);
            this.groupBox2.Controls.Add(this.label8);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.read_yaw_D);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Controls.Add(this.read_yaw_I);
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Controls.Add(this.read_yaw_P);
            this.groupBox2.Location = new System.Drawing.Point(264, 99);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(225, 171);
            this.groupBox2.TabIndex = 15;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Yaw";
            // 
            // txt_yaw_I_limit
            // 
            this.txt_yaw_I_limit.Location = new System.Drawing.Point(135, 135);
            this.txt_yaw_I_limit.Name = "txt_yaw_I_limit";
            this.txt_yaw_I_limit.Size = new System.Drawing.Size(80, 22);
            this.txt_yaw_I_limit.TabIndex = 21;
            // 
            // txt_yaw_D
            // 
            this.txt_yaw_D.Location = new System.Drawing.Point(135, 86);
            this.txt_yaw_D.Name = "txt_yaw_D";
            this.txt_yaw_D.Size = new System.Drawing.Size(80, 22);
            this.txt_yaw_D.TabIndex = 20;
            // 
            // txt_yaw_I
            // 
            this.txt_yaw_I.Location = new System.Drawing.Point(135, 58);
            this.txt_yaw_I.Name = "txt_yaw_I";
            this.txt_yaw_I.Size = new System.Drawing.Size(80, 22);
            this.txt_yaw_I.TabIndex = 19;
            // 
            // txt_yaw_P
            // 
            this.txt_yaw_P.Location = new System.Drawing.Point(135, 30);
            this.txt_yaw_P.Name = "txt_yaw_P";
            this.txt_yaw_P.Size = new System.Drawing.Size(80, 22);
            this.txt_yaw_P.TabIndex = 18;
            // 
            // read_yaw_I_limit
            // 
            this.read_yaw_I_limit.Location = new System.Drawing.Point(49, 135);
            this.read_yaw_I_limit.Name = "read_yaw_I_limit";
            this.read_yaw_I_limit.ReadOnly = true;
            this.read_yaw_I_limit.Size = new System.Drawing.Size(80, 22);
            this.read_yaw_I_limit.TabIndex = 17;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(3, 137);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(44, 17);
            this.label8.TabIndex = 16;
            this.label8.Text = "I Limit";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(26, 88);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(18, 17);
            this.label4.TabIndex = 13;
            this.label4.Text = "D";
            // 
            // read_yaw_D
            // 
            this.read_yaw_D.Location = new System.Drawing.Point(49, 86);
            this.read_yaw_D.Name = "read_yaw_D";
            this.read_yaw_D.ReadOnly = true;
            this.read_yaw_D.Size = new System.Drawing.Size(80, 22);
            this.read_yaw_D.TabIndex = 12;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(28, 60);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(11, 17);
            this.label5.TabIndex = 11;
            this.label5.Text = "I";
            // 
            // read_yaw_I
            // 
            this.read_yaw_I.Location = new System.Drawing.Point(49, 58);
            this.read_yaw_I.Name = "read_yaw_I";
            this.read_yaw_I.ReadOnly = true;
            this.read_yaw_I.Size = new System.Drawing.Size(80, 22);
            this.read_yaw_I.TabIndex = 10;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(26, 32);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(17, 17);
            this.label6.TabIndex = 9;
            this.label6.Text = "P";
            // 
            // read_yaw_P
            // 
            this.read_yaw_P.Location = new System.Drawing.Point(49, 30);
            this.read_yaw_P.Name = "read_yaw_P";
            this.read_yaw_P.ReadOnly = true;
            this.read_yaw_P.Size = new System.Drawing.Size(80, 22);
            this.read_yaw_P.TabIndex = 8;
            // 
            // btn_READ
            // 
            this.btn_READ.Location = new System.Drawing.Point(37, 277);
            this.btn_READ.Name = "btn_READ";
            this.btn_READ.Size = new System.Drawing.Size(452, 45);
            this.btn_READ.TabIndex = 16;
            this.btn_READ.Text = "READ ALL VALUES";
            this.btn_READ.UseVisualStyleBackColor = true;
            this.btn_READ.Click += new System.EventHandler(this.btn_READ_Click);
            // 
            // txt_log
            // 
            this.txt_log.Location = new System.Drawing.Point(13, 328);
            this.txt_log.Multiline = true;
            this.txt_log.Name = "txt_log";
            this.txt_log.Size = new System.Drawing.Size(842, 145);
            this.txt_log.TabIndex = 17;
            // 
            // btnConnectComPort
            // 
            this.btnConnectComPort.Location = new System.Drawing.Point(522, 42);
            this.btnConnectComPort.Name = "btnConnectComPort";
            this.btnConnectComPort.Size = new System.Drawing.Size(146, 38);
            this.btnConnectComPort.TabIndex = 18;
            this.btnConnectComPort.Text = "Connect Com Port";
            this.btnConnectComPort.UseVisualStyleBackColor = true;
            this.btnConnectComPort.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // btn_refreshComPorts
            // 
            this.btn_refreshComPorts.Location = new System.Drawing.Point(165, 42);
            this.btn_refreshComPorts.Name = "btn_refreshComPorts";
            this.btn_refreshComPorts.Size = new System.Drawing.Size(138, 38);
            this.btn_refreshComPorts.TabIndex = 19;
            this.btn_refreshComPorts.Text = "Refresh Com Ports";
            this.btn_refreshComPorts.UseVisualStyleBackColor = true;
            this.btn_refreshComPorts.Click += new System.EventHandler(this.btn_refreshComPorts_Click);
            // 
            // lblStatus
            // 
            this.lblStatus.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.lblStatus.Location = new System.Drawing.Point(309, 46);
            this.lblStatus.Name = "lblStatus";
            this.lblStatus.Size = new System.Drawing.Size(207, 23);
            this.lblStatus.TabIndex = 20;
            this.lblStatus.Text = "Status";
            this.lblStatus.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // btnClearLogs
            // 
            this.btnClearLogs.Location = new System.Drawing.Point(856, 328);
            this.btnClearLogs.Name = "btnClearLogs";
            this.btnClearLogs.Size = new System.Drawing.Size(75, 144);
            this.btnClearLogs.TabIndex = 21;
            this.btnClearLogs.Text = "Clear Logs";
            this.btnClearLogs.UseVisualStyleBackColor = true;
            this.btnClearLogs.Click += new System.EventHandler(this.btnClearLogs_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.txt_ANGLE_DEGREE_LIMIT_YAW);
            this.groupBox3.Controls.Add(this.label13);
            this.groupBox3.Controls.Add(this.read_ANGLE_DEGREE_LIMIT_YAW);
            this.groupBox3.Controls.Add(this.txt_ANGLE_DEGREE_LIMIT_PITCH_ROLL);
            this.groupBox3.Controls.Add(this.txt_MAX_YAW_CONTROL_GAIN);
            this.groupBox3.Controls.Add(this.txt_MAX_ROLL_PITCH_CONTROL_GAIN);
            this.groupBox3.Controls.Add(this.label10);
            this.groupBox3.Controls.Add(this.read_ANGLE_DEGREE_LIMIT_PITCH_ROLL);
            this.groupBox3.Controls.Add(this.label11);
            this.groupBox3.Controls.Add(this.read_MAX_YAW_CONTROL_GAIN);
            this.groupBox3.Controls.Add(this.label12);
            this.groupBox3.Controls.Add(this.read_MAX_ROLL_PITCH_CONTROL_GAIN);
            this.groupBox3.Location = new System.Drawing.Point(495, 99);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(407, 171);
            this.groupBox3.TabIndex = 22;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Other Parameters";
            // 
            // txt_ANGLE_DEGREE_LIMIT_YAW
            // 
            this.txt_ANGLE_DEGREE_LIMIT_YAW.Location = new System.Drawing.Point(338, 114);
            this.txt_ANGLE_DEGREE_LIMIT_YAW.Name = "txt_ANGLE_DEGREE_LIMIT_YAW";
            this.txt_ANGLE_DEGREE_LIMIT_YAW.Size = new System.Drawing.Size(63, 22);
            this.txt_ANGLE_DEGREE_LIMIT_YAW.TabIndex = 25;
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(56, 117);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(202, 17);
            this.label13.TabIndex = 22;
            this.label13.Text = "ANGLE_DEGREE_LIMIT_YAW";
            // 
            // read_ANGLE_DEGREE_LIMIT_YAW
            // 
            this.read_ANGLE_DEGREE_LIMIT_YAW.Location = new System.Drawing.Point(269, 114);
            this.read_ANGLE_DEGREE_LIMIT_YAW.Name = "read_ANGLE_DEGREE_LIMIT_YAW";
            this.read_ANGLE_DEGREE_LIMIT_YAW.ReadOnly = true;
            this.read_ANGLE_DEGREE_LIMIT_YAW.Size = new System.Drawing.Size(63, 22);
            this.read_ANGLE_DEGREE_LIMIT_YAW.TabIndex = 21;
            // 
            // txt_ANGLE_DEGREE_LIMIT_PITCH_ROLL
            // 
            this.txt_ANGLE_DEGREE_LIMIT_PITCH_ROLL.Location = new System.Drawing.Point(338, 86);
            this.txt_ANGLE_DEGREE_LIMIT_PITCH_ROLL.Name = "txt_ANGLE_DEGREE_LIMIT_PITCH_ROLL";
            this.txt_ANGLE_DEGREE_LIMIT_PITCH_ROLL.Size = new System.Drawing.Size(63, 22);
            this.txt_ANGLE_DEGREE_LIMIT_PITCH_ROLL.TabIndex = 20;
            // 
            // txt_MAX_YAW_CONTROL_GAIN
            // 
            this.txt_MAX_YAW_CONTROL_GAIN.Location = new System.Drawing.Point(338, 58);
            this.txt_MAX_YAW_CONTROL_GAIN.Name = "txt_MAX_YAW_CONTROL_GAIN";
            this.txt_MAX_YAW_CONTROL_GAIN.Size = new System.Drawing.Size(63, 22);
            this.txt_MAX_YAW_CONTROL_GAIN.TabIndex = 19;
            // 
            // txt_MAX_ROLL_PITCH_CONTROL_GAIN
            // 
            this.txt_MAX_ROLL_PITCH_CONTROL_GAIN.Location = new System.Drawing.Point(338, 30);
            this.txt_MAX_ROLL_PITCH_CONTROL_GAIN.Name = "txt_MAX_ROLL_PITCH_CONTROL_GAIN";
            this.txt_MAX_ROLL_PITCH_CONTROL_GAIN.Size = new System.Drawing.Size(63, 22);
            this.txt_MAX_ROLL_PITCH_CONTROL_GAIN.TabIndex = 18;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(2, 88);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(256, 17);
            this.label10.TabIndex = 13;
            this.label10.Text = "ANGLE_DEGREE_LIMIT_PITCH_ROLL";
            // 
            // read_ANGLE_DEGREE_LIMIT_PITCH_ROLL
            // 
            this.read_ANGLE_DEGREE_LIMIT_PITCH_ROLL.Location = new System.Drawing.Point(269, 86);
            this.read_ANGLE_DEGREE_LIMIT_PITCH_ROLL.Name = "read_ANGLE_DEGREE_LIMIT_PITCH_ROLL";
            this.read_ANGLE_DEGREE_LIMIT_PITCH_ROLL.ReadOnly = true;
            this.read_ANGLE_DEGREE_LIMIT_PITCH_ROLL.Size = new System.Drawing.Size(63, 22);
            this.read_ANGLE_DEGREE_LIMIT_PITCH_ROLL.TabIndex = 12;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(65, 61);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(193, 17);
            this.label11.TabIndex = 11;
            this.label11.Text = "MAX_YAW_CONTROL_GAIN";
            // 
            // read_MAX_YAW_CONTROL_GAIN
            // 
            this.read_MAX_YAW_CONTROL_GAIN.Location = new System.Drawing.Point(269, 58);
            this.read_MAX_YAW_CONTROL_GAIN.Name = "read_MAX_YAW_CONTROL_GAIN";
            this.read_MAX_YAW_CONTROL_GAIN.ReadOnly = true;
            this.read_MAX_YAW_CONTROL_GAIN.Size = new System.Drawing.Size(63, 22);
            this.read_MAX_YAW_CONTROL_GAIN.TabIndex = 10;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(11, 32);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(247, 17);
            this.label12.TabIndex = 9;
            this.label12.Text = "MAX_ROLL_PITCH_CONTROL_GAIN";
            // 
            // read_MAX_ROLL_PITCH_CONTROL_GAIN
            // 
            this.read_MAX_ROLL_PITCH_CONTROL_GAIN.Location = new System.Drawing.Point(269, 30);
            this.read_MAX_ROLL_PITCH_CONTROL_GAIN.Name = "read_MAX_ROLL_PITCH_CONTROL_GAIN";
            this.read_MAX_ROLL_PITCH_CONTROL_GAIN.ReadOnly = true;
            this.read_MAX_ROLL_PITCH_CONTROL_GAIN.Size = new System.Drawing.Size(63, 22);
            this.read_MAX_ROLL_PITCH_CONTROL_GAIN.TabIndex = 8;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(943, 484);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.btnClearLogs);
            this.Controls.Add(this.lblStatus);
            this.Controls.Add(this.btn_refreshComPorts);
            this.Controls.Add(this.btnConnectComPort);
            this.Controls.Add(this.txt_log);
            this.Controls.Add(this.btn_READ);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.btn_SET);
            this.Controls.Add(this.cmbComPorts);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Remote PID Configurator";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox cmbComPorts;
        private System.Windows.Forms.Button btn_SET;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox read_rollpitch_D;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox read_rollpitch_I;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox read_rollpitch_P;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox read_yaw_D;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox read_yaw_I;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox read_yaw_P;
        private System.Windows.Forms.TextBox read_rollpitch_I_limit;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button btn_READ;
        private System.Windows.Forms.TextBox txt_rollpitch_I_limit;
        private System.Windows.Forms.TextBox txt_rollpitch_D;
        private System.Windows.Forms.TextBox txt_rollpitch_I;
        private System.Windows.Forms.TextBox txt_rollpitch_P;
        private System.Windows.Forms.TextBox txt_yaw_I_limit;
        private System.Windows.Forms.TextBox txt_yaw_D;
        private System.Windows.Forms.TextBox txt_yaw_I;
        private System.Windows.Forms.TextBox txt_yaw_P;
        private System.Windows.Forms.TextBox read_yaw_I_limit;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox txt_log;
        private System.Windows.Forms.Button btnConnectComPort;
        private System.Windows.Forms.Button btn_refreshComPorts;
        private System.Windows.Forms.Label lblStatus;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button btnClearLogs;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox txt_ANGLE_DEGREE_LIMIT_PITCH_ROLL;
        private System.Windows.Forms.TextBox txt_MAX_YAW_CONTROL_GAIN;
        private System.Windows.Forms.TextBox txt_MAX_ROLL_PITCH_CONTROL_GAIN;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox read_ANGLE_DEGREE_LIMIT_PITCH_ROLL;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox read_MAX_YAW_CONTROL_GAIN;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.TextBox read_MAX_ROLL_PITCH_CONTROL_GAIN;
        private System.Windows.Forms.TextBox txt_ANGLE_DEGREE_LIMIT_YAW;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.TextBox read_ANGLE_DEGREE_LIMIT_YAW;
    }
}

