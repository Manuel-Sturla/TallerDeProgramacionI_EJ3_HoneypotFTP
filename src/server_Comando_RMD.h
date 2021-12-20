//
// Created by manfer on 30/9/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_COMANDO_RMD_H
#define EJ3___HONEYPOT_FTP_SERVER_COMANDO_RMD_H
#include <set>
#include <unordered_map>
#include "server_Comando.h"
#include "server_Directorios_Protegido.h"

class server_Comando_RMD: public server_Comando {
    std::string msj_dir_eliminado;
    std::string msj_dir_no_eliminado;
    server_Directorios_Protegido& directorios;
public:
    server_Comando_RMD(std::unordered_map<std::string, std::string>& rtas,\
    server_Directorios_Protegido &dirs);
    void _ejecutar(server_Cliente_Proxy& usuario, std::string& dir) override;
};


#endif //EJ3___HONEYPOT_FTP_SERVER_COMANDO_RMD_H
