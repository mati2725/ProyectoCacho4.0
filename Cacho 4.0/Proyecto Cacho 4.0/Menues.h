#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

#include "Suscriptores.h"

int MenuPrincipal(){
    int opcion;
    cout<<"1- MENU DEL CANDY"<<endl;
    cout<<"2- MENU DEL CINE"<<endl;
    cout<<"3- SUSCRIPTORES"<<endl;
    cout<<"4- PERSONAL"<<endl;
    cout<<"5- CONFIGURACIONES"<<endl;
    cout<<"6- MENU INFORMES"<<endl<<endl;
    cin>>opcion;
    return opcion;
}

void MenuSuscriptores(){

int Opcion;

cout << "1- NUEVO SUSCRIPTOR" << endl;
cout << "2- ELIMINAR SUSCRIPTOR" << endl;
cout << "3- LISTAR SUSCRIPTORES" << endl;
cout << "4- CONSULTAR SUSCRIPTOR" << endl;
cout << "5- GESTIONAR CANJES DE SUSCRIPTORES" << endl;
cout << "6- GESTIONAR BENEFICIOS" << endl;

cin >> Opcion;

switch(Opcion){

case 1:
    {Cliente reg;
    if(reg.Cargar()){
        reg.Grabar();
    }}
    break;

case 2:
    {
        system("cls");
        int dni;

    cout << "INGRESE NUMERO DE DNI: ";
    cin >> dni;

    if(EliminarSuscriptor(dni)){
        cout << "Suscriptor eliminado"<< endl;
    }
    else {cout << "No se pudo eliminar suscriptor" << endl;}
    }
    break;

case 3:
    break;

case 4:
    break;

case 5:
    break;

case 6:
    break;
}

}


#endif // MENUES_H_INCLUDED
