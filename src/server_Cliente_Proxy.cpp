//
// Created by manfer on 28/9/19.
//

#include <iostream>
#include <sstream>
#include "server_Cliente_Proxy.h"

bool server_Cliente_Proxy::esta_logueado() {
    return logueado;
}

void server_Cliente_Proxy::loguear() {
    this->logueado=true;
}

std::string server_Cliente_Proxy::obtener_ultimo_comando() {
    return ultimo_comando;
}

void server_Cliente_Proxy::actualizar_ultimo_comando(std::string nombre_comando) {
    ultimo_comando = nombre_comando;
}

std::string server_Cliente_Proxy::obtener_alias() {
    return alias;
}

void server_Cliente_Proxy::actualizar_alias(std::string& alias_recibido) {
    this->alias = alias_recibido;
}

void server_Cliente_Proxy::mostrar(const std::string& mensaje) {
    socket_cliente.enviar_linea(mensaje + '\n');
}
void server_Cliente_Proxy::mostrar(int num , const std::string &mensaje) {
    socket_cliente.enviar_linea(std::to_string(num) + " " + mensaje + '\n');
}

server_Cliente_Proxy::server_Cliente_Proxy(common_Socket socket) :\
    socket_cliente(std::move(socket)){
}

std::pair<std::string, std::string> server_Cliente_Proxy::recibir_comando() {
    std::string linea = socket_cliente.recibir_linea();
    linea.pop_back();
    std::string cmd;
    std::istringstream iss(linea);
    std::getline(iss, cmd, ' ');
    std::string extras;
    std::getline(iss, extras);
    return std::pair<std::string, std::string>(cmd, extras);
}

void server_Cliente_Proxy::desconectar() {
    socket_cliente.cerrar();
}

server_Cliente_Proxy::server_Cliente_Proxy(server_Cliente_Proxy &&otro):
    socket_cliente(std::move(otro.socket_cliente)){
    ultimo_comando = otro.ultimo_comando;
    alias = otro.alias;
    logueado = otro.logueado;

    otro.logueado = false;
    otro.alias = "";
    otro.ultimo_comando = "";
}
