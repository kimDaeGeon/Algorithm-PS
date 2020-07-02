#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int main() {
	int* arr, size;
	scanf("%d", &size);

	arr = new int[size];
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	std::sort(arr, arr + size);
	for (int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
	}
}