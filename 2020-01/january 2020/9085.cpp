#include<iostream>
using namespace std;

int main() {
	int test;
	cin >> test;
	for (int i = 0; i < test; i++) {
		int size, sum = 0;
		cin >> size;
		for (int i = 0; i < size; i++) {
			int temp; cin >> temp;
			sum += temp;
		}
		cout << sum << endl;
	}

	return 0;
}