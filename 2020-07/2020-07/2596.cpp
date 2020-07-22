#include<bits/stdc++.h>
using namespace std;

bool isSame(string str1, string str2) {
	int same = 0, diff = 0;
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] == str2[i]) same++;
		else diff++;
	}
	if (diff <= 1) return true;
	return false;
}
char getKey(string substr) {
	if (isSame(substr, "000000")) return 'A';
	else if (isSame(substr, "001111")) return 'B';
	else if (isSame(substr, "010011")) return 'C';
	else if (isSame(substr, "011100")) return 'D';
	else if (isSame(substr, "100110")) return 'E';
	else if (isSame(substr, "101001")) return 'F';
	else if (isSame(substr, "110101")) return 'G';
	else if (isSame(substr, "111010")) return 'H';
	return ' ';
}

int main() {
	int n;
	cin >> n;

	string str;
	cin >> str;

	string ans;

	for (int i = 0; i < str.length(); i+=6) {
		char key = getKey(str.substr(i, 6));
		//cout << str.substr(i, 6) << '\n';
		//cout << key << '\n';
		if (key != ' ') {
			ans += key;
		}
		else {
			cout << i/6 + 1 << '\n';
			return 0;
		}
	}
	cout << ans << '\n';


	return 0;
}