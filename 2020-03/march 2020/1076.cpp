#include<iostream>
#include<string>
using namespace std;

int main() {
	const string color[] = {
		"black", "brown", "red", "orange", 
		"yellow", "green", "blue", "violet",
		"grey", "white"
	};

	string str;
	int arr[3];
	long long resistance = 0;



	for (int i = 0; i < 3; i++) {
		cin >> str;
		for (int j = 0; j < 10; j++) {
			if (color[j] == str) {
				arr[i] = j;
			}
		}
	}


	resistance = arr[0] * 10 + arr[1];
	for (int i = 0; i < arr[2]; i++) resistance *= 10;

	cout << resistance << '\n';

	return 0;
}