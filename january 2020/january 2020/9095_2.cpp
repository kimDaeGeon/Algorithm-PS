#include<iostream>
using namespace std;

int main() {
	int dp[11] = { 0,1,2,4 };
	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	int test; cin >> test;
	for (int i = 0; i < test; i++) {
		int n; cin >> n;
		cout << dp[n] << endl;
	}
}