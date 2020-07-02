#include<iostream>
#include<vector>
using namespace std;

int isVisited[21][21] = { 0 };

int maxStep;
int x_size, y_size;

char map[21][21];

inline bool isSteped(char key, const vector<char>& step);
void DFS(int x, int y, int depth, vector<char> &step);

int main() {
	cin >> y_size >> x_size;
	
	for (int y = 0; y < y_size; y++) {
		cin >> map[y];
	}

	vector<char> step;
	DFS(0, 0, 1, step);
	
	

	cout << maxStep + 1 << '\n';
	return 0;
}


bool isSteped(char key, const vector<char>& step) {
	for (char ch : step) {
		if (ch == key) return true;
	}
	return false;
}
void DFS(int x, int y, int depth, vector<char> &step) {
	//int isVisited[21][21] = { 0 };

	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };

	isVisited[y][x] = depth;
	step.push_back(map[y][x]);

	for (int dir = 0; dir < 4; dir++) {
		int X = x + dx[dir];
		int Y = y + dy[dir];
		if ((0 <= X && X < x_size) && (0 <= Y && Y < y_size)) {
			if (isVisited[Y][X] == 0 && !isSteped(map[Y][X], step) && map[Y][X] != NULL) {
				DFS(X, Y, depth + 1, step);
				isVisited[Y][X] = 0;
				step.pop_back();
				maxStep = depth > maxStep ? depth : maxStep;
			}
		}
	}
}
