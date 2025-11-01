#pragma once
#include"Producto.h"

class ProductoArchivo{

public:
    ProductoArchivo(std::string nombre = "Productos.dat");

    bool guardar(Producto registro);
    bool guardar(int pos, Producto registro);
    bool eliminar(int pos);

    Producto leer(int pos);

    int getLegajoNuevo();
    int getCantidadRegistro();
    int LeerTodos(Producto registros[], int cantidad);
    int buscarIdProducto(std::string id);


private:
    std::string _nombreArchivo;

};
