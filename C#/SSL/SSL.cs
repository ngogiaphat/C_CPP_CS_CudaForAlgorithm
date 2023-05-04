using System;
using System.Net;
using System.Net.Security;
using System.Security.Cryptography.X509Certificates;
using System.IO;
public class SSLExample{
    static void Main(){
        ServicePointManager.ServerCertificateValidationCallback = new RemoteCertificateValidationCallback(ValidateServerCertificate);
        HttpWebRequest request = (HttpWebRequest)WebRequest.Create("https://www.example.com/");
        HttpWebResponse response = (HttpWebResponse)request.GetResponse();
        Stream stream = response.GetResponseStream();
        StreamReader reader = new StreamReader(stream);
        Console.WriteLine(reader.ReadToEnd());
    }
    public static bool ValidateServerCertificate(object sender, X509Certificate certificate, X509Chain chain, SslPolicyErrors sslPolicyErrors){
        if (sslPolicyErrors == SslPolicyErrors.None){
            return true;
        }
        Console.WriteLine("SSL Certificate Error: " + sslPolicyErrors.ToString());
        return false;
    }
}