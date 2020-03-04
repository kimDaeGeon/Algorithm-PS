#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr), cin.tie(nullptr);
	
	int n;
	cin >> n;

	int ten = 0;

	for (int i = 5; i <= n; i *= 5) {
		ten += n / i;
	}

	cout << ten << '\n';

	return 0;
}