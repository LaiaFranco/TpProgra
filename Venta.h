#pragma once
#include<string>
#include "Fecha.h"

class Venta{
public:
    Venta();
    Venta(int numero,int legajo,std::string dni,Fecha fecha,float total);

    int getNumTransaccion();
    int getLegajoEmpleado();
    std::string getDniCliente();
    Fecha getFecha();
    float getTotal();

    void setNumTransaccion(int numero);
    void setLegajoEmpleado(int legajo);
    void setDniCliente(std::string dni);
    void setFecha(Fecha fecha);
    void setTotal(float total);

    void Mostrar();

private:
   int _numeroTransaccion;
   int _legajoEmpleado;
   char _dniCliente[10];
   Fecha _fecha;
   float _total;

};
