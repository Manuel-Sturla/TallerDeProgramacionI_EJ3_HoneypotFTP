//
// Created by manfer on 14/10/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_ERROR_SERVIDOR_H
#define EJ3___HONEYPOT_FTP_SERVER_ERROR_SERVIDOR_H


#include <stdexcept>

class server_Error_Servidor: public std::runtime_error {
public:
    server_Error_Servidor(std::string msj);
};


#endif //EJ3___HONEYPOT_FTP_SERVER_ERROR_SERVIDOR_H
