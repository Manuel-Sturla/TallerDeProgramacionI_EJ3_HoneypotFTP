//
// Created by manfer on 11/10/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_COMANDO_SYST_H
#define EJ3___HONEYPOT_FTP_SERVER_COMANDO_SYST_H


#include "server_Comando.h"
#include <unordered_map>
#include <string>
class server_Comando_SYST: public server_Comando {
    std::string msj_informacion_sistema;
public:
    explicit server_Comando_SYST(std::unordered_map<std::string, \
std::string>& rtas);
    void _ejecutar(server_Cliente_Proxy &usuario, std::string &extra) override;
};


#endif //EJ3___HONEYPOT_FTP_SERVER_COMANDO_SYST_H
