#include <iostream>
#include <string.h>
#include "Fecha.h"
using namespace std;

class Persona{
protected:
	char Nombre[50],Apellido[50],Genero;
	Fecha Nacimiento;
public:
	char * GetNombre(){return Nombre;}
	char * GetApellido(){return Apellido;}
	char GetGenero(){return Genero;}
	Fecha GetNacimiento(){return Nacimiento;}
	void SetNombre(char* x){strcpy(Nombre,x);}
	void SetApellido(char* x){strcpy(Apellido,x);}
	void SetGenero(char x){Genero=x;}
	void SetNacimiento(Fecha x){Nacimiento=x;}
};
#include "Suscriptores.h"
#include "Menues.h"

int main()
{
    while(true){
        switch(MenuPrincipal()){
        case 1:
            break;
        case 2:
            break;
        case 3:
            system("cls");
            MenuSuscriptores();
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        }
    }
    return 0;
}
