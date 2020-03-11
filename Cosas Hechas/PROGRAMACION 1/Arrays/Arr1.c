#include <iostream>
using namespace std;

const int FILAS = 8;
const int COLUMNAS = 20;

void dibutaca (char but[FILAS][COLUMNAS], int col[COLUMNAS]);
void clintisbut (char but[FILAS][COLUMNAS], int col[COLUMNAS]);
void pidebut(char but[FILAS][COLUMNAS], int col[COLUMNAS]);

int main (){
  char res;
  char but [FILAS][COLUMNAS];
  int col [COLUMNAS];
  clintisbut(but, col);
  while (true) {
    dibutaca (but, col);
    pidebut(but, col);
  }


  return 0;
}

void dibutaca (char but[FILAS][COLUMNAS], int col[COLUMNAS]){
  int i, j;
  cout<< "BATIO DE PUTACAS"<<endl;
  cout<<" ";
  for (int i = 0; i < COLUMNAS; i++) {
    if(col[i] / 10 == 0){
      cout<<" ";
    }
    cout<<" "<<col[i];
  }
  cout<<endl;

  for (i= 0; i<FILAS; i++){
    cout << i + 1;
    for (j = 0; j<COLUMNAS; j++){
      cout <<"  "<< but[i][j];
    }
  cout << endl;
  }

}

void clintisbut(char but[FILAS][COLUMNAS], int col[COLUMNAS]){
  int i, j;
  for (i= 0; i<FILAS; i++){
    for (j = 0; j<COLUMNAS; j++){
      but[i][j] = ' ';
    }
  }
  int cont = 0;

  for (int i = 19; i > 0; i-=2) {
    col[cont] = i;
    cont++;
  }
  for (int i = 2; i < 21; i+=2) {
    col[cont] = i;
    cont++;
  }
  // for (int i = 0; i < COLUMNAS; i++) {
  //   cout<<"col["<<i<<"] = "<<col[i]<<endl;
  // }
  // cout<<endl;


}

void pidebut(char but[FILAS][COLUMNAS], int col[COLUMNAS]){
  int f, c;
  do {
    cout << "¿Qué fila desea?";
    cin>>f;
    cout<<"¿Qué columna desea?";
    cin>>c;
  } while(f>8 || f<1 || c>20 || c<1);

  int ccalc = 0;

  for (int i = 0; i < COLUMNAS; i++) {
    if(c == col[i]){
      ccalc = i;
      break;
    }
  }

  but[f-1][ccalc] = '*';

}
