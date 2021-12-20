//
// Created by manfer on 28/9/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_COMANDO_H
#define EJ3___HONEYPOT_FTP_SERVER_COMANDO_H


#include <string>
#include <unordered_map>
#include <bits/unordered_map.h>
#include "server_Cliente_Proxy.h"

class server_Comando {
    std::string nombre;
protected:
    std::string msj_no_logueado;
public:
    server_Comando(std::string nombre, \
    std::unordered_map<std::string, std::string> &respuestas);
    virtual void ejecutar(server_Cliente_Proxy& usuario,\
    std::string extra = "");
    virtual void _ejecutar(server_Cliente_Proxy& usuario, std::string& extra) = 0;
    virtual ~server_Comando();
};


#endif //EJ3___HONEYPOT_FTP_SERVER_COMANDO_H
