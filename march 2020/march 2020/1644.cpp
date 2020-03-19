#include<iostream>
#define MAX 4000000
using namespace std;

bool isNotPrime[MAX] = { false };

int main() {
	for (int i = 2; i <= MAX; i++) {
		if (!isNotPrime[i]) {
			for (int j = 2; i * j <= MAX; j++) {
				isNotPrime[i * j] = true;
			}
		}
	}

	for (int i = 2; i <= MAX; i++) {
		if (!isNotPrime[i]) cout << i << ' ';
	}

	return 0;
}