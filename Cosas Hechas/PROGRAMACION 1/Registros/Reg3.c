#include <iostream>

using namespace std;

typedef char TCadena[15];

typedef struct{
  int hora;
  int minutos;
}THora;

typedef struct{
  int num;
  TCadena nombre;
  char ing[3];
  /*
  char ing1; //a
  char ing2; //z
  char ing3; //xa
  */
  int numIngred;
  bool enviado;
  THora hora;
}TPedido;

typedef TPedido TPizzeria[100];//TPizzeria es un tipo que crea arrays de 100 TPedido

char menu();//Lo pone como char por que lo trata como char, podria ser int
void alta(TPizzeria, int &);//contador de pizzas, lleva & por que se irá sumando uno importante ponerlo por referencia
void marcar(TPizzeria, int);//Para saber cuantas celdas tienen pedidos
void mostrar(TPizzeria, int);

int main(){
  TPizzeria pizzas;//array de 100 TPedidos

  int cont;//Para saber cuantas pizzas tienes
  char op;//Será la opcion.
  cont = 0;

  do{
    op = menu();
    switch (op) {
      case '1':alta(pizzas, cont);
              break;
      case '2':marcar(pizzas, cont);
              break;
      case '3':mostrar(pizzas, cont);
              break;
    }
  }while (op!='4');
return 0;
}


char menu(){
  char op;
  do {
    cout<<" 1.-Dar de alta un pedido"<<endl;
    cout<<" 2.-Marcar un pedido como enviado"<<endl;
    cout<<" 3.-Mostrar el número de veces que hay un ingrediente"<<endl;
    cout<<" 4.-Salir del programa"<<endl;
    cout<<" Has elegido: ";
    cin>>op;
  } while(op<'1'|| op>'4');
  return op;
}

void alta(TPizzeria pizzas, int &cont){
  if (cont== 100) {
    cout << "Error, no se pueden dar de alta más pedidos"<<endl;
  }
  else{
    pizzas[cont].num=cont+1;
    cout<<"Pedido número "<< cont+1 <<endl;
    cout <<"Pizza: ";
    cin.get();//Para limpiar el buffer, sino el cin.getline da problemas.
    cin.getline(pizzas[cont].nombre, 15);
    cout<<"Número de extras: ";
    cin >> pizzas[cont].numIngred;
    for (int i = 0; i < pizzas[cont].numIngred; i++) {
      cout << "Ingrediente "<< i+1 << " ";
      cin >>pizzas[cont].ing[i];
    }
    pizzas[cont].enviado=false;
    pizzas[cont].hora.hora=0;
    pizzas[cont].hora.minutos=0;
    cont ++;
  }
}

void marcar(TPizzeria pizzas, int cont){
  int num;
  cout <<"Número de pedido ";
  cin >>num;
  if (num<=cont) {
    pizzas[num-1].enviado=true;
    cout << "Pedido "<< num <<" enviado con exito"<<endl;
  }
  else{
    cout<< "Error, introduzca un pedido valido"<<endl;
  }
}

void mostrar(TPizzeria pizzas, int cont){
  char ing;
  int i, j, cantidad;
  cantidad = 0;
  cout << "Ingrediente a contar: ";
  cin >> ing;
  for (i = 0; i < cont; i++) {
    for (j = 0; j < pizzas[i].numIngred; j++) {
      if (ing == pizzas[i].ing[j]) {
        cantidad ++;
      }
    }
  }
  cout<< "Tienes que preparar "<< cantidad << " unidades del ingrediente "<<ing<<endl;
}
