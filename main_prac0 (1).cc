#include <iostream>

using namespace std;

const unsigned kMATSIZE=5;

// Prototipos de las funciones
void deleteChar(char str[],char c);
unsigned factorial(unsigned n);
bool checkPassword(const char passwd[]);
int calculator(const int numbers[],unsigned size,const char operators[]);
unsigned buildNumber(const unsigned numbers[],unsigned size);
bool friends(unsigned x,unsigned y);
int sumNeighbors(int m[][kMATSIZE],int row,int col);
void printX(int n);

// 1. Borrar caracteres
void mainDeleteChar()
{
  char test1[]="cadena de pruebaas";
  cout << "deleteChar(\"" << test1 << "\",'a'), test=\"";
  deleteChar(test1,'a');
  cout << test1 << "\"" << endl;

  char test2[]="cadena de pruebaas";
  cout << "deleteChar(\"" << test2 << "\",'e'), test=\"";
  deleteChar(test2,'e');
  cout << test2 << "\"" << endl;

  char hola1[]="hola, mundo";
  cout << "deleteChar(\"" << hola1 << "\",'a'), hola=\"";
  deleteChar(hola1,'a');
  cout << hola1 << "\"" << endl;

  char hola2[]="hola, mundo";
  cout << "deleteChar(\"" << hola2 << "\",'o'), hola=\"";
  deleteChar(hola2,'o');
  cout << hola2 << "\"" << endl;
}

// 2. Factorial
void mainFactorial()
{
  cout << "factorial(1)=" << factorial(1) << endl;
  cout << "factorial(2)=" << factorial(2) << endl;
  cout << "factorial(3)=" << factorial(3) << endl;
  cout << "factorial(5)=" << factorial(5) << endl;
}

// 3. Comprobar contraseña
void mainCheckPassword()
{
   cout << "checkPassword(\"holaMundo\")=" << checkPassword("holaMundo") << endl;
   cout << "checkPassword(\"hlM7no\")=" << checkPassword("hlM7no") << endl;
   cout << "checkPassword(\"hlM7no8kj43\")=" << checkPassword("hlM7no8kj43") << endl;
   cout << "checkPassword(\"hlM7no8kj43aa\")=" << checkPassword("hlM7no8kj43aa") << endl;
   cout << "checkPassword(\"hola, mundo\")=" << checkPassword("hola, mundo") << endl;
   cout << "checkPassword(\"0123456789012345\")=" << checkPassword("0123456789012345") << endl;
   cout << "checkPassword(\"01234567890123a5\")=" << checkPassword("01234567890123a5") << endl;
}

// 4. Calculadora
void mainCalculator()
{
  const int numbers[]={10,15,4,-5};

  cout << "calculator(numbers, 4, \"+*/\")=" << calculator(numbers,4,"+*/") << endl;
  cout << "calculator(numbers, 2, \"+*/\")=" << calculator(numbers,2,"+*/") << endl;
  cout << "calculator(numbers, 3, \"+*/\")=" << calculator(numbers,3,"+*/") << endl;
  cout << "calculator(numbers, 4, \"+:/\")=" << calculator(numbers,4,"+:/") << endl;
  cout << "calculator(numbers, 1, \"+:/\")=" << calculator(numbers,1,"+:/") << endl;
}

// 5. Construir un número
void mainBuildNumber()
{
  const unsigned v1[] = {1,2,3,4,5};
  cout << "buildNumber({1,2,3,4,5},5)=" << buildNumber(v1,5) << endl;

  const unsigned v2[] = {4,3,0,2,2,2};
  cout << "buildNumber({4,3,0,2,2,2},6)=" << buildNumber(v2,6) << endl;

  const unsigned v3[] = {0,4,2};
  cout << "buildNumber({0,4,2},3)=" << buildNumber(v3,3) << endl;
}

// 6. Números amigos
void mainFriends()
{
  cout << "friends(2,2)=" << friends(2,2) << endl;
  cout << "friends(220,284)=" << friends(220,284) << endl;
  cout << "friends(20,54)=" << friends(20,54) << endl;
  cout << "friends(6,6)=" << friends(6,6) << endl;
}

// 7. Los vecinos suman
void mainSumNeighbors()
{
  int matrix[kMATSIZE][kMATSIZE] = { 1, 2, 3, 4, 5,
                                     6, 7, 8, 9,10,
                                    11,12,13,14,15,
                                    16,17,18,19,20,
                                    21,22,23,24,25
                                   };
  cout << "sumNeighbors(matrix,2,2)=" << sumNeighbors(matrix,2,2) << endl;
  cout << "sumNeighbors(matrix,0,0)=" << sumNeighbors(matrix,0,0) << endl;
  cout << "sumNeighbors(matrix,4,4)=" << sumNeighbors(matrix,4,4) << endl;
}

// 8. Imprimir una X
void mainPrintX()
{
  cout << "printX(1)" << endl; printX(1);
  cout << "printX(2)" << endl; printX(2);
  cout << "printX(5)" << endl; printX(5);
}

int main()
{
  mainDeleteChar();
  mainFactorial();
  mainCheckPassword();
  mainCalculator();
  mainBuildNumber();
  mainFriends();
  mainSumNeighbors();
  mainPrintX();

  return 0;
}
