#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6, maxn = 2e18;
int n, m, k;
int f[N];
struct node{
    int x, b, M, s;
}a[N];
inline bool cmp(node x, node y){return x.b < y.b;}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].b >> a[i].M;
        for(int j = 1; j <= a[i].M; j++)
        {
            int val;
            cin >> val;
            a[i].s ^= (1 << val - 1); 
        }
    }
    sort(a + 1, a + n + 1, cmp);
    for(int j = (1 << m); j; j--)
        f[j] = maxn;
    int ans = maxn;
    for(int i = 1; i <= n; i++)
    {
        for(int j = (1 << m); j >= 0; j--)
        {
            if(f[j] == maxn) continue;
            int spd = f[j] + a[i].x;
            f[j | a[i].s] = min(f[j | a[i].s], spd);
        }
        ans = min(ans, f[(1 << m) - 1] + a[i].b * k);
    }
    if(ans == maxn) cout << -1;
    else cout << ans;
    return 0;
}