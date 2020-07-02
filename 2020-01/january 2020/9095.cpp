#include<iostream>
using namespace std;

int partition(int n);

int main() {
	int* test, size;
	cin >> size; test = new int[size];
	for (int i = 0; i < size; i++) {
		int n; cin >> n;
		test[i] = partition(n);
	}


	for (int i = 0; i < size; i++)
		cout << test[i] << endl;

	return 0;
}

int partition(int n) {
	static int dp[11] = { 0,1,2,4 };
	if (dp[n] != 0)return dp[n];
	return dp[n] = partition(n - 1) + partition(n - 2) + partition(n - 3);
}