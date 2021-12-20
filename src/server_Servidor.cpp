//
// Created by manfer on 26/9/19.
//

#include "server_Servidor.h"
#include "server_Fabrica_Comandos.h"
#include "server_Aceptador.h"
#include "server_Cliente_Proxy.h"
#include "server_Error_Servidor.h"
#include <istream>
#include <fstream>
#include <sstream>
#include <iostream>

#include <algorithm>
#include <unordered_map>

server_Servidor::server_Servidor(const std::string& ruta_confg, \
const std::string& servicio) :
    aceptador(servicio, comandos){
    std::unordered_map<std::string, std::string> respuestas = \
    leer_configuracion(ruta_confg);
    server_Fabrica_Comandos fabrica_comandos(respuestas, directorios);
    for (std::string cmd : nombre_comandos){
        std::unique_ptr<server_Comando> ptr(\
        fabrica_comandos.crear_comando(cmd));
        comandos.emplace(cmd, std::move(ptr));
    }
}

std::unordered_map<std::string, std::string> server_Servidor::\
leer_configuracion(const std::string& ruta_config) {
    std::ifstream archivo_config;
    archivo_config.open(ruta_config, std::ios::in);
    if (!archivo_config.is_open()){
        throw server_Error_Servidor("No se pudo abrir el archivo");
    }
    std::unordered_map<std::string, std::string> respuestas;
    std::string entrada;
    while (std::getline(archivo_config, entrada)){
        if (entrada.empty()) continue;
        std::string clave;
        std::istringstream iss(entrada);
        std::getline(iss, clave, '=');
        std::string valor;
        std::getline(iss, valor);
        respuestas.emplace(clave, valor);
    }
    return respuestas;
}

void server_Servidor::escuchar() {
    aceptador.iniciar();
}

void server_Servidor::apagar() {
    aceptador.parar();
    aceptador.esperar();
}

server_Servidor::~server_Servidor() {
    for (auto& par : comandos)
        par.second.reset();
}






