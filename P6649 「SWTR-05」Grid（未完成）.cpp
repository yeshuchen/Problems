#include<bits/stdc++.h>
using namespace std;
int n, m, ans = INT_MAX;
int a[1005][1005];
int f[1005][1005];
int dp[1005][1005];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = min(dp[i][j - 1], 0) + a[i][j];
    for(int i = n - 1; i; i--)
        f[i][m] = f[i + 1][m] + a[i][m];
    for(int i = 1; i <= m; i++)
        f[n][i] = dp[n][i];
    for(int i = n - 1; i; i--)
    {
        for(int j = m - 1; j; j--)
            f[i][j] = min(f[i][j + 1], f[i + 1][j]);
        for(int j = 1; j < m; j++)
            f[i][j] = f[i][j] + dp[i][j];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cout << f[i][j] << ' ';
        cout << '\n';
    }
    for(int i = 1; i <= m; i++) ans = min(ans, f[1][i]);
    cout << ans;
    return 0;
}