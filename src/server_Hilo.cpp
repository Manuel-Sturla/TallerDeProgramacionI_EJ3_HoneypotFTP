//
// Created by manfer on 1/10/19.
//

#include <iostream>
#include "server_Hilo.h"
void server_Hilo::iniciar() {
    hilo = std::thread(&server_Hilo::ejecutar_seguro, this);
}

void server_Hilo::esperar() {
    hilo.join();
}

server_Hilo::server_Hilo(server_Hilo &&otro) {
    this->hilo = std::move(otro.hilo);
}

server_Hilo &server_Hilo::operator=(server_Hilo &&otro) {
    this->hilo = std::move(otro.hilo);
    return *this;
}

void server_Hilo::ejecutar_seguro() {
    try {
        ejecutar();
    } catch(std::exception &e){
        std::cerr << "Error en un hilo: " << e.what() << std::endl;
    } catch(...){
        std::cerr << "Error desconocido en un Hilo" << std::endl;
    }
}

