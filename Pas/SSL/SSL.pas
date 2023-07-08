program SSLExample;
type
  SSLConnection = record
    // Define properties and methods for SSL connection here
  end;
function CreateSSLConnection(host: string; port: integer): SSLConnection;
begin
  // Implement SSL connection creation logic here
end;
procedure ConnectSSL(connection: SSLConnection);
begin
  // Implement SSL connection establishment logic here
end;
procedure SendMessageSSL(connection: SSLConnection; message: string);
begin
  // Implement logic to send message over SSL connection here
end;

procedure CloseSSL(connection: SSLConnection);
begin
  // Implement SSL connection closing logic here
end;
var
  sslConn: SSLConnection;
begin
  // Usage example
  sslConn := CreateSSLConnection('example.com', 443);
  ConnectSSL(sslConn);
  SendMessageSSL(sslConn, 'This is a test message');
  CloseSSL(sslConn);
end.