#include<iostream>
using namespace std;

int main() {
	int price, count = 0;
	cin >> price;
	price = 1000 - price;

	if (price / 500 >= 1) {
		count += price / 500;
		price -= 500 * (price / 500);
	}
	if (price / 100 >= 1) {
		count += price / 100;
		price -= 100 * (price / 100);
	}
	if (price / 50 >= 1) {
		count += price / 50;
		price -= 50 * (price / 50);
	}
	if (price / 10 >= 1) {
		count += price / 10;
		price -= 10 * (price / 10);
	}
	if (price / 5 >= 1) {
		count += price / 5;
		price -= 5 * (price / 5);
	}
	
	count += price;
	cout << count << endl;


	return 0;
}