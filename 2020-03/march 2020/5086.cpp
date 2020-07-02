#include<iostream>
using namespace std;

int main() {
	while (true) {
		int a, b;
		cin >> a >> b;

		if (!a && !b) break;

		if (!(b % a)) cout << "factor" << '\n';
		else if (!(a % b)) cout << "multiple" << '\n';
		else cout << "neither" << '\n';
	}

	return 0;
}