#include<iostream>
#include<vector>
using namespace std;

#define STOP 0
#define FAIL -1
#define SUCCESS 1

int x_size, y_size;
char map[10][10];

template<typename T>void SWAP(T & x, T& y) {
	T temp = x; x = y; y = temp;
}
void print() {
	char stop;
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			cout << map[y][x];
		}
		cout << '\n';
	}
	cin >> stop;
}

int UP(pair<int, int>& red, pair<int, int>& blue);
int DOWN(pair<int, int>& red, pair<int, int>& blue);
int LEFT(pair<int, int>& red, pair<int, int>& blue);
int RIGHT(pair<int, int>& red, pair<int, int>& blue);
bool canSolve(const int solution[], pair<int,int> red, pair<int,int> blue);

/****************************************************************/

int main() {
	pair<int, int> red, blue;

	cin >> y_size >> x_size;
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'R')
				red.first = y, red.second = x;
			else if (map[y][x] == 'B')
				blue.first = y, blue.second = x;
		}
	}


	for (int a = 1; a <= 4; a++) { // 1
		for (int b = 1; b <= 4; b++) { // 2
			for (int c = 1; c <= 4; c++) { // 3
				for (int d = 1; d <= 4; d++) { // 4
					for (int e = 1; e <= 4; e++) { // 5
						for (int f = 1; f <= 4; f++) { // 6
							for (int g = 1; g <= 4; g++) { // 7
								for (int h = 1; h <= 4; h++) { //8
									for (int i = 1; i <= 4; i++) { // 9
										for (int j = 1; j <= 4; j++) { // 10
											int solution[] = { a,b,c,d,e,f,g,h,i,j };
											if (canSolve(solution,red,blue)) {
												cout << 1 << '\n';
												return 0;
											}
											else {
												continue;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	cout << 0 << '\n';
	

	return 0;
}


bool canSolve(const int solution[], pair<int, int> red, pair<int, int> blue) {
	for (int s = 0; s < 10; s++) {
		if (solution[s] == 1) {
			if (UP(red, blue) == SUCCESS) return true;
			else if (UP(red, blue) == STOP) continue;
			else if (UP(red, blue) == FAIL) return false;
		}
		else if (solution[s] == 2) {
			if (DOWN(red, blue) == SUCCESS) return true;
			else if (DOWN(red, blue) == STOP) continue;
			else if (DOWN(red, blue) == FAIL) return false;
		}
		else if (solution[s] == 3) {
			if (LEFT(red, blue) == SUCCESS) return true;
			else if (LEFT(red, blue) == STOP) continue;
			else if (LEFT(red, blue) == FAIL) return false;
		}
		else if (solution[s] == 4) {
			if (RIGHT(red, blue) == SUCCESS) return true;
			else if (RIGHT(red, blue) == STOP) continue;
			else if (RIGHT(red, blue) == FAIL) return false;
		}
	}
	return false;
}


int UP(pair<int,int> &red, pair<int,int> &blue) {
	bool isRedStop = false;
	bool isBlueStop = false;

	while (true) {
		int rx = red.second, ry = red.first;
		int bx = blue.second, by = blue.first;
		/// R B 중 위에있는 구슬 먼저 움직이고, 현재위치 업데이트
		if (ry < by) { /// R 가 더 위에 있음
			/// R
			if (map[ry - 1][rx] == '.') {
				SWAP(map[ry - 1][rx], map[ry][rx]);
				ry = ry - 1;
			}
			else if (map[ry - 1][rx] == '#') {
				isRedStop = true;
			}
			else if (map[ry - 1][rx] == 'O') {
				return SUCCESS;
			}
			/// B
			if (map[by - 1][bx] == '.') {
				SWAP(map[by - 1][bx], map[by][bx]);
				by = by - 1;
			}
			else if (map[by - 1][bx] == '#') {
				isBlueStop = true;
			}
			else if (map[by - 1][bx] == 'O') {
				return FAIL;
			}

			/// pair 업데이트
			red = make_pair(ry, rx);
			blue = make_pair(by, bx);
		}
		else { /// B 가 더 위에 있음
			/// B
			if (map[by - 1][bx] == '.') {
				SWAP(map[by - 1][bx], map[by][bx]);
				by = by - 1;
			}
			else if (map[by - 1][bx] == '#') {
				isBlueStop = true;
			}
			else if (map[by - 1][bx] == 'O') {
				return FAIL;
			}
			/// R
			if (map[ry - 1][rx] == '.') {
				SWAP(map[ry - 1][rx], map[ry][rx]);
				ry = ry - 1;
			}
			else if (map[ry - 1][rx] == '#') {
				isRedStop = true;
			}
			else if (map[ry - 1][rx] == 'O') {
				return SUCCESS;
			}

			/// pair 업데이트
			red = make_pair(ry, rx);
			blue = make_pair(by, bx);
		}
		
		 ///print();

		if (isRedStop && isBlueStop)
			return STOP;
	}
}

int DOWN(pair<int, int>& red, pair<int, int>& blue) {
	bool isRedStop = false;
	bool isBlueStop = false;

	while (true) {
		int rx = red.second, ry = red.first;
		int bx = blue.second, by = blue.first;
		/// R B 중 아래에있는 구슬 먼저 움직이고, 위치 업데이트
		if (ry > by) { /// R이 더 아래에 있음
			///R
			if (map[ry + 1][rx] == '.') {
				SWAP(map[ry + 1][rx], map[ry][rx]);
				ry = ry + 1;
			}
			else if (map[ry + 1][rx] == '#') {
				isRedStop = true;
			}
			else if (map[ry + 1][rx] == 'O') {
				return SUCCESS;
			}
			///B
			if (map[by + 1][bx] == '.') {
				SWAP(map[by + 1][bx], map[by][bx]);
				by = by + 1;
			}
			else if (map[by + 1][bx] == '#') {
				isBlueStop = true;
			}
			else if (map[by + 1][bx] == 'O') {
				return FAIL;
			}
			/// pair 업데이트
			red = make_pair(ry, rx);
			blue = make_pair(by, bx);
		}
		else {
			///B
			if (map[by + 1][bx] == '.') {
				SWAP(map[by + 1][bx], map[by][bx]);
				by = by + 1;
			}
			else if (map[by + 1][bx] == '#') {
				isBlueStop = true;
			}
			else if (map[by + 1][bx] == 'O') {
				return FAIL;
			}
			///R
			if (map[ry + 1][rx] == '.') {
				SWAP(map[ry + 1][rx], map[ry][rx]);
				ry = ry + 1;
			}
			else if (map[ry + 1][rx] == '#') {
				isRedStop = true;
			}
			else if (map[ry + 1][rx] == 'O') {
				return SUCCESS;
			}
			/// pair 업데이트
			red = make_pair(ry, rx);
			blue = make_pair(by, bx);
		}
		///print();

		if (isRedStop && isBlueStop)
			return STOP;
	}
}
int LEFT(pair<int, int>& red, pair<int, int>& blue) {
	bool isRedStop = false;
	bool isBlueStop = false;

	while (true) {
		int rx = red.second, ry = red.first;
		int bx = blue.second, by = blue.first;
		/// R B 중 왼쪽에 있는 구슬 먼저 움직이고, 위치 업데이트
		if (rx > bx) { /// B가 더 왼쪽
			/// B
			if (map[by][bx - 1] == '.') {
				SWAP(map[by][bx - 1], map[by][bx]);
				bx = bx - 1;
			}
			else if (map[by][bx - 1] == '#') {
				isBlueStop = true;
			}
			else if (map[by][bx - 1] == 'O') {
				return FAIL;
			}
			/// R
			if (map[ry][rx - 1] == '.') {
				SWAP(map[ry][rx - 1], map[ry][rx]);
				rx = rx - 1;
			}
			else if (map[ry][rx - 1] == '#') {
				isRedStop = true;
			}
			else if (map[ry][rx - 1] == 'O') {
				return SUCCESS;
			}

			//pair 업데이트
			red = make_pair(ry, rx);
			blue = make_pair(ry, rx);
		}
		else {
			/// R
			if (map[ry][rx - 1] == '.') {
				SWAP(map[ry][rx - 1], map[ry][rx]);
				rx = rx - 1;
			}
			else if (map[ry][rx - 1] == '#') {
				isRedStop = true;
			}
			else if (map[ry][rx - 1] == 'O') {
				return SUCCESS;
			}
			/// B
			if (map[by][bx - 1] == '.') {
				SWAP(map[by][bx - 1], map[by][bx]);
				bx = bx - 1;
			}
			else if (map[by][bx - 1] == '#') {
				isBlueStop = true;
			}
			else if (map[by][bx - 1] == 'O') {
				return FAIL;
			}

			//pair 업데이트
			red = make_pair(ry, rx);
			blue = make_pair(by, bx);
		}

		///print();
		
		if (isRedStop && isBlueStop)
			return STOP;
	}
}

int RIGHT(pair<int, int>& red, pair<int, int>& blue) {
	bool isRedStop = false;
	bool isBlueStop = false;

	while (true) {
		int rx = red.second, ry = red.first;
		int bx = blue.second, by = blue.first;
		/// R B 중 오른쪽에 있는 구슬 먼저 움직이고, 위치 업데이트
		if (rx > bx) { /// R이 더 오른쪽
			/// R
			if (map[ry][rx + 1] == '.') {
				SWAP(map[ry][rx + 1], map[ry][rx]);
				rx = rx + 1;
			}
			else if (map[ry][rx + 1] == '#') {
				isRedStop = true;
			}
			else if (map[ry][rx + 1] == 'O') {
				return SUCCESS;
			}
			/// B
			if (map[by][bx + 1] == '.') {
				SWAP(map[by][bx + 1], map[by][bx]);
				bx = bx + 1;
			}
			else if (map[by][bx + 1] == '#') {
				isBlueStop = true;
			}
			else if (map[by][bx + 1] == 'O') {
				return FAIL;
			}

			//pair 업데이트
			red = make_pair(ry, rx);
			blue = make_pair(ry, rx);
		}
		else {
			/// B
			if (map[by][bx + 1] == '.') {
				SWAP(map[by][bx + 1], map[by][bx]);
				bx = bx + 1;
			}
			else if (map[by][bx + 1] == '#') {
				isBlueStop = true;
			}
			else if (map[by][bx + 1] == 'O') {
				return FAIL;
			}
			/// R
			if (map[ry][rx + 1] == '.') {
				SWAP(map[ry][rx + 1], map[ry][rx]);
				rx = rx + 1;
			}
			else if (map[ry][rx + 1] == '#') {
				isRedStop = true;
			}
			else if (map[ry][rx + 1] == 'O') {
				return SUCCESS;
			}

			//pair 업데이트
			red = make_pair(ry, rx);
			blue = make_pair(by, bx);
		}

		///print();

		if (isRedStop && isBlueStop)
			return STOP;
	}
}