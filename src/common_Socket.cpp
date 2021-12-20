//
// Created by manfer on 30/9/19.
//

#include <sys/socket.h>
#include <csignal>
#include <stdexcept>
#include <unistd.h>
#include <netdb.h>
#include <cstring>
#include <iostream>
#include "common_Socket.h"
#include "common_Error_Socket.h"
#include <cstdio>
#define COLA_CONECCIONES 20

common_Socket::common_Socket() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    this->fd = fd;
}

common_Socket::~common_Socket() {
    if (fd > 0){
        cerrar();
    }
}

void setear_addrinfo_tcp_ipv4(struct addrinfo* hints){
    memset(hints, 0, sizeof(struct addrinfo));
    hints->ai_family = AF_INET;
    hints->ai_socktype = SOCK_STREAM;
}

void common_Socket::conectar(const std::string &host, \
const std::string &servicio) {
    struct addrinfo hints;
    struct addrinfo* res, *dir_act;
    setear_addrinfo_tcp_ipv4(&hints);
    hints.ai_flags = 0;
    int estado = getaddrinfo(host.c_str(), servicio.c_str(), &hints, &res);
    if (estado != 0){
        freeaddrinfo(res);
        throw common_Error_Socket(\
        "No se pudo conectar al host y servicio indicado");
    }
    for (dir_act = res; dir_act != NULL; dir_act = dir_act->ai_next){
        if (connect(fd, dir_act->ai_addr, dir_act->ai_addrlen) != -1){
            break;
        }
    }
    if(!dir_act){
        freeaddrinfo(res);
        throw common_Error_Socket("Error al conectar");
    }
    freeaddrinfo(res);
}

void common_Socket::enviar_linea(const std::string& linea) {
    ssize_t enviados = 0;
    ssize_t longitud = linea.length();
    do{
        ssize_t nuevos = send(fd, &linea.c_str()[enviados],\
			longitud-enviados, MSG_NOSIGNAL);
        if (nuevos < 0){
            throw common_Error_Socket("Error al enviar linea");
        }
        enviados += nuevos;
    }while (enviados < longitud);
}

std::string common_Socket::recibir_linea() {
    std::string buffer;
    char caracter;
    do{
        ssize_t nuevos = recv(this->fd, &caracter, 1, 0);
        if (nuevos <= 0){
            throw common_Error_Socket("Error en la recepcion de iformacion");
        } else if (nuevos == 0) {
            break;
        }
        buffer.push_back(caracter);
    }while (caracter != '\n');
    return buffer;
}

void common_Socket::bind_and_listen(const std::string &servicio) {
    struct addrinfo hints;
    struct addrinfo* resultados, *dir_act;
    setear_addrinfo_tcp_ipv4(&hints);
    hints.ai_flags = AI_PASSIVE;
    int variable = 1;
    int salida = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, \
    	&variable, sizeof(variable));
    if (salida < 0) {
        throw common_Error_Socket("Error al cambiar las opciones del socket");
    }
    int estado = getaddrinfo(NULL, servicio.c_str(), &hints, &resultados);
    if (estado != 0){
        freeaddrinfo(resultados);
        throw common_Error_Socket("Error al buscar direccion para bindear");
    }
    for (dir_act = resultados; dir_act != NULL; dir_act = dir_act->ai_next){
        if (bind(fd, dir_act->ai_addr, dir_act->ai_addrlen) != -1){
            break;
        }
    }
    freeaddrinfo(resultados);
    if (!dir_act){
        throw common_Error_Socket("No se pudo bindear a ninguna direccion");
    }
    if (listen(fd, COLA_CONECCIONES) != 0){
        throw common_Error_Socket("Error al poner el socket en modo escucha");
    }
}

common_Socket common_Socket::aceptar() {
    int fd_cliente = accept(fd, NULL, NULL);
    //Agrego el = para que tire error cuando se cierra la coneccion
    if (fd_cliente <= 0){
        throw common_Error_Socket("Error al aceptar");
    }
    common_Socket socket_cliente(fd_cliente);
    return socket_cliente;
}

common_Socket::common_Socket(int file_descriptor) {
    fd = file_descriptor;
}

common_Socket::common_Socket(common_Socket &&otro) {
    this->fd = otro.fd;
    otro.fd = -1;
}

void common_Socket::cerrar() {
    if (fd > 0){
        shutdown(fd, SHUT_RDWR);
        close(fd);
    }
    fd = -1;
}



