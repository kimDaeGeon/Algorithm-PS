#include <iostream>
using namespace std;
void func(int n, int x, int y) {
    if ((x/n % 3 == 1) && (y/n % 3 == 1))
        cout << " ";
    else
    {
        if (n / 3 == 0)
            cout << "*";
        else
            func(n / 3, x, y);
    }

}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            func(n, i, j);
        }
        cout << '\n';
    }
}