//
// Created by manfer on 11/10/19.
//

#include "server_Comando_SYST.h"
#define NOMBRE_SYST "SYST"
#define MSJ_INFO_SISTEMA "systemInfo"
#define NRO_INFO_SISTEMA 215

server_Comando_SYST::server_Comando_SYST(\
std::unordered_map<std::string, std::string>& rtas) :
    server_Comando(NOMBRE_SYST, rtas),
    msj_informacion_sistema(rtas.at(MSJ_INFO_SISTEMA)) {
}

void server_Comando_SYST::_ejecutar(server_Cliente_Proxy &usuario,\
std::string &extra) {
    usuario.mostrar(NRO_INFO_SISTEMA, msj_informacion_sistema);
}

