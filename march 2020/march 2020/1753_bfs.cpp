#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void BFS(vector<pair<int, int>> edge[], bool isVisited[], int node_size, int start_node);

int main(){
	int node_size, edge_size;
	cin >> node_size >> edge_size;

	vector<pair<int, int>>* edge = new vector<pair<int, int>>[node_size + 1];

	bool* isVisited = new bool[node_size + 1];
	for (int v = 0; v <= node_size; v++) isVisited[v] = false;

	for (int e = 0; e < edge_size; e++) {
		int from, to, weight;
		cin >> from >> to >> weight;

		edge[from].push_back(make_pair(to, weight));
	}


	return 0;
}

void BFS(vector<pair<int, int>> edge[], bool isVisited[], int node_size, int start_node) {
	queue<int> bfs;

	//최단 경로 저장 vector
	vector<int> route(node_size + 1);

	//첫번째 노드 방문
	isVisited[start_node] = true;
	bfs.push(start_node);
	
	for (int node = start_node+1; node <= node_size; node++) {

	}
}