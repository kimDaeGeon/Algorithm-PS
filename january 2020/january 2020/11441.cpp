#include<stdio.h>
#pragma warning (disable : 4996)

int main() {
	int* arr, size;
	scanf("%d", &size);
	arr = new int[size];
	
	for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

	int test;
	scanf("%d", &test);
	for (int i = 0; i < test; i++) {
		int n, m, sum = 0;
		scanf("%d %d", &n, &m);
		for (int idx = n - 1; idx < m; idx++) {
			sum += arr[idx];
		}
		printf("%d\n", sum);
	}
}