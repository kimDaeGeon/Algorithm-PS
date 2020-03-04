#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	string str;
	stack<char> left, right;
	cin >> str;

	for (char ch : str) {
		left.push(ch);
	}
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char command;
		cin >> command;

		if (command == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (command == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (command == 'B') {
			if (!left.empty()) {
				left.pop();
			}
		}
		else if (command == 'P') {
			cin >> command;
			left.push(command);
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
	cout << '\n';
	return 0;
}