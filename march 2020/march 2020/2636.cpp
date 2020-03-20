#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define CHEESE 1
#define BLANK 0

int x_size, y_size;
int cheese[100][100];
int melt();

int main() {
	int total_cheese = 0;
	cin >> y_size >> x_size;

	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			cin >> cheese[y][x];
			if (cheese[y][x] == CHEESE) total_cheese++;
		}
	}

	/// �ܰ躰�� ���� ġ�� ������ ������ vector �����̳ʿ� �����Ѵ�.
	int remained_cheese;
	vector<int> remain;
	while (true) {
		remained_cheese = melt();
		remain.push_back(remained_cheese);
		if (remained_cheese == 0) break;
	}

	/// �ѹ��� ġ� ��� ���������� Ȯ��
	if (remain.size() != 1) {
		cout << remain.size() << '\n';
		cout << remain[remain.size() - 2] << '\n';
	}
	else {
		/// �ѹ��� ġ� ��� �������� ���, ó�������� ġ����� ����Ѵ�.
		cout << remain.size() << '\n';
		cout << total_cheese << '\n';
	}
	
	return 0;
}

int melt() {
	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };

	bool isVisited[100][100] = { false };

	queue<pair<int,int>> bfs;

	/// [0][0]���� �ٱ��� ���� �����κ� �ʺ�켱Ž��
	isVisited[0][0] = true;
	bfs.push(make_pair(0, 0));

	while (!bfs.empty()) {
		int x = bfs.front().second;
		int y = bfs.front().first;

		for (int dir = 0; dir < 4; dir++) {
			int X = x + dx[dir];
			int Y = y + dy[dir];
			if ((0 <= X && X < x_size) && (0 <= Y && Y < y_size)) {
				if (isVisited[Y][X] == false && cheese[Y][X] == 0) {
					isVisited[Y][X] = true;
					bfs.push(make_pair(Y, X));
				}
			}
		}
		bfs.pop();
	}

	/// -1 ��ó ġ� ��� �����Ѵ�
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			/// [y][x]�� AIR �̸� ��ó dir �κ��� ġ� �����Ѵ�.
			if (isVisited[y][x] == true) {
				for (int dir = 0; dir < 4; dir++) {
					int X = x + dx[dir], Y = y + dy[dir];
					if ((0 <= X && X < x_size) && (0 <= Y && Y < y_size)) {
						cheese[Y][X] = 0;
					}
				}
			}
		}
	}

	/// ���� ġ�� ���� ����
	int countCheese = 0;
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			if (cheese[y][x] == CHEESE)
				countCheese++;
		}
	}

	return countCheese;
}