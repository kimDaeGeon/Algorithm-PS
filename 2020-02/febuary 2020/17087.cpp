#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a, int b);
int maxMovement(int gap[], int n);

int main() {
	int n;
	cin >> n;

	if (n != 1) {
		int* position = new int[n + 1];
		for (int i = 0; i < n + 1; i++) {
			cin >> position[i];
		}

		std::sort(position, position + n + 1);

		int* gap = new int[n];
		for (int i = 0; i < n; i++) {
			gap[i] = position[i + 1] - position[i];
		}

		cout << maxMovement(gap, n) << '\n';
	}
	else {
		int position, brother;
		cin >> position >> brother;
		cout << (position > brother ? position - brother : brother - position) << '\n';
	}

	return 0;
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int maxMovement(int gap[], int n) {
	int ret = gcd(gap[0], gap[1]);
	for (int i = 1; i < n-1; i++) {
		ret = gcd(ret, gap[i + 1]);
	}
	return ret;
}