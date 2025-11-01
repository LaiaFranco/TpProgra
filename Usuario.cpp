#include "Usuario.h"

Usuario::Usuario(){
    _legajo = 0;
    strcpy(_usuario,"");
    strcpy(_contrasenia,"");
    strcpy(_rol,"");
    _persona = Persona();
}

Usuario::Usuario(int legajo, std::string usuario,std::string contrasenia,std::string rol,Persona persona){
    setLegajo(legajo);
    setUsuario(usuario);
    setContrasenia(contrasenia);
    setRol(rol);
    setPersona(persona);
}

int Usuario::getLegajo(){
    return _legajo; }

std::string Usuario::getUsuario(){
return _usuario;}

std::string Usuario::getContrasenia(){
return _contrasenia;}

std::string Usuario::getRol(){
return _rol;}

Persona Usuario::getPersona(){
return _persona;}

void Usuario::setLegajo(int legajo){
    _legajo = legajo;
}
void Usuario::setUsuario(std::string usuario){
    int tamanio = 10;
    if(_valida.ValidarTamanios(usuario,tamanio)){
        strncpy(_usuario,usuario.c_str(),9);
        _usuario[9] = '\0';
    }
}
void Usuario::setContrasenia(std::string contrasenia){
    int tamanio = 10;
    if(_valida.ValidarTamanios(contrasenia,tamanio)){
        strncpy(_contrasenia,contrasenia.c_str(),10);
        _contrasenia[9] = '\0';
    }
}
void Usuario::setRol(std::string rol){
    int tamanio = 50;
   if(_valida.ValidarTamanios(rol,tamanio)){
    strncpy(_rol,rol.c_str(),50);
    _rol[49] = '\0';
   }
}
void Usuario::setPersona(Persona persona){
    _persona = persona;
}
