#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

template<typename T> void print(stack<T> st) {
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	return;
}
template<typename T> void print(vector<T> v) {
	for (T in : v) {
		cout << in;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr), cin.tie(nullptr);
	

	string str;
	stack<int> st;

	cin >> str;

	int div = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			st.push(i);
		}
		else {
			if (st.top() + 1 == i) {
				st.pop();
				div += st.size();
			}
			else {
				st.pop();
				div += 1;
			}
		}
	}
	cout << div << '\n';

	return 0;
}