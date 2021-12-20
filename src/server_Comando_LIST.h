//
// Created by manfer on 30/9/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_COMANDO_LIST_H
#define EJ3___HONEYPOT_FTP_SERVER_COMANDO_LIST_H

#include <set>
#include <unordered_map>
#include "server_Comando.h"
#include "server_Directorios_Protegido.h"

class server_Comando_LIST: public server_Comando {
    std::string msj_comienzo;
    std::string msj_final;
    server_Directorios_Protegido& directorios;
public:
    server_Comando_LIST(std::unordered_map<std::string, std::string>& rtas,\
    server_Directorios_Protegido &dirs);
    void _ejecutar(server_Cliente_Proxy& usuario, std::string& dir) override;
};


#endif //EJ3___HONEYPOT_FTP_SERVER_COMANDO_LIST_H
