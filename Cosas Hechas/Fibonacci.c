#include <iostream>
#include <math.h>

using namespace std;

void leeUsuario (int &nit, char &tip, char &itono);
int fibonacci (int nit);
void dibujaSerie(int &nit, char &tip, char &itono );



int main(){
  int nit, pint;
  char tip, itono;
  leeUsuario(nit, tip, itono);
  dibujaSerie(nit, tip, itono);
  return 0;
}

void leeUsuario(int &nit, char &tip, char &itono){
    do {
      cout << "Iteraciones: ";
      cin >> nit;
    } while(nit<0);

    cout << "Carácter: ";
    cin >> tip;

    do {
      cout << "Mostrar iteración [I/N/F]:";
      cin >> itono;
    } while(itono != 'I' && itono != 'N' && itono != 'F');
  }

int fibonacci (int nit){

  if (nit==1 || nit==2) {
    return 1;
  }
  else{
    return (fibonacci(nit - 1) + fibonacci (nit - 2));
  }
}
void dibujaSerie(int &nit, char &tip, char &itono ){
  int tot = 0;
  int fib = 0;
  for (int i = 1; i <= nit; i++) {
    if(itono == 'I') cout << "["<<i<<"]";
    fib = fibonacci(i);
    tot += fib;

    for (int j = 0; j < fib; j++) {
      cout<<tip;
    }

    if(itono == 'F') cout << "["<<i<<"]";
    cout<<endl;
    }
    cout<<"Total: "<<tot<<endl;
  }
