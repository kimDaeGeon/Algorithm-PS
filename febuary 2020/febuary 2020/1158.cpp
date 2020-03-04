#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);
	
	int n, k;
	queue<int> que;
	vector<int> v;

	//in;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		que.push(i);
	}

	while (!que.empty()) {
		for (int i = 0; i < k - 1; i++) {
			que.push(que.front());
			que.pop();
		}
		v.push_back(que.front());
		que.pop();
	}


	//out;
	cout << "<";
	for (int i = 0; i < v.size() - 1; i++) {
		cout << v[i] << ", ";
	}
	cout << v[v.size() - 1];
	cout << ">";

	return 0;
}