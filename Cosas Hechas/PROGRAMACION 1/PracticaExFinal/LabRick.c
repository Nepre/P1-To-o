#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

const int MAX = 50;

typedef struct{
  unsigned int tuercas;
  char name[69];
}pieza;

typedef struct{
  int id;
  char name[69];
  char uso[100];
  pieza partes[MAX];
  bool roto;
  int npiezas;
  unsigned int nusos;
  unsigned int nusosInit;
}cachivache;

typedef cachivache invenciones[MAX];

void crearcachivache(invenciones , int &);
void montacachivache(int &, char [], char [], pieza [], int, bool, unsigned int, unsigned int, invenciones);
void cachivachesIniciales(invenciones, int &);
void muestracachivaches(invenciones, int);
int menu();



int main(){
  invenciones garas;
  int inventario=0;//IMPORTANTE DECIR POR QUE NUMERO SE EMPIEZA.
  cachivachesIniciales(garas, inventario);
  //crearcachivache(garas, inventario);
  int op = 0;
  do{
    switch (menu()) {
      case 1:
        muestracachivaches(garas, inventario);
        break;
      default:
        break;
    }

  }while(op != 0);
  return 0;
}

void montacachivache(int &inventario,char name[], char uso[], pieza partes[], int npiezas, bool roto, unsigned int nusos, unsigned int nusosInit, invenciones garas){
  int id = inventario + 1;
  garas[inventario].id = id;
  for (int i = 0; i < 69; i++) {
    garas[inventario].name[i] = name[i];
  }

  for (int i = 0; i < 100; i++) {
    garas[inventario].uso[i] = uso[i];
  }

  for (int i = 0; i < MAX; i++) {
    garas[inventario].partes[i] = partes[i];
  }

  garas[inventario].npiezas = npiezas;
  garas[inventario].roto = roto;
  garas[inventario].nusos = nusos;
  garas[inventario].nusosInit = nusosInit;

  inventario++;
}


void crearcachivache(invenciones garas, int &inventario){

  char name[69];
  char uso[100];
  char sn;
  pieza partes[MAX];
  int npiezas=0;
  bool roto = false;
  unsigned int nusos;
  unsigned int nusosInit;
  cout<<"Introduzca el nombre de su cachivache: ";
  cin.get();
  cin.getline(name,69);
  cout<<"Cual es su uso principal? ";
  cin.get();
  cin.getline(uso, 100);
  cout<<"Añade una pieza del cachivache "<<endl;
  do {
    cout<<"Primero inserte el nombre ";
    cin.get();
    cin.getline(partes[npiezas].name, 69);
    cout<<"Ahora el numero de tuercas de este ";
    cin>>partes[npiezas].tuercas;
    cout<<"Quieres añadir otra pieza?(s/n): ";
    cin>>sn;
    cout<<endl;
  } while(sn == 's' || sn == 'S');
  cout<<"Dime el número de veces que puedes usarlo: ";
  cin>>nusos;
  nusosInit = nusos;


  montacachivache(inventario, name, uso, partes, npiezas, roto, nusos, nusosInit, garas);

}

void cachivachesIniciales(invenciones garas,int &inventario){
  pieza p1, p2, p3, p4;
  strcpy(p1.name, "Turbo cargador cuantico");
  p1.tuercas = 42;
  strcpy(p2.name, "Volatilizador de vacio particular");
  p2.tuercas = 38;
  strcpy(p3.name, "Chancla");
  p3.tuercas = 0;
  strcpy(p4.name, "Whisky");
  p4.tuercas = 0;

  pieza partes[MAX];
  partes[0] = p1;
  partes[1] = p3;
  partes[2] = p4;

  char name[69];
  char uso[100];

  strcpy(name, "Nave espacial");
  strcpy(uso, "Para volar por el espacio");

  montacachivache(inventario, name, uso, partes, 3, false, 160, 160, garas);

  strcpy(name, "Coche espacial");
  strcpy(uso, "Para conducir por el espacio");

  partes[2] = p2;
  montacachivache(inventario, name, uso, partes, 3, false, 130, 130, garas);

  //montacachivache();
}


int menu(){
  cout
    <<"Bienvenido al gestor de cachivaches de Rick, ¿Qué desea hacer?"<<endl
    <<"1. Mostrar cachivaches"<<endl
    <<"0. Salir"<<endl;
  int op = 0;
  cin>>op;
  return op;
}

void muestracachivaches(invenciones garas, int inventario){
  cout<<"----------------------"<<endl;
  for (int i = 0; i < inventario; i++) {
    cachivache c = garas[i];
    cout<<"Id: "<<c.id<<endl;
    cout<<"Name: "<<c.name<<endl;
    cout<<"Uso: "<<c.uso<<endl;
    cout<<"----------------------"<<endl;
  }
}
