#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5, size = 700;
int n, m, d, q, res, cnt;
int a[N], b[N], c[N], r[N], p[N], ans[N], temp[N];
bool vis[N];
map<int, int> zyb;
struct node{
    int pos, l, r;
}s[N];
inline bool cmp(node x, node y) {return x.r < y.r;}
inline void add(int x, int k)
{
    while(x <= n)
	{
		r[x] += k;
		x += (x & -x);
	}
}
inline int ask(int x)
{
	int res = 0;
	while(x)
	{
		res += r[x];
		x -= (x & -x);
	}
	return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> d >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    sort(b + 1, b + m + 1);
    for(int i = 1; i <= m; i++)
    {
        int x = b[i];
        while(x)
        {
            if(p[x]) {vis[i] = 1; break;}
            x /= d;
        }
        if(!vis[i]) zyb[b[i]] = ++res;
    }
    res = 0;
    for(int i = 1; i <= m; i++)
        if(!vis[i])
            temp[++res] = b[i];
    for(int i = 1; i <= res; i++)
        b[i] = temp[i];
    m = res;
    for(int i = 1; i <= n; i++)
    {
        int x = a[i];
        while(x)
        {
            if(zyb[x]) {c[i] = zyb[x]; break;}
            x /= d;
        }
    }
    for(int i = 1; i <= q; i++)
    {
        cin >> s[i].l >> s[i].r;
        s[i].pos = i;
    }
    sort(s + 1, s + q + 1, cmp);
	int r = 0; 
    for(int i = 1; i <= q; i++)
	{
		while(r < s[i].r)
		{
			if(c[++r])
			{
				if(p[c[r]]) add(p[c[r]], -1);
				p[c[r]] = r;
				add(p[c[r]], 1);
			}
		}
		ans[s[i].pos] = ask(s[i].r) - ask(s[i].l - 1);
	}
    for(int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
    return 0;
}
/*
按照左端点从左往右排序
*/