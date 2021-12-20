//
// Created by manfer on 28/9/19.
//

#include <iostream>
#include "server_Comando_PWD.h"
#include "server_Cliente_Proxy.h"



#define NOMBRE_COMANDO_PWD "PWD"
#define NOMBRE_MSJ_PWD "currentDirectoryMsg"
#define NRO_MSJ_PWD 257

server_Comando_PWD::server_Comando_PWD(std::unordered_map <std::string, \
std::string>& respuestas) :
    server_Comando(NOMBRE_COMANDO_PWD, respuestas),
    respuesta(std::move(respuestas.at(NOMBRE_MSJ_PWD))){
}

void server_Comando_PWD::_ejecutar(server_Cliente_Proxy& usuario,\
std::string& extra) {
    usuario.mostrar(NRO_MSJ_PWD, respuesta);
}
