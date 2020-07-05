using System;
using System.IO.Ports;
using System.Text;
using System.Windows.Forms;

namespace DesktopApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        StringBuilder sb = new StringBuilder();
        SerialPort port;
        DateTime lastSuccessfulRead = DateTime.Now;

        private void button1_Click(object sender, EventArgs e)
        {
            port.Close();
            Application.DoEvents();
            System.Threading.Thread.Sleep(5000);
            Application.DoEvents();
            port.Open();
        }

        private string getNextLine()
        {
            try
            {
                bool endOfLine = false;
                int index = 0;
                var line = string.Empty;
                while (!endOfLine)
                {
                    string str = sb[index].ToString() + sb[index + 1].ToString();
                    if (str == Environment.NewLine)
                    {
                        endOfLine = true;
                    }
                    else
                    {
                        line += sb[index];
                        index++;
                    }
                }

                sb.Remove(0, index + 1);
                return line;

            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                return null;
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            try
            {
                if (port == null)
                {
                    port = new SerialPort("COM5", 38400, Parity.None, 8, StopBits.One);
                }

                if (lastSuccessfulRead < DateTime.Now.AddSeconds(-3))
                {
                    port.Close();
                }

                if (port.IsOpen == false)
                {
                    port.Open();
                }
                var data = port.ReadExisting();
                if (data != string.Empty)
                {
                    lastSuccessfulRead = DateTime.Now;
                }
                sb.Append(data);

                while (true)
                {
                    var line = getNextLine();
                    if (line == null)
                    {
                        return;
                    }
                    var splitted = line.Split('\t');
                    if (splitted.Length == 11)
                    {
                        var timeMillis = Convert.ToUInt64(splitted[0]);
                        var imuPitch = Convert.ToDouble(splitted[1]);
                        var imuRoll = Convert.ToDouble(splitted[2]);
                        var imuYaw = Convert.ToDouble(splitted[3]);
                        var throttle = splitted[4];
                        var desiredPitch = Convert.ToDouble(splitted[5]);
                        var desiredRoll = Convert.ToDouble(splitted[6]);
                        var desiredYaw = Convert.ToDouble(splitted[7]);
                        var controlSignalPitch = Convert.ToDouble(splitted[8]);
                        var controlSignalRoll = Convert.ToDouble(splitted[9]);
                        var controlSignalYaw = Convert.ToDouble(splitted[10]);
                        chartThrottle.Series["ThrottleSeries"].Points.AddY(throttle);
                        chartRoll.Series["RollSeries"].Points.AddY(imuRoll);
                        chartRoll.Series["DesiredRollSeries"].Points.AddY(desiredRoll);
                        chartPitch.Series["PitchSeries"].Points.AddY(imuPitch);
                        chartPitch.Series["DesiredPitchSeries"].Points.AddY(desiredPitch);
                        chartYaw.Series["YawSeries"].Points.AddY(imuYaw);
                        chartYaw.Series["DesiredYawSeries"].Points.AddY(desiredYaw);
                        chartControlSignal.Series["ControlSignalRollSeries"].Points.AddY(controlSignalRoll);
                        chartControlSignal.Series["ControlSignalPitchSeries"].Points.AddY(controlSignalPitch);
                        chartControlSignal.Series["ControlSignalYawSeries"].Points.AddY(controlSignalYaw);

                        var cnt = chartThrottle.Series["ThrottleSeries"].Points.Count;
                        var removeCnt = cnt - 100;
                        for (int i = 0; i < removeCnt; i++)
                        {
                            chartThrottle.Series["ThrottleSeries"].Points.RemoveAt(i);
                            chartRoll.Series["RollSeries"].Points.RemoveAt(i);
                            chartRoll.Series["DesiredRollSeries"].Points.RemoveAt(i);
                            chartPitch.Series["PitchSeries"].Points.RemoveAt(i);
                            chartPitch.Series["DesiredPitchSeries"].Points.RemoveAt(i);
                            chartYaw.Series["YawSeries"].Points.RemoveAt(i);
                            chartYaw.Series["DesiredYawSeries"].Points.RemoveAt(i);
                            chartControlSignal.Series["ControlSignalRollSeries"].Points.RemoveAt(i);
                            chartControlSignal.Series["ControlSignalPitchSeries"].Points.RemoveAt(i);
                            chartControlSignal.Series["ControlSignalYawSeries"].Points.RemoveAt(i);
                        }
                    }
                }
            }
            catch (Exception exception)
            {
               //if (port.IsOpen) port.Close();
            }
        }
    }
}
