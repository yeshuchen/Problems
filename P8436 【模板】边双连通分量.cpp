#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,M=5e6+5;
int n, m, q, tot, top, res, cnt;
int ver[M], nxt[M], head[M];
int dfn[N], stk[N], low[N];
int vis[N];
vector<int> g[N];
inline void add(int x,int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
void tarjan(int x,int fa)
{
	bool f = 0;
    stk[++top] = x;
    dfn[x] = low[x] = ++res;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(!dfn[y])
        {
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
            if(dfn[x] < low[y])
            {
                cnt++;
                while(stk[top+1] != y)
                	g[cnt].push_back(stk[top--]);
            }
        }
        else if(y != fa || f) low[x] = min(low[x], dfn[y]);
        if(y == fa) f = 1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
 	for(int i = 1; i <= n; i++)
        if(!dfn[i])
        {
            tarjan(i, 0);
            cnt++;
            while(top)
                g[cnt].push_back(stk[top--]);
        }
    cout << cnt << '\n';
    for(int i = 1;i <= cnt; i++)
    {
    	cout << g[i].size() << ' ';
    	for(int j = 0; j < g[i].size(); j++)
    		cout << g[i][j] << ' ';
    	cout << '\n';
	}
    return 0;
}