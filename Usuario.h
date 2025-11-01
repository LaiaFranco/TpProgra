#pragma once
#include "Persona.h"
#include "Validador.h"
#include<string>
#include<cstring>

class Usuario{
public:
    Usuario();
    Usuario(int legajo,std::string usuario,std::string contrasenia,std::string rol,Persona persona);

    int getLegajo();
    std::string getUsuario();
    std::string getContrasenia();
    std::string getRol();
    Persona getPersona();

    void setLegajo(int legajo);
    void setUsuario(std::string usuario);
    void setContrasenia(std::string contrasenia);
    void setRol(std::string rol);
    void setPersona(Persona persona);


private:
    int _legajo;
    char _usuario[10];
    char _contrasenia[10];
    char _rol[50];
    Persona _persona;

    Validador _valida;

};
