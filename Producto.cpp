#include "Producto.h"
#include<cstring>

Producto::Producto(){
    strcpy(_idProducto,"");
    _numerocategoria = 0;
    strcpy(_cuitProveedor,"");
    strcpy(_nombre,"");
    _precioCompra = 0.0;
    _precioVenta = 0.0;
    _stock = 0.0;
    _estado = false;
}

Producto::Producto(std::string id,std::string cuit,std::string nombre, int categoria,float precioCompra,float precioVenta,float stock, bool estado){
    setIdProducto(id);
    setCuitProveedor(cuit);
    setNombre(nombre);
    setCategoria(categoria);
    setPrecioCompra(precioCompra);
    setPrecioVenta(precioVenta);
    setStock(stock);
    setEstado(estado);
}

std::string Producto::getIdProducto(){
return _idProducto;}
int Producto::getCategoria(){
return _numerocategoria;}
std::string Producto::getCuitProveedor(){
return _cuitProveedor;}
std::string Producto::getNombre(){
return _nombre;}
float Producto::getPrecioCompra(){
return _precioCompra;}
float Producto::getPrecioVenta(){
return _precioVenta;}
float Producto::getStock(){
return _stock;}
bool Producto::getEstado(){
return _estado;}

void Producto::setIdProducto(std::string  id){
    if(sizeof(id) <= 15){
        strncpy(_idProducto,id.c_str(),14);
        _idProducto[14] = '\0';
    }
}
void Producto::setCuitProveedor(std::string cuit){
    if(sizeof(cuit) <= 13){
        strncpy(_cuitProveedor,cuit.c_str(),12);
        _cuitProveedor[12] = '\0';
    }
}
void Producto::setNombre(std::string nombre){
    if(sizeof(nombre) <= 13){
        strncpy(_nombre,nombre.c_str(),12);
        _nombre[12] = '\0';
    }
}
void Producto::setCategoria(int categoria){
    _numerocategoria = categoria;
}
void Producto::setPrecioCompra(float precioCompra){
    _precioCompra = precioCompra;
}
void Producto::setPrecioVenta(float precioVenta){
    _precioVenta = precioVenta;
}
void Producto::setStock(float stock){
    _stock = stock;
}
void Producto::setEstado(bool estado){
    _estado = estado;
}


