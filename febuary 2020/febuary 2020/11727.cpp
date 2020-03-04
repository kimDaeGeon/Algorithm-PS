#include<iostream>
using namespace std;

int tiling(int n);

int main() {
	int n;
	cin >> n;
	cout << tiling(n) << '\n';

	return 0;
}

int tiling(int n) {
	static int dp[1001] = { 1,1 };
	if (dp[n] == 0) {
		return dp[n] = (tiling(n-1) + 2 * tiling(n-2)) % 10007;
	}
	return dp[n];
}