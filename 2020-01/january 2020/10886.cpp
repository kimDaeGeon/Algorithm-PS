#include<iostream>
using namespace std;

int main() {
	int test, sum = 0;
	cin >> test;
	for (int i = 0; i < test; i++) {
		int in; cin >> in;
		sum += in;
	}
	
	if (sum > test / 2.0)
		cout << "Junhee is cute!" << endl;
	else
		cout << "Junhee is not cute!" << endl;

	return 0;
}