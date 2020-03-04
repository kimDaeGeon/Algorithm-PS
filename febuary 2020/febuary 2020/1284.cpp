#include<iostream>
#include<string>
using namespace std;

int main() {
	while (true) {
		string n;
		cin >> n;
		if (n == "0") break;
		else {
			int len = n.length() + 1;
			for (char ch : n) {
				switch (ch) {
				case '0': len += 4; break;
				case '1': len += 2; break;
				default: len += 3; break;
				}
			}
			cout << len << '\n';
		}
	}
}