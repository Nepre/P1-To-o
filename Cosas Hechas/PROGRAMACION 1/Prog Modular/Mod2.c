#include <iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;



//cd mnt/c/Users/anton/Documents/P1-To-o/


void reparteCarta (int &nJ);
void calculaTotal (int &nJ, int &n1);


int main(){

    int n1, nJ, nM;
    char r;
    n1 = 0;
    srand(time(NULL));
    nM = 1 + rand()%(21) ;
    do{

      if(r=='s' || r=='S' || n1==0) {
        reparteCarta(nJ);
        calculaTotal(nJ, n1);
        cout<< "Por ahora tienes "<< n1<<". ";
      }
      if(n1<21){
        cout <<"¿Quieres carta? (s/n).";
        cin>>r;
      }
    } while((r!='n' && r!='N') && n1<21);
    cout<<"Tu puntuación es "<<n1<<" y la de la banca es "<<nM<<endl;
    if(n1>21){
      cout<<"Te pasaste de madre hijoelachingada"<<endl;
    }
    else if(nM<n1){
      cout<<"Has ganado!"<<endl;
    }
    else{
      cout<<"Has perdido!"<<endl;
    }


    return 0;
}

void reparteCarta (int &nJ){
    nJ = 1 + rand()%(12) ;
    cout<<"Te ha salido un "<< nJ <<endl;

}

void calculaTotal (int &nJ, int &n1){
  if(nJ == 1){
    n1 += 11;
  }
  else if( nJ > 9){
    n1+= 10;
  }
  else{
    n1+= nJ;
  }

}
