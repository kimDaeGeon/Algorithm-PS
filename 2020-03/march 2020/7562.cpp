#include<iostream>
#include<queue>

using namespace std;

int map[300][300] = { 0 };

int BFS(int from_x, int from_y, int to_x, int to_y, int size);

int main() {
	int test;
	cin >> test;

	for (int t = 0; t < test; t++) {
		int size;
		int from_x, from_y, to_x, to_y;
		cin >> size >> from_x >> from_y >> to_x >> to_y;

		cout << BFS(from_x, from_y, to_x, to_y, size) << '\n';
	}

	return 0;
}


int BFS(int from_x, int from_y, int to_x, int to_y, int size) {
	const int dx[] = { -1,1,2,2,1,-1,-2,-2 };
	const int dy[] = { -2,-2,-1,1,2,2,1,-1 };
	int isVisited[300][300] = { 0 };
	
	queue<pair<int,int>> bfs;

	bfs.push(make_pair(from_y, from_x));
	isVisited[from_y][from_x] = 1;

	while (!bfs.empty()) {
		int x = bfs.front().second;
		int y = bfs.front().first;
		for (int dir = 0; dir < 8; dir++) {
			int X = x + dx[dir];
			int Y = y + dy[dir];
			if ((0 <= X && X < size) && (0 <= Y && Y < size)) {
				if (isVisited[Y][X] == 0) {
					isVisited[Y][X] = isVisited[y][x] + 1;
					bfs.push(make_pair(Y, X));
				}
			}
		}

		bfs.pop();
	}

	return isVisited[to_y][to_x] - 1;
}