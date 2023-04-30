public partial class MyControl : UserControl{
  public MyControl(){
    InitializeComponent();
    ResizeRedraw = true;
  }
  protected override void OnPaintBackground(PaintEventArgs e){
    base.OnPaintBackground(e);
    // draw a blue ellipse into the control area
    e.Graphics.FillEllipse(new SolidBrush(Color.Blue), 2, 2, ClientRectangle.Width - 4, ClientRectangle.Height - 4);
  }
}