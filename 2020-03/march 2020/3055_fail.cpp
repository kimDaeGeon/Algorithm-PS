#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int x_size, y_size;
char map[50][50];

int BFS(int x, int y, vector<pair<int, int>> water);
bool overflow(vector<pair<int, int>> water);

int main() {
	/// 물의 위치를 모두 저장
	vector<pair<int, int>> water;

	int x_pos = 0, y_pos = 0;
	cin >> y_size >> x_size;

	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'S') {
				x_pos = x, y_pos = y;
			}
			else if (map[y][x] == '*') {
				water.push_back(make_pair(y, x));
			}
		}
	}

	cout << BFS(x_pos, y_pos, water) << '\n';



	return 0;
}

int BFS(int x, int y, vector<pair<int,int>> water) {
	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };
	int isVisited[50][50] = { 0 };

	queue<pair<int, int>> bfs;
	int route = 1;

	bfs.push(make_pair(y, x));
	isVisited[y][x] = route;

	while (!bfs.empty()) {
		int x = bfs.front().second;
		int y = bfs.front().first;
		for (int dir = 0; dir < 4; dir++) {
			int X = x + dx[dir], Y = y + dy[dir];
			if ((0 <= X && X < x_size) && (0 <= Y && Y < y_size)) {
				if (isVisited[Y][X] == 0 && map[Y][X] == '.') {
					isVisited[Y][X] = ++route;
					bfs.push(make_pair(Y, X));
				}
			}
		}

		if (!overflow(water)) return -1;
		bfs.pop();
	}
	
	return route;
}

bool overflow(vector<pair<int,int>> water) {
	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };

	for (pair<int, int> p : water) {
		for (int dir = 0; dir < 4; dir++) {
			int x = p.second + dx[dir];
			int y = p.first + dy[dir];
			if ((0 <= x && x < x_size) && (0 <= y && y < y_size)) {
				if (map[y][x] == '.') map[y][x] = '*';
				else if (map[y][x] == 'S') return false;
			}
		}
	}
	return true;
}