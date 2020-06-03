#include <iostream>
#include <math.h>
using namespace std;

bool end(int n) {
	int six = 0;
	int digit = 0;
	int div = n;
	while (div > 0) {
		div /= 10;
		digit++;
	}

	int* eachN = new int[digit];

	for (int i = digit - 1; i >= 0; i--) {
		eachN[i] = n / (int)pow(10, i);
		n -= eachN[i] * (int)pow(10, i);
	}

	for (int i = 0; i < digit-2; i++) {
		if (eachN[i] == 6 && eachN[i + 1] == 6 && eachN[i + 2] == 6) {
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;

	int nth = 0;
	int i = 0;
	while (true) {
		if (end(i)) {
			//cout << nth << " : " << i << '\n';
			if (++nth == n) {
				cout << i << '\n';
				return 0;
			}
		}
		i++;
	}
}