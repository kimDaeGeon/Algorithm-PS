#include<iostream>
using namespace std;

unsigned long long nCr(int n, int r);

int main() {
	int n, k;
	cin >> n >> k;
	cout << nCr(n, k) << endl;
}

unsigned long long nCr(int n, int r) {
	unsigned long long top = 1;
	unsigned long long bottom = 1;
	for (int i = n - r + 1, j = r; i <= n; i++, j--) {
		//cout << i << ", " << j << endl;
		top *= i;
		if (top % j == 0) top /= j;
		else bottom *= j;
	}
	return top / bottom;
}