//
// Created by manfer on 30/9/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_COMANDO_MKD_H
#define EJ3___HONEYPOT_FTP_SERVER_COMANDO_MKD_H


#include <set>
#include <unordered_map>
#include "server_Comando.h"
#include "server_Directorios_Protegido.h"

class server_Comando_MKD: public server_Comando {
std::string msj_dir_creado;
std::string msj_dir_no_creado;
server_Directorios_Protegido& directorios;
public:
    server_Comando_MKD(std::unordered_map<std::string, std::string>& rtas,\
    server_Directorios_Protegido& dirs);
    void _ejecutar(server_Cliente_Proxy& usuario, \
    std::string& directorio) override;
};


#endif //EJ3___HONEYPOT_FTP_SERVER_COMANDO_MKD_H
