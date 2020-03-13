//11724 bfs

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void BFS(int node, vector<int> edge[], int start, bool isVisited[]);

int main() {
	int node, edge_size;
	cin >> node >> edge_size;

	bool* isVisited = new bool[node + 1];
	vector<int>* edge = new vector<int>[node + 1];

	for (int i = 1; i <= node; i++) isVisited[i] = false;

	for (int i = 0; i < edge_size; i++) {
		int from, to;
		cin >> from >> to;

		edge[from].push_back(to);
		edge[to].push_back(from);
	}
	
	int connection = 0;
	for (int i = 1; i <= node; i++) {
		if (!isVisited[i]) {
			BFS(node, edge, i, isVisited);
			connection++;
		}
	}

	cout << connection << '\n';


	return 0;
}

void BFS(int node, vector<int> edge[], int start, bool isVisited[]) {
	queue<int> bfs;

	//첫번째 노드 방문
	isVisited[start] = true;
	bfs.push(start);

	while (!bfs.empty()) {
		for (int e : edge[bfs.front()]) {
			//방문하지 않은 연결된 노드 방문
			if (!isVisited[e]) {
				bfs.push(e);
				isVisited[e] = true;
			}
		}
		bfs.pop();
	}
	return;
}