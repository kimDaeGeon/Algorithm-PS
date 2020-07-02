//1707 dfs
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void DFS(int node_size, vector<int> edge[], int start, int isVisited_Group[]);

int main() {
	int test;
	cin >> test;

	for (int i = 0; i < test; i++) {
		int node_size, edge_size;
		cin >> node_size >> edge_size;

		vector<int>* edge = new vector<int>[node_size + 1];
		int* isVisited_Group = new int[node_size + 1];
		for (int visit = 1; visit <= node_size; visit++) {
			isVisited_Group[visit] = 0;
		}

		
		for (int e = 1; e <= edge_size; e++) {
			int from, to;
			cin >> from >> to;

			edge[from].push_back(to);
			edge[to].push_back(from);
		}

		DFS(node_size, edge, 1, isVisited_Group);


		bool isBipartiteGraph = true;
		for (int n = 1; n <= node_size; n++) {
			for(int m : edge[n]){
				if (isVisited_Group[n] == isVisited_Group[m]) {
					isBipartiteGraph = false;
				}
			}
		}
		cout << (isBipartiteGraph ? "YES" : "NO") << '\n';

		delete[] isVisited_Group;
		delete[] edge;
	}

	return 0;
}

void DFS(int node_size, vector<int> edge[], int start, int isVisited_Group[]) {
	int group = 1;

	stack<int> dfs;
	//isVisited_Group[] == 0 : 방문하지 않음
	//isVisited_Group[] == 1 : 방문한노드, 그룹1
	//isVisited_Group[] == -1 : 방문한노드, 그룹2

	for (int i = 1; i <= node_size; i++) {
		isVisited_Group[i] = 0;
	}

	//첫번째 노드 방문처리, 그룹1로 지정
	dfs.push(start);
	isVisited_Group[start] = group;

	while (!dfs.empty()) {
		bool nav = false;
		for (int e : edge[dfs.top()]) {
			//방문하지 않은 노드 탐색
			if (isVisited_Group[e] == 0) {
				dfs.push(e);
				isVisited_Group[e] = (group *= -1);

				nav = true;
				break;
			}
		}
		//탐색 실패시 이전 노드로 돌아감
		if (!nav) {
			dfs.pop();
		}
	}


	return;
}