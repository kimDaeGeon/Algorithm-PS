#include<bits/stdc++.h>
using namespace std;

void print(stack<char> st) {
	stack<char> newStack;
	while (!st.empty()) newStack.push(st.top()), st.pop();
	while (!newStack.empty()) {
		cout << newStack.top() << ' ';
		newStack.pop();
	}
	cout << '\n';
}

int main() {
	string bracket;
	cin >> bracket;


	stack<char> st;
	for (char ch : bracket) {
		print(st);
		if (ch == '(' || ch == '[') st.push(ch);
		else if (ch == ')' && st.top() == '(') st.pop(), st.push('2');
		else if (ch == ']' && st.top() == '[') st.pop(), st.push('3');
		else if (ch == ')' && st.top() != '(') {
			int sum = 0;
			while (st.top() != '(' || !st.empty()) {
				sum += st.top() - '0';
				st.pop();
			}
			st.push(2 * sum);
		}
		else if (ch == ']' && st.top() != '[') {
			int sum = 0;
			while (st.top() != '[' || !st.empty()) {
				sum += st.top() - '0';
				st.pop();
			}
			st.push(3 * sum);
		}
	}


	

	return 0;
}