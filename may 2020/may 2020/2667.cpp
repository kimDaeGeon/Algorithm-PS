#include <iostream>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)

using namespace std;
int arr[25][25];
bool visit[25][25] = { false };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n;
int cnt = 0;
vector <int>ans;
void dfs(int x, int y)
{
    visit[x][y] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < n)
        {
            if (arr[nx][ny] == 1 && visit[nx][ny] == false)
                dfs(nx, ny);
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '1' && !visit[i][j])
            {
                cnt = 0;
                dfs(i, j);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}