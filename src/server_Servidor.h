//
// Created by manfer on 26/9/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_SERVIDOR_H
#define EJ3___HONEYPOT_FTP_SERVER_SERVIDOR_H

#include "client_Cliente.h"
#include "server_Comando.h"
#include "server_Aceptador.h"
#include "server_Directorios_Protegido.h"
#include <unordered_map>
#include <set>
#include <vector>
#include <string>

class server_Servidor {
    std::vector<std::string> nombre_comandos{"USER", "PASS", "SYST", "LIST",\
    "PWD", "MKD", "RMD", "HELP", "INVALID", "QUIT", "NEW"};
    std::unordered_map<std::string, std::unique_ptr<server_Comando>> comandos;
    server_Directorios_Protegido directorios;
    server_Aceptador aceptador;
    std::unordered_map<std::string, std::string> leer_configuracion(\
    const std::string& ruta_config);
public:
    server_Servidor(const std::string& ruta_config, const std::string& servic);
    ~server_Servidor();
    void escuchar();
    void apagar();
};


#endif //EJ3___HONEYPOT_FTP_SERVER_SERVIDOR_H
