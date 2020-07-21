#ifndef SUSCRIPTORES_H_INCLUDED
#define SUSCRIPTORES_H_INCLUDED

class Cliente:public Persona{
private:
	int Dni;
	bool EsSuscriptor, Estado;
	int Puntos;
public:
    Cliente(){
        Dni=0;
        Puntos=0;
        strcpy(Nombre," ");
        strcpy(Apellido," ");
        Genero='-';
}
	int GetDni(){return Dni;}
	int GetPuntos(){return Puntos;}
	bool GetEsSuscriptor() {return EsSuscriptor;}
	bool GetEstado() {return Estado;}
	void SetDni(int x){Dni=x;}
	void SetEsSuscriptor(bool x){EsSuscriptor=x;}
	void SetEstado(bool x) {Estado=x;}
	void SetPuntos(int x){Puntos=x;}
	bool Cargar(){
	Estado=true;

	cin.ignore();

	cout << "NOMBRE: ";
	cin.getline(Nombre,50);

	cout << "APELLIDO: ";
	cin.getline(Apellido,50);

	cout << "DNI: ";
	cin >> Dni;
	cin.ignore();
	int Dia, Mes, Anio;

	cout << "FECHA DE NACIMIENTO" << endl;
	cout << "DIA: "; cin >> Dia;
    cout << "MES: "; cin >> Mes;
    cout << "AÑO: "; cin >> Anio;

    Nacimiento.setDia(Dia);
    Nacimiento.setMes(Mes);
    Nacimiento.setAnio(Anio);

    cout << "GENERO: ";
    cin >> Genero;

    system("cls");

    return true;

	}
	void Grabar(){
	FILE *p = fopen("Clientes.dat","ab");
	fwrite(this,sizeof (Cliente) ,1,p);
	fclose(p);
}
};

bool EliminarSuscriptor(int dni){
     FILE *p=fopen("Clientes.dat","rb+");
     Cliente reg;
     while(fread(&reg, sizeof reg, 1, p)==1){
        if(dni==reg.GetDni()){
            reg.SetEstado(false);
            fseek(p,-sizeof reg, 0);
            fwrite(&reg, sizeof reg, 1,p);
            fclose(p);
            return true;
        }
     }
     fclose(p);
     return false;
};

#endif // SUSCRIPTORES_H_INCLUDED
