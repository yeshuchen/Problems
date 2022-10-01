#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, k;
int tot, ver[N], val[N], nxt[N], head[N];
inline void add(int x, int y, int z)
{
    ver[++tot] = y;
    val[tot] = z;  
    nxt[tot] = head[x];
    head[x] = tot;
}
int d[N], vis[N];
inline bool check(int w)
{
    deque<int> q;
    q.push_back(1);
    memset(vis, 0, sizeof(vis));
    for(int i = 2; i <= n; i++) d[i] = INT_MAX;
    while(!q.empty())
    {
        int x = q.front(); q.pop_front();
        if(vis[x]) continue;
        vis[x] = 1;
        for(int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i], z = val[i];
            if(z > w) z = 1;
            else z = 0;
            if(d[x] + z < d[y])
            {
                d[y] = d[x] + z;
                if(z) q.push_back(y);
                else q.push_front(y);
            }
        }
    }
    if(d[n] <= k) return true;
    return false;
}
int l, r;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
        r = max(r, z);
    }
    check(INT_MAX);
    if(d[n] == INT_MAX)
    {
        cout << -1;
        return 0;
    }
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;
    return 0;
}