#include<iostream>
#include<vector>
using namespace std;

void DFS(int node, vector<int> edge[], int isVisited[], int group);

int main() {
	int test;
	cin >> test;

	for (int t = 0; t < test; t++) {
		int node_size, edge_size;
		cin >> node_size >> edge_size;

		int* isVisited = new int[node_size + 1];
		for (int i = 1; i <= node_size; i++) isVisited[i] = 0;

		vector<int>* edge = new vector<int>[node_size + 1];

		for (int i = 0; i < edge_size; i++) {
			int from, to;
			cin >> from >> to;
			edge[from].push_back(to);
			edge[to].push_back(from);
		}

		for (int i = 1; i <= node_size; i++) {
			if (isVisited[i] == 0) {
				DFS(i, edge, isVisited, 1);
			}
		}

		bool isBipartite = true;

		for (int i = 1; i <= node_size; i++) {
			for (int j : edge[i]) {
				if (isVisited[i] == isVisited[j])
					isBipartite = false;
			}
		}

		cout << (isBipartite ? "YES" : "NO") << '\n';

		delete[] isVisited;
		delete[] edge;
	}
}

void DFS(int node, vector<int> edge[], int isVisited[], int group) {
	isVisited[node] = group;
	for (int e : edge[node]) {
		int next = e;
		if (isVisited[next] == 0) {
			DFS(node, edge, isVisited, 3 - group);
		}
	}
}