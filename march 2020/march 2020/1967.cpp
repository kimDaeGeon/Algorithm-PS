#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int node_size;
bool isVisited[10001] = { false };
vector<pair<int, int>>* edge;

int BFS(int node);

int main() {
	cin >> node_size;
	edge = new vector<pair<int, int>>[node_size + 1];

	for (int node = 1; node <= node_size; node++) {
		int from, to, w;
		cin >> from >> to >> w;

		edge[from].push_back(make_pair(to, w));
		edge[to].push_back(make_pair(from, w));
	}


	for (int node = 1; node <= node_size; node++) {

	}


	return 0;
}

int BFS(int node) {
	queue<int> bfs;

	for (int n = 1; n <= node_size; n++)
		isVisited[n] = false;

	bfs.push(node);
	isVisited[node] = true;

	while (!bfs.empty()) {
		for (pair<int, int> p : edge[bfs.front()]) {
			if (!isVisited[p.first]) {
				bfs.push(p.first);
				isVisited[p.first];
			}
		}
		bfs.pop();
	}



}