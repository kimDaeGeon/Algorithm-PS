#pragma warning(disable:4996)
#include<iostream>
#include<queue>
using namespace std;

int x_size, y_size;
int map[100][100];
int isVisited[100][100]

void BFS();

int main() {
	cin >> x_size >> y_size;
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			scanf("%1d", &map[y][x]);
		}
	}

	BFS(0,0)


	return 0;
}

void BFS() {
	queue<pair<int, int>> bfs;
	
	bfs.push(make_pair(0, 0));

}

