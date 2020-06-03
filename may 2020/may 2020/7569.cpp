#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Position {
	int x, y, z;
};


int isVisited[100][100][100];
int tomatoes[100][100][100];
int x_size, y_size, z_size;

int BFS(const vector<Position> &ripedTomatoes);
bool isAllRiped();

int main() {
	vector<Position> ripedTomatoes;

	cin >> x_size >> y_size >> z_size;

	for (int z = 0; z < z_size; z++) {
		for (int y = 0; y < y_size; y++) {
			for (int x = 0; x < x_size; x++) {
				cin >> tomatoes[z][y][x];
				if (tomatoes[z][y][x] == 1) {
					ripedTomatoes.push_back({ x,y,z });
				}
			}
		}
	}
	if (!isAllRiped()) {
		int date = BFS(ripedTomatoes);
		if (isAllRiped()) {
			cout << date << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}
	else {
		cout << 0 << '\n';
	}


	return 0;
}

int BFS(const vector<Position> &ripedTomatoes) {
	int date = -1;

	const int dx[] = { 1,-1,0,0,0,0 };
	const int dy[] = { 0,0,1,-1,0,0 };
	const int dz[] = { 0,0,0,0,1,-1 };

	queue<Position> bfs;

	for (Position pos : ripedTomatoes) {
		bfs.push(pos);
		isVisited[pos.z][pos.y][pos.x] = 1;
	}

	while (!bfs.empty()) {
		//cout << "loop" << '\n';
		Position prev;
		prev.x = bfs.front().x;
		prev.y = bfs.front().y;
		prev.z = bfs.front().z;

		for (int dir = 0; dir < 6; dir++) {
			int x = prev.x + dx[dir];
			int y = prev.y + dy[dir];
			int z = prev.z + dz[dir];
			if ((0 <= x && x < x_size) && (0 <= y && y < y_size) && (0 <= z && z < z_size)) {
				if (isVisited[z][y][x] == 0 && tomatoes[z][y][x] == 0) {
					bfs.push({ x,y,z });
					date = isVisited[z][y][x] = isVisited[prev.z][prev.y][prev.x] + 1;
				}
			}
		}

		bfs.pop();
	}
	return date - 1;
}

bool isAllRiped() {
	for (int z = 0; z < z_size; z++) {
		for (int y = 0; y < y_size; y++) {
			for (int x = 0; x < x_size; x++) {
				if (tomatoes[z][y][x] == 0 && isVisited[z][y][x] == 0) {
					return false;
				}
			}
		}
	}
	return true;
}