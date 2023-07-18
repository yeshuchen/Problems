#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, sz;
int a[300005], p[1000005], mx[300005], bl[300005], lp[300005], rp[300005], sum[300005];
inline int solve(int x)
{
	int cnt = 0;
	for(int i = 1; i * i <= x; i++)
	{
		if(x % i == 0) cnt += 2;
		if(x % i == 0 && x / i == i) cnt--;
	}
	return cnt;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; sz = sqrt(n);
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		bl[i] = (i - 1) / sz + 1;
		if(!lp[bl[i]]) lp[bl[i]] = i;
		rp[bl[i]] = i;
	}
	// for(int i = 1; i<= bl[n]; i++)
	// 	cout <<lp[i] << ' ' << rp[i] <<'\n';
	for(int i = 1; i <= n; i++) mx[bl[i]] = max(mx[bl[i]], a[i]), sum[bl[i]] += a[i];
	while(m--)
	{
		int op, l, r;
		cin >> op >> l >> r;
		if(op == 1)
		{
			for(int i = bl[l] + 1; i < bl[r]; i++)
			{
				if(mx[i] <= 2) continue;
				for(int j = lp[i]; j <= rp[i]; j++)
				{
					if(p[a[j]]) a[j] = p[a[j]];
					else a[j] = p[a[j]] = solve(a[j]);
				}
				mx[i] = sum[i] = 0;
				for(int j = lp[i]; j <= rp[i]; j++)
					mx[i] = max(mx[i], a[j]), sum[i] += a[j];
			}
			if(bl[l] == bl[r])
			{
				for(int i = l; i <= r; i++)
				{
					if(p[a[i]]) a[i] = p[a[i]];
					else a[i] = p[a[i]] = solve(a[i]);
				}
				mx[bl[l]] = sum[bl[l]] = 0;
				for(int i = lp[bl[l]]; i <= rp[bl[l]]; i++)
					mx[bl[i]] = max(mx[bl[i]], a[i]), sum[bl[i]] += a[i];
			}
			else
			{
				for(int i = l; i <= rp[bl[l]]; i++)
				{
					if(p[a[i]]) a[i] = p[a[i]];
					else a[i] = p[a[i]] = solve(a[i]);
				}
				for(int i = lp[bl[r]]; i <= r; i++)
				{
					if(p[a[i]]) a[i] = p[a[i]];
					else a[i] = p[a[i]] = solve(a[i]);
				}
				mx[bl[l]] = mx[bl[r]] = sum[bl[l]] = sum[bl[r]] = 0;
				for(int i = lp[bl[l]]; i <= rp[bl[l]]; i++)
						mx[bl[i]] = max(mx[bl[i]], a[i]), sum[bl[i]] += a[i];
				for(int i = lp[bl[r]]; i <= rp[bl[r]]; i++)
					mx[bl[i]] = max(mx[bl[i]], a[i]), sum[bl[i]] += a[i];
			}
		}
		else
		{
			int res = 0;
			for(int i = bl[l] + 1; i < bl[r]; i++)
				res += sum[i];
			if(bl[l] == bl[r])
			{
				for(int i = l; i <= r; i++)
					res += a[i];
			}
			else
			{
				for(int i = l; i <= rp[bl[l]]; i++) res += a[i];
				for(int i = lp[bl[r]]; i <= r; i++) res += a[i];
			}
			cout << res << '\n';
		}
	}
	return 0;
}