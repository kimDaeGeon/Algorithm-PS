#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	cin >> str;

	char alphabet[26];
	for (int i = 0, ch = 65; i < 26; i++, ch++) {
		alphabet[i] = ch;
	}

	int count[26] = { 0 };

	for (char ch : str) {
		for (int i = 0; i < 26; i++) {
			if (ch == alphabet[i] || ch == alphabet[i] + 32) count[i]++;
		}
	}

	for (int i = 0; i < 26; i++)
		cout << count[i] << ' ';
	cout << '\n';

	return 0;
}