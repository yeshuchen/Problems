#include<bits/stdc++.h>
using namespace std;
int n, m, ans = INT_MAX;
int a[1005][1005], f[1005][1005], maxn[1005][1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            maxn[i][j] = min(maxn[i][j - 1], 0) + a[i][j];
    for(int i = 1; i <= m; i++)
        f[n][i] = maxn[n][i];
    for(int i = n - 1; i; i--)
        for(int j =d)
    for(int i = 1; i <= m; i++)
        ans = min(ans, f[1][i]);
    cout << ans;
    return 0;
}