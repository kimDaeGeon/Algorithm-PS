#include<iostream>
using namespace std;



int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a > b ? b : a;
}

int main() {
	int n, * prices;
	cin >> n;

	prices = new int[n];
	for (int i = 0; i < n; i++) cin >> prices[i];

	

	return 0;
}