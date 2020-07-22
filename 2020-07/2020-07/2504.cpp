#include<bits/stdc++.h>
using namespace std;

bool isCorrect(string bracket) {
	stack<char> st;
	for (char ch : bracket) {
		if (ch == '(' || ch == '[') st.push(ch);
		else {
			if (st.empty()) return false;
			if (ch == ')' && st.top() == '(') st.pop();
			else if (ch == ']' && st.top() == '[') st.pop();
		}
	}
	return true;
}
int getBracket(string bracket) {
	while (bracket.find("()") != -1) bracket.replace(bracket.find("()"), 2, "2");
	while (bracket.find("[]") != -1) bracket.replace(bracket.find("[]"), 2, "3");
	//cout << bracket << '\n';
	
	stack<char> st;
	stack<int> ans;
	for (char ch : bracket) {
		if (ch == '(' || ch == '[') st.push(ch);
		else if (ch == '2') {
			if (ans.empty() || st.empty()) ans.push(2);
			else {
				int n = ans.top() + 2;
				ans.pop();
				ans.push(n);
			}
		}
		else if (ch == '3') {
			if (ans.empty() || st.empty()) ans.push(3);
			else {
				int n = ans.top() + 3;
				ans.pop();
				ans.push(n);
			}
		}
		else if (ch == ')' && st.top() == '(') {
			int n = ans.top() * 2;
			ans.pop();
			ans.push(n);
		}
		else if (ch == ']' && st.top() == '[') {
			int n = ans.top() * 3;
			ans.pop();
			ans.push(n);
		}
	}

	int sum = 0;
	while (!ans.empty()) {
		sum += ans.top();
		ans.pop();
	}
	return sum;
}

int main() {
	string bracket;
	cin >> bracket;

	if (!isCorrect(bracket)) cout << 0 << '\n';
	else cout << getBracket(bracket) << '\n';

	return 0;
}