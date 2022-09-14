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
    f[1][0] = 1;
    for(int i = 1; i <= p; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k * k <= j; k++)
                if(j % k == 0)
                {
                    f[j][i] += f[k][i - 1];
                    if(k != j / k) f[j][i] += f[j / k][i - 1];
                    f[j][i] %= mod;
                }
    for(int i = 1; i <= n; i++)
        ans = (ans + f[i][p]) % mod;
    cout << ans;
    return 0;
}
// 设f[i][j]表示第j位置填i的方案