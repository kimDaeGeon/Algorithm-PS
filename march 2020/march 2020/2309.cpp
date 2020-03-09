#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int sum = 0;
	int height[9];

	bool end = false;

	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}


	vector<int> tall;

	for (int i = 0; i < 9; i++) {
		if (end) break;

		for (int j = i + 1; j < 9; j++) {
			if ((sum - height[i] - height[j]) == 100) {
				for (int idx = 0; idx < 9; idx++) {
					if (idx == i || idx == j) continue;
					tall.push_back(height[idx]);
				}
				end = true;
				break;
			}
		}
	}


	std::sort(tall.begin(), tall.end());

	for (int in : tall) {
		cout << in << '\n';
	}


	return 0;
}