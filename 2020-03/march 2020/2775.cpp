#include<iostream>
using namespace std;

long long dp[15][15] = { 0 };

int main() {
	int test;
	cin >> test;

	//0Ãþ
	for (int i = 1; i < 15; i++) {
		dp[0][i] = 1;
	}

	//dp[i][j] = dp[i-1][j] + dp[i][j-1]
	for (int i = 1; i <= 15; i++) {
		for (int j = 1; j < 15; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	while (test--) {
		int k, n;
		cin >> k >> n;
		cout << dp[k+1][n] << '\n';
	}

	return 0;
}