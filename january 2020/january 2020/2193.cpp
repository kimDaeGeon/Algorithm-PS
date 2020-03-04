#include<iostream>
#pragma warning(disable:4996)
using namespace std;

long long pinary(int n);

int main() {
	int n;
	scanf("%d", &n);
	printf("%lld", pinary(n));

	return 0;
}

long long pinary(int n) {
	static long long dp[91] = { 0, 1, 1, 2 };
	if (dp[n] != 0) return dp[n];
	else return dp[n] = pinary(n - 1) + pinary(n - 2);
}