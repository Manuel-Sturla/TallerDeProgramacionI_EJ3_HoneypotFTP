//
// Created by manfer on 26/9/19.
//

#ifndef EJ3___HONEYPOT_FTP_CLIENT_CLIENTE_H
#define EJ3___HONEYPOT_FTP_CLIENT_CLIENTE_H


#include "server_Servidor.h"
#include "client_Servidor_Proxy.h"
class client_Cliente {
    client_Servidor_Proxy servidor;
public:
    client_Cliente(const std::string& host, const std::string& servicio);
    void escuchar();
};


#endif //EJ3___HONEYPOT_FTP_CLIENT_CLIENTE_H
