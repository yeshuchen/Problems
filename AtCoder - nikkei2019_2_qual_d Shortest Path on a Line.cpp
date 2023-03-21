#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100010, M = 200010;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];
int n, m;
void add(int x, int y, int z)
{
    e[idx] = y;
	w[idx] = z;
	ne[idx] = h[x];
	h[x] = idx++;
}
void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; dist[n] = LLONG_MAX;
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
	q.push(make_pair(0, 1));
    while(q.size())
    {
        auto t = q.top(); q.pop();
        int ver = t.second, distance = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                q.push({dist[j], j});
            }
        }
    }
}
signed main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    for(int i = 2; i <= n; i++)
		add(i, i - 1, 0);
    dijkstra();
	if(dist[n] == LLONG_MAX) dist[n] = -1;
	cout << dist[n];
    return 0;
}