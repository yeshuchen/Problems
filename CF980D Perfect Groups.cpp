#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[5005], f[5005], cnt[5005], Ans[5005];
int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], f[i] = i;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
		{
			if(a[i] * a[j] <= 0) continue;
			int x = sqrt(a[i] * a[j]);
			if(x * x == a[i] * a[j])
			{
				int fi = find(i), fj = find(j);
				if(fi == fj) continue;
				f[fj] = fi;
			}
		}
	for(int i = 1; i <= n; i++) f[i] = find(i);
	for(int i = 1; i <= n; i++)
	{
		int ans = 0;
		for(int j = i; j <= n; j++)
		{
			if(a[j] == 0)
			{
				Ans[max(1ll, ans)]++;
				continue;
			}
			if(!cnt[f[j]]) ans++;
			cnt[f[j]]++;
			Ans[ans]++;
		}
		for(int j = i; j <= n; j++) cnt[f[j]] = 0;
	}
	for(int i = 1; i <= n; i++) cout << Ans[i] << ' ';
	return 0;
}