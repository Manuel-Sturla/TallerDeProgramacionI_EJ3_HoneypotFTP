//
// Created by manfer on 28/9/19.
//

#include <iostream>
#include "server_Comando.h"
#include <unordered_map>
#include <utility>
#include <bits/unordered_map.h>
#include "server_Cliente_Proxy.h"


#define MSJ_NO_LOGUEADO "clientNotLogged"
#define NRO_NO_LOGUEADO 530

void server_Comando::ejecutar(server_Cliente_Proxy& usuario, \
std::string extra) {
    if (!usuario.esta_logueado()){
        usuario.mostrar(NRO_NO_LOGUEADO, this->msj_no_logueado);
    } else{
        _ejecutar(usuario, extra);
    }
    usuario.actualizar_ultimo_comando(nombre);
}

server_Comando::server_Comando(std::string nombre, \
std::unordered_map<std::string, std::string> &respuestas)
    : nombre(std::move(nombre)),
    msj_no_logueado(respuestas[MSJ_NO_LOGUEADO]){}

server_Comando::~server_Comando() = default;

