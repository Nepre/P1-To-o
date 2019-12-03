//Grupo 402

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


void pidMov (int &, int &);
void genPos (int &, int &, int &, int &);
bool escMen(int, int, int, int, int, int);
void escPos(int, int, int, int, int, int);


int main(){
	int fJug, cJug, fTes, cTes, fMon, cMon;
	bool fin;
	char debug;
	
	srand(time(NULL));
	fin=false;
	fJug=1;
	cJug=1;
	genPos(fTes, cTes, fMon, cMon);	
	cout << "¿Quieres jugar en modo Debug (s/n)? ";
	cin >> debug;	
	do{
		if (debug=='s')
			escPos(fJug, cJug,fTes, cTes, fMon, cMon);
		pidMov(fJug, cJug);
		fin=escMen(fJug, cJug,fTes, cTes, fMon, cMon);
	}while (!fin);
	
	return 0;
}

//Pide el movimiento del jugador
void pidMov (int &f, int &c){
	char mov;
	bool pared;
	
	
	do{
		do{
			cout << "Introduce movimiento(U/D/L/R): ";
			cin >> mov;
			if (mov!='U' && mov!='D' && mov!='L' && mov!='R')
				cout << "Error: Los movimientos pueden ser: U, D, L, R\n";
		}while (mov!='U' && mov!='D' && mov!='L' && mov!='R');
		pared=false;
		switch (mov){
			case 'U': if (f>1)
						f--;
					  else
						pared=true;
					break;
			case 'D': if (f<4)
						f++;
					  else
						pared=true;
					break;
			case 'L': if (c>1)
						c--;
					  else
						pared=true;
					break;
					
			case 'R': if (c<4)
						c++;
					  else
						pared=true;
					break;
		}
		if (pared)
			cout << "Error: no te puedes salir del mundo\n";
	}while (pared);
}

//Genera las posiciones del tesoro y del monstruo
void genPos (int &fTes, int &cTes, int &fMon, int &cMon){
	
	do{
		fTes=rand()%4+1;
		cTes=rand()%4+1;
	}while (fTes==1 && cTes==1);
	do{
		fMon=rand()%4+1;
		cMon=rand()%4+1;	
	}while ((fTes==fMon && cTes==cMon) || (fMon==1 && cMon==1));
}

//Muestra las posiciones de los personajes
void escPos(int fJug, int cJug, int fTes, int cTes, int fMon, int cMon){
	
	cout << "Posiciones \n";
	cout << "\tJugador " << "Fila: "  << fJug << " Col: " << cJug << endl;
	cout << "\tTesoro " << "Fila: "  << fTes << " Col: " << cTes << endl;
	cout << "\tMonstruo " << "Fila: "  << fMon << " Col: " << cMon << endl;
}

//Muestra el mensaje tras cada movimiento del jugador
bool escMen(int fJug, int cJug, int fTes, int cTes, int fMon, int cMon){
	bool terminar;
	
	terminar=true;
	
	if (fJug==fTes && cJug==cTes)
		cout << "Felicidades: has encontrado el tesoro, has ganado\n";
	else if (fJug==fMon && cJug==cMon)
		cout << "Horror: el monstruo te ha devorado, has perdido\n";
	else{
		cout << "Estás en una celda fría y oscura…\n";
		terminar=false;
	}
	
	return terminar;
}
