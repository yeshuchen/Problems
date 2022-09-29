#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int cnt;
signed main()
{
    int n, m, c, k;
    cin >> n >> m >> c >> k;
    for(int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        cnt |= v;
    }
    int lim = 0;
    for(int i = 1; i <= m; i++)
    {
        int p, q;
        cin >> p >> q;
        lim |= 1ull << p;
    }
    int ans = 0;
    for(int i = 0; i < k; i++) ans += !((lim >> i) & 1) || ((cnt >> i) & 1);
    if(ans == 64 && !n) cout << "18446744073709551616";
    else cout << (ans == 64 ? -n : (1ull << ans) - n);
    return 0;
}