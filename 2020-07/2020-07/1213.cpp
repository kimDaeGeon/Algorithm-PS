#include<bits/stdc++.h>
using namespace std;

int alphabet[26] = { 0 };

int main() {
	string name, palendrome = "";
	cin >> name;

	if (name.length() == 1) {
		cout << name << '\n';
	}

	// even
	else if (name.length() % 2 == 0) {
		for (int i = 0; i < name.length(); i++) {
			alphabet[name[i] - 65]++;
		}

		for (int i = 0; i < 26; i++) {
			if (alphabet[i] != 0 && alphabet[i] % 2 != 0) {
				cout << "I'm Sorry Hansoo" << '\n';
				return 0;
			}
		}

		for (int i = 0; i < 26; i++) {
			int count = alphabet[i] / 2;
			for (int j = 0; j < count; j++) {
				while (count != 0) {
					palendrome += (char)('A' + i);
					count--;
				}
			}
		}

		cout << palendrome;
		reverse(palendrome.begin(), palendrome.end());
		cout << palendrome;
		
		return 0;
	}

	// odd
	else if (name.length() % 2 == 1) {
		int odd = 0;
		int ch;

		for (int i = 0; i < name.length(); i++) {
			alphabet[name[i] - 65]++;
		}

		for (int i = 0; i < 26; i++) {
			if (alphabet[i] % 2 == 1) {
				ch = i;
				odd++;
			}
			if (odd >= 2) {
				cout << "I'm Sorry Hansoo" << '\n';
				return 0;
			}
		}
		
		// count(odd) == 1
		alphabet[ch]--;
		for (int i = 0; i < 26; i++) {
			if (alphabet[i] % 2 == 0) {
				int count = alphabet[i] / 2;
				while (count != 0) {
					palendrome += (char)('A' + i);
					count--;
				}
			}
		}
		

		cout << palendrome;
		cout << (char)('A' + ch);
		reverse(palendrome.begin(), palendrome.end());
		cout << palendrome;

		return 0;
	}
}