#pragma warning(disable:4996)
#include<iostream>
#include<queue>
using namespace std;

static int x_len, y_len;
static int map[100][100] = { 0 };
static int isVisited[100][100] = { 0 };

void BFS(int x, int y);

int main() {
	cin >> y_len >> x_len;

	for (int y = 0; y < y_len; y++) {
		for (int x = 0; x < x_len; x++) {
			scanf("%1d", &map[y][x]);
		}
	}

	BFS(0, 0);

	/*
	putchar('\n');=
	for (int y = 0; y < y_len; y++) {
		for (int x = 0; x < x_len; x++) {
			printf("%d ", isVisited[y][x]);
		}
		printf("\n");
	}
	*/

	printf("%d", isVisited[y_len - 1][x_len - 1]);

	return 0;
}

void BFS(int x, int y) {
	const int dx[] = { 0,1,0,-1 };
	const int dy[] = { -1,0,1,0 };

	int distance = 1;
	queue<pair<int, int>> bfs;

	//첫번째 노드 방문
	bfs.push(make_pair(y, x));
	isVisited[y][x] = distance;

	while (!bfs.empty()) {
		int x = bfs.front().second;
		int y = bfs.front().first;
		distance = isVisited[y][x] + 1;

		for (int dir = 0; dir < 4; dir++) {
			int X = x + dx[dir];
			int Y = y + dy[dir];
			if ((0 <= X && X < x_len) && (0 <= Y && Y < y_len)) {
				if (isVisited[Y][X] == 0 && map[Y][X] == 1) {
					isVisited[Y][X] = distance;
					bfs.push(make_pair(Y, X));
				}
			}
		}
		bfs.pop();
	}
}