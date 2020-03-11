#include <iostream>
#include <math.h>

using namespace std;

unsigned buildNumber(const unsigned numbers[],unsigned size);

#define funcPrintArray(array, size)\
	cout << "{";\
	for (int i=0; i < (int)size; i++)\
	{\
		if (i)\
			cout << ",";\
			cout << array[i];\
	}\
	cout << "}";

void printBuildNumberTest(const unsigned v[], unsigned real_size, unsigned size)
{
	cout << "buildNumber(";
	funcPrintArray(v, real_size);
	cout << ", " << size << ")=" << buildNumber(v, size) << endl;
}

unsigned buildNumber(const unsigned numbers[], unsigned size){
	int nFinal = 0;

	for (int i = 0; i<size; i++) {
		nFinal *= 10;
		nFinal += numbers[i];
	}
		return nFinal;
}

void mainBuildNumber()
{
	const unsigned v1[] = {1,2,3,4,5};
	printBuildNumberTest(v1, 5, 5);

	const unsigned v2[] = {4,3,0,2,2,2};
	printBuildNumberTest(v2, 6, 6);

	const unsigned v3[] = {0,4,2};
	printBuildNumberTest(v3, 3, 3);
}


int main()
{
	mainBuildNumber();
}
