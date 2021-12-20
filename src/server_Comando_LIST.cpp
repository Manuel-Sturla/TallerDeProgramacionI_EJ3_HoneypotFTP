//
// Created by manfer on 30/9/19.
//

#include <iostream>
#include "server_Comando_LIST.h"
#include "server_Cliente_Proxy.h"
#define NOMBRE_LIST "LIST"
#define MSJ_COMIENZO "listBegin"
#define NRO_COMIENZO 150
#define MSJ_FINAL "listEnd"
#define NRO_FINAL 226
#define DETALLES_DIR "drwxrwxrwx 0 1000 1000 4096 Sep 24 12:34 "

server_Comando_LIST::server_Comando_LIST(std::unordered_map<std::string, \
std::string>& rtas, server_Directorios_Protegido &dirs)
        : server_Comando(NOMBRE_LIST, rtas),
        msj_comienzo(std::move(rtas.at(MSJ_COMIENZO))),
        msj_final(std::move(rtas.at(MSJ_FINAL))),
        directorios(dirs){
}

void server_Comando_LIST::_ejecutar(server_Cliente_Proxy &usuario,\
std::string &extra) {
    std::vector<std::string> lista_dirs = directorios.obtener_directorios();
    usuario.mostrar(NRO_COMIENZO, msj_comienzo);
    for (std::string& dir : lista_dirs)
        usuario.mostrar(DETALLES_DIR + dir);
    usuario.mostrar(NRO_FINAL, msj_final);
}
