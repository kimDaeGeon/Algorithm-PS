#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


enum color { R, G, B };
static int cost[1001][3] = { 0 };
static int dp[1001][3] = { 0 };

int min(int x, int y) {
	return x > y ? y : x;
}
int min(int x, int y, int z) {
	vector<int> v = { x,y,z };
	std::sort(v.begin(), v.end());
	return v[0];
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> cost[i][R] >> cost[i][G] >> cost[i][B];
	}

	//dp[i][0] = i-1번째 R, 이전까지 합의 최소
	//dp[i][1] = i-1번째 G, 이전까지 합의 최소
	//dp[i][2] = i-1번째 B, 이전까지 합의 최소

	for (int i = 1; i <= n; i++) {
		dp[i][R] += min(dp[i - 1][G], dp[i - 1][B]) + cost[i][R];
		dp[i][G] += min(dp[i - 1][R], dp[i - 1][B]) + cost[i][G];
		dp[i][B] += min(dp[i - 1][R], dp[i - 1][G]) + cost[i][B];
	}


	cout << min(dp[n][R], dp[n][G], dp[n][B]) << '\n';


	return 0;
}