#include <iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;

int porsien(int n1, int n2);

//cd mnt/c/Users/anton/Documents/P1-To-o/

int main() {
  int n1, n2;
  cout<<"Introduzca dos números,"<<endl;
  cin>>n1;
  cin>>n2;
  cout<<porsien(n1, n2)<<endl;
  return 0;
}

int porsien(int n1,int n2){
  if(n1 != 0){
    return n2 % 10 + 10*(n1%10) + porsien(n1/10, n2/10) * 100;
  }
  else{
    return 0;
  }
}
