#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, L, top;
int f[200005];
int c[200005], p[200005];
struct S {
	int x, y;
} t[100005], stk[100005];
inline double getk(S a, S b) {return 1.0 * (b.y - a.y) / (b.x - a.x);}
inline void update(int x)
{
	while(top >= 2 && getk(stk[top - 1], stk[top]) >= getk(stk[top], t[x]))
		top--;
	stk[++top] = t[x];
	p[top] = x;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> L; L++;
	for(int i = 1; i <= n; i++)
	{
		f[i] = LLONG_MAX;
		cin >> c[i]; c[i]++;
		c[i] += c[i - 1];
	}

	// for(int i = 1; i <= n; i++)
	// 	for(int j = 1; j <= i; j++)
	// 		f[i] = min(f[i], f[j - 1] + (c[i] - c[j - 1] - L) * (c[i] - c[j - 1] - L));
	stk[++top] = (S){c[0], L * L};
	for(int i = 1; i <= n; i++)
	{
		int l = 2, r = top, ans = 1;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(getk(stk[mid - 1], stk[mid]) <= 2 * c[i]) l = (ans = mid) + 1;
			else r = mid - 1;
		}
		f[i] = f[p[ans]] + (c[i] - c[p[ans]] - L) * (c[i] - c[p[ans]] - L);
		t[i].x = c[i]; t[i].y = f[i] + (c[i] + L) * (c[i] + L);
		update(i);
	}
	cout << f[n];
	return 0;
}