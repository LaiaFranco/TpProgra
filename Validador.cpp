#include "Validador.h"


Validador::Validador(){}

bool Validador::ValidarTamanios(std::string atributo,int tamanio){
    if(atributo.size() <= tamanio){
            return true;
    }
    return false;
}

bool Validador::ValidarTamDni(std::string dni){
    if(dni.size() == 8){
        return true;
    }else{
    return false;
    }
}

bool Validador::ValidarContrasenias(std::string contrasenia, int tam ){
    if(contrasenia.size() == tam){
        return true;
    }else{
        return false;
    }
}


