//인접리스트
#include<iostream>
#include<algorithm>

#include<vector>
#include<stack>
#include<queue>
using namespace std;

void DFS(int node, const vector<int>* edge, int start);

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
	for (int i = 1; i <= m; i++) {
		std::sort(edge[i].begin(), edge[i].end());
	}


}

void BFS(int node, const vector<int>* edge, int start) {
	queue<int> route;
	bool* isVisited = new bool[node + 1];
}