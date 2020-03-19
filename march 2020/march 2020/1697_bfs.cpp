#include<iostream>
#include<queue>
using namespace std;

static bool isVisited[200001];
static int dist[200001];

int main() {
	int current, find;
	cin >> current >> find;

	isVisited[current] = true;
	dist[current] = 0;

	queue<int> bfs;
	bfs.push(current);

	while (!bfs.empty()) {
		int current_pos = bfs.front();

		bfs.pop();

		//현위치 - 1
		if (current_pos - 1 >= 0) {
			if (isVisited[current_pos - 1] == false) {
				isVisited[current_pos - 1] = true;
				bfs.push(current_pos - 1);

				dist[current_pos - 1] = dist[current_pos] + 1;
			}
		}
		//현위치 + 1
		if (current_pos + 1 < 200001) {
			if (isVisited[current_pos + 1] == false) {
				isVisited[current_pos + 1] = true;
				bfs.push(current_pos + 1);

				dist[current_pos + 1] = dist[current_pos] + 1;
			}
		}
		//현위치 * 2
		if (current_pos *2 < 200001) {
			if (isVisited[current_pos *2] == false) {
				isVisited[current_pos *2] = true;
				bfs.push(current_pos *2);

				dist[current_pos *2] = dist[current_pos] + 1;
			}
		}
		
	}

	cout << dist[find] << '\n';

	return 0;
}