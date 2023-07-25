#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
int n, a, b, c, top;
int p[N];
ll f[N], s[N];
struct node {
	ll x, y;
} stk[N];
inline double getk(node a, node b) {return 1.0 * (b.y - a.y) / (b.x - a.x);}
inline void update(int x)
{
	node t = (node) {s[x], f[x] + a * s[x] * s[x] - b * s[x]};
	while(top >= 2 && getk(stk[top - 1], stk[top]) < getk(stk[top], t)) top--;
	stk[++top] = t;
	p[top] = x;
}
int main()
{
	cin >> n >> a >> b >> c;
	for(int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];
	update(0);
	for(int i = 1; i <= n; i++)
	{
		int l = 2, r = top, ans = 1;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(getk(stk[mid - 1], stk[mid]) > 2 * a * s[i]) l = (ans = mid) + 1;
			else r = mid - 1;
		}
		f[i] = f[p[ans]] + a * (s[i] - s[p[ans]]) * (s[i] - s[p[ans]]) + b * (s[i] - s[p[ans]]) + c;
		update(i);
	}
	cout << f[n];
	return 0;
}