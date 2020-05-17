#include<iostream>
#include<queue>
using namespace std;

int node_size;
int edge[100][100];

bool BFS(int from, int to);

int main() {
	cin >> node_size;

	for (int from = 0; from < node_size; from++) {
		for (int to = 0; to < node_size; to++) {
			cin >> edge[from][to];
		}
	}

	for (int from = 0; from < node_size; from++) {
		for (int to = 0; to < node_size; to++) {
			cout << BFS(from, to) << ' ';
		}
		cout << '\n';
	}


	return 0;
}

bool BFS(int from, int to) {
	queue<int> bfs;
	bool isVisited[100] = { false };

	bfs.push(from);
	//isVisited[from] = true;

	while (!bfs.empty()) {
		/// push
		for (int node = 0; node < node_size; node++) {
			if (edge[bfs.front()][node] == 1 && !isVisited[node]) {
				bfs.push(node);
				isVisited[node] = true;
			}
		}

		bfs.pop();
	}

	return isVisited[to];
}