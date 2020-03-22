#include<iostream>
using namespace std;

int x_size, y_size;
int map[500][500];

int maxTetromino();

int main() {
    cin >> y_size >> x_size;
    for (int y = 0; y < y_size; y++) {
        for (int x = 0; x < x_size; x++) {
            cin >> map[y][x];
        }
    }
    cout << maxTetromino() << '\n';
}


int maxTetromino() {
    int tetromino = 0;

    /// 4X1
    for (int x = 0; x < y_size; x++) {
        for (int y = 0; y <= x_size- 4; y++) {
            int sum = 0;
            for (int z = y; z < y + 4; z++) {
                sum += map[y][z];
            }
            tetromino = tetromino > sum ? tetromino : sum;
        }
    }
    /// 1X4
    for (int x = 0; x <=y_size- 4; x++) {
        for (int y = 0; y <x_size; y++) {
            int sum = 0;
            for (int z = x; z < x + 4; z++) {
                sum += map[z][y];
            }
            tetromino = tetromino > sum ? tetromino : sum;
        }
    }
    /// 2X3
    for (int i = 0; i <= y_size - 3; i++) {
        for (int j = 0; j <= x_size - 2; j++) {
            int sum = 0;
            for (int k = i; k < i + 3; k++) {
                for (int l = j; l < j + 2; l++) {
                    /// 2X3 의 모든 합
                    sum += map[k][l];
                }
            }
            int cases[] = {
                /// 2X3 에서 2블록 뺀 최댓값
                sum - map[i][j] - map[i][j + 1],
                sum - map[i][j] - map[i + 1][j],
                sum - map[i][j + 1] - map[i + 1][j + 1],
                sum - map[i + 2][j] - map[i + 2][j + 1],
                sum - map[i + 1][j + 1] - map[i + 2][j + 1],
                sum - map[i + 1][j] - map[i + 2][j],
                sum - map[i][j + 1] - map[i + 2][j],
                sum - map[i][j] - map[i + 2][j + 1],
                sum - map[i][j] - map[i + 2][j],
                sum - map[i][j + 1] - map[i + 2][j + 1]
            };
            int max = cases[0];
            for (int c = 1; c < 10; c++) {
                if (max < cases[c]) max = cases[c];
            }
            tetromino = max > tetromino ? max : tetromino;
        }
    }
    /// 3X2
    for (int i = 0; i <= y_size - 2; i++) {
        for (int j = 0; j <= x_size - 3; j++) {
            int sum = 0;
            for (int k = i; k < i + 2; k++) {
                for (int l = j; l < j + 3; l++) {
                    /// 3X2 의 모든 합
                    sum += map[k][l];
                }
            }
            int cases[] = {
                /// 3X2 에서 2블록 뺀 최댓값
                sum - map[i + 1][j] - map[i + 1][j + 1],
                sum - map[i][j] - map[i][j + 1],
                sum - map[i][j] - map[i + 1][j],
                sum - map[i][j + 2] - map[i + 1][j + 2],
                sum - map[i][j + 1] - map[i][j + 2],
                sum - map[i + 1][j + 1] - map[i + 1][j + 2],
                sum - map[i][j] - map[i + 1][j + 2],
                sum - map[i][j + 2] - map[i + 1][j],
                sum - map[i][j] - map[i][j + 2],
                sum - map[i + 1][j] - map[i + 1][j + 2]
            };
            int max = cases[0];
            for (int c = 1; c < 10; c++) {
                if (max < cases[c]) max = cases[c];
            }
            tetromino = max > tetromino ? max : tetromino;
        }
    }

    return tetromino;
}