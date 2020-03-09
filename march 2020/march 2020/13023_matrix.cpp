#include<iostream>
using namespace std;

static bool relative[2001][2001] = { false };

int main() {
	bool isRelative = false;

	int n, m;
	cin >> n >> m;
	

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;

		relative[from][to] = true;
		relative[to][from] = true;
	}
	
	m *= 2;

	//find A->B
	for (int a = 1; a <= n; a++) {
		//if A->B
		if (relative[a][a + 1] && relative[a + 1][a]) {
			//find B->C
			for (int b = a; b <= n; b++) {
				//if B->C
				if (relative[b][b + 1] && relative[b + 1][b]) {
					//find C->D
					for (int c = b; c <= n; c++) {
						//if C->D
						if (relative[c][c + 1] && relative[c + 1][c]) {
							//find D->E
							for (int d = c; d <= n; d++) {
								if (relative[d][d + 1] && relative[d + 1][d]) {
									isRelative = true;
									break;
								}
							}
							if (isRelative) break;
						}
						if (isRelative) break;
					}
					if (isRelative) break;
				}
				if (isRelative) break;
			}
			if (isRelative) break;
		}
		if (isRelative) break;
	}

	cout << isRelative << '\n';

}