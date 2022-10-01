#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9;
int n, cnt;
long long ans;
vector<int> g[1005];
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
    int ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if(__gcd(i, j) == 1)
            {
                cnt++;
                if(i == 1) g[1].push_back(j);
                if(j == n) g[n].push_back(i);
            }
    ans = (((g[1].size() - 1) * (g[n].size() - 1) * power(2, cnt - 3)) / ( (g[1].size() - 1) * (g[n].size() - 1) )  + power(2, cnt - 1));
    ans %= mod;
    cout << cnt << '\n';
    cout << ans + 1;
    return 0;
}
/*
性质一，你所选的组里必须包含1和n

首先预处理出所有的组合数对
*/