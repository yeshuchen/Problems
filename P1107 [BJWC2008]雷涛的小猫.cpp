#include<bits/stdc++.h>
using namespace std;
int n, h, delta;
int a[2005][2005], maxn[2005], f[2005][2005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> h >> delta;
    for(int i = 1; i <= n; i++)
    {
        int cnt;
        cin >> cnt;
        for(int j = 1; j <= cnt; j++)
        {
            int pos;
            cin >> pos;
            a[pos][i]++;
        }
    }
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j] + a[i][j];
            if(i >= delta) f[i][j] = max(f[i][j], maxn[i - delta] + a[i][j]);
            maxn[i] = max(maxn[i], f[i][j]);
        }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, f[h][i]);
    cout << ans;
    return 0;
}
//f[i][j]表示在第j棵树的高度i处向下最多能吃到多少柿子