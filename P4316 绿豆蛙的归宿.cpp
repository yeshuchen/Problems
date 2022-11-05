#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
double f[N];
int n, m, tot;
long long d[N], du[N];
int ver[N], val[N], nxt[N], head[N];
inline void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
inline void topo()
{
	memcpy(du, d, sizeof(du));
	queue<int> q;
	q.push(n);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i];
			d[y]--; f[y] += (f[x] + val[i]) / du[y];
			if(!d[y]) q.push(y);
		}
	}
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(y, x, z);
		d[x]++;
	}
	topo();
	printf("%.2lf", f[1]);
	return 0;
}