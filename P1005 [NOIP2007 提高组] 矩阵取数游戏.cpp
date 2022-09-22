#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[105][105];
__int128 ans, base[105], f[105][105];
void write(__int128 x)
{
    if(x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
int main()
{
    cin >> n >> m;
    base[0] = 1;
    for(int i = 1; i <= m; i++)
        base[i] = base[i - 1] * 2;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    for(int t = 1; t <= n; t++)
    {
        for(int len = 1; len <= m; len++)
            for(int i = 1; i <= m; i++)
            {
                int j = i + len - 1;
                if(j > m) break;
                f[i][j] = 0;
                f[i][j] = max(f[i][j], f[i][j - 1] + a[t][j] * base[m - len + 1]);
                f[i][j] = max(f[i][j], f[i + 1][j] + a[t][i] * base[m - len + 1]);
            }
        ans += f[1][m];
    }
    write(ans);
}