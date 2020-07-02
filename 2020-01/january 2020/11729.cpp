#include<iostream>
using namespace std;

void hanoi(int n, int from, int to);

int main() {
	int n;
	cin >> n;
	hanoi(n, 1, 3);

	return 0;
}


void hanoi(int n, int from, int to) {
	hanoi(n - 1, 1, 2);
	hanoi(1, 1, 3);
	hanoi(n - 1, 2, 3);
}