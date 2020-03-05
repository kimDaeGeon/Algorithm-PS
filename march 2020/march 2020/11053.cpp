#include<iostream>
using namespace std;

static int dp[1000];

int main() {
	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	int max = dp[0];
	for (int i = 0; i < n; i++) {
		if (dp[i] > max) max = dp[i];
	}

	cout << max << '\n';

	return 0;
}