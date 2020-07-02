#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(bool isVisited[], vector<int> edge[], int start_node);

int main() {
	int node_size, edge_size;
	cin >> node_size >> edge_size;

	vector<int>* edge = new vector<int>[node_size + 1];
	bool* isVisited = new bool[node_size + 1];

	for (int v = 1; v <= node_size; v++) isVisited[v] = false;


	for (int e = 0; e < edge_size; e++) {
		int from, to;
		cin >> from >> to;
		edge[from].push_back(to);
		edge[to].push_back(from);
	}

	BFS(isVisited, edge, 1);

	int computer = 0;
	for (int v = 2; v <= node_size; v++) {
		if (isVisited[v] == true) computer++;
	}
	
	cout << computer << '\n';

	delete[] isVisited;
	delete[] edge;
	return 0;
}


void BFS(bool isVisited[], vector<int> edge[], int start_node) {
	queue<int> bfs;

	//ù ��° ��� �湮
	isVisited[start_node] = true;
	bfs.push(start_node);

	while (!bfs.empty()) {
		//ù ���� ���� ����� ���� Ž��
		for (int e : edge[bfs.front()]) {
			//�湮���� ���� ��尡 ������, �湮ó�� �� Ǫ��
			if (isVisited[e] == false) {
				isVisited[e] = true;
				bfs.push(e);
			}
		}
		bfs.pop();
	}
}