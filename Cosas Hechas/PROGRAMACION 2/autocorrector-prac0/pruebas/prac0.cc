#include <iostream>
using namespace std;

//g++ -Wall main_prac0.cc prac0.cc -o prac0


void deleteChar (char  str[], char c){
  cout<<c<<endl;
  for (int i = 0; str[i] != '\0'; i++) {
    while (str[i]==c) {
      for (int j = i; str[j] != '\0' ; j++) {
        str[j]=str[j+1];
      }
    }
  }
}
unsigned factorial(unsigned n){
	if (n!=1) {
		return n * factorial(n-1);
	}
	else return 1;
}
bool checkPassword(const char passwd[]){
	int i = 0;
	bool digitosCorrectos = false;
	bool tieneMinusculas = false;
	bool tieneDigitos = false;
	bool tieneMayusculas = false;
	for (i=0; passwd[i] != '\0'; i++) {
		if (islower(passwd[i])) {
			tieneMinusculas = true;
		}
		if (isdigit(passwd[i])) {
			tieneDigitos = true;
		}
		if (islower(passwd[i])) {
		  tieneMayusculas = true;
		}
	}
	if (i<=12 && i>=8) {
		digitosCorrectos = true;
	}

	if(digitosCorrectos && tieneMayusculas && tieneDigitos && tieneMinusculas){
		return true;
	}
	else if (i == 16 && !tieneMayusculas && !tieneMinusculas) {
		return true;
	}
	else{
		return false;
	}

}
int calculator(const int numbers[],unsigned size,const char operators[]){
	int finalValue = numbers[0];
	bool wOperator = false;
	for (int i = 0; i < size - 1 && operators[i] != '\0' && !wOperator; i++) {
		switch (operators[i]) {
			case '+':
				finalValue += numbers[i+1];
				break;
			case '-':
				finalValue -= numbers[i-1]
				brak;
			case '*':
				finalValue *= numbers[i+1];
				break;
			case '/':
				finalValue /= numbers[i+1];
				break;

			default:
				wOperator = true;
		}
	}
	return finalValue;
}
unsigned buildNumber(const unsigned numbers[], unsigned size){
	int nFinal = 0;

	for (int i = 0; i<size; i++) {
		nFinal *= 10;
		nFinal += numbers[i];
	}
		return nFinal;
}
bool friends(unsigned x, unsigned y){
	int n1=0;
	int n2= 0;
	for (int i = 1; i <= x/2; i++) {
		if (x%i==0) {
			n1 += i;
		}
	}
	for (int j = 1; j <= y/2; j++) {
		if (y%j==0) {
			n2 += j;
		}
	}
	return (x == n2 && y == n1);
}
int sumNeighbors(int m[][kMATSIZE],int i,int j){
	int total=0;
	if(i+1 >= 0 && i+1 < 5 && j >= 0 && j < 5) total+=m[i+1][j];
	if(i-1 >= 0 && i-1 < 5 && j >= 0 && j < 5) total+=m[i-1][j];
	if(i >= 0 && i < 5 && j+1 >= 0 && j+1 < 5) total+=m[i][j+1];
	if(i >= 0 && i < 5 && j-1 >= 0 && j-1 < 5) total+=m[i][j-1];
	if(i+1 >= 0 && i+1 < 5 && j+1 >= 0 && j+1 < 5) total+=m[i+1][j+1];
	if(i+1 >= 0 && i+1 < 5 && j-1 >= 0 && j-1 < 5) total+=m[i+1][j-1];
	if(i-1 >= 0 && i-1 < 5 && j+1 >= 0 && j+1 < 5) total+=m[i-1][j+1];
	if(i-1 >= 0 && i-1 < 5 && j-1 >= 0 && j-1 < 5) total+=m[i-1][j-1];
	return total;
}
