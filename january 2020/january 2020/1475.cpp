#include<iostream>
#include<string>
using namespace std;

int main() {
	int count[10] = { 0 };
	string room;
	cin >> room;
	for (int i = 0; i < room.length(); i++) {
		for (char ch = '0', idx = 0; ch <= '9'; ch++, idx++) {
			if (room[i] == ch) {
				if (room[i] == '6' || room[i] == '9') count[7]++;
				else count[(int)idx]++;
			}
		}
	}
	++count[7] /= 2;

	int max = count[0];
	for (int i = 0; i < 10; i++)
		if (max < count[i]) max = count[i];

	cout << max << endl;

	//for (int i = 0; i < 10; i++) cout << count[i] << " "; 
	//cout << endl;
	

}