#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9;
int T;
map<int, int> phi;
inline int p(int x)
{
    int res = x;
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i != 0) continue;
        while(x % i == 0) x /= i;
        res = res / i * (i - 1);
    }
    return res / x * max(1ll, x - 1);
}
inline int power(int a, int b, int mod)
{
    int base = 1;
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
inline int solve(int a, int b, int mod)
{
    if(mod == 1 || b == 0) return 1;
    return power(a, solve(a, b - 1, phi[mod]), mod);
}
inline int c(int x)
{
    int cnt = 0;
    if(x == 0) return 1;
    while(x)
    {
        x /= 10;
        cnt++;
    }
    return cnt;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    int now = mod;
    while(now != 1)
        phi[now] = p(now), now = phi[now];
    phi[now] = 1;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        if(a == 0)
        {
            cout << !(b & 1) << '\n';;
            continue;
        }
        int ans = solve(a, b, mod);
        if(ans >= mod)
        {   
            cout << "...";
            int length = c(ans % mod);
            for(int i = 1; i <= 9 - length; i++) cout << 0;
        }
        cout << ans % mod << '\n';
    }
    return 0;
}