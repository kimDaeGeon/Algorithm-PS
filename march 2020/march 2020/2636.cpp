#include<iostream>
#include<queue>
using namespace std;
#define AIR -1

int x_size, y_size;
int cheese[100][100];
int isVisited[100][100] = { 0 };

void melt();

int main() {
	cin >> y_size >> x_size;

	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			cin >> cheese[y][x];
		}
	}



	return 0;
}

void melt() {
	const int dx[] = {1,-1,0,0};
	const int dy[] = { 0,0,1,-1 };

	queue<pair<int,int>> bfs;

	//[0][0]에서 바깥쪽 공기 닿은부분 너비우선탐색
	isVisited[0][0] = AIR;
	bfs.push(make_pair(0, 0));

	while (!bfs.empty()) {
		int x = bfs.front().second;
		int y = bfs.front().first;

		for (int dir = 0; dir < 4; dir++) {
			int X = x + dx[dir];
			int Y = y + dy[dir];
			if ((0 <= X && X < x_size) && (0 <= Y && Y < y_size)) {
				if (isVisited[Y][X] == 0 && cheese[Y][X] == 1) {
					isVisited[Y][X] = AIR;
					bfs.push(make_pair(Y, X));
				}
			}
		}
		bfs.pop();
	}
}