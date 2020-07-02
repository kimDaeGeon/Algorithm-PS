#include<iostream>
using namespace std;

int gcd(int x, int y);

int main() {
	int test;
	cin >> test;

	for (int i = 0; i < test; i++) {
		int n;
		cin >> n;

		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}

		cout << sum << '\n';
	}

	return 0;
}

int gcd(int x, int y) {
	if (!y) return x;
	else return gcd(y, x % y);
}