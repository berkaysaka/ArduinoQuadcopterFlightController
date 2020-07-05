namespace DesktopApp1
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
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea2 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend2 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series4 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea3 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend3 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series5 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series6 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea4 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend4 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series7 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series8 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea5 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend5 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series9 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series10 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series2 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series3 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.chartThrottle = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.chartRoll = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.chartPitch = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.chartYaw = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.chartControlSignal = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.tableLayoutPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chartThrottle)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.chartRoll)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.chartPitch)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.chartYaw)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.chartControlSignal)).BeginInit();
            this.SuspendLayout();
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 10;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.AutoSize = true;
            this.tableLayoutPanel1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.tableLayoutPanel1.ColumnCount = 5;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel1.Controls.Add(this.chartControlSignal, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.chartThrottle, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.chartRoll, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.chartPitch, 2, 0);
            this.tableLayoutPanel1.Controls.Add(this.chartYaw, 3, 0);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 1;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(1377, 629);
            this.tableLayoutPanel1.TabIndex = 7;
            // 
            // chartThrottle
            // 
            chartArea2.AxisX.IntervalAutoMode = System.Windows.Forms.DataVisualization.Charting.IntervalAutoMode.VariableCount;
            chartArea2.AxisY.Maximum = 150D;
            chartArea2.AxisY.Minimum = 0D;
            chartArea2.Name = "ChartArea1";
            this.chartThrottle.ChartAreas.Add(chartArea2);
            this.chartThrottle.Dock = System.Windows.Forms.DockStyle.Fill;
            legend2.LegendStyle = System.Windows.Forms.DataVisualization.Charting.LegendStyle.Row;
            legend2.Name = "Legend1";
            legend2.Position.Auto = false;
            legend2.Position.Height = 4.743083F;
            legend2.Position.Width = 46.64032F;
            legend2.Position.X = 50.35968F;
            legend2.Position.Y = 3F;
            this.chartThrottle.Legends.Add(legend2);
            this.chartThrottle.Location = new System.Drawing.Point(3, 2);
            this.chartThrottle.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.chartThrottle.Name = "chartThrottle";
            series4.BorderWidth = 3;
            series4.ChartArea = "ChartArea1";
            series4.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series4.Color = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            series4.Legend = "Legend1";
            series4.Name = "ThrottleSeries";
            this.chartThrottle.Series.Add(series4);
            this.chartThrottle.Size = new System.Drawing.Size(269, 625);
            this.chartThrottle.TabIndex = 9;
            this.chartThrottle.Text = "chartThrottle";
            // 
            // chartRoll
            // 
            chartArea3.AxisY.Interval = 1D;
            chartArea3.AxisY.IntervalType = System.Windows.Forms.DataVisualization.Charting.DateTimeIntervalType.Number;
            chartArea3.AxisY.IsLabelAutoFit = false;
            chartArea3.AxisY.Maximum = 25D;
            chartArea3.AxisY.Minimum = -25D;
            chartArea3.Name = "ChartArea1";
            this.chartRoll.ChartAreas.Add(chartArea3);
            this.chartRoll.Dock = System.Windows.Forms.DockStyle.Fill;
            legend3.LegendStyle = System.Windows.Forms.DataVisualization.Charting.LegendStyle.Column;
            legend3.Name = "Legend1";
            legend3.Position.Auto = false;
            legend3.Position.Height = 6.719368F;
            legend3.Position.Width = 46.64032F;
            legend3.Position.X = 50.35968F;
            legend3.Position.Y = 3F;
            this.chartRoll.Legends.Add(legend3);
            this.chartRoll.Location = new System.Drawing.Point(553, 2);
            this.chartRoll.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.chartRoll.Name = "chartRoll";
            series5.BorderWidth = 3;
            series5.ChartArea = "ChartArea1";
            series5.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series5.Color = System.Drawing.Color.Red;
            series5.Legend = "Legend1";
            series5.Name = "RollSeries";
            series6.BorderWidth = 3;
            series6.ChartArea = "ChartArea1";
            series6.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series6.Color = System.Drawing.Color.Blue;
            series6.Legend = "Legend1";
            series6.Name = "DesiredRollSeries";
            this.chartRoll.Series.Add(series5);
            this.chartRoll.Series.Add(series6);
            this.chartRoll.Size = new System.Drawing.Size(269, 625);
            this.chartRoll.TabIndex = 10;
            this.chartRoll.Text = "chartRoll";
            // 
            // chartPitch
            // 
            chartArea4.AxisY.Interval = 1D;
            chartArea4.AxisY.IntervalType = System.Windows.Forms.DataVisualization.Charting.DateTimeIntervalType.Number;
            chartArea4.AxisY.IsLabelAutoFit = false;
            chartArea4.AxisY.Maximum = 25D;
            chartArea4.AxisY.Minimum = -25D;
            chartArea4.Name = "ChartArea1";
            this.chartPitch.ChartAreas.Add(chartArea4);
            this.chartPitch.Dock = System.Windows.Forms.DockStyle.Fill;
            legend4.LegendStyle = System.Windows.Forms.DataVisualization.Charting.LegendStyle.Column;
            legend4.Name = "Legend1";
            legend4.Position.Auto = false;
            legend4.Position.Height = 6.719368F;
            legend4.Position.Width = 46.64032F;
            legend4.Position.X = 50.35968F;
            legend4.Position.Y = 3F;
            this.chartPitch.Legends.Add(legend4);
            this.chartPitch.Location = new System.Drawing.Point(828, 2);
            this.chartPitch.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.chartPitch.Name = "chartPitch";
            series7.BorderWidth = 3;
            series7.ChartArea = "ChartArea1";
            series7.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series7.Color = System.Drawing.Color.Red;
            series7.Legend = "Legend1";
            series7.Name = "PitchSeries";
            series8.BorderWidth = 3;
            series8.ChartArea = "ChartArea1";
            series8.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series8.Color = System.Drawing.Color.Blue;
            series8.Legend = "Legend1";
            series8.Name = "DesiredPitchSeries";
            this.chartPitch.Series.Add(series7);
            this.chartPitch.Series.Add(series8);
            this.chartPitch.Size = new System.Drawing.Size(269, 625);
            this.chartPitch.TabIndex = 6;
            this.chartPitch.Text = "chartPitch";
            // 
            // chartYaw
            // 
            chartArea5.AxisX.IntervalAutoMode = System.Windows.Forms.DataVisualization.Charting.IntervalAutoMode.VariableCount;
            chartArea5.AxisY.Maximum = 180D;
            chartArea5.AxisY.Minimum = -180D;
            chartArea5.Name = "ChartArea1";
            this.chartYaw.ChartAreas.Add(chartArea5);
            this.chartYaw.Dock = System.Windows.Forms.DockStyle.Fill;
            legend5.LegendStyle = System.Windows.Forms.DataVisualization.Charting.LegendStyle.Column;
            legend5.Name = "Legend1";
            legend5.Position.Auto = false;
            legend5.Position.Height = 6.719368F;
            legend5.Position.Width = 46.8504F;
            legend5.Position.X = 50.1496F;
            legend5.Position.Y = 3F;
            this.chartYaw.Legends.Add(legend5);
            this.chartYaw.Location = new System.Drawing.Point(1103, 2);
            this.chartYaw.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.chartYaw.Name = "chartYaw";
            series9.BorderWidth = 3;
            series9.ChartArea = "ChartArea1";
            series9.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series9.Color = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
            series9.Legend = "Legend1";
            series9.Name = "YawSeries";
            series10.BorderWidth = 2;
            series10.ChartArea = "ChartArea1";
            series10.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series10.Color = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            series10.Legend = "Legend1";
            series10.Name = "DesiredYawSeries";
            this.chartYaw.Series.Add(series9);
            this.chartYaw.Series.Add(series10);
            this.chartYaw.Size = new System.Drawing.Size(271, 625);
            this.chartYaw.TabIndex = 7;
            this.chartYaw.Text = "chartYaw";
            // 
            // chartControlSignal
            // 
            chartArea1.AxisX.IntervalAutoMode = System.Windows.Forms.DataVisualization.Charting.IntervalAutoMode.VariableCount;
            chartArea1.AxisY.Maximum = 40D;
            chartArea1.AxisY.Minimum = -40D;
            chartArea1.Name = "ChartArea1";
            this.chartControlSignal.ChartAreas.Add(chartArea1);
            this.chartControlSignal.Dock = System.Windows.Forms.DockStyle.Fill;
            legend1.DockedToChartArea = "ChartArea1";
            legend1.Name = "Legend1";
            legend1.Position.Auto = false;
            legend1.Position.Height = 9.134615F;
            legend1.Position.Width = 69.77612F;
            legend1.Position.X = 21.72897F;
            this.chartControlSignal.Legends.Add(legend1);
            this.chartControlSignal.Location = new System.Drawing.Point(278, 2);
            this.chartControlSignal.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.chartControlSignal.Name = "chartControlSignal";
            series1.BorderWidth = 2;
            series1.ChartArea = "ChartArea1";
            series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series1.Color = System.Drawing.Color.Fuchsia;
            series1.Legend = "Legend1";
            series1.Name = "ControlSignalRollSeries";
            series2.BorderWidth = 2;
            series2.ChartArea = "ChartArea1";
            series2.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series2.Color = System.Drawing.Color.Aqua;
            series2.Legend = "Legend1";
            series2.Name = "ControlSignalPitchSeries";
            series3.BorderWidth = 2;
            series3.ChartArea = "ChartArea1";
            series3.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series3.Color = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            series3.Legend = "Legend1";
            series3.Name = "ControlSignalYawSeries";
            this.chartControlSignal.Series.Add(series1);
            this.chartControlSignal.Series.Add(series2);
            this.chartControlSignal.Series.Add(series3);
            this.chartControlSignal.Size = new System.Drawing.Size(269, 625);
            this.chartControlSignal.TabIndex = 11;
            this.chartControlSignal.Text = "chartControlSignal";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1377, 629);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.tableLayoutPanel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.chartThrottle)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.chartRoll)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.chartPitch)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.chartYaw)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.chartControlSignal)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.DataVisualization.Charting.Chart chartYaw;
        private System.Windows.Forms.DataVisualization.Charting.Chart chartPitch;
        private System.Windows.Forms.DataVisualization.Charting.Chart chartRoll;
        private System.Windows.Forms.DataVisualization.Charting.Chart chartThrottle;
        private System.Windows.Forms.DataVisualization.Charting.Chart chartControlSignal;
    }
}

