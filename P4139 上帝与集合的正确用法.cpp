#include<bits/stdc++.h>
#define int long long
using namespace std;
int n = 10000000;
int phi[10000005];
inline int power(int a, int b, int mod)
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
inline int f(int k)
{
    if(k <= 2) return 0;
    int v = phi[k];
    return power(2, f(v) + v, k);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(int i = 1; i <= n; i++) phi[i] = i;
    for(int i = 2; i <= n; i++)
    {
        if(phi[i] != i) continue;
        for(int j = i; j <= n; j += i)
            phi[j] = phi[j] / i * (i - 1);
    }
    while(T--)
    {
        int p;
        cin >> p;
        cout << f(p) << '\n';
    }
}