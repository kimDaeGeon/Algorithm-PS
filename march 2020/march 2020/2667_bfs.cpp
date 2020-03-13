#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>

#pragma warning(disable:4996)

using namespace std;

static int map[25][25];
static int isVisited[25][25] = { 0 };
void BFS(int x, int y, int group, int size);

int main() {
	int size;

	scanf("%d", &size);
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			scanf("%1d", &map[y][x]);
		}
	}

	int group = 0;
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			if (map[y][x] == 1 && isVisited[y][x] == 0) {
				BFS(x, y, ++group, size);
			}
		}
	}	

	printf("%d\n", group);
	int* groupSize = new int[group+1];
	for (int g = 1; g <= group; g++) {
		groupSize[g] = 0;
		for (int y = 0; y < size; y++) {
			for (int x = 0; x < size; x++) {
				if (isVisited[y][x] == g) {
					groupSize[g]++;
				}
			}
		}
	}

	std::sort(groupSize + 1, groupSize + group + 1);
	for (int g = 1; g <= group; g++) {
		printf("%d\n", groupSize[g]);
	}

	delete[] groupSize;

	return 0;
}

void BFS(int x, int y, int group, int size) {
	queue<pair<int,int>> bfs;
	
	//첫번째 노드 방문
	bfs.push(make_pair(x,y));
	isVisited[y][x] = group;
	
	while (!bfs.empty()) {
		//연결된 다음 노드 탐색, 방문하지 않고 배열 범위 내 체크
		int x = bfs.front().first;
		int y = bfs.front().second;
		
		//UP [y-1][x]
		if ((0 <= y - 1 && y - 1 < size) && (0 <= x && x < size)) {
			if (isVisited[y - 1][x] == 0 && map[y - 1][x] == 1) {
				bfs.push(make_pair(x, y-1));
				isVisited[y - 1][x] = group;
			}
		}
		//DOWN [y+1][x]
		if ((0 <= y + 1 && y + 1 < size) && (0 <= x && x < size)) {
			if (isVisited[y + 1][x] == 0 && map[y + 1][x] == 1) {
				bfs.push(make_pair(x, y+1));
				isVisited[y + 1][x] = group;
			}
		}
		//LEFT [y][x-1]
		if ((0 <= y && y < size) && (0 <= x - 1 && x - 1 < size)) {
			if (isVisited[y][x - 1] == 0 && map[y][x - 1] == 1) {
				bfs.push(make_pair(x-1, y));
				isVisited[y][x - 1] = group;
			}
		}
		//RIGHT [y][x+1]
		if ((0 <= y && y < size) && (0 <= x + 1 && x + 1 < size)) {
			if (isVisited[y][x + 1] == 0 && map[y][x + 1] == 1) {
				bfs.push(make_pair(x+1, y));
				isVisited[y][x + 1] = group;
			}
		}

		bfs.pop();
	}
	return;
}