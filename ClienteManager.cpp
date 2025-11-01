#include "ClienteManager.h"
#include <cstring>
#include <iostream>
#include<limits>

using namespace std;
ClienteManager::ClienteManager(){
}

string ClienteManager::CargarCadena(){
    string texto;
    if(cin.peek()=='\n'){
        cin.ignore();
    }
    getline(cin,texto);
    return texto;
}

void ClienteManager::AgregarCliente(){
    Cliente registro;
    int id,dia,mes,anio;
    int edad;
    std::string nombre, apellido,dni,direccion,telefono,mail;
    bool estado;

    id = _cArchi.getIdNuevo();
    cout<<"NOMBRE: ";
    nombre = CargarCadena();
    cout<<"APELLIDO: ";
    apellido = CargarCadena();
    cout<<"DNI: ";
    dni = CargarCadena();
    if(_cArchi.ValidarDni(dni)){
        cout<<"DNI INCORRECTO.Numero ya registrado..."<<endl;
        return;
    }
    cout<<"FECHA DE NACIMINETO "<<endl;
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
    if(!_fecha.validarFecha(dia,mes,anio)){
        cout<<"Fecha inexistente..."<<endl;
        return;
    }
    edad = _fecha.ObtenerEdad(dia,mes,anio);
    cout<<"EDAD: "<<edad<<endl;
    cout<<"DIRECCION: ";
    direccion = CargarCadena();
    cout<<"TELEFONO: ";
    telefono = CargarCadena();
    cout<<"MAIL: ";
    mail = CargarCadena();

    registro = Cliente(nombre,apellido,dni,direccion,telefono,mail,Fecha(dia,mes,anio),edad,true,id);

    if(_cArchi.guardar(registro)){
        cout<<"Se guardo exitosamente!."<<endl;
    }else{
        cout<<"Ocurrio un error, no se pudo guardar correctamente."<<endl;
        cout<<"Vuelvalo a intentar mas tarde..."<<endl;
    }
}

void ClienteManager::EliminarCliente(){
    int id;
    char eliminado;
    Cliente cliente;

    cout<<"--- ELIMINAR CLIENTE "<<endl;
    cout<<"Ingresar id de cliente a eliminar: ";
    cin>>id;

    cliente = _cArchi.leer(id -1);
    cout<<"Datos del cliente: "<<endl;
    MostrarCliente(cliente);
    cout<<endl<<"Eliminar? S/N: ";
    cin>>eliminado;

    if(eliminado == 's' or eliminado == 'S'){
        cliente.setEstado(false);
    }else{
        cliente.setEstado(true);
    }

    if(_cArchi.eliminar(id-1)){
        cout<<"La tarea fue eliminada correctamente..."<<endl;
    }else{
        cout<<"Hubo un error en la eliminacion..."<<endl;
    }

}

void ClienteManager::SubMenuListRegistros(){
    int opcion;
    while(true){
    cout<<"--TIPOS DE LISTADOS DE CLIENTES "<<endl;
    cout<<"1.LISTAR POR APELLIDO" <<endl;
    cout<<"2.LISTAR POR NOMBRE"<<endl;
    cout<<"3.LISTAR POR EDAD"<<endl;
    cout<<"0.SALIR"<<endl;

    cout<<endl<<"OPCION: ";
    cin>>opcion;

    if(opcion >= 0 and opcion <=3){
    ListadoOpcion(opcion);
    }else{
        system("cls");
        cout<<"Opcion Incorrecta..."<<endl<<endl;
        system("pause");
        system("cls");
    }
    }
}


void ClienteManager::ListadoOpcion(int opcion){
    switch(opcion){
    case 1:{
        listarPorApellido();
        break;
    }
    case 2:{
        listarPorNombre();
        break;
    }
    case 3:{
        listarPorEdad();
        break;
    }
    case 0:{
        cout<<"Saliendo..."<<endl;
        break;
    }
    }
}

void ClienteManager::listarPorApellido(){
    int cantidad = _cArchi.getCantidadRegistro();
    Cliente *clientes = new Cliente[cantidad];

    _cArchi.LeerTodos(clientes,cantidad);

    for(int i=0;i<cantidad;i++){
        bool intercambio = false;
        for(int j=0;j<cantidad - 1 -i;j++){
            if(clientes[j].getApellido() > clientes[j+1].getApellido()){
                Cliente aux = clientes[j];
                clientes[j] = clientes[j+1];
                clientes[j+1] = aux;
                intercambio = true;
            }
        }
        if(!intercambio){
            break;
        }
    }
    for(int i=0;i<cantidad;i++){
        MostrarCliente(clientes[i]);
        cout<<"-----------------"<<endl;
    }
}
void ClienteManager::listarPorNombre(){
    int cantidad = _cArchi.getCantidadRegistro();
    Cliente *clientes = new Cliente[cantidad];

    _cArchi.LeerTodos(clientes,cantidad);

    for(int i=0;i<cantidad;i++){
        bool intercambio = false;
        for(int j=0;j<cantidad - 1 -i;j++){
            if(clientes[j].getNombre() > clientes[j+1].getNombre()){
                Cliente aux = clientes[j];
                clientes[j] = clientes[j+1];
                clientes[j+1] = aux;
                intercambio = true;
            }
        }
        if(!intercambio){
            break;
        }
    }

    for(int i=0;i<cantidad;i++){
        MostrarCliente(clientes[i]);
        cout<<"-----------------"<<endl;
    }
}
void ClienteManager::listarPorEdad(){
    int cantidad = _cArchi.getCantidadRegistro();
    Cliente *clientes = new Cliente[cantidad];

    _cArchi.LeerTodos(clientes,cantidad);

    for(int i=0;i<cantidad;i++){
        bool intercambio = false;
        for(int j=0;j<cantidad - 1 -i;j++){
            if(clientes[j].getEdad() > clientes[j+1].getEdad()){
                Cliente aux = clientes[j];
                clientes[j] = clientes[j+1];
                clientes[j+1] = aux;
                intercambio = true;
            }
        }
        if(!intercambio){
            break;
        }
    }

    for(int i=0;i<cantidad;i++){
        MostrarCliente(clientes[i]);
        cout<<"-----------------"<<endl;
    }
}
Cliente ClienteManager::buscarPorDni(){
    string dni;

    cout<<"INGRESE DNI DEL CLIENTE: ";
    dni = CargarCadena();

    bool validacion = _validar.ValidarTamDni(dni);


    while(validacion == false){
       cout<<"INGRESE NUEVAMENTE EL DNI: ";
       dni = CargarCadena();
       validacion = _validar.ValidarTamDni(dni);
    }

    int pos = _cArchi.buscarDni(dni);

    if(pos < 0){
        return Cliente();
    }else{
    Cliente registro =_cArchi.leer(pos);
    return registro;
    }
}

void ClienteManager::MostrarCliente(Cliente cliente){
    std::cout<<"---DATOS DEL CLIENTE"<<std::endl<<std::endl;
    std::cout<<"ID: "<<cliente.getIdCliente()<<std::endl;
    std::cout<<"NOMBRE: "<<cliente.getNombre()<<std::endl;
    std::cout<<"APELLIDO: "<<cliente.getApellido()<<std::endl;
    std::cout<<"DNI: "<<cliente.getDni() <<std::endl;
    std::cout<<"EDAD: "<<cliente.getEdad()<<endl;
    std::cout<<"DIRECCION: "<<cliente.getDireccion()<<std::endl;
    std::cout<<"TELEFONO: "<<cliente.getTelefono()<<std::endl;
    std::cout<<"MAIL: "<<cliente.getMail()<<std::endl;
}
