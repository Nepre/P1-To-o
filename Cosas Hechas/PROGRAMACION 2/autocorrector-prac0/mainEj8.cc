#include <iostream>

using namespace std;

void printX(int n);

void printPrintX(int n)
{
	cout << "printX(" << n << ")" << endl;
	printX(n);
}

void printX(int n){
	int x1=0;
	int x2=n-1;
	if (n%2==0) {
		cout<<"ERROR"<<endl;
	}
	else{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == x1 || j == x2) {
					cout<<'X';
				}
				else{
					cout<<' ';
				}
			}
			x2--;
			x1++;
			cout<<endl;
		}
		cout<<endl;
	}

}

void mainPrintX()
{
	printPrintX(1);
	printPrintX(2);
	printPrintX(5);
}

int main()
{
	mainPrintX();
}
