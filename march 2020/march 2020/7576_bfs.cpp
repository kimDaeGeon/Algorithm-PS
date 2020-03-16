#include<iostream>
#include<queue>

using namespace std;

static int map[1000][1000] = { 0 };
static bool isVisited[1000][1000] = { false };

void BFS(int x, int y);

int main() {
	int x_size, y_size;
	cin >> x_size >> y_size;

	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			cin >> map[y][x];
		}

	
	return 0;
}

void BFS(int x, int y) {
	queue<pair<int, int>> bfs;

	//첫 번째 노드 방문합니다
	bfs.push(make_pair(y, x));
	isVisited[y][x] = true;

	while()
}