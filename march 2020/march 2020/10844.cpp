#include<iostream>
using namespace std;

int dp[101][10] = { {}, {1,1,1,1,1,1,1,1,1,1} };

int main() {
	int n;
	cin >> n;

	for (int i = 2; i <= 100; i++) {
		dp[i][1] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][9];
		for (int j = 2; j <= 8; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
		}
	}

	int stair = 0;
	for (int i = 1; i <= 9; i++) {
		stair += dp[n][i];
	}
	cout << stair << '\n';


	return 0;
}