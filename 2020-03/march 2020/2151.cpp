#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Pos {
	int x, y;
};

int len;
char map[50][50];

void BFS(int x, int y);

int main() {
	Pos from;
	cin >> len;
	for (int y = 0; y < len; y++) {
		for (int x = 0; x < len; x++) {
			cin >> map[y][x];
			if (map[y][x] == '#') from.y = y, from.x = x;
		}
	}


	/// dx,dy 탐색 노드연결
}

void BFS(int x, int y) {
	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };

	queue<pair<int, int>> bfs;
	bfs.push(make_pair(y, x));

	while (!bfs.empty()) {
		int x = bfs.front().second, y = bfs.front().first;
		for (int dir = 0; dir < 4; dir++) {
			int X = x + dx[dir], Y = y + dy[dir];
		}
	}
}