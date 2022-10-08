#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n;
int f[200005];
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
inline int C(int n, int m)
{
    return f[n] * power(f[m], mod - 2) % mod * power(f[n - m], mod - 2) % mod;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    f[1] = 1;
    for(int i = 2; i <= 2 * n; i++)
        f[i] = f[i - 1] * i % mod;
    cout << C(2 * n, n) * power(n + 1, mod - 2) % mod;
    return 0;
}