#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int test;
	int count, length;
	int i, j;
	char input[101];
	int letter[26]; 

	count = 0;
	cin >> test;
	for (i = 0; i < test; i++) {
		memset(letter, 0, sizeof(letter));
		cin >> input;
		length = strlen(input);

		letter[input[0] - 97] = 1;
		for (j = 1; j < length; j++) {
			if (input[j - 1] != input[j]) {
				if (letter[input[j] - 97] != 0) break;
				else letter[input[j] - 97] = 1;
			}
		}
		if (j == length) count++;
	}
	printf("%d", count);
}