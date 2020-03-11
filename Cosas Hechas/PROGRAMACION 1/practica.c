
#include <iostream>
#include <time.h>
using namespace std;
/*int digitospares(int n1, int npares){
  if (n1 != 0) {
    int n1ph= n1%10;
    if (n1ph%2 == 0) {
      npares ++;
      return digitospares(n1/10, npares );
    }
    else{
      return digitospares(n1/10, npares );
    }
  }
  else return npares;
}


int main() {
  int n1;
  int npares = 0;
  cout<<"introduzca un número"<<endl;
  cin>>n1;
  digitospares(n1, npares);
  cout<<digitospares(n1, npares)<<endl;
  return 0;
}
*/

const int M=2;
const int N=3;

void rellenamatriz(int matriz[M][N]){

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      matriz[i][j] = rand()%24;
    }
  }
}

void rellenamenor(){

      do {
        for (int i = 0; i < 1  ; i++) {
          for (int j = 0; j < 2; j++) {
            if (matriz[i][j]> matriz[i+1][j]) {
              matriz[i][j]== matriz[i+1][j];
            }
            else if (matriz[i][j] matriz[i][j+1]) {
              matriz[i][j]== matriz[i+1][j]
            }
            else if (matriz[i][j]> matriz[i+1][j+1]) {
              matriz[i][j]== matriz[i+1][j+1]
            }
          }
        }
      } while(matriz[i][j]> matriz[i+1][j]||matriz[i][j]> matriz[i+1][j+1]||matriz[i][j]> matriz[i][j+1]);
      
int main() {
  srand(time(NULL));
  int matriz[M][N];
  return 0;
}
