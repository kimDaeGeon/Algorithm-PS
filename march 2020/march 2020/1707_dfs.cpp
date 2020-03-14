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
	//isVisited_Group[] == 0 : �湮���� ����
	//isVisited_Group[] == 1 : �湮�ѳ��, �׷�1
	//isVisited_Group[] == -1 : �湮�ѳ��, �׷�2

	for (int i = 1; i <= node_size; i++) {
		isVisited_Group[i] = 0;
	}

	//ù��° ��� �湮ó��, �׷�1�� ����
	dfs.push(start);
	isVisited_Group[start] = group;

	while (!dfs.empty()) {
		bool nav = false;
		for (int e : edge[dfs.top()]) {
			//�湮���� ���� ��� Ž��
			if (isVisited_Group[e] == 0) {
				dfs.push(e);
				isVisited_Group[e] = (group *= -1);

				nav = true;
				break;
			}
		}
		//Ž�� ���н� ���� ���� ���ư�
		if (!nav) {
			dfs.pop();
		}
	}


	return;
}