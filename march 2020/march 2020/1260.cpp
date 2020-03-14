//��������Ʈ
#include<iostream>
#include<algorithm>

#include<stack>
#include<vector>
#include<queue>
using namespace std;

void BFS(int node, const vector<int>* edge, int start);
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
	for (int i = 1; i <= n; i++) {
		std::sort(edge[i].begin(), edge[i].end());
	}

	DFS(n, edge, start);
	BFS(n, edge, start);

	return 0;
}

void BFS(int node, const vector<int>* edge, int start) {
	queue<int> route;
	bool* isVisited = new bool[node + 1];

	for (int i = 1; i <= node; i++) {
		isVisited[i] = false;
	}

	//ù��° ��� �湮
	isVisited[start] = true;
	route.push(start);
	cout << start << ' ';

	while (!route.empty()) {
		//���� ����� ��� Ž��
		for (int e : edge[route.front()]) {
			//�湮���� ���� ��尡 ������
			if (isVisited[e] == false) {
				//��� �湮ó�� �� Ǫ��
				isVisited[e] = true;
				route.push(e);

				cout << e << ' ';
			}
		}
		//
		route.pop();
	}
	cout << '\n';
	return;
}
void DFS(int node, const vector<int>* edge, int start) {
	stack<int> route;
	bool* isVisited = new bool[node + 1];

	for (int i = 1; i <= node; i++) isVisited[i] = false;

	//ù��° ��� �湮
	route.push(start);
	isVisited[start] = true;
	cout << start << ' ';

	while (!route.empty()) {
		bool search = false;
		//route.top() �� ����� edge Ž��
		for (int e : edge[route.top()]) {
			//��带 �湮���� �ʾ�����
			if (isVisited[e] == false) {
				//��� �湮ó��
				isVisited[e] = true;
				//���ÿ� Ǫ��
				route.push(e);
				cout << e << ' ';

				search = true;
				break;
			}
		}
		if (!search) {
			route.pop();
		}
	}
	cout << '\n';
	return;
}