#include <iostream>
#include<string.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

typedef char TCadena[15];

typedef struct{
  TCadena nombre;
  float precio;
}TProducto;

typedef TProducto prductos[50];

int menu();
void alta(productos objeto, int &lugar);

int main(){
  productos objeto;
  int lugar;
  int op;
  do {
    op=menu();
    if (op == 1){
      alta(objeto, lugar);
    }
    if (op == 2) {
      baja();
    }

  } while(op!=5);
  return 0;
}

int menu(){
  int op;
  cout<<"Qué opción quiere?"<<endl;
  cout<<"1.-Dar de alta"<<endl;
  cout<<"2.-Vender un producto"<<endl;
  cout<<"3.-Modificar un producto"<<endl;
  cout<<"4.-Mostrar productos"<<endl;
  cout<<"5.-Salir"<<ednl;
  cin>>op;
  cout<<"Opción "<<op<<" elegida"<<endl;
  return op;
}
void alta(productos objeto, int &lugar){
  int lugar;
  cout<<"Nombre del producto:";
  cin>>objeto[lugar].nombre;
  cout<<endl;
  cout<<"Precio del producto:";
  cin>>objeto[lugar].precio;
  cout<<endl;
}
void baja(productos objeto, int &lugar, char conf){
  char prim;
  int posObjetosBorrar = 0;
  cout<<"Quiere vender un producto?";
  cin>>prim;
  TCadena producto;
  cin.get();
  cin.getline(producto, 15);
  if (prim == "si") {
    for (int i = 0; i < lugar; i++) {
      if(strcmp(objeto[i].nombre,producto)==0){
        posObjetosBorrar = i;
      }
    }
    for (int i = posObjetosBorrar; i < lugar-1; i++) {
      objeto[i] = objeto[i+1];
    }
    /*
    objeto[posObjetosBorrar] = objeto[lugar-1]; // Esto coge el último objeto y lo pone donde está el objeto a borrar, sustituyendolo
    lugar --; // 1 - 2 - 3 - 4 - 5 --> borramos 2 --> 1 - 5 - 3 - 4 - 5 --> lugar-- --> entonces obviamos el último 5 quedando 1 - 5 - 3 - 4
    */
  }
  else{
    cout<<"No elija esta opción si no va a borrar, payaso"<<endl;
  }
  lugar--;
}

  void Modificar(productos objeto, int &lugar){
    TCadena1 producto;
    TCadena newnombre;
    float newprecio
    cin.get();
    cin.getline(producto, 15);
    for (int i = 0; i < lugar; i++) {
      if(strcmp(objeto[i].nombre,producto)==0){
        posObjetosMod = i;
      }
    }
    for (int i = posObjetosMod; i < lugar; i++) {
      objeto[i].nombre = newnombre;
      objeto[i].precio = newprecio;
    }


}

void
