#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long double eps = 1e-10;
int T;
int n, L, p;
int s[100005];
long double f[100005];
int pos[100005];
char str[100005][35];
struct node {int p, l, r;} t[200005];
inline long double qpow(long double a, int b)
{
	long double base = 1;
	while(b)
	{
		if(b & 1) base = base * a;
		a = a * a;
		b >>= 1;
	}
	return base;
}
inline long double cal(int x, int y) {return qpow(abs(s[y] - s[x] - L), p);}
inline void print(int x)
{
	if(!x) return;
	print(pos[x]);
	for(int i = pos[x] + 1; i <= x; i++)
		cout << (str[i] + 1) << (i == x ? '\n' : ' ');
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> L >> p; L++;
		for(int i = 1; i <= n; i++)
		{
			cin >> (str[i] + 1);
			s[i] = s[i - 1] + strlen(str[i] + 1) + 1;
		}
		int tl, hd;
		t[tl = hd = 1] = (node){0, 1, n};
		for(int i = 1; i <= n; i++)
		{
			while(hd < tl && t[hd].r < i) hd++; t[hd].l = i;
			int p = t[hd].p; f[i] = f[p] + cal(p, i); pos[i] = p;
			while(hd < tl && f[i] + cal(i, t[tl].l) <= f[t[tl].p] + cal(t[tl].p, t[tl].l)) tl--;
			int l = t[tl].l, r = t[tl].r, res = t[tl].l;
			while(l <= r)
			{
				int mid = l + r >> 1;
				if(f[i] + cal(i, mid) <= f[t[tl].p] + cal(t[tl].p, mid)) r = mid - 1;
				else l = (res = mid) + 1;
			}
			l = res;
			if(l < n) t[tl].r = l, t[++tl] = {i, l + 1, n};
		}
		if(f[n] - eps > 1e18) cout << "Too hard to arrange\n";
		else cout << (ll)f[n] << '\n', print(n);
		cout << "--------------------\n";
	}
	return 0;
}