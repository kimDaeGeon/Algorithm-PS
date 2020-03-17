#include <iostream>
#include <queue>
using namespace std;

static int map[1000][1000];
static int isVisited[1000][1000];

int main() {
    const int dx[] = { 0,0,1,-1 };
    const int dy[] = { 1,-1,0,0 };

    int x_size, y_size;
    int riped_tomatoes, unriped_tomatoes;

    cin >> x_size >> y_size;
    riped_tomatoes = unriped_tomatoes = 0;


    queue<pair<int, int>> bfs;
    for (int y = 0; y < y_size; y++) {
        for (int x = 0; x < x_size; x++) {
            cin >> map[y][x];
            //모든 노드 푸시
            if (map[y][x] == 1) bfs.push(make_pair(y, x));
            //덜익은 토마토 카운트
            else if (map[y][x] == 0) unriped_tomatoes++;
        }
    }


    //BFS 로 큐에 푸시된 모든 노드 탐색
    int day = 0;
    while (!bfs.empty()) {
        int x = bfs.front().second;
        int y = bfs.front().first;

        for (int dir = 0; dir < 4; dir++) {
            int X = x + dx[dir];
            int Y = y + dy[dir];
            day = isVisited[y][x] + 1;
            if ((0 <= X && X < x_size) && (0 <= Y && Y < y_size)) {
                // 덜익은 토마토 && 방문하지 않은 경우
                if (map[Y][X] == 0 && isVisited[Y][X] == 0) {
                    isVisited[Y][X] = day;
                    bfs.push(make_pair(Y, X));
                }
            }
        }
        bfs.pop();
    }
    
    
    for (int y = 0; y < y_size; y++) {
        for (int x = 0; x < x_size; x++) {
            if (isVisited[y][x] != 0) riped_tomatoes++;
            //cout << isVisited[y][x];
        }
        //cout << '\n';
    }


    if (riped_tomatoes == unriped_tomatoes) cout << day - 1 << '\n';
    else cout << -1 << '\n';
    
    
    return 0;
}