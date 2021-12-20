//
// Created by manfer on 1/10/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_HILO_H
#define EJ3___HONEYPOT_FTP_SERVER_HILO_H


#include <thread>

class server_Hilo {
private:
    std::thread hilo;
public:
    server_Hilo() = default;
    void iniciar();

    void esperar();
    virtual ~server_Hilo() = default;
    void ejecutar_seguro();
    virtual void ejecutar() = 0;
    server_Hilo(const server_Hilo&) = delete;
    server_Hilo& operator=(const server_Hilo&) = delete;
    server_Hilo(server_Hilo&& otro);
    server_Hilo& operator=(server_Hilo&& otro);
};


#endif //EJ3___HONEYPOT_FTP_SERVER_HILO_H
