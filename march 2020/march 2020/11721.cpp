#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int count = 0;
	for (int i = 0; i < str.length(); i++, count++) {
		if (count == 10) {
			cout << '\n'; count = 0;
		}
		cout << str[i];
	}

	return 0;
}