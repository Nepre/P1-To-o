#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;


int main(){
  char a;
  // a =
  //
  //int a = (int)'a';
  //int z = (int)'z';
  string sti = "Hola soy Germán";

  getline(cin, sti);
  //cout<<z-a<<endl;
  //cout<<sti<<endl;

  for (int i=0; i<sti.length(); i++){
    if (islower(sti[i])) {
      sti[i] -=97;
      sti[i]= 25 - sti[i] + 97;
      cout<<sti[i];
    }
    else if (sti[i]==' ' || isdigit(sti[i])) {
      cout<<sti[i];
    }

  }
  cout<< endl;

  return 0;
}
