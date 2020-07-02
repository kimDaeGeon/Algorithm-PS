#include<iostream>
using namespace std;

int fibo[51] = { 0,1,1 };

int main() {
	int test;

	for (int i = 3; i <= 50; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	cin >> test;
	for (int i = 0; i < test; i++) {
		int n; cin >> n;

		if (n == 0) cout << "1 0" << '\n';
		else cout << fibo[n - 1] << " " << fibo[n] << '\n';
	}

	return 0;
}