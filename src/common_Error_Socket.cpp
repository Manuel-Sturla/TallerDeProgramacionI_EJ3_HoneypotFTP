//
// Created by manfer on 9/10/19.
//

#include "common_Error_Socket.h"

common_Error_Socket::common_Error_Socket(const std::string& msj) :
    std::runtime_error(msj){

}
