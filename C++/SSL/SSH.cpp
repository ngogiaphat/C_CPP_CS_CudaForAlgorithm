#include <iostream>
#include <libssh/libssh.h>
int main(){
    ssh_session my_ssh_session;
    int rc;
    // Khởi tạo phiên SSH
    my_ssh_session = ssh_new();
    if(my_ssh_session == NULL){
        std::cout << "Không thể khởi tạo phiên SSH." << std::endl;
        exit(-1);
    }
    // Đặt thông tin kết nối SSH
    ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, "example.com");
    ssh_options_set(my_ssh_session, SSH_OPTIONS_PORT, 22);
    ssh_options_set(my_ssh_session, SSH_OPTIONS_USER, "user");
    ssh_options_set(my_ssh_session, SSH_OPTIONS_PASSWORD, "password");
    // Mở kết nối SSH
    rc = ssh_connect(my_ssh_session);
    if(rc != SSH_OK){
        std::cout << "Không thể mở kết nối SSH: " << ssh_get_error(my_ssh_session) << std::endl;
        ssh_free(my_ssh_session);
        exit(-1);
    }
    // Xác thực với máy chủ SSH
    rc = ssh_userauth_password(my_ssh_session, NULL, "password");
    if(rc != SSH_AUTH_SUCCESS){
        std::cout << "Xác thực không thành công: " << ssh_get_error(my_ssh_session) << std::endl;
        ssh_disconnect(my_ssh_session);
        ssh_free(my_ssh_session);
        exit(-1);
    }
    // Mở mới một kênh SSH
    ssh_channel my_ssh_channel;
    my_ssh_channel = ssh_channel_new(my_ssh_session);
    if(my_ssh_channel == NULL){
        std::cout << "Không thể mở kênh SSH." << std::endl;
        ssh_disconnect(my_ssh_session);
        ssh_free(my_ssh_session);
        exit(-1);
    }
    // Mở kênh SSH
    rc = ssh_channel_open_session(my_ssh_channel);
    if(rc != SSH_OK){
        std::cout << "Không thể mở kênh SSH: " << ssh_get_error(my_ssh_session) << std::endl;
        ssh_channel_free(my_ssh_channel);
        ssh_disconnect(my_ssh_session);
        ssh_free(my_ssh_session);
        exit(-1);
    }
    // Gửi lệnh "ls" thông qua kênh SSH
    rc = ssh_channel_request_exec(my_ssh_channel, "ls");
    if(rc != SSH_OK){
        std::cout << "Không thể gửi lệnh: " << ssh_get_error(my_ssh_session) << std::endl;
        ssh_channel_close(my_ssh_channel);
        ssh_channel_free(my_ssh_channel);
        ssh_disconnect(my_ssh_session);
        ssh_free(my_ssh_session);
        exit(-1);
    }
    // Đọc kết quả từ kênh SSH
    char buffer[256];
    int nbytes;
    while((nbytes = ssh_channel_read(my_ssh_channel, buffer, sizeof(buffer), 0)) > 0){
        std::cout.write(buffer, nbytes);
    }
    if(nbytes < 0){
        std::cout << "Lỗi đọc kênh: " << ssh_get_error(my_ssh_session) << std::endl; 
        ssh_channel_close(my_ssh_channel); 
        ssh_channel_free(my_ssh_channel); 
        ssh_disconnect(my_ssh_session); 
        ssh_free(my_ssh_session); 
        exit(-1); 
    }
    // Đóng kênh SSH
    ssh_channel_send_eof(my_ssh_channel);
    ssh_channel_close(my_ssh_channel);
    ssh_channel_free(my_ssh_channel);
    // Ngắt kết nối SSH và giải phóng phiên SSH
    ssh_disconnect(my_ssh_session);
    ssh_free(my_ssh_session);
}