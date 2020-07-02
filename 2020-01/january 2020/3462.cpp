#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int stirling(int n, int m);

int main() {
	/*
	int test;
	scanf("%d", &test);
	for (int i = 0; i < test; i++) {
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", stirling(n, m) % 2);
	}
	*/
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d %d = %d\n", i, j, stirling(i, j));
		}
		printf("\n");
	}
	return 0;
}

int stirling(int n, int m) {
	static int dp[10000][10000] = { 0 };
	if (dp[n][m] == 0) {
		if (n == 0 && m == 0) return dp[n][m] = 1;
		if (n > 0 && m == 0) return dp[n][m] = 0;
		if (n == 0 && m > 0) return dp[n][m] = 0;
		if (n > 0 && m > 0) return dp[n][m] = m * stirling(n - 1, m) + stirling(n - 1, m - 1);
	}
	return dp[n][m];
}
