//
// Created by manfer on 1/10/19.
//

#include "server_Comando_INVALID.h"

#define NOMBRE_INVALID "INVALID"
#define MSJ_CMD_INVALIDO "unknownCommand"
#define NRO_CMD_INVALIDO 530
void server_Comando_INVALID::_ejecutar(server_Cliente_Proxy &usuario, \
std::string& extra) {
    usuario.mostrar(NRO_CMD_INVALIDO, msj_comando_invalido);
}

server_Comando_INVALID::server_Comando_INVALID(\
    std::unordered_map<std::string, std::string>& rtas) :\
    server_Comando(NOMBRE_INVALID, rtas),
    msj_comando_invalido(rtas.at(MSJ_CMD_INVALIDO)){
}

void server_Comando_INVALID::ejecutar(server_Cliente_Proxy &usuario, \
std::string extra) {
    _ejecutar(usuario, extra);
}
