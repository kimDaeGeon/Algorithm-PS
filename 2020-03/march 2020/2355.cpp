#include<iostream>
using namespace std;

int main() {
	long long i, j, sum;
	cin >> i >> j;

	cout << (i + j) * (abs(j - i) + 1) / 2 << '\n';
}