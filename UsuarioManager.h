#pragma once
#include "UsuarioArchivo.h"
#include "Usuario.h"
#include "Fecha.h"
#include "Validador.h"
#include<string>

class UsuarioManager{
public:
    UsuarioManager();

    void InicializarSistema();
    void CrearUsuario();
    std::string getObtenerRol();
    int Login(std::string usuario, std::string contrasenia);

    void MostrarUsuario(Usuario registro);
    void EliminarUsuario();

    void ModificarUsuario(int opcion);
    void MostrarActualizacion(bool ok,Usuario registro);

    void ListarUsuarios(int opcion);



protected:
    std::string CargarCadena();
    void OrdenarVecApellido(Usuario vec[],int tam); ///devuelve un puntero al vector ordebnado

private:
    UsuarioArchivo _UserArchi;
    Fecha _fecha;
    Validador _validar;
    std::string vecRoles[2] = {"Administrador","Vendedor"};
};
