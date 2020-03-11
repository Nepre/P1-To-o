#include <iostream>
#include <math.h>

using namespace std;

int main() {
  float ante;
  int erno=0;
  cout<<"Introduzca un numero real: ";
  cin>>ante;
  while (ante<0) {
    erno++;
    cout<<"Introduzca un numero real: " ;
    cin>>ante;
  }
  cout<<"Su numero es positivo, ha dicho un total de "<<erno<<" numeros negativos"<<endl;

  return 0;
}
