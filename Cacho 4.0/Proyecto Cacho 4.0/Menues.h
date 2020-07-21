#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

int MenuPrincipal(){
    int opcion;
    cout<<"1- MENU DEL CANDY"<<endl;
    cout<<"2- MENU DEL CINE"<<endl;
    cout<<"3- SUSCRIPTORES"<<endl;
    cout<<"4- PERSONAL"<<endl;
    cout<<"5- CONFIGURACIONES"<<endl;
    cout<<"6- MENU INFORMES"<<endl;
    cout<<"0- SALIR"<<endl<<endl;
    cout<<"OPCION: ";
    cin>>opcion;
    system("cls");
    return opcion;
}

void MenuGestionCandy(){
    int opcion;
    while(true){
        cout<<"1- AGREGAR PRODUCTO"<<endl;
        cout<<"2- MODIFICAR PRODUCTO"<<endl;
        cout<<"3- ELIMINAR PRODUCTO"<<endl;
        cout<<"4- LISTAR PRODUCTOS"<<endl;
        cout<<"0- VOLVER"<<endl<<endl;
        cout<<"OPCION: ";
        cin>>opcion;
        system("cls");
        switch(opcion){
        case 1:
            AgregarCandy();
            break;
        case 2:
            ElegirProductoCandy();
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            return;
            break;
        }
    }
}
void MenuCandy(){
    int opcion;
    while(true){
        cout<<"1- AGREGAR VENTA"<<endl;
        cout<<"2- GESTION CANDY"<<endl;
        cout<<"0- VOLVER"<<endl<<endl;
        cout<<"OPCION: ";
        cin>>opcion;
        system("cls");
        switch(opcion){
        case 1:
            break;
        case 2:
            MenuGestionCandy();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"OPCION INVALIDA"<<endl;
            break;
        }
    }
    return;
}

#endif // MENUES_H_INCLUDED
