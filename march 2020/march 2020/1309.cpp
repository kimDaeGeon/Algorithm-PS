#include<iostream>
using namespace std;

enum locate { L = 1, R = 2 };

static int dp[100001][3] = { 0 };
//dp[N][0] = N번째 배치하지 않음
//dp[N][1] = N번째 왼쪽 배치
//dp[N][2] = N번째 오른쪽 배치

int main() {

	int n;
	cin >> n;

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][L] + dp[i - 1][R]) % 9901;
		dp[i][L] = (dp[i - 1][0] + dp[i - 1][R]) % 9901;
		dp[i][R] = (dp[i - 1][0] + dp[i - 1][L]) % 9901;
	}

	cout << (dp[n][0] + dp[n][L] + dp[n][R]) % 9901 << '\n';

	return 0;
}