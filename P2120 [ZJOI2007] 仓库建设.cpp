#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
int n, top, P[N];
ll f[N], sd[N], sp[N];
ll x[N], p[N], c[N];
struct node {
	ll x, y;
} stk[N];
inline double getk(node a, node b) {return 1.0 * (b.y - a.y) / (b.x - a.x);}
inline void update(int x)
{
	node t = (node) {sp[x], f[x]};
	while(top >= 2 && getk(stk[top - 1], stk[top]) >= getk(stk[top], t)) top--;
	stk[++top] = t;
	P[top] = x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i] >> p[i] >> c[i];
		sp[i] = sp[i - 1] + p[i];
	}
	for(int i = 1; i <= n; i++) f[0] += (x[n] - x[i]) * p[i];
	update(0);
	for(int i = 1; i <= n; i++)
	{
		int l = 2, r = top, ans = 1;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(getk(stk[mid - 1], stk[mid]) <= x[i] - x[n]) l = (ans = mid) + 1;
			else r = mid - 1;
		}
		f[i] = f[P[ans]] + c[i] - (x[n] - x[i]) * (sp[i] - sp[P[ans]]);
		update(i);
	}
	ll ans = f[n];
	while(!p[n] && n) ans = min(ans, f[--n]);
	cout << ans;
	return 0;
}