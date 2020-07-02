#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isVPS(string str);

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		string str;
		cin >> str;
		if (isVPS(str)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

bool isVPS(string str) {
	stack<char> st;
	for (char ch : str) {
		if (ch == '(') {
			st.push(ch);
		}
		else {
			if (st.size() == 0) return false;
			st.pop();
		}
	}
	if (st.size() == 0) return true;
	return false;
}