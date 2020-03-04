#include<stdio.h>

int main() {

	int test;
	scanf("%d", &test);
	for (int i = 0; i < test; i++) {
		int n, max;
		scanf("%d",&n); max = n;
		while (n != 1) {
			if (n % 2 == 0) n /= 2;
			else {
				n *= 3; n++;
				max = n > max ? n : max;
			}
		}
		printf("%d\n", max);
	}

	return 0;
}