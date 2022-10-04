#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 5;
int n, m, tot;
int w[N], temp[N];
inline int phi(int x)
{
    int p = x;
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i != 0) continue;
        p = p / i * (i - 1);
        while(x % i == 0)
            x /= i;
    }
    if(x > 1) p = p / x * (x - 1);
    return p;
}
inline void s(int x)
{
    while(x > 1)
        temp[++tot] = x = phi(x);
}
inline int power(int a, int b, int mod)
{
    int base = 1, flag = 0;
    while(b)
    {
        if(b & 1)
        {
            base = base * a;
            if(base > mod) base = base % mod + mod;
        }
        b >>= 1;
        a = a * a;
        if(a > mod) a = a % mod + mod;
    }
    return base;
}
inline int solve(int l, int r, int mod, int step)
{
    if(l == r + 1 || mod == 1) return 1;
    int t = solve(l + 1, r, temp[step], step + 1);
    return power(w[l], t, mod);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    s(m);
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cout << solve(l, r, m, 1) % m << '\n';
    }
    return 0;
}