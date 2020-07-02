#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int size;
	cin >> size;

	pair<int, int>* arr = new pair<int, int>[size];

	for (int i = 0; i < size; i++) {
		int x, y;
		cin >> x >> y;

		arr[i] = make_pair(x, y);
	}

	std::sort(arr, arr + size);

	for (int i = 0; i < size; i++) {
		cout << arr[i].first << ' ' << arr[i].second << '\n';
	}
}