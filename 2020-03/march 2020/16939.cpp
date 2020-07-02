#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>

using namespace std;

int cube[25];

bool isSolved(const int cube[]);
void rotateCube(deque<int> &dq, bool dir);

const vector<int> idx1 = { 1,3,5,7,9,11,22,24 };
const vector<int> idx2 = { 5,6,17,18,21,22,13,14 };
const vector<int> idx3 = { 1,2,18,20,11,12,13,15 };

int main() {
	deque<int> rotate;
	for (int i = 1; i <= 24; i++) cin >> cube[i];

	int temp[25];

	/***********************************************************/
	/// 1,3,5,7,9,11,22,24 沥规氢
	std::copy(cube, cube + 25, temp);

	for (int idx : idx1) rotate.push_back(temp[idx]);
	rotateCube(rotate, true);
	for (int idx : idx1) temp[idx] = rotate.front(), rotate.pop_front();
	
	if (isSolved(temp)) {
		cout << 1 << '\n';
		return 0;
	}

	/// 1,3,5,7,9,11,22,24 开规氢
	std::copy(cube, cube + 25, temp);

	for (int idx : idx1) rotate.push_back(temp[idx]);
	rotateCube(rotate, false);
	for (int idx : idx1) temp[idx] = rotate.front(), rotate.pop_front();

	if (isSolved(temp)) {
		cout << 1 << '\n';
		return 0;
	}

	/***********************************************************/
	/// 5,6,17,18,21,22,13,14 沥规氢
	std::copy(cube, cube + 25, temp);

	for (int idx : idx2) rotate.push_back(temp[idx]);
	rotateCube(rotate, true);
	for (int idx : idx2) temp[idx] = rotate.front(), rotate.pop_front();

	if (isSolved(temp)) {
		cout << 1 << '\n';
		return 0;
	}

	/// 5,6,17,18,21,22,13,14 开规氢
	std::copy(cube, cube + 25, temp);

	for (int idx : idx2) rotate.push_back(temp[idx]);
	rotateCube(rotate, false);
	for (int idx : idx2) temp[idx] = rotate.front(), rotate.pop_front();

	if (isSolved(temp)) {
		cout << 1 << '\n';
		return 0;
	}

	/***********************************************************/
	/// 1,2,18,20,11,12,13,15 沥规氢
	std::copy(cube, cube + 25, temp);

	for (int idx : idx3) rotate.push_back(temp[idx]);
	rotateCube(rotate, true);
	for (int idx : idx3) temp[idx] = rotate.front(), rotate.pop_front();

	if (isSolved(temp)) {
		cout << 1 << '\n';
		return 0;
	}

	/// 1,2,18,20,11,12,13,15 开规氢
	std::copy(cube, cube + 25, temp);

	for (int idx : idx3) rotate.push_back(temp[idx]);
	rotateCube(rotate, false);
	for (int idx : idx3) temp[idx] = rotate.front(), rotate.pop_front();

	if (isSolved(temp)) {
		cout << 1 << '\n';
		return 0;
	}

	/***********************************************************/

	cout << 0 << '\n';
	return 0;
}


bool isSolved(const int cube[]) {
	return (cube[1] == cube[2] && cube[2] == cube[3] && cube[3] == cube[4])
		&& (cube[5] == cube[6] && cube[6] == cube[7] && cube[7] == cube[8])
		&& (cube[9] == cube[10] && cube[10] == cube[11] && cube[11] == cube[12])
		&& (cube[13] == cube[14] && cube[14] == cube[15] && cube[15] == cube[16])
		&& (cube[17] == cube[18] && cube[18] == cube[19] && cube[19] == cube[20]);
}

void rotateCube(deque<int> &dq, bool dir) {
	if (dir) { /// 沥规氢
		for (int i = 0; i < 2; i++) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
	}
	else {
		for (int i = 0; i < 2; i++) {
			dq.push_front(dq.back());
			dq.pop_back();
		}
	}
}