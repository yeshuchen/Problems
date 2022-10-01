#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e8;
int n, m, ans;
int c[15][15];
int f[15][10005];
bool check(int x, int row)
{
    for(int i = 1; i < m; i++)
        if((x & (1 << i)) && (x & (1 << i - 1)))
            return false;
    for(int i = 0; i < m; i++)
        if((x & (1 << i)) && !c[row][i + 1])
            return false;
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> c[i][j];
    for(int i = 0; i < (1 << m); i++)
        if(check(i, 1))
            f[1][i] = 1;
    for(int i = 2; i <= n; i++)
        for(int j = 0; j < (1 << m); j++)
            for(int k = 0; k < (1 << m); k++)
                if(check(j, i - 1) && check(k, i) && (j & k) == 0)
                    f[i][k] += f[i - 1][j], f[i][k] %= mod;
    for(int i = 0; i < (1 << m); i++)
        ans += f[n][i], ans %= mod;
    cout << ans;
    return 0;
}