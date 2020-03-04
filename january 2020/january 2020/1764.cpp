#include<iostream>
#include<string>
using namespace std;

int main() {
	string* s1, * s2, *result;
	int s1_size, s2_size;
	cin >> s1_size >> s2_size;

	s1 = new string[s1_size];
	s2 = new string[s2_size];
	result = new string[s1_size > s2_size ? s2_size : s1_size];
	for (int i = 0; i < s1_size; i++)
		cin >> s1[i];
	for (int i = 0; i < s2_size; i++)
		cin >> s2[i];

	int count = 0;
	for (int i = 0; i < s1_size; i++) {
		for (int j = 0; j < s2_size; j++) {
			if (s1[i] == s2[j]) result[count++] = s1[i];
		}
	}

	cout << count << endl;
	for (int i = 0; i < count; i++)
		cout << result[i] << endl;


	return 0;
}