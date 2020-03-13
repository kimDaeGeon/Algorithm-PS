#include<iostream>
#include<queue>
using namespace std;

void BFS(const short map[50][50], short isVisited[50][50], short x, short y, short x_len, short y_len, short group);

int main() {
	short test;
	cin >> test;

	for (short t = 0; t < test; t++) {
		short map[50][50] = { 0 };
		short isVisited[50][50] = { 0 };

		short x_len, y_len, position;
		cin >> x_len >> y_len >> position;

		for (short p = 0; p < position; p++) {
			short x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		int group = 0;
		for (short y = 0; y < y_len; y++) {
			for (short x = 0; x < x_len; x++) {
				if (map[y][x] == 1 && isVisited[y][x] == 0) {
					BFS(map, isVisited, x, y, x_len, y_len, ++group);
				}
			}
		}


		cout << group << '\n';


	}

}



void BFS(const short map[50][50], short isVisited[50][50], short x, short y, short x_len, short y_len, short group) {
	queue<pair<short, short>> bfs;

	//첫번째 노드 방문
	isVisited[y][x] = group;
	bfs.push(make_pair(y, x));

	while (!bfs.empty()) {
		short y = bfs.front().first;
		short x = bfs.front().second;

		//UP	[Y-1][X]
		if ((0 <= x && x < x_len) && (0 <= y - 1 && y - 1 < y_len)) {
			if (map[y - 1][x] == 1 && isVisited[y - 1][x] == 0) {
				bfs.push(make_pair(y - 1, x));
				isVisited[y - 1][x] = group;
			}
		}
		//DOWN	[Y+1][X]
		if ((0 <= x && x < x_len) && (0 <= y + 1 && y + 1 < y_len)) {
			if (map[y + 1][x] == 1 && isVisited[y + 1][x] == 0) {
				bfs.push(make_pair(y + 1, x));
				isVisited[y + 1][x] = group;
			}
		}
		//LEFT	[Y][X-1]
		if ((0 <= x - 1 && x - 1 < x_len) && (0 <= y && y < y_len)) {
			if (map[y][x - 1] == 1 && isVisited[y][x - 1] == 0) {
				bfs.push(make_pair(y, x - 1));
				isVisited[y][x - 1] = group;
			}
		}
		//RIGHT [Y][X+1]
		if ((0 <= x + 1 && x + 1 < x_len) && (0 <= y && y < y_len)) {
			if (map[y][x + 1] == 1 && isVisited[y][x + 1] == 0) {
				bfs.push(make_pair(y, x + 1));
				isVisited[y][x + 1] = group;
			}
		}

		bfs.pop();
	}
}