//인접리스트 DFS
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void DFS(int node, const vector<int> *edge, int start);

int main() {
	int n, m, start;
	cin >> n >> m >> start;

	vector<int>* edge = new vector<int>[n+1];

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

	DFS(n, edge, start);


	return 0;
}

void DFS(int node, const vector<int> *edge, int start) {
	stack<int> route;
	bool* isVisited = new bool[node + 1];

	for (int i = 1; i <= node; i++) isVisited[i] = false;

	//첫번째 노드 방문
	route.push(start);
	isVisited[start] = true;
	cout << start << ' ';

	while (!route.empty()) {
		bool search = false;
		//route.top() 과 연결된 edge 탐색
		for (int e : edge[route.top()]) {
			//노드를 방문하지 않았으면
			if (isVisited[e] == false) {
				//노드 방문처리
				isVisited[e] = true;
				//스택에 푸시
				route.push(e);
				cout << e << ' ';

				search = true;
				break;
			}
		}
		if (!search) {
			route.pop();
		}
	}
	cout << '\n';
	return;
}