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

	/// L������ ����Ÿ� ����
	int treasureTime = 0;

	/// ��� L �� ���� BFS Ž�� ����
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

	/// ù ��° ��� �湮
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


	/// ��� �Ÿ��� �ִܰŸ� ����
	int distance = 0;
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			distance = (isVisited[y][x] > distance ? isVisited[y][x] : distance);
		}
	}

	return distance - 1;
}