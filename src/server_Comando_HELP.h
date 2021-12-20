//
// Created by manfer on 11/10/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_COMANDO_HELP_H
#define EJ3___HONEYPOT_FTP_SERVER_COMANDO_HELP_H


#include <string>
#include "server_Comando.h"

class server_Comando_HELP: public server_Comando {
    std::string msj_ayuda;
public:
    void _ejecutar(server_Cliente_Proxy &usuario, std::string &extra) override;
    explicit server_Comando_HELP(std::unordered_map<std::string, \
std::string>& rtas);
};


#endif //EJ3___HONEYPOT_FTP_SERVER_COMANDO_HELP_H
