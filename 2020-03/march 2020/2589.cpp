#include<iostream>
#include<queue>
using namespace std;

int x_size, y_size;
char map[50][50];

int BFS(int x, int y);

int main() {
	cin >> y_size >> x_size;

	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			cin >> map[y][x];
		}
	}

	/// L끼리의 최장거리 저장
	int treasureTime = 0;

	/// 모든 L 에 대해 BFS 탐색 진행
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			if (map[y][x] == 'L') {
				int time = BFS(x, y);
				treasureTime = (treasureTime < time ? time : treasureTime);
			}
		}
	}

	cout << treasureTime << '\n';


	return 0;
}

int BFS(int x, int y) {
	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };

	queue<pair<int, int>> bfs;
	int isVisited[50][50] = { false };

	/// 첫 번째 노드 방문
	bfs.push(make_pair(y, x));
	isVisited[y][x] = 1;

	while (!bfs.empty()) {
		int x = bfs.front().second;
		int y = bfs.front().first;
		for (int dir = 0; dir < 4; dir++) {
			int X = x + dx[dir], Y = y + dy[dir];
			if ((0 <= X && X < x_size) && (0 <= Y && Y < y_size)) {
				if (isVisited[Y][X] == 0 && map[Y][X] == 'L') {
					isVisited[Y][X] = isVisited[y][x] + 1;
					bfs.push(make_pair(Y, X));
				}
			}
		}

		bfs.pop();
	}


	/// 모든 거리중 최단거리 리턴
	int distance = 0;
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			distance = (isVisited[y][x] > distance ? isVisited[y][x] : distance);
		}
	}

	return distance - 1;
}