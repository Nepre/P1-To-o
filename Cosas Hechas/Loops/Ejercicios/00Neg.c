#include <iostream>
using namespace std;

int main(){
  int i, j;
  i = j = 0;
  cin>>i;
  while(i>=10){
    while(i!=0){
      j+=i%10;
      i/=10;
    }
    i=j;
    j=0;
  }
  cout<<i<<endl;
  return 0;
}
