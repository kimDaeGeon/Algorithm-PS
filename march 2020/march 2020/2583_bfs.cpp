#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

static int x_size, y_size, square;
static int map[100][100] = { 0 };
static int isVisited[100][100] = { 0 };

void BFS(int x, int y, int group);

int main() {
	cin >> y_size >> x_size >> square;

	for (int sq = 0; sq < square; sq++) {
		int LB_x, LB_y, RT_x, RT_y;
		cin >> LB_x >> LB_y >> RT_x >> RT_y;

		for (int y = LB_y; y < RT_y; y++) {
			for (int x = LB_x; x < RT_x; x++) {
				map[y][x] = 1;
			}
		}
	}

	int group = 0;
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			if (isVisited[y][x] == 0 && map[y][x] == 0) {
				BFS(x, y, ++group);
			}
		}
	}

	int* groupSize = new int[group + 1];
	for (int g = 1; g <= group; g++) {
		groupSize[g] = 0;
		for (int y = 0; y < y_size; y++) {
			for (int x = 0; x < x_size; x++) {
				if (isVisited[y][x] == g)
					groupSize[g]++;
			}
		}
	}

	sort(groupSize + 1, groupSize + 1 + group);

	cout << group << '\n';
	for (int g = 1; g <= group; g++)
		cout << groupSize[g] << " ";
	cout << '\n';

	return 0;
}

void BFS(int x, int y, int group) {
	const int dx[] = { 0,-1,1,0 };
	const int dy[] = { -1,0,0,1 };

	queue<pair<int, int>> bfs;

	//첫 번째 노드 방문
	isVisited[y][x] = group;
	bfs.push(make_pair(y, x));

	while (!bfs.empty()) {
		int x = bfs.front().second;
		int y = bfs.front().first;

		for (int dir = 0; dir < 4; dir++) {
			int X = x + dx[dir];
			int Y = y + dy[dir];

			//map 범위 내에 있는지 확인
			if ((0 <= X && X < x_size) && (0 <= Y && Y < y_size)) {
				if (isVisited[Y][X] == 0 && map[Y][X] == 0) {
					isVisited[Y][X] = group;
					bfs.push(make_pair(Y, X));
				}
			}
		}
		bfs.pop();
	}

	return;
}