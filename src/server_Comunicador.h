//
// Created by manfer on 1/10/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_COMUNICADOR_H
#define EJ3___HONEYPOT_FTP_SERVER_COMUNICADOR_H


#include <atomic>
#include "server_Hilo.h"
#include "common_Socket.h"
#include "server_Comando.h"

class server_Comunicador: public server_Hilo {
    server_Cliente_Proxy cliente;
    std::unordered_map<std::string, std::unique_ptr<server_Comando>>& comandos;
    std::atomic<bool> continuar;
public:
    server_Comunicador(server_Cliente_Proxy& cliente, \
    std::unordered_map<std::string, std::unique_ptr<server_Comando>>& cmds);
    void ejecutar() override;
    void parar();
    bool esta_muerto();
};


#endif //EJ3___HONEYPOT_FTP_SERVER_COMUNICADOR_H
