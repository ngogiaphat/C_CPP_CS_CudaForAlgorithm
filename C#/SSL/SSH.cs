using Renci.SshNet;
class Program {
    static void Main(string[] args){
        using(var client = new SshClient("host_ssh", "username", "password")){
            client.Connect();
            if(client.IsConnected){
                Console.WriteLine("Kết nối SSH thành công");
                var command = client.CreateCommand("ls");
                var result = command.Execute();
                Console.WriteLine("Kết quả của lệnh: " + result);
                client.Disconnect();
                Console.WriteLine("Ngắt kết nối SSH");
            }
        }
    }
}