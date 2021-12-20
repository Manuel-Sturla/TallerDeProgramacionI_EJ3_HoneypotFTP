//
// Created by manfer on 30/9/19.
//

#include <iostream>
#include "server_Comando_MKD.h"
#include <set>
#include <unordered_map>
#include "server_Cliente_Proxy.h"

#define NOMBRE_MKD "MKD"
#define MSJ_DIR_CREADO "mkdSuccess"
#define NRO_DIR_CREADO 257
#define MSJ_DIR_NO_CREADO "mkdFailed"
#define NRO_DIR_NO_CREADO 550

server_Comando_MKD::server_Comando_MKD(\
std::unordered_map<std::string, std::string>& rtas,\
server_Directorios_Protegido &dirs)
    : server_Comando(NOMBRE_MKD,rtas),
    msj_dir_creado(std::move(rtas.at(MSJ_DIR_CREADO))),
    msj_dir_no_creado(std::move(rtas.at(MSJ_DIR_NO_CREADO))),
    directorios(dirs){
}

void server_Comando_MKD::_ejecutar(server_Cliente_Proxy& usuario,\
std::string& dir) {
    bool ok = directorios.agregar_directorio(dir);
    if (ok) usuario.mostrar(NRO_DIR_CREADO,"\"" + dir + "\""\
    + " "  + msj_dir_creado);
    else {
        usuario.mostrar(NRO_DIR_NO_CREADO, msj_dir_no_creado);
    }
}
