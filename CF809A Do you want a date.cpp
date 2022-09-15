#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n, ans;
int a[500006];
inline int power(int a, int b)
{
    int base = 1;
    while(b)
    {
        if(b & 1) base = base * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return base;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        ans += ((a[i] - a[i - 1]) * (power(2, i - 1) - 1)) % mod * (power(2, n - i + 1) - 1);
        ans %= mod;
    }
    cout << ans;
    return 0;
}