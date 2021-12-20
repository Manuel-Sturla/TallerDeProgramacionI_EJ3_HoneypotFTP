//
// Created by manfer on 30/9/19.
//

#include <iostream>
#include "server_Comando_RMD.h"
#include "server_Cliente_Proxy.h"

#define NOMBRE_RMD "RMD"
#define MSJ_ELIMINADO_EXITOSO "rmdSuccess"
#define MSJ_ELIMINADO_FALLIDO "rmdFailed"
#define NRO_ELIMINADO_EXITOSO 250
#define NRO_ELIMINADO_FALLIDO 550
server_Comando_RMD::server_Comando_RMD(\
std::unordered_map<std::string, std::string>& rtas,\
server_Directorios_Protegido &dirs) :
        server_Comando(NOMBRE_RMD, rtas),\
        msj_dir_eliminado(std::move(rtas.at(MSJ_ELIMINADO_EXITOSO))),\
        msj_dir_no_eliminado(std::move(rtas.at(MSJ_ELIMINADO_FALLIDO))),\
        directorios(dirs){
}

void server_Comando_RMD::_ejecutar(server_Cliente_Proxy& usuario, \
std::string& dir) {
    int contador = directorios.eliminar_directorio(dir);
    if (contador>0) usuario.mostrar(NRO_ELIMINADO_EXITOSO, "\"" + dir + "\" " + msj_dir_eliminado);
    else usuario.mostrar(NRO_ELIMINADO_FALLIDO, msj_dir_no_eliminado);
}
