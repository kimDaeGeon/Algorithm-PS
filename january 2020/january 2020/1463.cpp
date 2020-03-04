#include<iostream>
using namespace std;

int dp[10000000] = { 0 };
int main() {
	int n; cin >> n;

	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		int sol[3] = { 100000,100000,100000 };
		sol[0] = dp[i - 1] + 1;
		if (i % 2 == 0) sol[1] = dp[i / 2] + 1;
		if (i % 3 == 0) sol[2] = dp[i / 3] + 1;

		dp[i] = sol[0] > sol[1] ? sol[1] : sol[0];
		dp[i] = dp[i] > sol[2] ? sol[2] : dp[i];
		//cout << dp[i] << endl;
	}
	cout << dp[n] << endl;
}