#include<bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int a, b;
	scanf("%d:%d", &a, &b);

	cout << a / gcd(a, b) << ":" << b / gcd(a, b) << '\n';

	return 0;
}