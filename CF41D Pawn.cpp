#include<bits/stdc++.h>
using namespace std;
int n, m, K;
int a[105][105];
int f[105][105][905];
int pos[105][105][905];
int main()
{
    cin >> n >> m >> K;
    K++;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            a[i][j] = ch - '0';
        }
    memset(pos, -1, sizeof(pos));
    for(int i = 1; i <= m; i++)
        f[n][i][a[n][i]] = 1, pos[n][i][a[n][i]] = i;
    for(int i = n - 1; i >= 1; i--)
        for(int j = 1; j <= m; j++)
        {
            for(int k = a[i][j]; k <= 900; k++)
            {
                if(f[i + 1][j - 1][k - a[i][j]]) f[i][j][k] = 1, pos[i][j][k] = j - 1;
                if(f[i + 1][j + 1][k - a[i][j]]) f[i][j][k] = 1, pos[i][j][k] = j + 1;
            }
        }
    stack<char> s;
    for(int k = 900 / K * K; k >= 0; k -= K)
        for(int i = 1; i <= m; i++)
            if(f[1][i][k])
            {
                cout << k << '\n';
                int x = 1, y = i, t;
                int temp = k;
                while(pos[x][y][temp] != -1)
                {
                    if(pos[x][y][temp] - y == 1) s.push('L');
                    else if(pos[x][y][temp] - y == -1) s.push('R');
                    t = y;
                    y = pos[x][y][temp];
                    temp -= a[x][t];
                    x++;
                }
                cout << y << '\n';
                while(!s.empty()) cout << s.top(), s.pop();
                return 0;
            }
    cout << -1;
    return 0;
}
/*
f[i][j][k]表示在位置(i,j)能否将k凑出来
pos[i][j][k]表示如果能凑出来，是由谁凑出来的
*/