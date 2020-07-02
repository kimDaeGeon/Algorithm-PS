#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int x_size, y_size;
char canEat;

char map[1000][1000];
int isVisited[1000][1000] = { 0 };

int BFS(int fromX, int fromY, int toX, int toY);

int main() {
	vector<pair<int, int>> cheese;
	int start_x, start_y;

	cin >> y_size >> x_size >> canEat;
	
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'S') {
				start_x = x, start_y = y;
			}
			else if ('1' <= map[y][x] && map[y][x] <= canEat) {
				cheese.push_back(make_pair(y, x));
			}
		}
	}

	int dist = 0;
	for (pair<int, int> p : cheese) {
		dist += BFS(start_x, start_y, p.second, p.first);
		start_x = p.second;
		start_y = p.first;
	}

	cout << dist << '\n';

	return 0;
}

int BFS(int fromX, int fromY, int toX, int toY) {
	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };

	for (int y = 0; y < y_size; y++)
		for (int x = 0; x < x_size; x++)
			isVisited[y][x] = 0;

	
	queue<pair<int, int>> bfs;

	bfs.push(make_pair(fromY, fromX));
	isVisited[fromY][fromX] = 1;

	while (!bfs.empty()) {
		int x = bfs.front().second;
		int y = bfs.front().first;
		for (int dir = 0; dir < 4; dir++) {
			int X = x + dx[dir], Y = y + dy[dir];
			if ((0 <= X && X < x_size) && (0 <= Y && Y < y_size)) {
				if (!isVisited[Y][X] && map[Y][X] != 'X') {
					isVisited[Y][X] = isVisited[y][x] + 1;
					map[Y][X] = '.';
					bfs.push(make_pair(Y, X));
				}
			}
		}

		bfs.pop();
	}

	return isVisited[toY][toX] - 1;
}