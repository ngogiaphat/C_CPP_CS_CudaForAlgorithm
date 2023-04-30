private void MyTask(string[] files)
{
  foreach (string file in files)
  {
    // a time consuming operation with a file (compression, encryption etc.)
    Thread.Sleep(1000);
  }
}