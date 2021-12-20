//
// Created by manfer on 28/9/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_CLIENTE_PROXY_H
#define EJ3___HONEYPOT_FTP_SERVER_CLIENTE_PROXY_H


#include <string>
#include "common_Socket.h"

class server_Cliente_Proxy {
    bool logueado = false;
    std::string ultimo_comando = "";
    std::string alias;
    common_Socket socket_cliente;
public:
    explicit server_Cliente_Proxy(common_Socket socket);
    server_Cliente_Proxy(server_Cliente_Proxy&& otro);
    bool esta_logueado();
    void loguear();
    void actualizar_ultimo_comando(std::string nombre_comando);
    std::string obtener_ultimo_comando();
    void actualizar_alias(std::string& alias);
    std::string obtener_alias();
    void mostrar(const std::string& mensaje);
    void mostrar(int num, const std::string &mensaje);
    std::pair<std::string, std::string> recibir_comando();
    void desconectar();
};


#endif //EJ3___HONEYPOT_FTP_SERVER_CLIENTE_PROXY_H
