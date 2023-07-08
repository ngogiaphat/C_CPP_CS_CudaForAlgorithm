const ssh = require('ssh2');
const conn = new ssh();
conn.on('ready', function(){
  console.log('Kết nối SSH thành công');
  // Thực thi lệnh SSH
  conn.exec('ls', function(err, stream){
    if (err) throw err;
    stream.on('close', function(code, signal){
      console.log('Lệnh đang thực thi đã kết thúc với mã code: ' + code);
      conn.end();
    }).on('data', function(data){
      console.log('Kết quả của lệnh: ' + data);
    }).stderr.on('data', function(data){
      console.log('Lỗi khi thực thi lệnh: ' + data);
    });
  });
}).connect({
  host: 'host_ssh',
  port: 'port_ssh',
  username: 'username',
  password: 'password'
});