//
// Created by manfer on 11/10/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_COMANDO_NEW_H
#define EJ3___HONEYPOT_FTP_SERVER_COMANDO_NEW_H


#include <string>
#include "server_Comando.h"

class server_Comando_NEW: public server_Comando {
    std::string msj_bienvenida;
public:
    explicit server_Comando_NEW(std::unordered_map<std::string, \
    std::string>& rtas);
    void ejecutar(server_Cliente_Proxy &usuario, std::string extra) override;
    void _ejecutar(server_Cliente_Proxy &usuario, std::string &extra) override;
};


#endif //EJ3___HONEYPOT_FTP_SERVER_COMANDO_NEW_H
