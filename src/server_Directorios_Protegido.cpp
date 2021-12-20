//
// Created by manfer on 10/10/19.
//

#include "server_Directorios_Protegido.h"

bool server_Directorios_Protegido::agregar_directorio(std::string &dir) {
    std::unique_lock<std::mutex> lock(mutex);
    auto par = directorios.emplace(dir);
    return par.second;
}

int server_Directorios_Protegido::eliminar_directorio(std::string &dir) {
    std::unique_lock<std::mutex> lock(mutex);
    return directorios.erase(dir);
}

std::vector<std::string> server_Directorios_Protegido::obtener_directorios() {
    std::unique_lock<std::mutex> lock(mutex);
    std::vector<std::string> resultado;
    resultado.reserve(directorios.size());
    for(const std::string& dir : directorios)
        resultado.push_back(dir);
    return resultado;
}
