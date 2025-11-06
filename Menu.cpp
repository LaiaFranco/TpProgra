#include "Menu.h"
#include<iostream>

using namespace std;

Menu::Menu(){}
string Menu::CargarCadena(){
    string texto;
    if(cin.peek()=='\n'){
        cin.ignore();
    }
    getline(cin,texto);
    return texto;
}

void Menu::MostrarMenuPrincipal(){
    cout<<"||  BIENVENIDO  ||"<<endl;

    system("pause");
    system("cls");
    int opcion;

    while(true){
        _userMan.InicializarSistema();
        MostrarEncabezdoLogin();

    string usuario;
    string contrasenia;
    int rol;

    for(int i = 0; i < 3; i++){

    cout<<endl<<endl;
    cout<<"||USUARIO: ";
    usuario = CargarCadena();
    cout<<"||CONTRASENIA: ";
    contrasenia = CargarCadena();

    if(!(_validador.ValidarContrasenias(contrasenia) and _validador.ValidarTamDni(usuario))){
           cout<<endl<<"USUARIO Y/O CONTRASENIA INCORRECTO ''( "<<endl;

    }else{
        rol = _userMan.Login(usuario,contrasenia);

        if(rol == 1 or rol == 2){
            MenuRol(rol);
            break;
        }

        MostrarEncabezdoLogin();
        cout<<endl<<"USUARIO Y/O CONTRASENIA INCORRECTO ;( "<<endl;
            if(i == 2){
                cout<<"Usuario bloqueado temporalmente.Vuelva a intentarlo mas tarde..."<<endl<<endl;
                system("pause");
                system("cls");
                return;
            }
    }
    }
        system("pause");
        system("cls");
        MostrarEncabezdoLogin();
    }

}
void Menu::MenuRol(int rol){
    if(rol == 1){
        MenuAdministrador();
    }else if(rol == 2){
        ///aca comienza la venta;
    }
}

void Menu::MenuAdministrador(){
    int opcion;
    do{
            system("cls");
        cout<<"                  -- MENU ADMINISTRADOR --                "<<endl;
        cout<<endl;
        cout<<" ........................... ...........................  "<<endl;
        cout<<"|| 1.GESTION DE USUARIOS   | | 2.GESTION DE PRODUCTOS  || "<<endl;
        cout<<" ........................... ...........................  "<<endl;
        cout<<" ........................... ...........................  "<<endl;
        cout<<"|| 3.GESTION DE CATEGORIAS | | 4.GESTION DE VENTAS     || "<<endl;
        cout<<" ........................... ...........................  "<<endl;
        cout<<" ........................... ...........................  "<<endl;
        cout<<"|| 5.GESTION DE DESCUENTOS | | 6.REPORTES              || "<<endl;
        cout<<" ........................... ...........................  "<<endl;
        cout<<" ........................... ...........................  "<<endl;
        cout<<"|| 7.CONFIGURACION         | | 0.SALIR                 || "<<endl;
        cout<<" ........................... ...........................  "<<endl;
        cout<<endl;
        cout<<"_OPCION: ";
        cin>>opcion;

        OpcionMenuAdministrador(opcion);

    }while(opcion != 0);

}
void Menu::MostrarEncabezdoLogin(){
    system("cls");
    cout<<"................................... "<<endl;
    cout<<"||        INICIO DE SESION       || "<<endl;
    cout<<"................................... "<<endl;

}
void Menu::OpcionMenuAdministrador(int opcion){
    switch(opcion){
    case 1:
        MenuGestionUsuarios();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 0:
        cout<<"Saliendo..."<<endl;
        break;
    }

}

void Menu::MenuGestionUsuarios(){
   int opcion;
   do{
   cout<<" == GESTION DE USARIOS =="<<endl;
    cout<<"1. ALTA USUARIO    "<<endl;
    cout<<"2. MODIFICAR USUARIO "<<endl;
    cout<<"3. ELIMINAR USUARIO" <<endl;
    cout<<"4. LISTAR USUARIOS" <<endl;
    cout<<"5. BUSCAR USUARIO POR LEGAJO"<<endl;
    cout<<"0.SALIR  "<<endl;

    cout<<endl<<"OPCION: ";
    cin>>opcion;

    OpcionGestionUsuarios(opcion);
    }while(opcion !=0);

}

void Menu::OpcionGestionUsuarios(int opcion){
    switch(opcion){
    case 1:{
        system("pause");
        system("cls");
        _userMan.CrearUsuario();
        break;
    }
    case 2:{
        system("pause");
        system("cls");
        int opc;
        opc = _subMenu.SubMenuModificar();
        _userMan.ModificarUsuario(opc);
        break;
    }
    case 3:{
        system("pause");
        system("cls");
        _userMan.EliminarUsuario();
        break;
    }
    case 4:{
        system("pause");
        system("cls");
        //_userMan.ListarUsuarios();
    }
    case 5:

        break;
    case 0:
        cout<<"Saliendo..."<<endl;
        break;

    }
}
