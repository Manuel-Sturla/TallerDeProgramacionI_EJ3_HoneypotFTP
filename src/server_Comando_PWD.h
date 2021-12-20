//
// Created by manfer on 28/9/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_COMANDO_PWD_H
#define EJ3___HONEYPOT_FTP_SERVER_COMANDO_PWD_H


#include <unordered_map>
#include "server_Comando.h"

class server_Comando_PWD: public server_Comando{
    std::string respuesta;
public:
    explicit server_Comando_PWD(\
    std::unordered_map <std::string, std::string>& respuestas);
    void _ejecutar(server_Cliente_Proxy& usuario, std::string& extra) override;
};


#endif //EJ3___HONEYPOT_FTP_SERVER_COMANDO_PWD_H
