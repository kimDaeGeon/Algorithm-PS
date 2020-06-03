#include<iostream>
#include<algorithm>
using namespace std;

int x_size, y_size;
int map[501][501];

int max();
int shape1(); //¦¡
int shape2(); //¤±
int shape3(); //¤¤
int shape4(); //¦¦¦¤
int shape5(); // ¤Ì

int main() {
	cin >> y_size >> x_size;

	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			cin >> map[y][x];
		}
	}

	cout << max() << '\n';
}

int shape1() {
	int max = 0;
	// l
	for (int y = 0; y < y_size - 3; y++) {
		for (int x = 0; x < x_size; x++) {
			int sum = 0;
			for (int i = 0; i <= 3; i++) {
				sum += map[y + i][x];
			}
			max = max < sum ? sum : max;
		}
	}
	// ¤Ñ
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size - 3; x++) {
			int sum = 0;
			for (int i = 0; i <= 3; i++) {
				sum += map[y][x + i];
			}
			max = max < sum ? sum : max;
		}
	}
	return max;
}
int shape2() {
	int max = 0;
	//¤±
	for (int y = 0; y < y_size - 1; y++) {
		for (int x = 0; x < x_size - 1; x++) {
			int sum = map[y][x] + map[y + 1][x] + map[y][x + 1] + map[y + 1][x + 1];
			max = max < sum ? sum : max;
		}
	}
	return max;
}
int shape3() {
	int max = 0;
	//1
	for (int y = 0; y < y_size - 2; y++) {
		for (int x = 0; x < x_size - 1; x++) {
			int sum = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 2][x + 1];
			max = max < sum ? sum : max;
		}
	}
	//2
	for (int y = 0; y < y_size-1; y++) {
		for (int x = 0; x < x_size-2; x++) {
			int sum = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x];
			max = max < sum ? sum : max;
		}
	}
	//3
	for (int y = 0; y < y_size - 2; y++) {
		for (int x = 0; x < x_size - 1; x++) {
			int sum = map[y][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 2][x + 1];
			max = max < sum ? sum : max;
		}
	}
	//4
	for (int y = 0; y < y_size - 1; y++) {
		for (int x = 0; x < x_size - 2; x++) {
			int sum = map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2] + map[y][x + 2];
			max = max < sum ? sum : max;
		}
	}
	//5
	for (int y = 0; y < y_size - 2; y++) {
		for (int x = 0; x < x_size - 1; x++) {
			int sum = map[y][x + 1] + map[y + 1][x + 1] + map[y + 2][x + 1] + map[y + 2][x];
			max = max < sum ? sum : max;
		}
	}
	//6
	for (int y = 0; y < y_size - 1; y++) {
		for (int x = 0; x < x_size - 2; x++) {
			int sum = map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2];
			max = max < sum ? sum : max;
		}
	}
	//7
	for (int y = 0; y < y_size - 2; y++) {
		for (int x = 0; x < x_size - 1; x++) {
			int sum = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y][x + 1];
			max = max < sum ? sum : max;
		}
	}
	//8
	for (int y = 0; y < y_size - 1; y++) {
		for (int x = 0; x < x_size - 2; x++) {
			int sum = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 2];
			max = max < sum ? sum : max;
		}
	}
	return max;
}
int shape4() {
	int max = 0;
	//1
	for (int y = 0; y < y_size - 2; y++) {
		for (int x = 0; x < x_size - 1; x++) {
			int sum = map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x + 1];
			max = max < sum ? sum : max;
		}
	}
	//2
	for (int y = 0; y < y_size - 1; y++) {
		for (int x = 0; x < x_size - 2; x++) {
			int sum = map[y][x + 1] + map[y][x + 2] + map[y + 1][x] + map[y + 1][x + 1];
			max = max < sum ? sum : max;
		}
	}
	//3 
	for (int y = 0; y < y_size - 2; y++) {
		for (int x = 0; x < x_size - 1; x++) {
			int sum = map[y][x + 1] + map[y + 1][x + 1] + map[y + 1][x] + map[y + 2][x];
			max = max < sum ? sum : max;
		}
	}
	//4
	for (int y = 0; y < y_size - 1; y++) {
		for (int x = 0; x < x_size - 2; x++) {
			int sum = map[y][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 1][x + 2];
			max = max < sum ? sum : max;
		}
	}
	return max;
}
int shape5() {
	int max = 0;
	//1
	for (int y = 0; y < y_size - 1; y++) {
		for (int x = 0; x < x_size - 2; x++) {
			int sum = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 1];
			max = max < sum ? sum : max;
		}
	}
	//2
	for (int y = 0; y < y_size - 2; y++) {
		for (int x = 0; x < x_size - 1; x++) {
			int sum = map[y][x + 1] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x + 1];
			max = max < sum ? sum : max;
		}
	}
	//3
	for (int y = 0; y < y_size - 1; y++) {
		for (int x = 0; x < x_size - 2; x++) {
			int sum = map[y][x + 1] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2];
			max = max < sum ? sum : max;
		}
	}
	//4
	for (int y = 0; y < y_size - 2; y++) {
		for (int x = 0; x < x_size - 1; x++) {
			int sum = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x + 1];
			max = max < sum ? sum : max;
		}
	}
	return max;
}
int max() {
	int sum[] = {
		shape1(),
		shape2(),
		shape3(),
		shape4(),
		shape5(),
	};
	sort(sum, sum + 5);
	return sum[4];
}