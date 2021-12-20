//
// Created by manfer on 11/10/19.
//

#include "server_Comando_NEW.h"
#define NOMBRE_NEW "NEW"
#define MSJ_BIENVENIDA "newClient"
#define NRO_BIENVENIDA 220
server_Comando_NEW::server_Comando_NEW(std::unordered_map<std::string,\
std::string> &rtas) :\
    server_Comando(NOMBRE_NEW, rtas),
    msj_bienvenida(rtas.at(MSJ_BIENVENIDA)){
}

void server_Comando_NEW::_ejecutar(server_Cliente_Proxy &usuario,\
std::string &extra) {
    usuario.mostrar(NRO_BIENVENIDA, msj_bienvenida);
}

void server_Comando_NEW::ejecutar(server_Cliente_Proxy &usuario,\
std::string extra) {
   _ejecutar(usuario, extra);
}
