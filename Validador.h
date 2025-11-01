#pragma once
#include<string>

class Validador{
public:
    Validador();

    bool ValidarTamanios(std::string atributo,int tamanio);
    bool ValidarTamDni(std::string dni);
    bool ValidarContrasenias(std::string contrasenia,int tam = 6);
    bool ValidarOpcionesMenu(int opcion, int cantidad);





};
