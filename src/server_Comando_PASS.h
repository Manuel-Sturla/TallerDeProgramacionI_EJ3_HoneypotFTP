//
// Created by manfer on 29/9/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_COMANDO_PASS_H
#define EJ3___HONEYPOT_FTP_SERVER_COMANDO_PASS_H


#include "server_Comando.h"
#include "server_Cliente_Proxy.h"

class server_Comando_PASS: public server_Comando{
    std::string contrasenia_incorrecta;
    std::string login_exitoso;
    std::string usuario_no_ingresado;
    std::string contrasenia;
    std::string usuario;
public:
    explicit server_Comando_PASS(\
    std::unordered_map<std::string, std::string>& rtas);
    void ejecutar(server_Cliente_Proxy& cliente, std::string extra) override;
    void _ejecutar(server_Cliente_Proxy& usuario, std::string& extra) override;
};


#endif //EJ3___HONEYPOT_FTP_SERVER_COMANDO_PASS_H
