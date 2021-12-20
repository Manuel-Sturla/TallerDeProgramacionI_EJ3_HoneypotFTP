//
// Created by manfer on 30/9/19.
//

#ifndef EJ3___HONEYPOT_FTP_CLIENT_SERVIDOR_PROXY_H
#define EJ3___HONEYPOT_FTP_CLIENT_SERVIDOR_PROXY_H


#include <string>
#include "common_Socket.h"

class client_Servidor_Proxy {
    common_Socket socket_cliente;
    std::string ejecutar_list(std::string basicString);
public:
    client_Servidor_Proxy(const std::string& host, const std::string& serv);
    std::string ejecutar_comando(std::string comando);
    std::string recibir_linea();
};


#endif //EJ3___HONEYPOT_FTP_CLIENT_SERVIDOR_PROXY_H
