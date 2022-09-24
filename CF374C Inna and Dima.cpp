#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5;
int n, m, tot;
char c[1005][1005];
int x[5] = {0, 1, -1, 0, 0};
int y[5] = {0, 0, 0, 1, -1};
int d[N], f[N], dep[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> c[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int k = 1; k <= 4; k++)
            {
                int nx = i + x[k], ny = j + y[k];
                if(c[i][j] == 'D' && c[nx][ny] == 'I' || c[i][j] == 'I' && c[nx][ny] == 'M' || c[i][j] == 'M' && c[nx][ny] == 'A' || c[i][j] == 'A' && c[nx][ny] == 'D')
                    add((i - 1) * m + j, (nx - 1) * m + ny), d[(nx - 1) * m + ny]++;
            }
    queue<int> q;
    int cnt = 0;
    for(int i = 1; i <= n * m; i++)
        if(!d[i])
        {
            q.push(i);
            dep[i] = 1;
            cnt++;
        }
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        for(int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            d[y]--; f[y] = f[x]; dep[y] = dep[x] + 1;
            if(dep[y] % 4 == 0) f[y]++;
            if(!d[y]) q.push(y), cnt++;
        }
    }
    if(cnt < n * m)
    {
        cout << "Poor Inna!";
        return 0;
    }
    int ans = 0; 
    for(int i = 1; i <= n * m; i++)
        if(c[(i - 1) / m + 1][(i - 1) % m + 1] == 'A')
            ans = max(ans, f[i]);
    if(!ans) cout << "Poor Dima!";
    else cout << ans;
    return 0;
}