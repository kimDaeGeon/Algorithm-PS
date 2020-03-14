//��������Ʈ
#include<iostream>
#include<algorithm>

#include<vector>
#include<queue>
using namespace std;

void BFS(int node, const vector<int>* edge, int start);

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

<<<<<<< HEAD

=======
	BFS(n, edge, start);
>>>>>>> e4a0c9db30d78934b3cbd103317f7e1f5cbd4462
}

void BFS(int node, const vector<int>* edge, int start) {
	queue<int> route;
	bool* isVisited = new bool[node + 1];
<<<<<<< HEAD
=======

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
>>>>>>> e4a0c9db30d78934b3cbd103317f7e1f5cbd4462
}