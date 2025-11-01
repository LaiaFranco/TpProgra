#include "UsuarioManager.h"
#include <iostream>

using namespace std;
UsuarioManager::UsuarioManager(){
}
string UsuarioManager::CargarCadena(){
    string texto;
    if(cin.peek()=='\n'){
        cin.ignore();
    }
    getline(cin,texto);
    return texto;
}
void UsuarioManager::InicializarSistema(){
    int cantidadRegistros = _UserArchi.getCantidadRegistro();
    if(cantidadRegistros ==0){
        cout<<endl<<endl<<"||       No hay usuarios registrados en el sistema... ||"<<endl;
        cout<<"||       Debe crear el primer usuario Administrador.  ||" <<endl<<endl;
        system("pause");
        system("cls");
        cout<<"    Hola Administrador del sistema!!."<<endl;
        cout<<"    A continuacion le dejamos los pasos para registrarse"<<endl;
        cout<<"    Esperamos disfrute la experiencia prueba beta de nustro sistema de gestion..."<<endl;
        system("pause");
        system("cls");
        CrearUsuario();
    }


}
string UsuarioManager::getObtenerRol(){

    int opcion;

    cout<<"== OPCIONES DE ROLES"<<endl;
    cout<<endl<<"1.ADMINISTRADOR"<<endl;
    cout<<"2.VENDEDOR"<<endl;

    cout<<endl;
    cout<<"Opcion: ";
    cin>> opcion;

    return vecRoles[opcion-1];
}

void UsuarioManager::CrearUsuario(){
    Usuario user;
    int legajo;
    string usuario,contrasenia,rol;
    Persona persona;
    int dia,mes,anio;
    int edad;
    std::string nombre, apellido,dni,direccion,telefono,mail;
    bool estado;

    cout<<"---CREAR NUEVO USUARIO"<<endl;
    legajo = _UserArchi.getLegajoNuevo();
    cout<<"NOMBRE: ";
    nombre = CargarCadena();
    cout<<"APELLIDO: ";
    apellido = CargarCadena();
    cout<<"DNI: ";
    dni = CargarCadena();
    if(_UserArchi.ValidarDni(dni)){
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

    persona = Persona(nombre,apellido,dni,direccion,telefono,mail,Fecha(dia,mes,anio),edad,true);
    system("pause");
    system("cls");
    cout<<"---DEFINIR NOMBRE DE USUARIO Y CONTRASENIA"<<endl;
    cout<<"USUARIO: "<<dni;
    usuario = dni;

    cout<<endl<<"CONTRASENIA(solo 6 caracteres): ";
    contrasenia = CargarCadena();
    while(contrasenia.size() != 6){
        cout<<"ERROR.La contrasenia debe contener 6 digitos (numeros o letras)..."<<endl;

        cout<<endl<<"CONTRASENIA(solo 6 caracteres): ";
        contrasenia = CargarCadena();
        if(contrasenia.size() == 6){
            break;
        }
    }
    system("pause");
    system("cls");

    string contrasenia2;

    cout<<"REPETIR CONTRASENIA: ";
    contrasenia2 = CargarCadena();
    if(contrasenia == contrasenia2){
        cout<<"Contrasenia establecida correctamente!!"<<endl;
                system("pause");
                system("cls");

    }else {
        for(int i=0;i<3;i++){
                cout<<"Contrasenia incorrecta"<<endl;
                cout<<"REPETIR CONTRASENIA: ";
                contrasenia2 = CargarCadena();

                if(contrasenia == contrasenia2){
                cout<<"Contrasenia establecida correctamente!!"<<endl;
                break;

                }
        if(i==2){
            system("cls");
            system("pause");
            cout<<"Vuelva a intentarlo mas tarde..."<<endl;
            return;
            }
        system("pause");
        system("cls");

    }
    }

    cout<<"ROL: "<<endl;
    rol =  getObtenerRol();

    user = Usuario(legajo,usuario,contrasenia,rol,persona);
    if(_UserArchi.guardar(user)){
        cout<<"Se guardo correctamente.."<<endl;
    }else{
        cout<<"Hubo un error, no se pudo guardar.."<<endl;
    }

}

int UsuarioManager::Login(string usuario, string contrasenia){

    system ("pause"); ///nos va a devolver 1,2 o cero
    system ("cls");

    int cantidadReg = _UserArchi.getCantidadRegistro();
    Usuario *vecUsuarios = new Usuario[cantidadReg];

    for(int i=0;i<cantidadReg; i++){
            if(vecUsuarios[i].getUsuario() == usuario and vecUsuarios[i].getContrasenia() == contrasenia and vecUsuarios[i].getPersona().getEstado()== true){
                if(vecUsuarios[i].getRol() == vecRoles[0]){
                    return 1;
                }else if(vecUsuarios[i].getRol() == vecRoles[1]){
                    return 2;
                }
            }else{
                return 0;
            }
    }
    delete[]vecUsuarios;
    return 0;

}


void UsuarioManager::MostrarUsuario(Usuario registro){
    cout<<"== DATOS DE USUARIO === "<<endl;
    cout<<"ROL: "<<registro.getRol()<<endl;
    cout<<"USUARIO: "<<registro.getUsuario();
    cout<<endl<<"CONSTRASENIA: "<<registro.getContrasenia()<<endl;
    cout<<endl;

    cout<<endl<<"---DATOS PEROSNALES"<<std::endl<<std::endl;
    cout<<"LEGAJO: "<<registro.getLegajo()<<std::endl;
    cout<<"NOMBRE: "<<registro.getPersona().getNombre()<<std::endl;
    cout<<"APELLIDO: "<<registro.getPersona().getApellido()<<std::endl;
    cout<<"DNI: "<<registro.getPersona().getDni() <<std::endl;
    cout<<"EDAD: "<<registro.getPersona().getEdad()<<endl;
    cout<<"DIRECCION: "<<registro.getPersona().getDireccion()<<std::endl;
    cout<<"TELEFONO: "<<registro.getPersona().getTelefono()<<std::endl;
    cout<<"MAIL: "<<registro.getPersona().getMail()<<std::endl;

}
void UsuarioManager::EliminarUsuario(){
    int legajo;
    char opcion;
    bool ok;
    Usuario registro;

    cout<<"INGRESE LEGAJO: ";
    cin>>legajo;
    int pos = _UserArchi.buscarLegajo(legajo);
    system("pause");
    system("cls");
    cout<<"ESTA SEGURO QUE DESEA ELIMINARLO? (S/N) :";
    cin>>opcion;
    if(opcion == 's' or opcion == 'S'){
            ok =  _UserArchi.eliminar(pos);
            registro = _UserArchi.leer(pos);
            MostrarActualizacion(ok,registro);
    }
}
void UsuarioManager::MostrarActualizacion(bool ok,Usuario registro){
    if(ok){
        cout<<"ACTUALIZACION"<<endl;
            cout<<"SE MODIFICO CORRECTAMENTE"<<endl;
            cout<<"---------"<<endl;
            MostrarUsuario(registro);
        }else{
            cout<<"ALGO SALIO MAL, NO SE PUDO MODIFICAR..."<<endl;
        }
}


void UsuarioManager::ModificarUsuario(int opcion){
    int legajo;
    bool ok;
    Usuario registro;
    cout<<"INGRESE LEGAJO DEL EMPLEADO: ";
    cin>>legajo;

    int pos = _UserArchi.buscarLegajo(legajo);
    if(pos < 0){
        cout<<"EL LEGAJO INGRESADO NO EXISTE..."<<endl;
        return;
    }
    registro = _UserArchi.leer(pos);
    MostrarUsuario(registro);
    cout<<endl;
    switch(opcion){
    case 1:{
        string  rol;
        rol = getObtenerRol();
        registro.setRol(rol);
        ok =_UserArchi.guardar(pos,registro);
        MostrarActualizacion(ok,registro);
        break;
    }
    case 2:{
        string telefono;
        cout<<"TELEFONO NUEVO: ";
        telefono = CargarCadena();
        registro.getPersona().setTelefono(telefono);
        ok = _UserArchi.guardar(pos,registro);
        MostrarActualizacion(ok,registro);
        break;
    }
    case 3:{
        string direccion;
        cout<<"DIRECCION NUEVA: ";
        direccion = CargarCadena();
        registro.getPersona().setDireccion(direccion);
        ok = _UserArchi.guardar(pos,registro);
        MostrarActualizacion(ok,registro);
        break;
    }
    case 4:{
        string mail;
        cout<<"MAIL NUEVO: ";
        mail = CargarCadena();
        registro.getPersona().setMail(mail);
        ok = _UserArchi.guardar(pos,registro);
        MostrarActualizacion(ok,registro);
        break;
    }
    }
}
void UsuarioManager::ListarUsuarios(int opcion){
    int cantidadRegistros = _UserArchi.getCantidadRegistro();
    Usuario *vecRegistros = new Usuario[cantidadRegistros;


    _UserArchi.LeerTodos(vecRegistros,cantidadRegistros);

    int cantidaActivos = 0;
    for(int i=0;i<cantidadRegistros;i++){
        if(vecRegistros[i].getPersona().getEstado() == true){
            cantidaActivos++;
        }
    }

    Usuario *vecActivos = new Usuario[cantidaActivos];
    int contador = 0;
    for(int i=0;i<cantidadRegistros;i++){
            if(vecRegistros[i].getPersona().getEstado() == true){
                vecActivos[contador] = vecRegistros[i];
                contador++;
            }
    }

    switch(opcion){
    case 1: {
    for(int i=0; i<cantidadRegistros;i++){
      bool intercambio = false;
        for(int j=0;j<cantidadRegistros - 1 -i;j++){
            if(vecRegistros[j].getPersona().getApellido() > vecRegistros[j+1].getPersona().getApellido()){
                Usuario aux = vecRegistros[j];
                vecRegistros[j] = vecRegistros[j+1];
                vecRegistros[j+1] = aux;
                intercambio = true;
            }
        }
        if(!intercambio){
            break;
        }
    }
    for(int i=0;i<cantidad;i++){
        MostrarCliente(vecRegistros[i]);
        cout<<"-----------------"<<endl;
    }
    break;
    }

    case 2:{
        OrdenarVecApellido(vecActivos,cantidaActivos);
        for(int i=0;i<cantidaActivos;i++){
            MostrarUsuario(vecActivos[i]);
            cout<<"______________________________"<<endl;
        }
        delete[]vecRegistros;
        delete []vecActivos;
        break;
    }
    case 3:{
        for(int i=0; i<cantidadRegistros;i++){
        bool intercambio = false;
        for(int j=0;j<cantidadRegistros - 1 -i;j++){
            if(vecRegistros[j].getPersona().getEdad() > vecRegistros[j+1].getPersona().getEdad()){
                Usuario aux = vecRegistros[j];
                vecRegistros[j] = vecRegistros[j+1];
                vecRegistros[j+1] = aux;
                intercambio = true;
            }
        }
        if(!intercambio){
            break;
        }
    }
    for(int i=0;i<cantidadRegistros;i++){
        MostrarCliente(vecRegistros[i]);
        cout<<"-----------------"<<endl;
    }








    delete[]vecRegistros;
    break;
    }

}

Usuario *UsuarioManager::OrdenarVecApellido(Usuario vec[],int tam){
     for(int i=0; i<tam;i++){
        bool intercambio = false;
        for(int j=0;j<tam - 1 -i;j++){
            if(vec > vec[j+1].getPersona().getNombre()){
                Usuario aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
                intercambio = true;
            }
        }
        if(!intercambio){
            break;
        }
    }
        return vec;
}
