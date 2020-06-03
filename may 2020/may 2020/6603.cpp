#include<iostream>
#include<vector>
using namespace std;

void printVector(const vector<int> element, const vector<int> index) {
	for (int idx : index) {
		cout << element[idx] << ' ';
	}
	cout << '\n';
}

void pick(int size, const vector<int> element, vector<int> &index, int toPick) {
	if (toPick == 0) {
		printVector(element, index);
		return;
	}
	int min = index.empty() ? 0 : index.back() + 1;
	for (int next = min; next < size; next++) {
		index.push_back(next);
		pick(size, element, index, toPick - 1);
		index.pop_back();
	}
}

int main() {

	while (true) {
		int size;
		cin >> size;

		if (size == 0) break;

		vector<int> element;
		for (int i = 0; i < size; i++) {
			int e; cin >> e;
			element.push_back(e);
		}
		
		vector<int> index;
		pick(size, element, index, 6);

		for (int idx : index) {
			cout << idx << ' ';
		}
		cout << '\n';
	}

	return 0;
}