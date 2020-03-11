#include <iostream>
#include <math.h>

using namespace std;

int main() {
  char las;
  do {
      cout<<"Introduzca un caracter: ";
      cin>>las;
  } while(las != 'a' && las != 'e' && las != 'i' && las != 'o' && las != 'u');
  cout<<"CORRECTO"<<endl;

  return 0;
}
