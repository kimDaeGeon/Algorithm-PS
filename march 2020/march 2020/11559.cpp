#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int x_size = 6;
const int y_size = 12;
char map[12][6];

bool BFS(int x, int y, char puyo);
void rearrangePuyo();

int main() {
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			cin >> map[y][x];
		}
	}

	int combo = 0;

	while (true) {
		int boom = 0;
		for (int y = 0; y < y_size; y++) {
			for (int x = 0; x < x_size; x++) {
				if (map[y][x] != '.') {
					/// �����°� �ѹ��� �Ͼ�������� ��������
					boom += BFS(x, y, map[y][x]);
				}
			}
		}
		rearrangePuyo();
		if (boom == 0) break;
		combo++;
	}

	cout << combo << '\n';
	
	return 0;
}

bool BFS(int x, int y, char puyo) {
	/// puyo�� �ش��ϴ� ���� �ʺ� �켱 Ž��
	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };
	int isVisited[12][6] = { 0 };

	queue<pair<int, int>> bfs;
	vector<pair<int, int>> puyo_pos;


	int adjacency = 0;
	isVisited[y][x] = ++adjacency;
	bfs.push(make_pair(y, x));
	puyo_pos.push_back(make_pair(y,x));

	while (!bfs.empty()) {
		int x = bfs.front().second;
		int y = bfs.front().first;
		for (int dir = 0; dir < 4; dir++) {
			int X = x + dx[dir], Y = y + dy[dir];
			if ((0 <= X && X < x_size) && (0 <= Y && Y < y_size)) {
				if (isVisited[Y][X] == 0 && map[Y][X] == puyo) {
					isVisited[Y][X] = ++adjacency;
					puyo_pos.push_back(make_pair(Y, X));
					bfs.push(make_pair(Y, X));
				}
			}
		}

		bfs.pop();
	}

	/// 4�� �ѿ䰡 �´�� ������ �Ͷ߸�
	if (adjacency >= 4) {
		for (pair<int, int> p : puyo_pos) {
			map[p.first][p.second] = '.';
		}
		return true;
	}
	return false;
}

void rearrangePuyo() {
	for (int i = 11; i >= 0; i--)
		for (int j = 0; j <= 6; j++)
		{
			if (i == 11) continue;
			int tmp = i;
			while (map[tmp + 1][j] == '.' && map[tmp][j] != '.')
				map[tmp + 1][j] = map[tmp][j], map[tmp][j] = '.', tmp++;

		}
}