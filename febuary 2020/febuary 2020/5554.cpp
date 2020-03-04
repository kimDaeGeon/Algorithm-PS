#include<iostream>
using namespace std;

int main() {

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int total = a + b + c + d;

	cout << ((int)total / 60) << '\n' << total % 60 << '\n';


	return 0;
}