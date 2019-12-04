#include <iostream>
#include <cstring>
#include <time.h>
#include <stdio.h>
using namespace std;

const int MAX=50; //NUMERO MAXIMO DE GATOS QUE PUEDE TENER LA ABUELA TERESA

typedef char TCadena[10];

typedef struct{
	int dia;
	int mes;
	int anyo;
}TFecha;

typedef struct{
	TCadena nombre;
	TFecha fec;
}TMascota;

typedef TMascota TGatos[MAX];

void iniciaMininos(TGatos, int &);
void altaMininos (TGatos, int &);
int iniciaMenu (int);

int main(){
  int opc;
  time_t t;
  struct tm *tlocal;
  int dia, mes;
  t=time(NULL);
  tlocal=localtime(&t);
  dia=tlocal->tm_mday;
  mes=tlocal->tm_mon+1;
	TGatos mininos;
	int tam;

  iniciaMenu (opc);
  /*do {
    if (opc = 1) {
      altaMininos(mininos, tam);
    }
    else if (opc = 2) {
      compVac ();
    }
    else{
      MuestMininos(TGatos, tam);
    }
  } while(opc != 4);
	iniciaMininos(mininos, tam);
}*/

int iniciaMenu (int opc){
  do {
    cout <<"1.- DAR DE ALTA UN MININO"<< endl;
    cout <<"2.- COMPROBAR VACUNAS"<< endl;
    cout <<"3.- LISTADO"<< endl;
    cout <<"4.- SALIR"<< endl;
    cin >>opc;
  } while(opc > 4 || opc < 1 );

  cout <<"OPCIÓN . . . "<<opc<<endl;
  return opc;
}



void iniciaMininos(TGatos mininos, int &tam){
	strcpy(mininos[0].nombre,"Manolo");
	mininos[0].fec.dia=1;
	mininos[0].fec.mes=1;
	mininos[0].fec.anyo=2015;

	strcpy(mininos[1].nombre,"Kira");
	mininos[1].fec.dia=22;
	mininos[1].fec.mes=12;
	mininos[1].fec.anyo=2018;

	strcpy(mininos[2].nombre,"Peluso");
	mininos[2].fec.dia=5;
	mininos[2].fec.mes=3;
	mininos[2].fec.anyo=2017;

	strcpy(mininos[3].nombre,"Bolita");
	mininos[3].fec.dia=5;
	mininos[3].fec.mes=3;
	mininos[3].fec.anyo=2017;
	tam=4;
}
void altaMininos (TGatos mininos, int &tam){
  cout <<"NOMBRE DEL MININO . . . ";
  cin.getline >> mininos[0].nombre;
  cout<<endl;
  cout <<"FECHA DE ADOPCIÓN";
  cin >>mininos[tam].fec.dia;
  cout <<endl<<"         DÍA. . ."<<fec.dia;
  cin >> mininos[tam].fec.mes;
  cout <<endl<<"         MES. . ."<<fec.mes;
  cin >> mininos[tam].fec.anyo;
  cout <<endl<<"         AÑO. . ."<<fec.anyo;
  tam++;
}
