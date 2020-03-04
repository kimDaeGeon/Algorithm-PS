#include<iostream>
using namespace std;

long long koong(int n);

int main() {
	int size; cin >> size;
	for (int i = 0; i < size; i++) {
		int n; cin >> n;
		cout << koong(n) << endl;
	}

	return 0;
}

long long koong(int n) {
	static long long dp[100] = { 1,1,2,4 };
	if (dp[n] != 0)return dp[n];
	dp[n] = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
	return dp[n];
}