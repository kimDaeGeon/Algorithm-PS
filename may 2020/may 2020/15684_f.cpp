#include<iostream>
using namespace std;

int N, M, H, destination;
int ladder[30][40] = { 0 };

void DFS(int x, int y = 0) {
	const int dx[] = {-1,1,0};
	const int dy[] = {0,0,1};

	ladder[y][x] += 1;
	destination = x;

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < 2 * N - 1; x++) {
			if (ladder[y][x] != 0) cout << ladder[y][x];
			else cout << " ";
		}
		cout << '\n';
	}
	cout << '\n';

	if (ladder[y][x - 1] == 1) {
		if ((0 <= x - 1 && x - 1 < 2 * N - 1) && (0 <= y && y < H)) {
			DFS(x - 1, y);
		}
	}
	else if (ladder[y][x + 1] == 1) {
		if ((0 <= x + 1 && x + 1 < 2 * N - 1) && (0 <= y && y < H)) {
			DFS(x + 1, y);
		}
	}
	else if (ladder[y + 1][x] == 1) {
		if ((0 <= x && x < 2 * N - 1) && (0 <= y + 1 && y + 1 < H)) {
			DFS(x, y + 1);
		}
	}
}

int main() {
	cin >> N >> M >> H;

	//vertical line
	for (int x = 0; x < 2 * N - 1; x += 2) {
		for (int y = 0; y < H; y++) {
			ladder[y][x] = 1;
		}
	}


	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a - 1][b * 2 - 1] = 1;
	} 

	DFS(0);
	cout << destination / 2 << '\n';


	return 0;
}