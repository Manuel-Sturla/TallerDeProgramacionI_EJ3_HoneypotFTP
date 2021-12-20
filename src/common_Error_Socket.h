//
// Created by manfer on 9/10/19.
//

#ifndef EJ3___HONEYPOT_FTP_COMMON_ERROR_SOCKET_H
#define EJ3___HONEYPOT_FTP_COMMON_ERROR_SOCKET_H


#include <stdexcept>

class common_Error_Socket: public std::runtime_error {
public:
    common_Error_Socket(const std::string& msj);
};


#endif //EJ3___HONEYPOT_FTP_COMMON_ERROR_SOCKET_H
