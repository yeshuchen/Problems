#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5, mod = 998244353;
int T, n;
int a[N], b[N], fac[N], inv[N];
int ksm(int a, int b)
{
    int base = 1;
    while(b)
    {
        if(b & 1) base = base * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return base;
}
int C(int a, int b) {return fac[a] * inv[b] % mod * inv[a - b] % mod;}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n; int ans = 1;
        fac[0] = inv[0] = 1;
        for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
        inv[n] = ksm(fac[n], mod - 2);
        for(int i = n - 1; i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
        for(int i = 1; i <= n; i++)
            cin >> a[i], b[i] = a[i];
        reverse(b + 1, b + n + 1);
        for(int i = 1; i <= n; i++) a[i] += a[i - 1], b[i] += b[i - 1];
        if(!a[n]) {cout << ksm(2, n - 1) << '\n'; continue;}
        for(int l = 1, r; l <= n; l = r + 1)
        {
            int res = 0;
            r = upper_bound(a + 1, a + n + 1, a[l]) - a - 1;
            int L = lower_bound(b + 1, b + n + 1, a[l]) - b;
            int R = upper_bound(b + 1, b + n + 1, a[l]) - b - 1;
            if((b[L] ^ a[l])) continue;
            if(n - R + 1 <= r)
            {
                if(n - R == l && n - L == r) ans = ans * ksm(2, r - l + 1) % mod;
                continue;
            }
            for(int i = 0; i <= min(r - l + 1, R - L + 1); i++) res = (res + C(r - l + 1, i) * C(R - L + 1, i)) % mod;
            ans = ans * res % mod;
        }
        cout << ans << '\n';
    }
    return 0;
}