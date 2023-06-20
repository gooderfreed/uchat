#include "../inc/client.h"

Connection mx_init_socket(DataForChat *data_chat) {
    Connection conn;

    char *ip = data_chat->ip;
    int port = data_chat->port;

    (void) ip;
    (void) port;


    if ((conn.socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        exit(-1);
    }

    conn.serv_addr.sin_family = AF_INET;
    conn.serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &conn.serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        exit(-1);
    }

    return conn;
}

void mx_disconnect(Connection conn) {
    close(conn.socket);
    exit(0);
}
