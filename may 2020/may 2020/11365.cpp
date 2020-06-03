#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char str[1000];

	while (true) {
		cin.getline(str, 1000, '\n');

		if (!strcmp(str,"END")) {
			break;
		}

		char* ptr = str;
		while (*ptr != NULL) {
			ptr++;
		}
		while (ptr != str) {
			ptr--;
			cout << *(ptr);
		}
		cout << '\n';
	}

	return 0;
}