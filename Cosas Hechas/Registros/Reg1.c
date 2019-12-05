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
void MuestMininos(TGatos, int);
void compVac (TGatos, int, tm *);
void iniciaMenu (int &);

int main(){
  int opc;
  time_t t;
  TGatos mininos;
	int tam;
  struct tm *tlocal;
  t=time(NULL);
  tlocal=localtime(&t);



  iniciaMininos(mininos, tam);
  do {
		iniciaMenu(opc);
    if (opc == 1) {
      altaMininos(mininos, tam);
    }
    else if (opc == 2) {
			compVac (mininos, tam, tlocal);
  	}
    else if(opc == 3){
      MuestMininos(mininos, tam);
    }
  } while(opc != 4);

}

void iniciaMenu (int &opc){
	cout<<"--------------------------------------------"<<endl;
  do {
    cout <<"1.- DAR DE ALTA UN MININO"<< endl;
    cout <<"2.- COMPROBAR VACUNAS"<< endl;
    cout <<"3.- LISTADO"<< endl;
    cout <<"4.- SALIR"<< endl;
    cin >>opc;
  } while(opc > 4 || opc < 1 );

  cout <<"OPCIÓN . . . "<<opc<<endl;
	cout<<"--------------------------------------------"<<endl;
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
  cin >> mininos[tam].nombre;
  cout<<endl;
  cout <<"FECHA DE ADOPCIÓN. . ."<<endl;
  cout <<"         DÍA. . .";
  cin >>mininos[tam].fec.dia;
  cout <<"         MES. . .";
  cin >> mininos[tam].fec.mes;
  cout <<"         AÑO. . .";
  cin >> mininos[tam].fec.anyo;
  tam++;
}
void compVac (TGatos mininos, int tam, tm* tlocal){
	bool vacunado = false;
	for (int i = 0; i < tam; i++) {
		if (mininos[i].fec.anyo != tlocal->tm_year+1900 && (mininos[i].fec.mes < tlocal->tm_mon+1 || (mininos[i].fec.mes == tlocal->tm_mon+1 && mininos[i].fec.dia <= tlocal->tm_mday))) {
			if(!vacunado) cout<<"TOCA VACUNAR A:"<<endl;
			vacunado = true;
			cout<<mininos[i].nombre<<endl;
		}
	}
	if(!vacunado) cout<<"No hay que vacunar a ningún minino"<<endl;
}

void MuestMininos(TGatos mininos, int tam){
	for (int i = 0; i < tam; i++) {
		cout<<i+1
			<<". "
			<<mininos[i].nombre<<' '
			<<mininos[i].fec.dia<<'-'
			<<mininos[i].fec.mes<<'-'
			<<mininos[i].fec.anyo<<
		endl;
	}
}
