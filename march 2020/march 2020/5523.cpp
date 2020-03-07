#include<iostream>
using namespace std;

int main() {
	int n, a, b;
	cin >> n;

	a = b = 0;
	while (n--) {
		int score1, score2;
		cin >> score1 >> score2;
		if (score1 > score2) a++;
		else if (score1 < score2) b++;
		else continue;
	}

	cout << a << ' ' << b << '\n';

	return 0;
}