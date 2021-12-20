//
// Created by manfer on 1/10/19.
//

#include "server_Aceptador.h"

#include <utility>
#include <algorithm>
#include <iostream>


void server_Aceptador::ejecutar() {
    continuar = true;
    socket.bind_and_listen(servicio);
    while (continuar){
        try{
            server_Cliente_Proxy cliente(socket.aceptar());
            clientes.emplace_back(new server_Comunicador(cliente, comandos));
            clientes.back()->iniciar();
            cerrar_clientes_terminados();
        }catch (const common_Error_Socket &e){
            break;
        }
    }
    std::for_each(clientes.begin(), clientes.end(), \
    [](std::unique_ptr<server_Comunicador>& ptr){
       ptr->parar();
       ptr->esperar();
    });
}

server_Aceptador::server_Aceptador(std::string servicio,\
std::unordered_map<std::string, std::unique_ptr<server_Comando>>& comandos) :\
    servicio(std::move(servicio)), comandos(comandos), continuar(true){
}

void server_Aceptador::parar() {
    continuar = false;
    socket.cerrar();
}

void server_Aceptador::cerrar_clientes_terminados() {
    auto it = clientes.begin();
    while (it != clientes.end()){
        if ((*it)->esta_muerto()){
            (*it)->esperar();
            it = clientes.erase(it);
        }else{
            it++;
        }
    }
}
