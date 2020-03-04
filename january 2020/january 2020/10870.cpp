#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int fibo(int n);

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", fibo(n));

	return 0;
}

int fibo(int n) {
	static int dp[21] = { 0,1,1 };
	if (n == 0) return 0;
	else if (dp[n] != 0) return dp[n];
	else return dp[n] = fibo(n - 1) + fibo(n - 2);
}