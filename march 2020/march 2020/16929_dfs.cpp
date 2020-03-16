#include<iostream>
#include<stack>
using namespace std;

int x_len, y_len;

const int dx[] = { 0,1,0,-1 };
const int dy[] = { -1,0,1,0 };

static char map[50][50] = { 0 };
static bool isVisited[50][50] = { false };

bool DFS(int x, int y, char type);

int main() {
	cin >> x_len >> y_len;

	for (int y = 0; y < y_len; y++) {
		for (int x = 0; x < x_len; x++) {
			cin >> map[y][x];
		}
	}
}

bool DFS(int x, int y, char type) {
	//이전 칸이 아닌 칸으로 이동, 이미 방문했던 칸을 방문했으면 사이클 존재

	int distance = 0;
	stack<pair<int, int>> dfs;

	dfs.push(make_pair(y, x));
	isVisited[y][x] = true;
	distance++;

	int x = dfs.top().second;
	int y = dfs.top().first;

	while (!dfs.empty()) {
		for (int dir = 0; dir < 4; dir++) {
			int X = x + dx[dir];
			int Y = y + dy[dir];
			if ((0 <= X && X < x_len) && (0 <= Y && Y < y_len)) {
				if (map[Y][X] == type && isVisited[Y][X] == false) {

				}
			}
		}
	}


}