#include<iostream>
#include<queue>
using namespace std;

const int dx[] = { 0,1,0,-1 };
const int dy[] = { -1,0,1,0 };

void BFS(int x, int y, int size, char color, int group);

char map[100][100] = { 0 };
int isVisited[100][100] = { 0 };

int main() {
	int size;
	cin >> size;
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			cin >> map[y][x];
		}
	}
	
	//일반인
	int group1 = 0;
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			if (map[y][x] == 'R' && isVisited[y][x] == 0) {
				BFS(x, y, size, 'R', ++group1);
			}
			else if (map[y][x] == 'G' && isVisited[y][x] == 0) {
				BFS(x, y, size, 'G', ++group1);
			}
			else if (map[y][x] == 'B' && isVisited[y][x] == 0) {
				BFS(x, y, size, 'B', ++group1);
			}
		}
	}


	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			isVisited[y][x] = 0;
		}
	}

	//적록색약
	int group2 = 0;

	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			if (map[y][x] == 'G') map[y][x] = 'R';
		}
	}
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			if (map[y][x] == 'R' && isVisited[y][x] == 0) {
				BFS(x, y, size, 'R', ++group2);
			}
			else if (map[y][x] == 'B' && isVisited[y][x] == 0) {
				BFS(x, y, size, 'B', ++group2);
			}
		}
	}


	cout << group1 << " " << group2 << '\n';


}

void BFS(int x, int y, int size, char color, int group) {
	queue<pair<int, int>> bfs;
	
	//첫번째 노드 방문
	isVisited[y][x] = group;
	bfs.push(make_pair(y, x));

	while (!bfs.empty()) {
		int x = bfs.front().second;
		int y = bfs.front().first;

		for (int dir = 0; dir < 4; dir++) {
			int X = x + dx[dir];
			int Y = y + dy[dir];
			if ((0 <= X && X < size) && (0 <= Y && Y < size)) {
				if (isVisited[Y][X] == 0 && map[Y][X] == color) {
					isVisited[Y][X] = 1;
					bfs.push(make_pair(Y, X));
				}
			}
		}
		bfs.pop();
	}
	return;
}