//11724 DFS

#include<iostream>
#include<vector>
#include<stack>
using namespace std;


void DFS(int node, vector<int> edge[], int start, bool isVisited[]);

int main() {
	int node, edge_size;
	cin >> node >> edge_size;

	vector<int>* edge = new vector<int>[node + 1];

	bool* isVisited = new bool[node + 1];
	for (int i = 1; i <= node; i++) {
		isVisited[i] = false;
	}

	for (int i = 0; i < edge_size; i++) {
		int from, to;
		cin >> from >> to;
		edge[from].push_back(to);
		edge[to].push_back(from);
	}

	int connection = 0;
	for (int i = 1; i <= node; i++) {
		if (isVisited[i] == false) {
			DFS(node, edge, i, isVisited);
			connection++;
		}
	}

	cout << connection << '\n';


	return 0;
}


void DFS(int node, vector<int> edge[], int start, bool isVisited[]) {
	static int connection = 0;

	stack<int> dfs;
	
	//bool* isVisited = new bool[node + 1];
	//for (int i = 1; i <= node; i++) {
	//	isVisited[i] = false;
	//}

	//ù��° ��� �湮
	dfs.push(start);
	isVisited[start] = true;
	//cout << start << ' ';

	while (!dfs.empty()) {
		bool search = false;

		for (int e : edge[dfs.top()]) {
			//Ž���� ��尡 �湮���� ���� �����
			if (isVisited[e] == false) {
				//�湮 ó�� �� Ǫ��
				isVisited[e] = true;
				dfs.push(e);

				//cout << e << ' ';
				search = true;
				break;
			}
		}
		if (!search) {
			dfs.pop();
		}
	}
	return;
}