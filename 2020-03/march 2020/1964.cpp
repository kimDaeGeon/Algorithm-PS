#include<iostream>
using namespace std;

int pts[10000001] = { 0,5 };

int main() {
	int n;
	cin >> n;

	if (!pts[n]) {
		for (int i = 2; i <= n; i++) {
			pts[i] = (pts[i - 1] + 2 * (i + 1) + (i - 1)) % 45678;
		}
	}

	cout << pts[n]%45678 << '\n';
	return 0;
}