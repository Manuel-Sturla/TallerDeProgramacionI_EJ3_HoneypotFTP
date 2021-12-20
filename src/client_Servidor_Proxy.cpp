//
// Created by manfer on 30/9/19.
//

#include <sstream>
#include <algorithm>
#include "client_Servidor_Proxy.h"

#define COMANDO_LIST "LIST"
#define NRO_FIN_LIST 226

client_Servidor_Proxy::client_Servidor_Proxy(const std::string &host,\
const std::string &serv){
    socket_cliente.conectar(host, serv);
}

std::string client_Servidor_Proxy::ejecutar_comando(std::string comando) {
    if (comando == COMANDO_LIST){
        return ejecutar_list(comando);
    }
    comando.push_back('\n');
    socket_cliente.enviar_linea(comando);
    std::string linea_recibida = recibir_linea();
    return linea_recibida;
}

std::string client_Servidor_Proxy::recibir_linea() {
    return socket_cliente.recibir_linea();
}

int obtener_numero(std::string& linea){
    std::string numero;
    std::istringstream iss(linea);
    std::getline(iss, numero, ' ');
    if (std::any_of(numero.begin(), numero.end(), \
    [](char c) {return !isdigit(c);})){
        return 0;
    } else{
        return std::stoi(numero);
    }
}

std::string client_Servidor_Proxy::ejecutar_list(std::string comando) {
    comando.push_back('\n');
    socket_cliente.enviar_linea(comando);
    std::string respuesta;
    std::string linea;
    do {
        linea = recibir_linea();
        respuesta += linea;
    }while (obtener_numero(linea) != NRO_FIN_LIST);
    return respuesta;
}
