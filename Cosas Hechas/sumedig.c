#include <iostream>
#include <math.h>


using namespace std;

void suma (int &n1, int &n2, int &tot);
void resta (int &n1, int &n2, int &tot);
void pideNumeros (int &n1, int &n2);
void multiplica(int &n1, int &n2, int &tot);
void pot (int &n1, int &n2, int &tot);
int poten (int n1, int n2);

int main(){
  char c, res;
  int n1 = 0;
  int n2 = 0;
  int tot = 0;


  do {
    cout << "Quiere Sumar (S), Restar (R), Multiplicar(M), Potencia(P) o Suma de Cifras(C)?"<<endl;
    cin>> c;
    if (c=='S') {
      suma (n1, n2, tot);
    }
    else if (c=='R') {
      resta (n1, n2, tot);
    }
    else if (c=='M'){
      multiplica (n1, n2, tot);
    }
    else if (c=='P'){
      pot (n1, n2, tot);
    }
    cout <<"Quiere realizar otra operación?(S/N)";
    cin>>res;
  } while(res=='S' || res=='s');

  return 0;
}

void suma (int &n1, int &n2, int &tot){
  pideNumeros(n1, n2);
  tot = n1 + n2;
  cout << "El resultado es "<<tot<<endl;
}
void pideNumeros (int &n1, int &n2){
  cout << "Con qué números quiere operar?"<<endl;
  cin >> n1;
  cin>> n2;
}
void resta (int &n1, int &n2, int &tot){
  pideNumeros(n1, n2);
  tot = n1 - n2;
  cout << "El resultado es "<<tot<<endl;

}
void multiplica (int &n1, int &n2, int &tot){
  pideNumeros(n1, n2);
  tot = n1* n2;
  cout<< "El resultado es "<<tot<<endl;
}
void pot (int &n1, int &n2, int &tot ){
  pideNumeros(n1, n2);

  cout << "El resultado es "<<poten (n1, n2)<<endl;

}
int poten (int n1, int n2 ){
  if (n2==0)
    return 1;
  else{
    return n1 * (poten ( n1, n2-1));
  }
}
