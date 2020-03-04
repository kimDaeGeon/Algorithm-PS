#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N;
	long long sum = 0;
	long long dice[6];

	cin >> N;
	for (int i = 0; i < 6; i++) cin >> dice[i];

	long long arr[3] = {
		dice[0] > dice[5] ? dice[5] : dice[0],
		dice[1] > dice[4] ? dice[4] : dice[1],
		dice[2] > dice[3] ? dice[3] : dice[2],
	};

	long long min3 = arr[0] + arr[1] + arr[2];
	long long min2 = arr[0] + arr[1];
	long long min1 = arr[2];

	if (N == 1) {
		std::sort(dice, dice + 6);
		for (int i = 0; i < 5; i++) sum += dice[i];
	}
	else {
		sum += ((N - 1) * (N - 2) * 4 + (N - 2) * (N - 2)) * min1;
		sum += ((N - 1) * 4 + (N - 2) * 4) * min2;
		sum += min3 * 4;
	}

	std::cout << sum << endl;
}