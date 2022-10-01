#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, ans, maxn;
int prime[11] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
inline int power(int a, int b)
{
    int base = 1;
    while(b)
    {
        if(b & 1) base = base * a;
        a *= a;
        b >>= 1;
    }
    return base;
}
void dfs(int step, int val, int mul, int pos)
{
    if(step > 10)
    {
        if(val > maxn) maxn = val, ans = mul;
        else if(val == maxn) ans = min(ans, mul);
        return;
    }
    for(int i = pos; i >= 0; i--)
    {
        int w = power(prime[step], i);
        if(w > n) continue;
        if(mul * w > n) continue;
        dfs(step + 1, val * (i + 1), mul * w, i);
    }
}
signed main()
{
    cin >> n;
    for(int i = 30; i >= 0; i--)
    {
        if(power(2, i) > n) continue;
        dfs(2, i + 1, (int)(pow(2, i)), i);
    }
    cout << ans;
    return 0;
}