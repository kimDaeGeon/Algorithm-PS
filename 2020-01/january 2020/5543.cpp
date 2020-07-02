#include<iostream>
using namespace std;

int main() {
	int min1, min2;
	int burger, drink;
	min1 = min2 = 2000;
	for (int i = 0; i < 3; i++) {
		cin >> burger;
		min1 = burger < min1 ? burger : min1;
	}
	for (int i = 0; i < 2; i++) {
		cin >> drink;
		min2 = drink < min2 ? drink : min2;
	}

	cout << min1 + min2 - 50 << endl;

	return 0;
}