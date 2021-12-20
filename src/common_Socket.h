//
// Created by manfer on 30/9/19.
//

#ifndef EJ3___HONEYPOT_FTP_COMMON_SOCKET_H
#define EJ3___HONEYPOT_FTP_COMMON_SOCKET_H

#include "common_Error_Socket.h"
class common_Socket {
    int fd;
    common_Socket(int file_descriptor);
public:
    common_Socket();
    common_Socket(common_Socket &&otro);
    ~common_Socket();
    void conectar(const std::string &host, const std::string &servicio);
    void enviar_linea(const std::string& linea);
    std::string recibir_linea();
    void bind_and_listen(const std::string& servicio);
    common_Socket aceptar();
    void cerrar();
};


#endif //EJ3___HONEYPOT_FTP_COMMON_SOCKET_H
