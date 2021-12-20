//
// Created by manfer on 1/10/19.
//

#include <iostream>
#include "server_Comunicador.h"
#include "common_Error_Socket.h"

#define CMD_INVALIDO "INVALID"
#define CMD_BIENVENIDA "NEW"

server_Comunicador::server_Comunicador(server_Cliente_Proxy& cliente,\
std::unordered_map<std::string, std::unique_ptr<server_Comando>> &cmds):\
    cliente(std::move(cliente)), comandos(cmds), continuar(true){
}

void server_Comunicador::ejecutar() {
    continuar = true;
    std::pair<std::string, std::string> cmd;
    comandos.at(CMD_BIENVENIDA)->ejecutar(cliente);
    while (continuar){
        try{
            cmd = cliente.recibir_comando();
            comandos.at(cmd.first)->ejecutar(cliente, cmd.second);
        }catch(std::out_of_range& e){
            comandos.at(CMD_INVALIDO)->ejecutar(cliente, cmd.second);
        }catch(const common_Error_Socket &e){
            continuar = false;
            break;
        }
    }
}

void server_Comunicador::parar() {
    continuar = false;
    //Desconecto el cliente, para forzar el fin de la coneccion
    cliente.desconectar();
}

bool server_Comunicador::esta_muerto() {
    return !continuar;
}

