#include<bits/stdc++.h>
#define int long long
using namespace std;
int h, x, y, z;
int f[500005];
int vis[500005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> h;
    cin >> x >> y >> z;
    if(x == 1 || y == 1 || z == 1)
    {
        cout << h;
        return 0;
    }
    queue<int> q;
    q.push(1);
    for(int i = 0; i < x; i++) f[i] = LONG_LONG_MAX;
    f[1] = 1;
    while(!q.empty())
    {
        int X = q.front(); q.pop();
        vis[X] = 0;
        int nxt = (X + y) % x;
        if(f[X] + y < f[nxt])
        {
            f[nxt] = f[X] + y;
            if(!vis[nxt]) vis[nxt] = 1, q.push(nxt);
        }
        nxt = (X + z) % x;
        if(f[X] + z < f[nxt])
        {
            f[nxt] = f[X] + z;
            if(!vis[nxt]) vis[nxt] = 1, q.push(nxt);
        }
    }
    int ans = 0;
    for(int i = 0; i < x; i++)
        if(h >= f[i])
            ans += (h - f[i]) / x + 1;
    cout << ans;
    return 0;
}