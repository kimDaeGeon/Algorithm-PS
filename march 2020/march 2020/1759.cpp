#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

char ch[15];
int pw_size, ch_size;

void password(int n, vector<int>& picked, int toPick);

int main() {
	cin >> pw_size >> ch_size;

	for (int i = 0; i < ch_size; i++) cin >> ch[i];

	sort(ch, ch + ch_size);
	
	vector<int> picked;
	password(ch_size, picked, pw_size);


	return 0;
}

void password(int n, vector<int>& picked, int toPick) {
	if (toPick == 0) {
		string pw;
		int aeiou = 0, else_ch = 0;
		for (int i : picked) {
			pw += ch[i];
			if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u') aeiou++;
			else else_ch++;
		}
		if (aeiou >= 1 && else_ch >= 2) cout << pw << '\n';
		return;
	}

	int idx = picked.empty() ? 0 : picked.back() + 1;

	for (int next = idx; next < n; next++) {
		picked.push_back(next);
		password(n, picked, toPick - 1);
		picked.pop_back();
	}
}