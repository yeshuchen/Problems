#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n, p, ans;
int f[2005][2005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> p;
    for(int i = 1; i <= n; i++)
        f[1][i] = 1;
    for(int i = 2; i <= p; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n / j; k++)
                f[i][j * k] = (f[i][j * k] + f[i - 1][j]) % mod;
    for(int i = 1; i <= n; i++)
        ans = (ans + f[p][i]) % mod;
    cout << ans;
    return 0;
}
// 设f[i][j]表示第i位置填j的方案