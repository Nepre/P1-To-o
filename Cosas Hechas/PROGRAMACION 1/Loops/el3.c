#include <iostream>
#include <math.h>

using namespace std;

int main() {
  int num=0;
  int sum=0;

  cout<<"Introduzca un numero entero: ";
  cin>>num;
  do {
    sum+=num%10;
    num/=10;
  } while(num!=0);
  cout<<"La suma de los digitos es "<<sum<<endl;
  return 0;
}
