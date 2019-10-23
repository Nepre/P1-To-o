#include <iostream>
using namespace std;
///mnt/c/Users/anton/Documents/P1-To-o/Cosas Hechas/Prog Modular$  

void leePar(char &c1, char &c2, int &n) {
  cout<<"Introduce un caracter:";
  cin>>c1;

  do{

    cout<<"Introduzca otro caracter (R/V): ";
    cin>>c2;

    if (c2!='R' && c2!='V'){
      cout<<c2<<" no es valido"<<endl;
    }

  }while(c2!='R' && c2!='V');


  do{

    cout<<"Introduce un número (entre 4 y 20): ";
    cin>>n;

    if (n<4 || n>20){
      cout<<n<<" no es valido"<<endl;
    }

  }while(n<4 || n>20);

}

void dibujaLleno(char c1, int n){
  for (int i = 0; i < n; i++) {
    cout<<c1;
  }
  cout<<endl;
}

void dibujaVacio(char c1, int n){
  for (int i = 0; i < n; i++) {
    if (i==0 || i==n-1){
      cout<<c1;
    }
    else{
      cout<<' ';
    }

  }
  cout<<endl;
}


void dibuja(char c1,char c2, int n){
  for(int j = 0; j < n; j++){
    if (c2 == 'R' || j==0 || j==n-1) {
      dibujaLleno(c1, n);
    }
    else {
      dibujaVacio(c1, n);
    }
  }



}



int main (){
  char c1, c2;
  int n;
  leePar(c1, c2, n);
  dibuja(c1, c2, n);
  return 0;
}
