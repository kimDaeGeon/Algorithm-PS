#include<iostream>
using namespace std;

int main() {
	int test;
	cin >> test;

	while (test--) {
		int noadv, adv, cost;
		cin >> noadv >> adv >> cost;

		if (noadv > adv - cost) {
			cout << "do not advertise" << '\n';
		}
		else if (noadv < adv - cost) {
			cout << "advertise" << '\n';
		}
		else {
			cout << "does not matter" << '\n';
		}
	}


	return 0;
}