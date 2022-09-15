#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[1006], d[1005];
int f[1005][1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> d[i];
    for(int i = 1; i <= n; i++)
    {
        int minn = f[i - 1][i - 1];
        for(int j = i; j <= m - n + i; j++)
        {
            f[i][j] = INT_MAX;
            f[i][j] = min(f[i][j], minn + d[j] *a[i]);
            minn = min(minn, f[i - 1][j]);
        }
    }
    int ans = INT_MAX;
    for(int i = n; i <= m; i++)
        ans = min(ans, f[n][i]);
    cout << ans;
    return 0;
}
//设f[i][j]表示第j天到达第i个城市的最小疲劳值