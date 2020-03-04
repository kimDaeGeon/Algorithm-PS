#include<iostream>
using namespace std;

long long dp[100000] = { 0,0,0,2,3 };

int main() {
	int test;
	cin >> test;

	while (test--) {
		int n;
		cin >> n;

		if (n < 4) {
			cout << dp[n] << '\n';
		}
		else {
			if (dp[n] != 0) {
				cout << dp[n] << '\n';
			}
			else {
				for (int i = 5; i <= n; i++) {
					dp[i] = (2 * dp[i - 3] + 2 * dp[i - 4] + 2 * dp[i - 5]) % 1000000009;
				}
				cout << dp[n] % 1000000009 << '\n';
			}
		}
		
	}
	return 0;
}