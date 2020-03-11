#include <iostream>
using namespace std;

typedef char Videojuego[20];
typedef char Genero[15];
typedef char Cliente[15];
typedef char Direccion[25];

typedef struct{
  int code;
  Videojuego nombre;
  Genero tipo;
  float precio;
  int anyo;
}Juego;

typedef Juego UltimosJuegos[10];
typedef Juego tiendavj[500];

typedef struct{
  int codigo;
  Cliente nombre;
  Direccion vivienda;
  UltimosJuegos ultimosjuegos;
}Cliente;

typedef struct{
  Genero nombre;
  int cantidad;
}genero_cantidad

typedef Cliente promo[100];


int main() {
  char array[10]{
    'a','ve'
  }
  cin.get();
  cin.getline();
  genero_cantidad tipos[4];
  tiendavj tienda;
  promo clientes;
  int idJuego, idcliente, ncliente;
  Juego juegoAux;
  int cont;
  cout<<"Qúe juego quieres comprar?"<<endl;
  cin>>idJuego;
  for (int i = 0; i < cont; i++) {
    if(idJuego == tienda[i].code){
      juegoAux = tienda[i];
    }
  }
  for (int i = 0; i < 100; i++) {
    if (clientes[i].codigo==idcliente) {
      ncliente = i;
    }
  }
  nuevacompra( ncliente, clientes,juegoAux);
  return 0;
}

void nuevacompra(int idCliente, promo &clientes, Juego juegoAux){
  for (size_t i = 0; i < 10; i++) {
    clientes[idCliente].ultimosjuegos[i] = clientes[idCliente].ultimosjuegos[i+1];
  }
  clientes[idCliente].ultimosjuegos[9] = juegoAux;
}

void muestravideojuegos(Videojuego &nombreVj, genero_cantidad tipos[4]){
  int anyoAux = 10000;

  for (int i = 0; i < cont; i++) {
    //cout << //... los datos (nombre tipo y precio).
    for (int j = 0; j < 4; j++) {
      if(strcmp(tienda[i].tipo, tipos[j].nombre)==0){
        tipos[j].cantidad++;
      }
    }

    if(tienda[i].anyo < anyoAux){
      anyoAux = tienda[i].anyo;
      nombreVj = tienda[i].nombre;
    }
  }
}




















/*EJERCICIO 4;
int sumaimp(int n1, int n1ph);

int main(){
  int n1, n1ph;
  cout<<"introduce un numero"<<endl;
  cin>>n1;
  cout<<sumaimp(n1, n1ph);
  return 0;
}

int sumaimp(int n1, int n1ph){
  if (n1!=0) {
    if (n1%2!=0) {
      return n1ph = n1%10 + sumaimp(n1/10, n1ph);
    }
    else return n1ph = sumaimp(n1/10, n1ph);
  }
  else return 0;
}
*/
/*EJERCICIO 3;
int ordenanum1[10];
int ordenanum2[10];
int arr[20];

int main(){
  int n1, n2;
  cout<<"mete diez numeros en orden ascendente en la 1a matriz"<<endl;
  for (int i = 0; i < 10; i++) {
    cin>>ordenanum1[i];
  }
  cout<<"mete diez numeros en orden ascendente en la 2a matriz"<<endl;
  for (int j = 0; j < 10; j++) {
    cin>>ordenanum2[j];
  }

  //--------------------------
  int i, j, k;
  i = j = k = 0;
  do {
    if(ordenanum1[i] > ordenanum2[j] || i == 10){
      arr[k] = ordenanum2[j];
      j++;
      k++;
    }
    else if(ordenanum1[i] <= ordenanum2[j] || j == 10){
      arr[k] = ordenanum1[i];
      i++;
      k++;
    }
  } while(k < 20);
  return 0;
}
*/



/*}EJERCICIO 2;
void creanumero(){
  int n1, n1ph, cont;
  do {
    cout<<"introduce un numero entre 1 y 9 incluidos"<<endl;
    cin>>n1ph;
    if(n1ph != -1){
      n1= n1*10 + n1ph;
      cont++;
    }
  } while(cont<7 || n1ph!=-1);
}
*/
