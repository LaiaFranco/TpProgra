#include "SubMenu.h"
#include <iostream>

using namespace std;
SubMenu::SubMenu(){

}

int SubMenu::SubMenuModificar(){
    int opcion;
    system("cls");
    cout<<"QUE DESEA MODIFICAR? "<<endl;
    cout<<"1.ROL"<<endl;
    cout<<"2.TELEFONO"<<endl;
    cout<<"3.DIRECCION"<<endl;
    cout<<"4.MAIL"<<endl;

    cout<<endl<<"OPCION: ";
    cin>>opcion;

    return opcion;
}
