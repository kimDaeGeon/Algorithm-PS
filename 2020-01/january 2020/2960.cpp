#include<iostream>
using namespace std;

int main() {
	int del_count = 1;
	int* arr, size, nth;
	cin >> size >> nth;

	arr = new int[size-1];
	for (int i = 0; i < size - 1; i++) arr[i] = i + 2;
	
	for (int i = 0, j = 2; i < size - 1; i++, j++) {
		for (int k = i; k < size - 1; k += j) {
			//for (int l = 0; l < size - 1; l++) cout << arr[l] << " ";
			//cout << " : " << del_count << endl;
			if (arr[k] != 0) {
				//cout << del_count << endl;
				if(del_count == nth)
					cout << arr[k] << endl;
				del_count++;
				arr[k] = 0;
			}
			else {
				continue;
			}
		}
		//cout <<  endl;
	}

	/*
	for (int i = 2, j = 2; i < size; i += 2, j++) {
		for (int k = i; k < size; k += j) {
			cout << k << " ";
		}
		cout << endl;
	}
	*/

	return 0;
}