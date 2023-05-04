#include <iostream>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netdb.h>
#include <string.h>
#define MAX_BUF_SIZE 4096
int main(int argc, char* argv[]) {
    SSL_CTX* ctx = NULL;
    SSL* ssl = NULL;
    BIO* bio = NULL;
    const char* hostname = "www.google.com";
    const char* port = "443";
    const char* request = "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n";
    char buffer[MAX_BUF_SIZE];
    //Create SSL library
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    //Create SSL context
    ctx = SSL_CTX_new(TLS_client_method());
    //Create object
    ssl = SSL_new(ctx);

    //Create BIO object to connect the web server
    bio = BIO_new_ssl_connect(ctx);
    BIO_get_ssl(bio, &ssl);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);
    BIO_set_conn_hostname(bio, hostname);
    BIO_set_conn_port(bio, port);
    //To connect the web server
    if (BIO_do_connect(bio) <= 0) {
        std::cout << "Không thể kết nối đến máy chủ web" << std::endl;
        ERR_print_errors_fp(stderr);
        return 1;
    }
    //Establish connection SSL/TLS
    if (BIO_do_handshake(bio) <= 0) {
        std::cout << "Không thể thiết lập kết nối SSL/TLS" << std::endl;
        ERR_print_errors_fp(stderr);
        return 1;
    }
    //Send request HTTP to web server
    BIO_write(bio, request, strlen(request));
    //Get the content of the site
    while (true) {
        int bytes_read = BIO_read(bio, buffer, MAX_BUF_SIZE - 1);
        if (bytes_read <= 0) break;
        buffer[bytes_read] = '\0';
        std::cout << buffer;
    }
    //Close connection SSL/TLS
    SSL_shutdown(ssl);
    //Freeing up resources
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    BIO_free_all(bio);
    return 0;
}