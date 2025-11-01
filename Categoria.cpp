#include "Categoria.h"
#include<cstring>
#include<iostream>

Categoria::Categoria()
:_numeroCategoria(0){
    strcpy(_nombre,"");
    strcpy(_descripcion,"");
}
Categoria::Categoria(int numero, std::string nombre,std::string descripcion){
    setNumeroCategoria(numero);
    setNombre(nombre);
    setDescripcioon(descripcion);
}

int Categoria::getNumeroCategoria(){
return _numeroCategoria;}
std::string Categoria::getNombre(){
return _nombre;}
std::string Categoria::getDescripcion(){
return _descripcion;}
bool Categoria::getEstado(){
return _estado;}

void Categoria::setNumeroCategoria(int numero){
    _numeroCategoria = numero;
}
void Categoria::setNombre(std::string nombre){
    if(sizeof(nombre) <= 30){
        strncpy(_nombre,nombre.c_str(),29);
        _nombre[29] = '\0';
    }
}
void Categoria::setDescripcioon(std::string descripcion){
    if(sizeof(descripcion) <= 100){
        strncpy(_descripcion,descripcion.c_str(),99);
        _descripcion[99] = '\0';
    }
}
bool Categoria::setEstado(bool estado){
    _estado = estado;
}

void Categoria::Mostrar(){
    std::cout<<"--DATOS DE LA CATEGORIA"<<std::endl<<std::endl;
    std::cout<<"NUMERO: "<<getNumeroCategoria()<<std::endl;
    std::cout<<"NOMBRE: "<<getNombre()<<std::endl;
    std::cout<<"DESCRIPCION: "<<getDescripcion()<<std::endl;
}



