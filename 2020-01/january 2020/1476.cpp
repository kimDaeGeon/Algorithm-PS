#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main() {
	int E, S, M;
	scanf("%d %d %d", &E, &S, &M);

	int year = 0;
	while (true) {
		if (year % 15 == E-1 && year % 28 == S-1 && year % 19 == M-1) break;
		year++;
	}

	printf("%d", year+1);

	return 0;
}