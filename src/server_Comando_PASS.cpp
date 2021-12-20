//
// Created by manfer on 29/9/19.
//

#include <iostream>
#include "server_Comando_PASS.h"
#include "server_Cliente_Proxy.h"
#include <unordered_map>
#include "server_Cliente_Proxy.h"

#define NOMBRE_PASS "PASS"
#define MSJ_LOGIN_EXITOSO "loginSuccess"
#define NRO_LOGIN_EXITOSO 230
#define MSJ_LOGIN_FALLIDO "loginFailed"
#define NRO_LOGIN_FALLIDO 530
#define CONTRASENIA "password"
#define USUARIO "user"

server_Comando_PASS::server_Comando_PASS(\
    std::unordered_map<std::string, std::string>& rtas) :
    server_Comando(NOMBRE_PASS, rtas),
    contrasenia_incorrecta(std::move(rtas.at(MSJ_LOGIN_FALLIDO))),
    login_exitoso(std::move(rtas.at(MSJ_LOGIN_EXITOSO))),
    contrasenia(std::move(rtas.at(CONTRASENIA))),
    usuario(std::move(rtas.at(USUARIO))){
}

void server_Comando_PASS::ejecutar(server_Cliente_Proxy &cliente, \
    std::string extra) {
    if (cliente.obtener_ultimo_comando() != "USER"){
        cliente.mostrar(NRO_LOGIN_FALLIDO, msj_no_logueado);
        cliente.actualizar_ultimo_comando(NOMBRE_PASS);
        return;
    }
    _ejecutar(cliente, extra);
}

void server_Comando_PASS::_ejecutar(server_Cliente_Proxy &usuarioActual,\
    std::string &contra) {
    if ((usuarioActual.obtener_alias() != usuario) or (contra !=contrasenia)){
        usuarioActual.mostrar(NRO_LOGIN_FALLIDO, contrasenia_incorrecta);
    } else {
        usuarioActual.mostrar(NRO_LOGIN_EXITOSO, login_exitoso);
        usuarioActual.loguear();
    }
    usuarioActual.actualizar_ultimo_comando(NOMBRE_PASS);
}
