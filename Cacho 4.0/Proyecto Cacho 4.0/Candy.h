#ifndef CANDY_H_INCLUDED
#define CANDY_H_INCLUDED


class ProductoCandy{
private:
	int Id;
	char Nombre[50];
	float Precio;
	bool Estado;
public:
    ProductoCandy(){
        strcpy(Nombre," ");
	    Precio=0;
        Estado=false;
    }
	int GetId(){
        return Id;
	}
	char* GetNombre(){
        return Nombre;
	}
	float GetPrecio(){
        return Precio;
	}
	bool GetEstado(){
        return Estado;
	}
	void SetEstado(bool x){
        Estado=x;
	}
	void SetId(int x){
        Id=x;
	}
	void SetNombre(char* x){
        strcpy(Nombre,x);
	}
	void SetPrecio(float x){
        Precio=x;
	}
	void Cargar(int numero, char nomb[50],float prec){
	    Id=numero;
	    strcpy(Nombre,nomb);
	    Precio=prec;
	    Estado=true;
    }
	bool Grabar(){
        FILE *p;
        p=fopen("Productos Candy.dat","ab");
        fwrite(this,sizeof(ProductoCandy),1,p);
        fclose(p);
        return true;
	}
};

int ContarProductosCandy(){
    FILE *p;
    p=fopen("Productos Candy.dat","rb");
    if(p==NULL) return 0;
    ProductoCandy reg;
    int c=0;
    while(fread(&reg,sizeof(ProductoCandy),1,p)==1){
        c++;
    }
    fclose(p);
    return c;
}
int ContarProductosCandyACTIVOS(){
    FILE *p;
    p=fopen("Productos Candy.dat","rb");
    if(p==NULL) return 0;
    ProductoCandy reg;
    int c=0;
    while(fread(&reg,sizeof(ProductoCandy),1,p)==1){
            if(reg.GetEstado()) c++;
    }
    fclose(p);
    return c;
}
bool LlenarVectorProductos(ProductoCandy *vec, int tam){
    FILE *p;
    p=fopen("Productos Candy.dat","rb");
    if(p==NULL) return false;
    ProductoCandy reg;
    int i=0;
    while(fread(&reg,sizeof(ProductoCandy),1,p)==1){
        if(reg.GetEstado()){
            vec[i]=reg;
            i++;
        }
    }
    fclose(p);
    return true;
}

bool AgregarCandy(){
    int ID=ContarProductosCandy();
    char nombre[50];
    float precio;
    cout<<"ID: "<<ID<<endl;
    cout<<"NOMBRE: ";
    cin>>nombre;
    cout<<"PRECIO: ";
    cin>>precio;
    cout<<endl<<"CONFIRMAR PRODUCTO?  (1-SI , 2-NO)"<<endl;
    cout<<"OPCION: ";
    while(true){
        int opc;
        cin>>opc;
        system("cls");
        if(opc==1){
            ProductoCandy reg;
            reg.Cargar(ID,nombre,precio);
            if(reg.Grabar())return true;
            exit(-1);
        } else if (opc == 2){
            return false;
        } else{
            cout<<"OPCION INVALIDA"<<endl<<endl;
            cout<<"ID: "<<ID<<endl;
            cout<<"NOMBRE: "<<nombre<<endl;
            cout<<"PRECIO: "<<precio<<endl<<endl;
            cout<<"CONFIRMAR PRODUCTO?  (1-SI , 2-NO)"<<endl;
            cout<<"OPCION: ";
        }
    }
}

void MostrarProductosCandy(ProductoCandy *vec,int tam){
    for(int i=0;i<tam;i++){
        cout<<"ID: "<<setw(5)<<vec[i].GetId()<<"NOMBRE: "<<setw(60)<<vec[i].GetNombre()<<"PRECIO: "<<vec[i].GetPrecio()<<endl;
    }
}

ProductoCandy ElegirProductoCandy(){
    int tam = ContarProductosCandyACTIVOS();
    ProductoCandy reg,*vec;
    vec = new ProductoCandy [tam];
    LlenarVectorProductos(vec,tam);

    while(true){
        int opc;
        MostrarProductosCandy(vec,tam);
        cout<<endl<<"ELEGIR PRODUCTO: ";
        cin>>opc;
    }
}

#endif // CANDY_H_INCLUDED
