#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, l, r;
bool vis[500005];
int a[12], f[500005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> l >> r;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    f[0] = 0;
    for(int i = 1; i < a[1]; i++)
        f[i] = INT_MAX;
    queue<int> q;
    q.push(0); vis[0] = 1;
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        vis[x] = 0;
        for(int i = 2; i <= n; i++)
        {
            int y = (x + a[i]) % a[1];
            if(f[x] + a[i] < f[y])
            {
                f[y] = f[x] + a[i];
                if(!vis[y]) vis[y] = 1, q.push(y);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < a[1]; i++)
    {
        if(r >= f[i]) ans += ((r - f[i]) / a[1] + 1);
        if(l > f[i]) ans -= ((l - f[i]) / a[1] + 1);
    }
    cout << ans;
    return 0;
}