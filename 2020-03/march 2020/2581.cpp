#include<iostream>
using namespace std;

bool isPrime[10001];

int main() {
	for (int i = 2; i <= 10000; i++) {
		isPrime[i] = true;
	}
	for (int i = 2; i <= 10000; i++) {
		if (isPrime[i]) {
			for (int j = 2; i * j <= 10000; j++) {
				isPrime[i * j] = false;
			}
		}
	}

	long long sum = 0;

	bool findMinIdx = false;
	int from, to, min;
	cin >> from >> to;

	for (int idx = from; idx <= to; idx++) {
		if (isPrime[idx]) {
			if (!findMinIdx) min = idx, findMinIdx = true;
			sum += idx;
		}
	}

	if (!sum) cout << -1 << '\n';
	else cout << sum << '\n' << min << '\n';

	return 0;
}