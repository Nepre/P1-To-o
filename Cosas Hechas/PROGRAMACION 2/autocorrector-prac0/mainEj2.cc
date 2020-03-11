#include <iostream>

using namespace std;

unsigned factorial(unsigned n);


void printFactorialTest(int n)
{
	cout << "factorial(" << n << ")=" << factorial(n) << endl;
}

unsigned factorial(unsigned n){
	if (n!=1) {
		return n * factorial(n-1);
	}
	else return 1;
}

void mainFactorial()
{
	printFactorialTest(1);
	printFactorialTest(2);
	printFactorialTest(3);
	printFactorialTest(5);
}

int main() {
    mainFactorial();
}
