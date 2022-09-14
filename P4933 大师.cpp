#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, ans;
int a[10006], f[1005][40005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int p = 20000;
    ans = n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            f[i][a[i] - a[j] + p] += f[j][a[i] - a[j] + p] + 1;
            f[i][a[i] - a[j] + p] %= mod;
            ans += f[j][a[i] - a[j] + p] + 1;
            ans %= mod;
        }
    }
    cout << ans;
    return 0;
}
// 设f[i][j]表示以i结尾公差为j的等差数列的个数