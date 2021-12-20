//
// Created by manfer on 1/10/19.
//

#include <iostream>
#include "client_Cliente.h"

int main(int argc, char** argv){
    if (argc != 3){
        std::cout << "Comandos invalidos" << std::endl;
        return 1;
    }
    try{
        client_Cliente cliente(argv[1], argv[2]);
        cliente.escuchar();
    } catch(const common_Error_Socket &e) {
        std::cerr << "Se termino la coneccion" << std::endl;
        return 0;
    }catch(std::exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }catch(...){
        std::cerr << "Error desconocido" << std::endl;
        return 1;
    }
    return 0;
}