#include<iostream>
#include<queue>
using namespace std;

int n;
int map[100][100];

int max(int maxHeight);
void BFS(int x, int y, int rain, int isVisited[100][100], int field);

int main() {
	cin >> n;

	int maxHeight = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
			if (map[y][x] > maxHeight) {
				maxHeight = map[y][x];
			}
		}
	}

	cout << max(maxHeight) << '\n';
	
}

int max(int maxHeight) {
	int maxField = 0;

	for (int rain = 0; rain <= maxHeight; rain++) {
		int field = 0;
		int isVisited[100][100] = { 0 };
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (isVisited[y][x] == 0 && map[y][x] - rain > 0) {
					BFS(x, y, rain, isVisited, ++field);
				}
			}
		}
		maxField = field > maxField ? field : maxField;

		/*
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cout << isVisited[y][x] << ' ';
			}
			cout << '\n';
		}
		cout << "\n\n";
		*/
	}
	return maxField;
}

void BFS(int x, int y, int rain, int isVisited[100][100], int field) {
	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };

	queue<pair<int, int>> bfs;

	bfs.push(make_pair(y, x));
	isVisited[y][x] = field;

	while (!bfs.empty()) {
		int x = bfs.front().second;
		int y = bfs.front().first;
		for (int dir = 0; dir < 4; dir++) {
			int X = x + dx[dir];
			int Y = y + dy[dir];
			if ((0 <= X && X < n) && (0 <= Y && Y < n)) {
				if (isVisited[Y][X] == 0 && map[Y][X] - rain > 0) {
					bfs.push(make_pair(Y, X));
					isVisited[Y][X] = field;
				}
			}
		}

		bfs.pop();
	}
}