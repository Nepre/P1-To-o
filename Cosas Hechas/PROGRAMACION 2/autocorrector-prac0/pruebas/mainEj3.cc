#include <iostream>
#include <cctype>

using namespace std;

bool checkPassword(const char passwd[]);

void printCheckPasswordTest(const char password[])
{
	cout << "checkPassword("<< password << ")=" << (checkPassword(password)? "true" : "false") << endl;
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


void mainCheckPassword()
{
	printCheckPasswordTest("holaMundo");
	printCheckPasswordTest("hlM7no");
	printCheckPasswordTest("hlM7no8kj43");
	printCheckPasswordTest("hlM7no8kj43aa");
	printCheckPasswordTest("hola, mundo");
	printCheckPasswordTest("0123456789012345");
	printCheckPasswordTest("01234567890123a5");
}

int main() {
    mainCheckPassword();
}
