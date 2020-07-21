#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <iostream>
#include <time.h>
using namespace std;
class Fecha
{
  private:
    int dia;
    int mes;
    int anio;
    bool esbisiesto(int);
    void NumeroSerieaFecha(int);
  public:
    Fecha(int d=0,int m=0,int a=0);
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;};
    void setAnio(int a){anio=a;}
    void MostrarFecha();
    void MostrarFechaTexto();
    int NumeroSerie();
    bool operator >(Fecha &);
    bool operator ==(Fecha &);
    Fecha operator+(int);
    int operator -(Fecha &);
    void operator +=(int);
    int operator==(const char*);
    friend istream & operator>>(istream &, Fecha &);
    friend ostream & operator<<(ostream &, Fecha &);
    int cantDiasMes();
    int cantDiasHabilesMes();
    int cantAniosHastaHoy();
    int GetEdad(){
        Fecha aux;
        int Edad=aux.getAnio();
        Edad-=anio;
        if(mes<aux.getMes()) return Edad;
        if(dia<aux.getDia()) return Edad;
        Edad--;
        return Edad;
    }
};

Fecha::Fecha(int d,int m,int a)
{//El constructor asigna los valores recibidos, si le son pasados como par�metros
  if(d!=0)
  {
  dia=d;mes=m;anio=a;//�Qu� modificaci�n habr�a que hacerle al constructor para
  }                   // garantizar que no se asignen valores absurdos? Ej.:65/65/-12
  else  //si no recibe valores asigna por defecto la fecha actual
  {
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    anio=tmPtr->tm_year+1900;
    mes=tmPtr->tm_mon+1;
    dia=tmPtr->tm_mday;
  }
}

//Devuelve true si el a�o recibido es bisiesto.
bool Fecha::esbisiesto(int a)
{
  bool bisiesto=false;
  if(a%4==0)
     bisiesto=true;
  if((a%100==0) && (a%400!=0))
           bisiesto=false;
  return bisiesto;
}

//Muestra la fecha en formato n�mero. Ej.:  15/10/2008
void Fecha::MostrarFecha()
{
if(dia<10)cout<<"0";
  cout<<dia<<"/";
  if (mes<10)cout<<"0";
  cout<<mes<<"/"<<anio;
}//�Qu� modificaci�n habr�a que hacer para que siempre muestre DD/MM/AAAA?


//Devuelve 1 si la fecha coincide con una cadena que representa un d�a de la semana
int Fecha::operator==(const char *diaSemana)
{
  int cantdias=NumeroSerie()-1;//cantidad de d�as transcurridos desde 01/01/1900
  //El 01/01/1900 fue Lunes
  int numerodia=cantdias%7;

  char mdia[7][10];
  strcpy(mdia[0],"Lunes");
  strcpy(mdia[1],"Martes");
  strcpy(mdia[2],"Miercoles");
  strcpy(mdia[3],"Jueves");
  strcpy(mdia[4],"Viernes");
  strcpy(mdia[5],"S�bado");
  strcpy(mdia[6],"Domingo");
  if(strcmp(mdia[numerodia],diaSemana)==0)
    return 1;
  return 0;
  }

//Muestra la fecha indicando en texto el d�a y el mes.Ej.: Lunes 1 de enero de 1900
void Fecha::MostrarFechaTexto()
{
char mmes[12][11];
  strcpy(mmes[0],"Enero");
  strcpy(mmes[1],"Febrero");
  strcpy(mmes[2],"Marzo");
  strcpy(mmes[3],"Abril");
  strcpy(mmes[4],"Mayo");
  strcpy(mmes[5],"Junio");
  strcpy(mmes[6],"Julio");
  strcpy(mmes[7],"Agosto");
  strcpy(mmes[8],"Septiembre");
  strcpy(mmes[9],"OCtubre");
  strcpy(mmes[10],"Noviembre");
  strcpy(mmes[11],"Diciembre");


  int cantdias=NumeroSerie()-1;//cantidad de d�as transcurridos desde 01/01/1900
  //El 01/01/1900 fue Lunes
  int numerodia=cantdias%7;

  char mdia[7][10];
  strcpy(mdia[0],"Lunes");
  strcpy(mdia[1],"Martes");
  strcpy(mdia[2],"Miercoles");
  strcpy(mdia[3],"Jueves");
  strcpy(mdia[4],"Viernes");
  strcpy(mdia[5],"S�bado");
  strcpy(mdia[6],"Domingo");

  cout<<endl<<mdia[numerodia]<<" "<<dia<<" de "<<mmes[mes-1]<<" de "<<anio<<endl;
  }

  //Devuelve la cantidad de d�as transcurridos desde el 01/01/1900
  int Fecha::NumeroSerie()
  {
    int cont=0,i;
    for(i=1900;i<anio;i++)
      if(esbisiesto(i)) cont++;
    int vmes[]={31,28,31,30,31,30,31,31,30,31,30,31},suma=0;
    if(esbisiesto(anio)) vmes[1]=29;
    for(int i=0;i<mes-1;i++)  suma+=vmes[i];
    int cantdias=(anio-1900)*365+cont+suma+dia;
    return cantdias;
  }

//Sobrecargas
bool Fecha::operator>(Fecha &obj)
{
  if(NumeroSerie()>obj.NumeroSerie())
    return true;
  return false;
}

bool Fecha::operator==(Fecha &obj)
{
  if(NumeroSerie()==obj.NumeroSerie()) return true;
  //Otra posibilidad
  //if(dia==obj.dia && mes==obj.mes && anio==obj.anio)
  //  return true;
  return false;
}

void Fecha::NumeroSerieaFecha(int ns)
{
  int suma=0, dia_adicional, suma_ant;
  int anio_real=1900;
  while(ns>suma)
    {
    dia_adicional=(esbisiesto(anio_real)?1:0);
    suma_ant=suma;
    suma+=365+dia_adicional;
    anio_real++;
    }
   anio=anio_real-1;
   //Cantidad de d�as pasados desde anio
  int dias_anio_actual=ns-suma_ant,i=0;
  int vmes[]={31,28,31,30,31,30,31,31,30,31,30,31};
  if(esbisiesto(anio)) vmes[1]=29;
  suma=0;
  while(dias_anio_actual>suma) suma+=vmes[i++];
  mes=i;
  dia=dias_anio_actual-(suma-vmes[i-1]);
 }

void Fecha::operator +=(int masdias)
{
 int  ns=NumeroSerie()+masdias;
 NumeroSerieaFecha(ns);
 }

istream & operator>>(istream &entra, Fecha &f)
{
  cout<<"Ingrese el dia: ";
  entra>>f.dia;
  cout<<"Ingrese el mes: ";
  entra>>f.mes;
  cout<<"Ingrese el a�o: ";
  entra>>f.anio;
  return entra;
}

ostream & operator<<(ostream &sale, Fecha &f)
{
  cout<<"Dia: ";
  sale<<f.dia<<endl;
  cout<<"Mes: ";
  sale<<f.mes<<endl;
  cout<<"A�o: ";
  sale<<f.anio<<endl;
  return sale;
}

Fecha Fecha::operator+(int masdias)
{
 Fecha aux;
 int  ns=NumeroSerie()+masdias;
 aux.NumeroSerieaFecha(ns);
 return aux;
}

int Fecha::operator -(Fecha &obj)
{
  return NumeroSerie()-obj.NumeroSerie();
  }

int Fecha::cantDiasMes()
{
  int vmes[]={31,28,31,30,31,30,31,31,30,31,30,31};
  if(esbisiesto(anio)) vmes[1]=29;
  return vmes[mes-1];
  }
// Devuelve la cantidad de d�as h�biles del mes correspondiente a la fecha
// No tiene en cuenta si en el mes hay o no feriados
// Una posibilidad es que se identifique en una matriz los d�as feriados del a�o
// y se compare cada d�a con esa matriz
int Fecha::cantDiasHabilesMes()
 {
   int totDias=cantDiasMes();
   int dia, cant=0;
   Fecha aux=*this;
   for(int i=1;i<=totDias;i++)
      {
        dia=(aux.NumeroSerie()-1)%7;
        if(dia<5) cant++;
        aux+=1;
        }
   return cant;
 }

//Devuelve la cantidad de a�os entre una fecha y el d�a actual
int Fecha::cantAniosHastaHoy()
{
  Fecha aux; //por usar un constructor por defecto tiene la fecha de hoy;
  int cant=aux.anio-anio;
  if(mes>aux.mes) return cant-1;
  if(mes==aux.mes && dia>aux.dia) return cant-1;
  return cant;
  }

#endif // FECHA_H_INCLUDED
