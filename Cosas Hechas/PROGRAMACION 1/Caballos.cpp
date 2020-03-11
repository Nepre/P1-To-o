//Problema del Caballo
#include <iostream>
using namespace std;


void movimientos(int f, int c){
	int fil, col, i =1, j, a, k=1;
	
	for(j =0; j<2;j++){
		for(a=0; a<2; a++){
			fil = f + 2*k;
			col = c + i;
			if(fil >0 && fil<9 && col >0 && col<9){
				cout<<"("<<fil<<","<<col<<") ";}
			else {
			}
			i = i-2;
		}
		i=1;
		k=k-2;
	}
	i=1;
	k=1;
	
	for(j =0; j<2;j++){
		for(a=0; a<2; a++){
			fil = f + i;
			col = c + 2*k;
			if(fil >0 && fil<9 && col >0 && col<9){
				cout<<"("<<fil<<","<<col<<") ";}
			else {
			}
			i = i-2;
		}
		i=1;
		k=k-2;
	}
}



int main(){
	
	int fila, columna;
	cout<<"En que fila está el caballo?: ";
	cin>>fila;
	cout<<"En que columna está el caballo?: ";
	cin>>columna;
	
	movimientos(fila, columna);
	return 0;	
}
