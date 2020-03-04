#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int occasion(const int arr[][500], int size);

int main() {
	int arr[500][500] = { 0 };
	int size;
	scanf("%d", &size);

	for (int y = 0; y < size; y++) {
		for (int x = 0; x <= y; x++) {
			scanf("%d", &arr[y][x]);
		}
	}

	for (int y = 0; y < size; y++) {
		for (int x = 0; x <= y; x++) {
			printf("%d", arr[y][x]);
		}
		putchar('\n');
	}



	return 0;
}

int occasion(const int arr[][500], int size) {
	static int dp[500] = { 0 };
}