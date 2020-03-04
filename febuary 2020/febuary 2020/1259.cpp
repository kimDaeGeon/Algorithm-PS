#include<iostream>
#include<string>
using namespace std;

int main() {

	while (true) {
		string n;
		cin >> n;

		if (n == "0") break;
		bool isPelindrom = true;
		for (int i = 0; i < n.length()/2 ; i++) {
			if (n[i] != n[n.length() - i - 1]) {
				isPelindrom = false;
				break;
			}
		}
		if (isPelindrom) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}

	return 0;
}