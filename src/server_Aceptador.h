//
// Created by manfer on 1/10/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_ACEPTADOR_H
#define EJ3___HONEYPOT_FTP_SERVER_ACEPTADOR_H


#include <string>
#include <vector>
#include <atomic>
#include "common_Socket.h"
#include "server_Cliente_Proxy.h"
#include "server_Hilo.h"
#include "server_Comunicador.h"
#include "server_Comando.h"

class server_Aceptador: public server_Hilo{
    common_Socket socket;
    std::string servicio;
    std::vector<std::unique_ptr<server_Comunicador>> clientes;
    std::unordered_map<std::string, std::unique_ptr<server_Comando>>& comandos;
    std::atomic<bool> continuar;
    void cerrar_clientes_terminados();
public:
    server_Aceptador(std::string servicio, \
    std::unordered_map<std::string, std::unique_ptr<server_Comando>>& comando);
    void ejecutar() override;
    void parar();
};


#endif //EJ3___HONEYPOT_FTP_SERVER_ACEPTADOR_H
