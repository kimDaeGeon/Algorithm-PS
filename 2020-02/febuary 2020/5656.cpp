#include<iostream>
#include<string>
using namespace std;

int main() {
	int n, m, count = 1;
	string comp;

	do {
		cin >> n >> comp >> m;


		if (comp == "E") {
			break;
		}

		cout << "Case " << count++ << ": ";
		if (comp == ">") {
			cout << (n > m ? "true" : "false") << endl;
		}
		else if (comp == ">=") {
			cout << (n >= m ? "true" : "false") << endl;
		}
		else if (comp == "<") {
			cout << (n < m ? "true" : "false") << endl;
		}
		else if (comp == "<=") {
			cout << (n <= m ? "true" : "false") << endl;
		}
		else if (comp == "==") {
			cout << (n == m ? "true" : "false") << endl;
		}
		else if (comp == "!=") {
			cout << (n != m ? "true" : "false") << endl;
		}
	} while (true);

	return 0;
}