#include<iostream>
#include<vector>
#include<string>
using namespace std;

static int x_size, y_size;
static char map[50][50];
static bool isVisited[50][50] = { false };

bool DFS(int x, int y, int prev_x, int prev_y, char type);

int main() {
	cin >> y_size >> x_size;

	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			cin >> map[y][x];
		}
	}

	//찾아낸 모든 char 에 대해 깊이우선탐색 진행
	bool isCycleExist = false;
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			if (isVisited[y][x] == false) {
				if (DFS(x,y,x,y,map[y][x])) {
					isCycleExist = true;
					cout << "Yes" << '\n';	
					break;
				}
			}
		}
		if (isCycleExist) break;
	}

	if (!isCycleExist) cout << "No" << '\n';

	return 0;
}

bool DFS(int x, int y, int prev_x, int prev_y, char type) {
	static int cycle;

	cycle++;
	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };

	if (isVisited[y][x]) return true;

	isVisited[y][x] = true;
	for (int dir = 0; dir < 4; dir++) {
		int X = x + dx[dir];
		int Y = y + dy[dir];

		if ((0 <= X && X < x_size) && (0 <= Y && Y < y_size)) {
			//이전과 다른 좌표로 탐색
			if (!(X == prev_x && Y == prev_y) && map[Y][X] == type) {
				if (DFS(X, Y, x, y, type)) {
					if (cycle >= 4) return true;
				}
			}
		}
	}

	return false;
}