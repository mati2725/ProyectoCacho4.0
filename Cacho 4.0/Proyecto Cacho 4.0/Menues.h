#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

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

int MenuCandy(){
    int opcion;
    cin>>opcion;
    return opcion;
}

#endif // MENUES_H_INCLUDED
