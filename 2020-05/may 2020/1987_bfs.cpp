#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int x_size, y_size;
char map[21][21];
int isVisited[21][21];

bool isSteped(char key, const vector<char> step) {
	for (char ch : step) {
		if (key == ch) return true;
	}
	return false;
}

int BFS(int x, int y, vector<char> step) {
	int dist = 1;

	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };
	queue<pair<int, int>> bfs;

	bfs.push(make_pair(y, x));
	step.push_back(map[y][x]);
	isVisited[y][x] = 1;

	while (!bfs.empty()) {
		int x = bfs.front().second;
		int y = bfs.front().first;

		for (int dir = 0; dir < 4; dir++) {
			int X = x + dx[dir];
			int Y = y + dy[dir];

			if ((0 <= X && X < x_size) && (0 <= Y && Y < y_size)) {
				if (isVisited[Y][X] == 0 && !isSteped(map[Y][X], step)) {
					bfs.push(make_pair(Y, X));
					step.push_back(map[Y][X]);
					isVisited[Y][X] = isVisited[y][x] + 1;

					dist = dist < isVisited[Y][X] ? isVisited[Y][X] : dist;
				}
			}
		}

		bfs.pop();
		
	}
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			cout << isVisited[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';

	return dist;
}

int main() {
	vector<char> step;

	cin >> y_size >> x_size;
	for (int y = 0; y < y_size; y++) {
		cin >> map[y];
	}

	cout << BFS(0, 0, step);
}