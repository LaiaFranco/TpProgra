#pragma once
#include<string>
#include "UsuarioManager.h"
#include "ClienteManager.h"
#include "Validador.h"
#include "SubMenu.h"

class Menu{
public:
    Menu();
    void MostrarMenuPrincipal();
    void MenuRol(int rol);
    void MenuAdministrador();
    void OpcionMenuAdministrador(int opcion);

    void MenuGestionUsuarios();
    void OpcionGestionUsuarios(int opcion);


protected:
    std::string CargarCadena();
    void MostrarEncabezdoLogin();

private:
    UsuarioManager _userMan;
    Validador _validador;
    SubMenu _subMenu;


};
