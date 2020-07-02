#include<iostream>
#pragma warning(disable:4996)
using namespace std;

long long pado(int n);

int main() {
	int test; cin >> test;

	for (int i = 0; i < test; i++) {
		int n;
		cin >> n;
		cout << pado(n) << endl;
	}

	return 0;
}

long long pado(int n) {
	static long long dp[101] = { 0,1,1,1,2,2,3,4 };
	if (dp[n] != 0) return dp[n];
	return dp[n] = pado(n - 1) + pado(n - 5);
}