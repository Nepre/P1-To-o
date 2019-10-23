#include <iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;


void reparteCarta(int nM, int &nJ);
void calculaTotal(int nM, int &nJ,char r);


int main(){
    
    int n1, nJ, nM;
    char r;
    
    srand(time(NULL));
    reparteCarta(nM, nJ);
    calculaTotal(nM, nJ, r);
    return 0;
}

void reparteCarta (int nM, int &nJ){
    
    nM = 1 + rand()%(21) ;
    nJ = 1 + rand()%(12) ;
    cout<<"Te ha salido un "<< nJ <<endl;
}

void calculaTotal (int nM, int &nJ, char r){
    
    cout<< "Por ahora tienes "<< nJ <<". ¿Quieres carta? (s/n).";
    cin>>r;
    do{
        cout<< "Por ahora tienes "<< nJ <<". ¿Quieres carta? (s/n).";
        cin>>r;
        nJ = nJ + 1 + rand()%(12);
        cout<<nJ<<endl;
   
        
    }while (r=='s' || r=='S' && nJ<21);
    

}
    
        
        