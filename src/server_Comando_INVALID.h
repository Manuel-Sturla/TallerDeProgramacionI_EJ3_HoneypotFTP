//
// Created by manfer on 1/10/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_COMANDO_INVALID_H
#define EJ3___HONEYPOT_FTP_SERVER_COMANDO_INVALID_H

#include <unordered_map>
#include <string>
#include "server_Comando.h"

class server_Comando_INVALID: public server_Comando {
    std::string msj_comando_invalido;
public:
    explicit server_Comando_INVALID(\
    std::unordered_map<std::string, std::string>& rtas);
    void _ejecutar(server_Cliente_Proxy& usuario, std::string& extra) override;
    void ejecutar(server_Cliente_Proxy& usuario, std::string extra) override;
};


#endif //EJ3___HONEYPOT_FTP_SERVER_COMANDO_INVALID_H
