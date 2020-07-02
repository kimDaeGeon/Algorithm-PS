#include<iostream>
using namespace std;

unsigned long long nCk(int n, int k);

int main() {
	int test; cin >> test;
	for (int i = 0; i < test; i++) {
		int n, k; cin >> n >> k;
		cout << nCk(n - 1, k) << endl;
	}
}

unsigned long long nCk(int n, int k) {
	unsigned long long bottom = 1;
	unsigned long long top = 1;
	int temp = k;
	for (int i = n; i >= n-temp+1; i--, k--) {
		top *= i;
		if (k > 0) {
			if (top % k == 0) top /= k;
			else bottom *= k;
		}
	}
	return  top /bottom;
}