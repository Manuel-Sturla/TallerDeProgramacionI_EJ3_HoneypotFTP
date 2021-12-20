//
// Created by manfer on 6/10/19.
//

#include "server_Comando_QUIT.h"

#define NOMBRE_QUIT "QUIT"
#define MSJ_SALIR "quitSuccess"
#define NRO_SALIR 221
server_Comando_QUIT::server_Comando_QUIT(\
std::unordered_map<std::string, std::string>& rtas) : \
    server_Comando(NOMBRE_QUIT, rtas),
    msj_fin(rtas.at(MSJ_SALIR)){
}

void server_Comando_QUIT::_ejecutar(server_Cliente_Proxy &usuario, \
std::string &extra) {
    usuario.mostrar(NRO_SALIR, msj_fin);
}

void server_Comando_QUIT::ejecutar(server_Cliente_Proxy &usuario, \
std::string extra) {
    _ejecutar(usuario, extra);
}
