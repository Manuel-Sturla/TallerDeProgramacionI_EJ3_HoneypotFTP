//
// Created by manfer on 28/9/19.
//

#include <memory>
#include <unordered_map>
#include <set>
#include "server_Fabrica_Comandos.h"
#include "server_Comando_PWD.h"
#include "server_Comando_USER.h"
#include "server_Comando_PASS.h"
#include "server_Comando_MKD.h"
#include "server_Comando_RMD.h"
#include "server_Comando_LIST.h"
#include "server_Comando_INVALID.h"
#include "server_Comando_QUIT.h"
#include "server_Comando_NEW.h"
#include "server_Comando_HELP.h"
#include "server_Comando_SYST.h"


#define NOMBRE_COMANDO_PWD "PWD"
#define NOMBRE_COMANDO_USER "USER"
#define NOMBRE_COMANDO_PASS "PASS"
#define NOMBRE_COMANDO_MKD "MKD"
#define NOMBRE_COMANDO_RMD "RMD"
#define NOMBRE_COMANDO_LIST "LIST"
#define NOMBRE_COMANDO_INVALIDO "INVALID"
#define NOMBRE_COMANDO_QUIT "QUIT"
#define NOMBRE_COMANDO_NEW "NEW"
#define NOMBRE_COMANDO_HELP "HELP"
#define NOMBRE_COMANDO_SYST "SYST"

server_Fabrica_Comandos::server_Fabrica_Comandos(\
std::unordered_map<std::string, std::string> &rtas,\
server_Directorios_Protegido &directorios) :
    respuestas(std::move(rtas)),
    directorios(directorios) {
}

server_Comando* server_Fabrica_Comandos::crear_comando(std::string &cmd) {
    if (cmd == NOMBRE_COMANDO_PWD){
        return new server_Comando_PWD(respuestas);
    } else if (cmd == NOMBRE_COMANDO_USER){
        return new server_Comando_USER(respuestas);
    } else if (cmd == NOMBRE_COMANDO_PASS){
        return new server_Comando_PASS(respuestas);
    } else if (cmd == NOMBRE_COMANDO_MKD){
        return new server_Comando_MKD(respuestas, directorios);
    } else if (cmd == NOMBRE_COMANDO_RMD){
        return new server_Comando_RMD(respuestas, directorios);
    } else if (cmd == NOMBRE_COMANDO_LIST) {
        return new server_Comando_LIST(respuestas, directorios);
    } else if (cmd == NOMBRE_COMANDO_INVALIDO){
        return new server_Comando_INVALID(respuestas);
    } else if (cmd == NOMBRE_COMANDO_QUIT) {
        return new server_Comando_QUIT(respuestas);
    }else if (cmd == NOMBRE_COMANDO_NEW) {
        return new server_Comando_NEW(respuestas);
    }else if (cmd == NOMBRE_COMANDO_HELP) {
        return new server_Comando_HELP(respuestas);
    }else if (cmd == NOMBRE_COMANDO_SYST) {
        return new server_Comando_SYST(respuestas);
    }else{
        return nullptr;
    }
}
