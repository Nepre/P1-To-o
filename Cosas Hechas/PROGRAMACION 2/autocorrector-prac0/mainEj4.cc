#include <iostream>

using namespace std;

int calculator(const int numbers[],unsigned size,const char operators[]);

#define funcPrintArray(array, size)\
	cout << "{";\
	for (int i=0; i < (int)size; i++)\
	{\
		if (i)\
			cout << ",";\
		cout << array[i];\
	}\
	cout << "}";

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


void printCalculatorTest(const int numbers[], int numbers_length, int size, const char operators[])
{
	cout << "calculator(";
	funcPrintArray(numbers, numbers_length);
	cout << "," << size << operators << ")=" << calculator(numbers, size, operators) << endl;
}

void mainCalculator()
{
	const int numbers1[]={10,15,4,-5};
	int numbers_length1 = 4;

	printCalculatorTest(numbers1, numbers_length1, 4, "+*/");
	printCalculatorTest(numbers1, numbers_length1, 2, "+*/");
	printCalculatorTest(numbers1, numbers_length1, 3, "+*/");
	printCalculatorTest(numbers1, numbers_length1, 4, "+:/");
	printCalculatorTest(numbers1, numbers_length1, 1, "+:/");
}

int main()
{
	mainCalculator();
}
