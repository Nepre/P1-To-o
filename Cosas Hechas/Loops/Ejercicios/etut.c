#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  char cos;

  srand (time(NULL)); // Inicializar la semilla (sino siempre será la misma)

  int n1, n2, nT;
  float ando=0;

  do {
    for(int i=0;i<5;i++){
      n1= rand() % 10;
      n2= rand() % 10;

      cout<<"Multiplique "<<n1<<" y "<<n2<<endl;
      cin>>nT;
      if (nT==n1*n2) {
        cout<<"CORRECTO"<<endl;
        ando++;
      }
      else{
        cout<<"Eres tonto?"<<endl;
        if(nT<n1*n2){
          cout<<"poencima"<<endl;
        }
        else{
          cout<<"poabajo"<<endl;
        }
        cout<<"Prueba otra vez "<<endl;
        cin>>nT;
        if (nT==n1*n2) {
          cout<<"CORRECTO"<<endl;
          ando+=0.5;
        }
        else{
          cout<<"LACONCHATUMAREPELOTUDO"<<endl;
        }
      }
    }

    cout<<ando<<" es tu puntuación final"<<endl;
    cout<<"Tú querrà jogar altra vegada?¿(S/N(SI/NO(RESPECTIVAMENTE))) "<<endl;
    cin>>cos;
  } while(cos=='S' || cos=='s');


  return 0;
}
