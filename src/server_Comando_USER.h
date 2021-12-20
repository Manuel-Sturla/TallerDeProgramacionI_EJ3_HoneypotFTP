//
// Created by manfer on 29/9/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_COMANDO_USER_H
#define EJ3___HONEYPOT_FTP_SERVER_COMANDO_USER_H


#include <string>
#include <unordered_map>
#include "server_Cliente_Proxy.h"
#include "server_Comando.h"

class server_Comando_USER: public server_Comando {
    std::string msj_ingrese_contrasenia;
    std::string msj_ya_logueado;
public:
    explicit server_Comando_USER(\
    std::unordered_map<std::string, std::string>& rtas);
    void ejecutar(server_Cliente_Proxy& usuario, std::string extra) override;
    void _ejecutar(server_Cliente_Proxy& usuario, std::string& extra) override;
};


#endif //EJ3___HONEYPOT_FTP_SERVER_COMANDO_USER_H
