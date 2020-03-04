#include<iostream>
using namespace std;

int main() {
	int date, count = 0;
	cin >> date;
	for (int i = 0; i < 5; i++) {
		int car; cin >> car;
		count += (car == date) ? 1 : 0;
	}
	cout << count << endl;

	return 0;
}