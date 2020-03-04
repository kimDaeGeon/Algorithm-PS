#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main() {
	int x, count = 0;
	scanf("%d", &x);

	while (x != 0) {
		if (x == 64) {
			x -= 64; count++;
		}
		if (x >= 32) {
			x -= 32; count++;
		}
		if (x >= 16) {
			x -= 16; count++;
		}
		if (x >= 8) {
			x -= 8; count++;
		}
		if (x >= 4) {
			x -= 4; count++;
		}
		if (x >= 2) {
			x -= 2; count++;
		}
		if (x >= 1) {
			x -= 1; count++;
		}

	}
	printf("%d", count);
}