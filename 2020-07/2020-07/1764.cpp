#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<string> str1, str2, intersection;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		str1.push_back(str);
	}
	sort(str1.begin(), str1.end());

	for (int i = 0; i < m; i++) {
		string str; cin >> str;
		str2.push_back(str);
	}
	sort(str2.begin(), str2.end());

	set_intersection(str1.begin(), str1.end(), str2.begin(), str2.end(),back_inserter(intersection));

	cout << intersection.size() << '\n';
	for (string str : intersection) {
		cout << str << '\n';
	}

	return 0;
}