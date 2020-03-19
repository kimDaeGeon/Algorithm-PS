#include<iostream>
using namespace std;

static long long dp[50] = { 0,1 };

int main() {

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	
	cout << dp[n] << '\n';

	return 0;
}