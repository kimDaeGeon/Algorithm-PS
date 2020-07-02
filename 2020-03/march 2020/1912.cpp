#include<iostream>
using namespace std;

static long long dp[100000];

int main() {
	int size;
	cin >> size;

	int* arr = new int[size];
	for (int i = 0; i < size; i++) cin >> arr[i];

	dp[0] = arr[0];
	for (int i = 1; i < size; i++) {
		dp[i] = (arr[i] > dp[i - 1] + arr[i] ? arr[i] : dp[i - 1] + arr[i]);
	}

	long long max = dp[0];
	for (int i = 0; i < size; i++) {
		if (dp[i] > max) max = dp[i];
	}
	 
	cout << max << '\n';

	return 0;
}