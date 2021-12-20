//
// Created by manfer on 29/9/19.
//

#include <iostream>
#include <unordered_map>

#include "server_Comando_USER.h"
#include "server_Cliente_Proxy.h"

#define NOMBRE "USER"
#define NOMBRE_MSJ_USER "passRequired"
#define NRO_MSJ_USER 331

#define NOMBRE_MSJ_YA_LOGUEADO "unknownCommand"
#define NRO_YA_LOGUEADO 530
void server_Comando_USER::_ejecutar(server_Cliente_Proxy &usuario, \
std::string &nombre_alias) {
    usuario.mostrar(NRO_MSJ_USER, msj_ingrese_contrasenia);
    usuario.actualizar_alias(nombre_alias);
    usuario.actualizar_ultimo_comando(NOMBRE);
}

void server_Comando_USER::ejecutar(server_Cliente_Proxy &usuario, std::string extra) {
    if (usuario.esta_logueado()){
        usuario.mostrar(NRO_YA_LOGUEADO,msj_ya_logueado);
        return;
    }
    _ejecutar(usuario, extra);
}

server_Comando_USER::server_Comando_USER(\
    std::unordered_map<std::string, std::string>& rtas) :
    server_Comando(NOMBRE, rtas),
    msj_ingrese_contrasenia(std::move(rtas.at(NOMBRE_MSJ_USER))),
    msj_ya_logueado(rtas.at(NOMBRE_MSJ_YA_LOGUEADO)){
}
