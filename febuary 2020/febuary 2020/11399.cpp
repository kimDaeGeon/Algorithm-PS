#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);
	
	
	int *arr, n;
	cin >> n;

	arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	std::sort(arr, arr + n);

	int totalMin = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += arr[j];
		}
		totalMin += sum;
	}

	cout << totalMin << endl;
	

	return 0;
}