#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main() {
	int n;
	int dp[100001] = { 0 };

	scanf("%d", &n);

	for (int i = 1; i*i <= n; i++) {
		dp[i*i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if(dp[i] == 0)
			dp[i] = 10000;
		for (int L = 1, R = i - 1; L <= R; L++, R--) {
			if (dp[i] > dp[L] + dp[R]) {
				dp[i] = dp[L] + dp[R];
			}
		}
	}

	for (int i = 1; i <= n; i++) printf("%d : %d\n", i, dp[i]);
	
	printf("%d", dp[n]);
	return 0;
}