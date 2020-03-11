#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//cd mnt/c/Users/anton/Documents/P1-To-o/



int int main() {
  int fjug, cjug, ftes, ctes, fmon, cmon;
  fjug = 0;
  cjug = 0;
  ftes = 0;
  ctes = 0;
  fmon = 0;
  cmon = 0;
  int tam[FILAS][COLUMNAS];
  srand(time(NULL));
  GenPos();
  while (terminado == false) {
    getDireccion();
    moverJugador();
  }

  return 0;
}
void ElijeTam(int &tam[FILAS][COLUMNAS]){
  cout << "Por favor, introduzca la cantidad de filas y columnas con las que jugará"<<endl;
  cin>> FILAS;
  cout<<"Jugará con "<<FILAS<<" filas"<<endl;
  cin>> COLUMNAS;
  cout<<"Jugará con "<<COLUMNAS<<" columnas"<<endl;
}


void GenPos(int &tam[FILAS][COLUMNAS]){
  for (int i = 0; i < FILAS; i++) {
    for (int j = 0; j < COLUMNAS; j++) {
      if(i == 0 && j == 0) tam[i][j] == 'J';
      else if(valor == 2 )
      else if
      else tam[i][j] = '.'
    }
  }
}

void dibujaEscenario(&tam){
  for (size_t i = 0; i < count; i++) {
    for (size_t j = 0; j < count; j++) {
      /* code */
    }
  }
}

void moverJugador(&tam, dir, posPlX, posPlY, &terminado){
  if(dir == N){
    if(posPlY + 1 < 0 || posPlY +1 > FILAS){
      cout<<"No puedes ir por ahí";
      return;
    }
    if(tam[posPlX][posPlY+1] == 'M'){
      cout<<"Estas muerto subno";
      terminado == true;
    }

  }
}
