#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int node_size;
int graph[101][101] = { 0 };
bool isVisited[101] = { false };

bool BFS(int from, int to);

int main() {
	cin >> node_size;

	for (int from = 1; from <= node_size; from++) {
		for (int to = 1; to <= node_size; to++) {
			cin >> graph[from][to];
		}
	}

	cout << '\n';

	for (int from = 1; from <= node_size; from++) {
		for (int to = 1; to <= node_size; to++) {
			cout << BFS(from,to);
		}
		cout << '\n';
	}


	return 0;
}

bool BFS(int from, int to) {
	queue<int> bfs;

	///첫번째 노드 방문
	isVisited[from] = true;
	bfs.push(from);

	///
	while (!bfs.empty()) {
		for (int node = 1; node <= node_size; node++) {
			///연결된 노드 탐색
			if (graph[bfs.front()][node] == 1) {
				if (isVisited[node] == false) {
					isVisited[node] = true;
					bfs.push(node);
				}
			}
		}
		bfs.pop();
	}

	if (isVisited[to]) return true;
	else return false;
}