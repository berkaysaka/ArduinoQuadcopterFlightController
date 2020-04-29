using QuadCopterPidTuner.Properties;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Management;
using System.Windows.Forms;

namespace QuadCopterPidTuner
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        SerialPort port;
        private string lastConnectedPort = null;

        private void btnRefresh_Click(object sender, EventArgs e)
        {
            LoadComPorts();
        }

        private void LoadComPorts()
        {
            var selected = (string)cmbComPorts.SelectedValue;
            var comboSource = new Dictionary<string, string>();
            comboSource.Add(string.Empty, string.Empty);

            using (var searcher = new ManagementObjectSearcher
                ("\\root\\CIMV2", "SELECT * FROM Win32_PnPEntity WHERE ConfigManagerErrorCode = 0"))
            {
                //string[] portnames = SerialPort.GetPortNames();
                var ports = searcher.Get().Cast<ManagementObject>().ToList().Where(p => p["Caption"] != null && p["Caption"].ToString().Contains("(COM")).ToList();

                ports.ForEach(c => comboSource.Add(ExtractComPortNameFromCaption(c["Caption"].ToString()), c["Caption"].ToString()));
            }

            cmbComPorts.DisplayMember = "Value";
            cmbComPorts.ValueMember = "Key";
            cmbComPorts.DataSource = new BindingSource(comboSource, null);

            if (!string.IsNullOrEmpty(selected) && comboSource.ContainsKey(selected))
                cmbComPorts.SelectedValue = selected;
            else if (!string.IsNullOrEmpty(lastConnectedPort) && comboSource.ContainsKey(lastConnectedPort))
                cmbComPorts.SelectedValue = lastConnectedPort;
        }

        private string ExtractComPortNameFromCaption(string caption)
        {
            return caption.Substring(caption.LastIndexOf("(COM")).Replace("(", string.Empty).
            Replace(")", string.Empty);
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            lastConnectedPort = Settings.Default.comport;
            LoadComPorts();
        }

        private void PortOnDisposed(object sender, EventArgs e)
        {
            AddLog("port disposed event triggered");
            SetStatus(false);
        }

        private void Port_PinChanged(object sender, SerialPinChangedEventArgs e)
        {
            AddLog("port pin changed event triggered");
        }

        private void Port_ErrorReceived(object sender, SerialErrorReceivedEventArgs e)
        {
            AddLog("port error received event triggered");
        }

        private void PortOnDataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            SetActionButtonsEnable(true);
            System.Threading.Thread.Sleep(300);
            var data = port.ReadExisting();
            if (data.StartsWith("<pidconfig>") && data.EndsWith("</pidconfig>"))
            {
                var pidConfig = data.Replace("<pidconfig>", string.Empty).Replace("</pidconfig>", string.Empty).Split('\t');
                Invoke(new Action(() =>
                {
                    read_rollpitch_P.Text = pidConfig[0];
                    read_rollpitch_I.Text = pidConfig[1];
                    read_rollpitch_D.Text = pidConfig[2];
                    read_yaw_P.Text = pidConfig[3];
                    read_yaw_I.Text = pidConfig[4];
                    read_yaw_D.Text = pidConfig[5];
                    read_yaw_I_limit.Text = pidConfig[6];
                    read_rollpitch_I_limit.Text = pidConfig[7];
                    read_MAX_ROLL_PITCH_CONTROL_GAIN.Text = pidConfig[8];
                    read_MAX_YAW_CONTROL_GAIN.Text = pidConfig[9];
                    read_ANGLE_DEGREE_LIMIT_PITCH_ROLL.Text = pidConfig[10];
                    read_ANGLE_DEGREE_LIMIT_YAW.Text = pidConfig[11];
                    read_YAW_ANGLE_BOOSTER.Text = pidConfig[12];

                    if (txt_rollpitch_P.Text == string.Empty)
                    {
                        txt_rollpitch_P.Text = pidConfig[0];
                        txt_rollpitch_I.Text = pidConfig[1];
                        txt_rollpitch_D.Text = pidConfig[2];
                        txt_yaw_P.Text = pidConfig[3];
                        txt_yaw_I.Text = pidConfig[4];
                        txt_yaw_D.Text = pidConfig[5];
                        txt_yaw_I_limit.Text = pidConfig[6];
                        txt_rollpitch_I_limit.Text = pidConfig[7];
                        txt_MAX_ROLL_PITCH_CONTROL_GAIN.Text = pidConfig[8];
                        txt_MAX_YAW_CONTROL_GAIN.Text = pidConfig[9];
                        txt_ANGLE_DEGREE_LIMIT_PITCH_ROLL.Text = pidConfig[10];
                        txt_ANGLE_DEGREE_LIMIT_YAW.Text = pidConfig[11];
                        txt_YAW_ANGLE_BOOSTER.Text = pidConfig[12];
                    }
                }));
                AddLog("pid config received from quadcopter");
            }
            else if (data.StartsWith("<pidconfighasbeenset>") && data.EndsWith("</pidconfighasbeenset>"))
            {
                AddLog("pid config set successfull");
                readPidConfig();
            }
            else
            {
                AddLog("unknown command received from port : " + data);
            }
        }

        private void btn_READ_Click(object sender, EventArgs e)
        {
            readPidConfig();
        }

        private void bnt_SET_Click(object sender, EventArgs e)
        {
            setPidConfig();
        }

        private void readPidConfig()
        {
            SendCommand("<sendmepid></sendmepid>");
        }

        private void setPidConfig()
        {
            SendCommand($"<setpid>{txt_rollpitch_P.Text}\t{txt_rollpitch_I.Text}\t{txt_rollpitch_D.Text}\t{txt_yaw_P.Text}\t{txt_yaw_I.Text}\t{txt_yaw_D.Text}\t{txt_yaw_I_limit.Text}\t{txt_rollpitch_I_limit.Text}\t{txt_MAX_ROLL_PITCH_CONTROL_GAIN.Text}\t{txt_MAX_YAW_CONTROL_GAIN.Text}\t{txt_ANGLE_DEGREE_LIMIT_PITCH_ROLL.Text}\t{txt_ANGLE_DEGREE_LIMIT_YAW.Text}\t{txt_YAW_ANGLE_BOOSTER.Text}</setpid>");
        }

        private void AddLog(string message)
        {
            if (InvokeRequired)
            {
                this.BeginInvoke(new Action<string>(AddLog), new object[] { message });
                return;
            }
            txt_log.Text = message + "\r\n" + txt_log.Text;
        }

        private void SendCommand(string cmd)
        {
            byte[] MyMessage = System.Text.Encoding.UTF8.GetBytes(cmd);
            port.Write(MyMessage, 0, MyMessage.Length);
            SetActionButtonsEnable(false);
        }

        private void SetActionButtonsEnable(bool enabled)
        {
            Invoke(new Action(() =>
            {
                btn_READ.Enabled = enabled;
                btn_SET.Enabled = enabled;
            }));
        }

        private void btnConnect_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty((string)cmbComPorts.SelectedValue))
                return;

            Connect((string)cmbComPorts.SelectedValue);
        }

        private void Connect(string comPort)
        {
            if (port != null)
            {
                if (port.IsOpen)
                {
                    try
                    {
                        port.Close();
                        SetStatus(false);
                        Application.DoEvents();
                    }
                    catch (Exception exception)
                    {
                    }
                }
            }

            port = new SerialPort((string)cmbComPorts.SelectedValue, 9600);
            port.DataReceived += PortOnDataReceived;
            port.ErrorReceived += Port_ErrorReceived;
            port.PinChanged += Port_PinChanged;
            port.Disposed += PortOnDisposed;
            
            OpenPort();
        }

        private void btn_refreshComPorts_Click(object sender, EventArgs e)
        {
            LoadComPorts();
        }

        private void SetStatus(bool status)
        {
            Invoke(new Action(() =>
            {
                lblStatus.Text = status ? $"Connected: {port.PortName}" : "Disconnected";
                lblStatus.ForeColor = status ? Color.Green : Color.DarkRed;
                SetActionButtonsEnable(status);
            }));
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (port != null)
            {
                SetStatus(port.IsOpen);
                if (!port.IsOpen && port.PortName == lastConnectedPort)
                {
                    try
                    {
                        OpenPort();
                    }
                    catch (Exception exception)
                    {
                    }
                }
            }
        }

        private void btnClearLogs_Click(object sender, EventArgs e)
        {
            txt_log.Clear();
        }

        private void OpenPort()
        {
            try
            {
                port.Open();
                lastConnectedPort = port.PortName;
                Settings.Default.comport = lastConnectedPort;
                Settings.Default.Save();
                SetStatus(true);
                readPidConfig();
            }
            catch (Exception exception)
            {
            }
        }
        private void cmbComPorts_SelectedIndexChanged(object sender, EventArgs e)
        {
            var selectedComPort = (string)cmbComPorts.SelectedValue;
            if (string.IsNullOrEmpty(selectedComPort))
                return;

            if (port == null)
                Connect(selectedComPort);

            if (port.PortName != selectedComPort)
                Connect(selectedComPort);

            if (!port.IsOpen)
                Connect(selectedComPort);
        }
    }
}
