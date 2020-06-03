#include<iostream>
#include<math.h>
using namespace std;

bool KumMinSu(int n) {
	int div = n;
	int digit = 0;
	while (div > 0) {
		div /= 10; digit++;
	}
	for (int d = digit-1; d >= 0; d--) {
		int each = n / (int)pow(10, d);
		n -= each * (int)pow(10, d);
		if (each != 4 && each != 7) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int i = n; i >= 4; i--) {
		if (KumMinSu(i)) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}