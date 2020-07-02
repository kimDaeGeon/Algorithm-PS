#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main() {
	int test;
	scanf("%d", &test);
	for (int i = 0; i < test; i++) {
		int a, b;
		scanf("%d, %d", &a, &b);
		printf("%d\n", a + b);
	}
}