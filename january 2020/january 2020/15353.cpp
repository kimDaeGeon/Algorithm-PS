#include<iostream>
#include<string>
using namespace std;

int toInt(char c);
char toChar(int i);
string plus(string n1, string n2);

int main() {
	string n1, n2, temp;

	cin >> n1 >> n2;
	if (n1.length() > n2.length()) {
		string zero;
		for (int len = 0; len < n1.length() - n2.length(); len++) zero += "0";
		n2 = zero + n2;
	}
	else {
		string zero;
		for (int len = 0; len < n2.length() - n1.length(); len++) zero += "0";
		n1 = zero + n1;
	}
	//cout << n1 << endl << n2 << endl;
	string result = ::plus(n1, n2);
	for (int i = result.length(); i >= 0; i--) cout << result[i];
	

	return 0;
}

int toInt(char c) {
	switch (c) {
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	}
}
char toChar(int i) {
	switch (i) {
	case 0: return '0';
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	}
}
string plus(string n1, string n2) {
	string newString;
	for (int i = n1.length() - 1; i >= 0; i--) {
		int calc = toInt(n1[i]) + toInt(n2[i]);
		if (calc >= 10) {
			int next = calc / 10;
			int prev = calc % 10;
			newString.push_back(toChar(prev));
			newString.push_back(toChar(next));
		}
		else {
			newString.push_back(toChar(calc));
		}
	}
	return newString;
}