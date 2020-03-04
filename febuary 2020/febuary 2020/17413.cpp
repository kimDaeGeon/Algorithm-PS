#include<iostream>
#include<string>
#include<stack>
using namespace std;

template<typename T> void print(stack<T>& s) {
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}


int main() {
	string str;
	stack<char> st;

	getline(cin, str, '\n');

	bool tag = false;

	for (char ch : str) {
		if (ch == '<') {
			print(st);
			tag = true;
			cout << ch;
		}
		else if (ch == '>') {
			tag = false;
			cout << ch;
		}
		else if (tag) {
			cout << ch;
		}
		else {
			if (ch == ' ') {
				print(st);
				cout << ch;
			}
			else {
				st.push(ch);
			}
		}
	}
	print(st);

	return 0;
}