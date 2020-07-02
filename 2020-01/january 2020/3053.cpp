#include<iostream>
#define PI	3.14159265358979
using namespace std;

int main() {
	double r;
	cin >> r;
	
	//cout.precision(10);
	printf("%6f\n", PI * r * r);
	//cout << fixed << PI * r * r << endl;
	//cout.precision(10);
	//cout << fixed << 2 * r * r << endl;
	printf("%6f\n", 2.0 * r * r);
}

/*
(p,	q) (x, y)
|p-x|+|q-y| = 1
x+y = 1, y = -x+1
*/