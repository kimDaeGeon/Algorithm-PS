#include<iostream>
#include<queue>
using namespace std;

const int dx[] = { -1,0,1,1,1,1,0,-1,-1 };
const int dy[] = { -1,-1,-1,0,1,1,1,1,0 };

void BFS(short map[50][50], short isVisited[50][50], int x_len, int y_len, int x, int y, int group);

int main() {
	int x_len, y_len;
	while(true){
		cin >> x_len >> y_len;
		if (x_len == 0 && y_len == 0) break;

		short map[50][50] = { 0 };
		short isVisited[50][50] = { 0 };


		for (int y = 0; y < y_len; y++) {
			for (int x = 0; x < x_len; x++) {
				cin >> map[y][x];
			}
		}

		int group = 0;
		for (int y = 0; y < y_len; y++) {
			for (int x = 0; x < x_len; x++) {
				if (map[y][x] == 1 && isVisited[y][x] == 0) {
					BFS(map, isVisited, x_len, y_len, x, y, ++group);
				}
			}
		}

		cout << group << '\n';


	}
}

void BFS(short map[50][50], short isVisited[50][50], int x_len, int y_len, int x, int y, int group){
	queue<pair<int, int>> bfs;

	//첫번째 노드 방문
	isVisited[y][x] = group;
	bfs.push(make_pair(y, x));

	while (!bfs.empty()) {
		int x = bfs.front().second;
		int y = bfs.front().first;

		for (int dir = 0; dir < 9; dir++) {
			int X = x + dx[dir];
			int Y = y + dy[dir];
			
			if ((0 <= X && X < x_len) && (0 <= Y && Y < y_len)) {
				if (map[Y][X] == 1 && isVisited[Y][X] == 0) {
					isVisited[Y][X] = group;
					bfs.push(make_pair(Y, X));
				}
			}
		}

		bfs.pop();

	}
	return;
}