//
// Created by manfer on 6/10/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_COMANDO_QUIT_H
#define EJ3___HONEYPOT_FTP_SERVER_COMANDO_QUIT_H


#include "server_Comando.h"

class server_Comando_QUIT: public server_Comando {
    std::string msj_fin;
public:
    explicit server_Comando_QUIT(\
    std::unordered_map<std::string, std::string>& rtas);
    void _ejecutar(server_Cliente_Proxy& usuario, std::string& extra) override;
    void ejecutar(server_Cliente_Proxy& usuario, std::string extra) override;
};


#endif //EJ3___HONEYPOT_FTP_SERVER_COMANDO_QUIT_H
