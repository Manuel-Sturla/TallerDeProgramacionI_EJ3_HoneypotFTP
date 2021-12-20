//
// Created by manfer on 14/10/19.
//

#include "server_Error_Servidor.h"

server_Error_Servidor::server_Error_Servidor(std::string msj):
    std::runtime_error(msj){
}
