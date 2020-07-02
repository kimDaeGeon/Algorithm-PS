#include<iostream>
#include<algorithm>
using namespace std;

int lowerBound(int arr[], int size, int key);

int main() {
	int *points, m, n;
	cin >> m >> n;

	points = new int[m];
	for (int i = 0; i < m; i++) cin >> points[i];
	std::sort(points, points + m);

	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		int idx1 = lowerBound(points, m, from);
		int idx2 = lowerBound(points, m, to);

		if()
	}
	return 0;
}

int lowerBound(int arr[], int size, int key) {
	int front = 0, end = size - 1, mid;
	while (end > front) {
		mid = (front + end) / 2;
		if (arr[mid] >= key) {
			end = mid;
		}
		else front = mid + 1;
	}
	return end;
}
