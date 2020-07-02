#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	int test;
	cin >> test;
	cin.ignore();

	while (test--) {
		string str;
		getline(cin, str);
		str += '\n';

		stack<char> st;
		for (char ch : str) {
			if (ch == ' ' || ch == '\n') {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << ch;
			}
			else {
				st.push(ch);
			}
		}
	}
	return 0;
}