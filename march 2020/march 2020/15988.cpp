#include<iostream>
#include<vector>
using namespace std;

static long long dp[1000001] = { 0,1,2,4 };

int main() {
	vector<int> test;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		test.push_back(t);
	}
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
	}


	for (int t : test) {
		cout << dp[t] % 1000000009 << '\n';
	}
	

	return 0;
}