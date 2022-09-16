#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int T, k;
int f[100005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> T >> k;
    f[0] = 1;
    for(int i = 1; i <= 100000; i++)
    {
        if(i < k) f[i] = 1;
        else f[i] = f[i - 1] + f[i - k];
        f[i] %= mod;
    }
    for(int i = 1; i <= 100000; i++)
        f[i] = (f[i] + f[i - 1]) % mod;
    while (T--)
    {
        int l, r;
        cin >> l >> r;
        cout << (f[r] + mod - f[l - 1]) % mod << '\n';
    }
    return 0;
}