#pragma once
#include<string>

class Producto{
public:
    Producto();
    Producto(std::string id,std::string cuit,std::string nombre, int categoria,float precioCompra,float precioVenta,float stock, bool estado);

    std::string getIdProducto();
    int getCategoria();
    std::string getCuitProveedor();
    std::string getNombre();
    float getPrecioCompra();
    float getPrecioVenta();
    float getStock();
    bool getEstado();

    void setIdProducto(std::string id);
    void setCuitProveedor(std::string cuit);
    void setNombre(std::string nombre);
    void setCategoria(int  categoria);
    void setPrecioCompra(float precioCompra);
    void setPrecioVenta(float precioVenta);
    void setStock(float stock);
    void setEstado(bool estado);


private:
    char _idProducto[15];
    char _cuitProveedor[13];
    char _nombre[50];
    int _numerocategoria;
    float _precioCompra;
    float _precioVenta;
    float _stock;
    bool _estado;

};
