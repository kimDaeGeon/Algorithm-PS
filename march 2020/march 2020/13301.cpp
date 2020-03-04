#include<iostream>
using namespace std;

long long fibo(int n);

int main() {
	int n;
	cin >> n;

	cout << fibo(n) * 2 + fibo(n - 1) * 2 << '\n';

	return 0;
}

long long fibo(int n) {
	static long long dp[100] = { 1,1 };
	if (!dp[n]) return dp[n] = fibo(n - 1) + fibo(n - 2);
	else return dp[n];
}