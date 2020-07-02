#include<iostream>
#include<vector>
#include<queue>

#define VIRUS 2
#define WALL 1
#define EMPTY 0
using namespace std;

int x_size, y_size;
int map[10][10] = { 0 };

int spreadVirus(vector<pair<int, int>> wall);

int main() {
	vector<pair<int, int>> open_area;

	cin >> y_size >> x_size;

	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			cin >> map[y][x];
			if (map[y][x] == 0) {
				open_area.push_back(make_pair(y, x));
			}
		}
	}


	///모든 벽 세울 수 있는 경우에 대해 벽을 세움
	int maxSafeArea = 0;

	for (int i = 0; i < open_area.size(); i++) {
		for (int j = i+1; j < open_area.size(); j++) {
			for (int k = j+1; k < open_area.size(); k++) {
				vector<pair<int, int>> wall;
				wall.push_back(open_area[i]);
				wall.push_back(open_area[j]);
				wall.push_back(open_area[k]);

				///BFS 로 바이러스를 퍼뜨림
				int safeArea = spreadVirus(wall);
				maxSafeArea = (safeArea > maxSafeArea ? safeArea : maxSafeArea);
			}
		}
	}

	cout << maxSafeArea << '\n';

	return 0;
}

int spreadVirus(vector<pair<int,int>> wall) {
	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };

	int new_map[10][10];
	bool isVisited[10][10] = { false };

	queue<pair<int, int>> bfs;

	/// 맵 복사
	for (int y = 0; y < y_size; y++ ) {
		for (int x = 0; x < x_size; x++) {
			new_map[y][x] = map[y][x];
			if (map[y][x] == VIRUS) {
				bfs.push(make_pair(y, x));
				isVisited[y][x] = true;
			}
		}
	}

	/// 벽 세우기 x = p.second, y = p.first
	for (pair<int, int> p : wall) {
		new_map[p.first][p.second] = WALL;
	}

	/// BFS
	
	while (!bfs.empty()) {
		for (int dir = 0; dir < 4; dir++) {
			int X = bfs.front().second + dx[dir];
			int Y = bfs.front().first + dy[dir];

			/// 범위내의 map 에 존재하는지 확인
			if ((0 <= X && X < x_size) && (0 <= Y && Y < y_size)) {
				/// 방문하지 않은 노드 && 벽이 아닌 빈칸이면
				if (!isVisited[Y][X] && new_map[Y][X] == EMPTY) {
					/// 방문처리 후 큐에 푸시
					bfs.push(make_pair(Y, X));
					isVisited[Y][X] = true;
				}
			}
		}
		bfs.pop();
	}
	
	/// 바이러스가 확산 되지 않은곳
	int safeArea = 0;
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			//벽이 아니고 방문하지 않았다면
			if ((new_map[y][x] != WALL) && (!isVisited[y][x])) {
				safeArea++;
			}
		}
	}
	return safeArea;
}