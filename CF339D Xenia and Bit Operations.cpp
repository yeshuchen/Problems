#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
int n, m;
int a[1000005];
inline void build(int p, int l, int r, int dep)
{
	if(l == r)
	{
		cin >> a[p];
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid, dep + 1);
	build(rs, mid + 1, r, dep + 1);
	if(dep % 2 == n % 2) a[p] = (a[ls] | a[rs]);
	else a[p] = (a[ls] ^ a[rs]);
}
inline void change(int p, int l, int r, int pos, int x, int dep)
{
	if(l == r) {a[p] = x; return;}
	int mid = l + r >> 1;
	if(pos <= mid) change(ls, l, mid, pos, x, dep + 1);
	else change(rs, mid + 1, r, pos, x, dep + 1);
	if(dep % 2 == n % 2) a[p] = (a[ls] | a[rs]);
	else a[p] = (a[ls] ^ a[rs]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	build(1, 1, (1 << n), 1);
	for(int i = 1; i <= m; i++)
	{
		int p, x;
		cin >> p >> x;
		change(1, 1, (1 << n), p, x, 1);
		cout << a[1] << '\n';
	}
	return 0;
}
