#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int genAl();
bool op(int&, int);

int main(){
  int al1, al2, res;
  srand(time(NULL));
  al1 = genAl();
  for (int i = 0; i < 7; i++) {
    al2 = genAl();
    op(al1, al2)?  : i--; // acierta al1 y al2? si es a : sino b
  }
  return 0;
}

int genAl(){
  int res;
  res = 1 + rand()%(9);
  return res;
}
bool op(int &al1, int al2){
  int oper, res, aux ;
  bool aux2 = false;
  oper = rand()%(3);
  if (oper==0) {
    cout<< al1 << "+" << al2 << "=";
    res = al1 + al2;
  }
  else if (oper==1){
    cout << al1 << "-" << al2 << "=";
    res = al1 - al2;
  }
  else if (oper==2){
    cout << al1 << "*" << al2 << "=";
    res = al1 * al2;
  }
  else{
    cout << al1 << "/" << al2 << "=";
    res = al1 / al2;
  }
  cin>>uwu;
  if (res==aux){
    cout<<"Has acertado"<<endl;
    aux2 = true;
  }
  else{
    cout<<"Has fallado"<<endl;
  }
  al1 = res;
  return aux2;
}

/*
i < 7
1 0
2 1
3 2
4 3
i--
i=2
5 3
6 4
7 5
8 6


*/
