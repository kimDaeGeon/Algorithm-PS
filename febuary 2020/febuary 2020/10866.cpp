#include<iostream>
#include<string>
#include<deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr), cin.tie(nullptr);

	int n;
	cin >> n;

	deque<int> dq;
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;

		if (command == "push_front") {
			int x; cin >> x;
			dq.push_front(x);
		}
		else if (command == "push_back") {
			int x; cin >> x;
			dq.push_back(x);
		}
		else if (command == "pop_front") {
			if (dq.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << dq.front() << endl;
			dq.pop_front();
		}
		else if (command == "pop_back") {
			if (dq.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << dq.back() << endl;
			dq.pop_back();
		}
		else if (command == "size") {
			cout << dq.size() << endl;
		}
		else if (command == "empty") {
			cout << dq.empty() << endl;
		}
		else if (command == "front") {
			if (dq.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << dq.front() << endl;
		}
		else if (command == "back") {
			if (dq.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << dq.back() << endl;
		}
	}
}