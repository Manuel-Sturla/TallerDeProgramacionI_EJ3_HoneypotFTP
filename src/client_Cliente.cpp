//
// Created by manfer on 26/9/19.
//

#include <iostream>
#include "client_Cliente.h"
#include "server_Servidor.h"


#define COMANDO_SALIDA "QUIT"


void client_Cliente::escuchar() {
    std::string entrada;
    std::cout << servidor.recibir_linea();
    do {
        if(std::getline(std::cin, entrada, '\n').eof()){
            break;
        }
        std::cout << servidor.ejecutar_comando(entrada);
    }while ((entrada != COMANDO_SALIDA) and (std::cin.good()));
}

client_Cliente::client_Cliente(const std::string &host, \
const std::string &servicio): \
    servidor(host, servicio) {
}
