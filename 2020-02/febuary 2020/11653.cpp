#include<iostream>
#include<vector>
using namespace std;

vector<int> getPrime(int n);

int main() {
	int n;
	cin >> n;

	vector<int> prime = getPrime(n);
	vector<int> division;

	while (n != 1) {
		for (int i = 0; i < prime.size(); i++) {
			if (!(n % prime[i])) {
				division.push_back(prime[i]);
				n /= prime[i];
				break;
			}
		}
	}

	for (int i : division) {
		cout << i << '\n';
	}


	return 0;
}

vector<int> getPrime(int n) {
	vector<int> prime;
	bool* isPrime = new bool[n + 2];
	for (int i = 0; i < n + 2; i++) isPrime[i] = true;

	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			prime.push_back(i);
			for (int j = i + i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
	return prime;
}