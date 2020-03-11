#include <iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;

int main() {
  int array[25];
  int array2[25];
  int tot = 0;
  srand(time(NULL));
  for (int i = 0; i < 25; i++) {
      array[i] = 1 + rand()%(99);
  }

  for (int i = 0; i < 25; i++) {
      cout<<array[i]<<"  ";
  }

  int minVal = 10000;
  int minPos = 10000;

  for (int i = 0; i < 25; i++) {
    minVal = 10000;
    for (int j = 0; j < 25; j++) {
      if(array[j] < minVal){
        minVal = array[j];
        minPos = j;
      }
    }
    array2[i] = minVal;
    array[minPos] = 10000;
  }

  cout<<endl;
  for (int i = 0; i < 25; i++) {
    cout<<array2[i]<<"  ";
  }


  cout<<endl;

  return 0;
}
