#include<iostream>
using namespace std;

int main() {
	int test; cin >> test;
	for (int i = 0; i < test; i++) {
		int n, count = 0;
		cin >> n;
		bool* isOpened = new bool[n+1];
		for (int i = 1; i <= n; i++) isOpened[i] = true;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; i * j <= n; j++) {
				isOpened[i * j] = isOpened[i * j] ? false : true;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (isOpened[i]) count++;
		}
		cout << count << endl;
	}

	return 0;
}