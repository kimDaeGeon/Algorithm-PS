#include<iostream>
using namespace std;

int max(int a, int b);

int main() {
	int n;

	cin >> n;
	int* price = new int[n+1];
	int dp[1000] = { 0 };
	for (int i = 1; i <= n; i++) cin >> price[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + price[j]);
		}
	}
	cout << dp[n] << '\n';

	return 0;
}

int max(int a, int b) {
	return a > b ? a : b;
}