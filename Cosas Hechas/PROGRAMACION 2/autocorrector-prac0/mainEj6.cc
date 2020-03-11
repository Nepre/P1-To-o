#include <iostream>

using namespace std;

bool friends(unsigned x,unsigned y);
void printMainFriends(unsigned x, unsigned y)
{
	cout << "friends(" << x << "," << y << ")=" << friends(x,y) << endl;
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

void mainFriends()
{
	printMainFriends(2,2);
	printMainFriends(220,284);
	printMainFriends(20,54);
	printMainFriends(6,6);
}


int main()
{
	mainFriends();
}
