//
// Created by manfer on 28/9/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_FABRICA_COMANDOS_H
#define EJ3___HONEYPOT_FTP_SERVER_FABRICA_COMANDOS_H


#include <unordered_map>
#include <set>
#include <unordered_map>
#include "server_Comando.h"
#include "server_Directorios_Protegido.h"

class server_Fabrica_Comandos {
    std::unordered_map<std::string, std::string> respuestas;
    server_Directorios_Protegido& directorios;
public:
    server_Fabrica_Comandos(\
    std::unordered_map<std::string, std::string> &rtas,\
    server_Directorios_Protegido &directorios);
    server_Comando* crear_comando(std::string &cmd);
};


#endif //EJ3___HONEYPOT_FTP_SERVER_FABRICA_COMANDOS_H
