//
// Created by manfer on 10/10/19.
//

#ifndef EJ3___HONEYPOT_FTP_SERVER_DIRECTORIOS_PROTEGIDO_H
#define EJ3___HONEYPOT_FTP_SERVER_DIRECTORIOS_PROTEGIDO_H


#include <set>
#include <string>
#include <mutex>
#include <vector>

class server_Directorios_Protegido {
    std::mutex mutex;
    std::set<std::string> directorios;
public:
    bool agregar_directorio(std::string& dir);
    int eliminar_directorio(std::string& dir);
    std::vector<std::string> obtener_directorios();
};


#endif //EJ3___HONEYPOT_FTP_SERVER_DIRECTORIOS_PROTEGIDO_H
