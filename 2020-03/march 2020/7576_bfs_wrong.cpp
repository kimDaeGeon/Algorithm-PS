#include<iostream>
#include<queue>
#include<vector>

using namespace std;

static int x_size, y_size;
static int map[1000][1000] = { 0 };
static int isVisited[1000][1000] = { 0 };

int BFS(vector<pair<int, int>> *ripedTomatoes);

int main() {
	int total_tomatoes = 0;
	int unripedTomatoes = 0;
	cin >> x_size >> y_size;

	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			cin >> map[y][x];
			if (map[y][x] == 0) total_tomatoes++;
		}
	}

	vector<pair<int, int>> ripedTomatoes;
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			if (map[y][x] == 1) {
				ripedTomatoes.push_back(make_pair(y, x));
			}
		}
	}

	int ans = BFS(&ripedTomatoes);

	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			if (isVisited[y][x] > 0) {
				unripedTomatoes++;
			}
		}
	}

	if (unripedTomatoes != total_tomatoes) cout << ans << '\n';
	else cout << -1 << '\n';

	
	return 0;
}

int BFS(vector<pair<int,int>> *ripedTomatoes) {
	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };

	int date = 1;
	queue<pair<int, int>> bfs;

	//첫 번째 노드 방문
	for (pair<int, int> p : *ripedTomatoes) {
		//y = p.first, x = p.secod
		bfs.push(make_pair(p.first, p.second));
		isVisited[p.first][p.second] = date;
	}

	//ripedTomatoes 의 같은 위치 노드에서 탐색 진행
	while (!bfs.empty()) {
		date = isVisited[bfs.front().first][bfs.front().second] + 1;

		for (pair<int, int> p : *ripedTomatoes) {
			for (int dir = 0; dir < 4; dir++) {
				int X = bfs.front().second + dx[dir];
				int Y = bfs.front().first + dy[dir];

				if ((0 <= X && X < x_size) && (0 <= Y && Y < y_size)) {
					if (isVisited[Y][X] == 0 && map[Y][X] == 0) {
						isVisited[Y][X] = date;
						bfs.push(make_pair(Y, X));
					}
				}
			}
		}

		bfs.pop();
	}
	return date - 2;
}