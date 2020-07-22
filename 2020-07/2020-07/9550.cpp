#include<iostream>
using namespace std;

int main() {
	int test;
	cin >> test;

	while (test--) {
		int max = 0;
		int n, k;
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			int candy;
			cin >> candy;
			max += candy / k;
		}
		cout << max << '\n';
	}

	return 0;
}