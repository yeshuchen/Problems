#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, m;
int s[N], q[N];
int f[N], g[N];
int pos[N][200];
struct node {
	int x, y;
} p[N];
inline double cal(int x, int y)
{
	if(s[x] == s[y]) return -1e18;
	return 1.0 * (p[x].y - p[y].y) / (p[x].x - p[y].x);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> s[i], s[i] += s[i - 1];
	for(int k = 1; k <= m; k++)
	{
		int hd = 1, tl = 0;
		for(int i = 1; i <= n; i++)
		{
			while(hd < tl && cal(q[hd], q[hd + 1]) <= s[i]) hd++;
			int j = q[hd]; pos[i][k] = j;
			f[i] = g[j] + (s[i] - s[j]) * s[j];
			p[i] = {-s[i], g[i] - s[i] * s[i]};
			while(hd < tl && cal(q[tl - 1], q[tl]) >= cal(q[tl], i)) tl--;
			q[++tl] = i;
		}
		memcpy(g, f, sizeof(f));
	}
	cout << f[n] << '\n';
	int p = n; stack<int> stk;
	for(int i = m; i; i--)
	{
		p = pos[p][i];
		stk.push(p);
	}
	while(!stk.empty()) cout << stk.top() << ' ', stk.pop();
	return 0;
}