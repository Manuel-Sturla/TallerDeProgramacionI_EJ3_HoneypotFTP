//
// Created by manfer on 11/10/19.
//

#include "server_Comando_HELP.h"

#define NOMBRE_HELP "HELP"
#define MSJ_AYUDA "commands"
#define NRO_AYUDA 214

server_Comando_HELP::server_Comando_HELP(\
std::unordered_map<std::string, std::string> &rtas) :
    server_Comando(NOMBRE_HELP, rtas),
    msj_ayuda(rtas[MSJ_AYUDA]){
}

void server_Comando_HELP::_ejecutar(server_Cliente_Proxy &usuario, \
std::string &extra) {
    usuario.mostrar(NRO_AYUDA, msj_ayuda);
}
