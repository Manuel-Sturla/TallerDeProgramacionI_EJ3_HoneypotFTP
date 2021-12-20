//
// Created by manfer on 1/10/19.
//

#include <iostream>
#include "server_Servidor.h"
#include "server_Error_Servidor.h"

int main(int argc, char** argv){
    if (argc != 3){
        std::cout << "Comandos invalidos";
        return 1;
    }
    try{
        server_Servidor servidor(argv[2], argv[1]);
        servidor.escuchar();
        char c = '0';
        do{
            std::cin.get(c);
            //Saco el \n restante
            std::cin.get();
        }while (c != 'q');
        servidor.apagar();
    }catch(const server_Error_Servidor &e) {
        std::cout << e.what() << std::endl;
    }catch (std::exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }catch(...){
        std::cerr << "Error desconocido" << std::endl;
    }
    return 0;
}