//인접리스트
#include<iostream>
#include<algorithm>

#include<vector>
#include<queue>
using namespace std;

void BFS(int node, const vector<int>* edge, int start);

int main() {
	int n, m, start;
	cin >> n >> m >> start;

	vector<int>* edge = new vector<int>[n + 1];

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		edge[from].push_back(to);
		edge[to].push_back(from);
	}

	//edge sort
	for (int i = 1; i <= n; i++) {
		std::sort(edge[i].begin(), edge[i].end());
	}

<<<<<<< HEAD

=======
	BFS(n, edge, start);
>>>>>>> e4a0c9db30d78934b3cbd103317f7e1f5cbd4462
}

void BFS(int node, const vector<int>* edge, int start) {
	queue<int> route;
	bool* isVisited = new bool[node + 1];
<<<<<<< HEAD
=======

	for (int i = 1; i <= node; i++) {
		isVisited[i] = false;
	}

	//첫번째 노드 방문
	isVisited[start] = true;
	route.push(start);
	cout << start << ' ';

	while (!route.empty()) {
		//노드와 연결된 노드 탐색
		for (int e : edge[route.front()]) {
			//방문하지 않은 노드가 있으면
			if (isVisited[e] == false) {
				//노드 방문처리 후 푸시
				isVisited[e] = true;
				route.push(e);

				cout << e << ' ';
			}
		}
		//
		route.pop();
	}
	cout << '\n';
	return;
>>>>>>> e4a0c9db30d78934b3cbd103317f7e1f5cbd4462
}