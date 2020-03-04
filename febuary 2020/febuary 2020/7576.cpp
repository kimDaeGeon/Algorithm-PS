#include<iostream>
#include<stdlib.h>
using namespace std;

int tomatoes[1000][1000] = { 0 };

int ripe(int m, int n);
int print(int m, int n);

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int m, n;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tomatoes[i][j];
		}
	}

	ripe(m, n);



	return 0;
}

int ripe(int m, int n) {
	int count = 0;

	while (true) {
		//find 1
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (tomatoes[i][j] == 1) {
					//up
					if (i-1 >= 0 && tomatoes[i - 1][j] == 0)
						tomatoes[i - 1][j] = 1;
					//down
					if (i+1 < m && tomatoes[i + 1][j] == 0)
						tomatoes[i + 1][j] = 1;
					//left
					if (j-1 >= 0 && tomatoes[i][j - 1] == 0)
						tomatoes[i][j - 1] = 1;
					//right
					if (j+1 < n && tomatoes[i][j +1] == 0)
						tomatoes[i][j + 1] = 1;
				}
			}
		}
		cout << print(m, n) << '\n';
		system("pause");
	}

	return 0;
}

int print(int m, int n) {			
	int count = 0;
	cout << '\n';
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (tomatoes[i][j] == 1)
				count++;
			cout << tomatoes[i][j] << ' ';
		}
		cout << '\n';
	}
	return count;
}