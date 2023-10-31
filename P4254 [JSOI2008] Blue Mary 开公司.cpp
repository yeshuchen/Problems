#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
const int N = 2e6 + 5, maxn = 5e4;
int n, cnt;
struct line {
	double k, b;
} t[N];
int s[N];
double calc(int x, int y, int pos)
{
	double n1 = t[x].k * pos + t[x].b, n2 = t[y].k * pos + t[y].b;
	return n1 > n2;
}
void update(int p, int l, int r, int pos)
{
	int &v = s[p], mid = l + r >> 1;
	if(calc(pos, v, mid)) swap(v, pos);
	if(l == r) return;
	if(calc(pos, v, l)) update(ls, l, mid, pos);
	if(calc(pos, v, r)) update(rs, mid + 1, r, pos);
}
double query(int p, int l, int r, int pos)
{
	if(l == r) return t[s[p]].k * pos + t[s[p]].b;
	int mid = l + r >> 1;
	if(pos <= mid) return max(query(ls, l, mid, pos), t[s[p]].k * pos + t[s[p]].b);
	else return max(query(rs, mid + 1, r, pos), t[s[p]].k * pos + t[s[p]].b);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		string opt;
		cin >> opt;
		if(opt[0] == 'P')
		{
			double x, y;
			cin >> x >> y;
			t[++cnt] = {y, x - y};
			update(1, 1, maxn, cnt);
		}
		else
		{
			int x;
			cin >> x;
			cout << floor(query(1, 1, maxn, x) / 100) << '\n';
		}
	}
	return 0;
}