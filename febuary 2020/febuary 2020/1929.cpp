#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr), cin.tie(nullptr);


	int m, n;
	cin >> m >> n;

	vector<int> prime;
	bool* isPrime = new bool[n + 3];

	for (int i = 2; i <= n; i++) isPrime[i] = false;

	for (int i = 2; i <= n; i++) {
		if (!isPrime[i]) {
			prime.push_back(i);
			for (int j = i; j <= n; j += i) {
				isPrime[j] = true;
			}
		}
	}

	for (int p : prime) {
		if (p >= m) cout << p << '\n';
	}

	return 0;
}