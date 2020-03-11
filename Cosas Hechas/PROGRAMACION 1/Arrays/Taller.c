#include <iostream>
#include<string.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

typedef char nombrecoche[10];

typedef struct{
  nombrecoche nombre;
  bool ruedas[4];
  /
    X-|M|-B
      | |
    B-|A|-B
    Matricula: 1969 kkk
    M = 5

  */
  int motor;
  bool aceite;
}TCoche;

typedef TCoche ncoches[25];

int menu();
void cochenuevo(ncoches reparar, int &coche);
void estadocoche(ncoches reparar, int &coche);
void reparacoche(ncoches reparar, int &coche);
void dardealta(ncoches reparar, int &coche);

int main (){
  ncoches reparar;
  int coche;
  int op;
  do {
    op = menu();
    if (op == 1) {
      cochenuevo(reparar, coche);
    }
    else if (op == 2){
      estadocoche(reparar, coche);
      cout<<"op 2"<<endl;
    }
    else if (op == 3){
      reparacoche(reparar, coche);
      cout<< "op3"<<endl;
    }
    else if (op == 3){
      dardebaja(reparar, coche);
      cout<< "op4"<<endl;
    }

  } while(op<5 || op>1);


  return 0;
}

int menu(){
  int op;
  cout<<"Qué opción quiere?"<<endl;
  cout<<"1.-Dar de alta un coche"<<endl;
  cout<<"2.-Comprobar el estado del coche"<<endl;
  cout<<"3.-Reparar el coche"<<endl;
  cout<<"4.-Dar de alta el coche"<<endl;
  cout<<"5.-Salir."<<endl;
  cin>>op;
  return op;
}

void cochenuevo(ncoches reparar, int &coche){
  char aceite;
  cout<<"Qué modelo es el coche? ";
  cin.get();
  cin.getline(reparar[coche].nombre, 10);
  do {
    cout<<"Del 0 al 5 como de nuevo esta el motor de su coche?";
    cin>>reparar[coche].motor;
  } while(reparar[coche].motor<0 || reparar[coche].motor>5 );
  cout<<"Se ha de cambiar el aceite?(s/n) ";
  cin>>aceite;
  if (aceite == 's' ||aceite == 'S') {
    reparar[coche].aceite = false;
  }

  cout<<"Cuantas de las 4 ruedas se han de reparar? ";
  cin>>reparar[coche].ruedas;
  coche ++;
}

void estadocoche(ncoches reparar, int &coche){
  cout<<"Qué coche quiere ver?";
  cin.get();
  cin.getline(reparar[coche].nombre, 10);
  for (int i = 0; i < coche; i++) {
    if(strcmp(reparar[i].nombre,coche)==0){
      posCocheRep = i;
    }
  }
}

void reparacoche(ncoches reparar, int &coche){
  TNombre coche;
  cout<<"Qué coche quiere reparar?";
  cin.get();
  cin.getline(reparar[coche].motor, 10);
  for (int i = 0; i < coche; i++) {
    if(strcmp(reparar[i].nombre,coche)==0){
      posCocheRep = i;
    }
  }
  reparar[posCocheRep].aceite == true;
  reparar[posCocheRep].ruedas == 4;
  reparar[posCocheRep].motor == 5;
}

void dardebaja(ncoches reparar, int &coche){

}
