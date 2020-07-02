#include<iostream>
#include<math.h>
using namespace std;

int constructor(int n) {
	int result = n;
	int div = n;
	int digit = 0;
	while (div > 0) {
		div /= 10; digit++;
	}
	for (int d = digit; d >= 0; d--) {
		int each = n / (int)pow(10, d);
		n -= each * (int)pow(10, d);
		result += each;
	}

	return result;
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= 1000000; i++) {
		if (constructor(i) == n) {
			cout << i << '\n';
			return 0;
		}
	}

	cout << 0 << '\n';

	return 0;
}