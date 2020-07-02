#include<iostream>
using namespace std;

int main() {
	bool isExist = false;
	int m, n, sum = 0, min = 10000;
	cin >> m >> n;

	int i = 0;
	while(true){
		if (i * i > n) break;
		if (i * i >= m) {
			isExist = true;
			min = (i * i) < min ? (i * i) : min;
			sum += i * i;
		}
		i++;
	}
	
	if (isExist) {
		cout << sum << endl << min << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}