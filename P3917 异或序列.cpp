#include<bits/stdc++.h>
using namespace std;
int n;
int cnt[3], a[100005], p[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; int f = 0, maxn = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i], maxn = max(maxn, a[i]);	
	long long ans = 0;
	for(int pos = 1; pos <= maxn; pos <<= 1)
	{
	    cnt[0] = cnt[1] = 0;
	    for(int i = 1; i <= n; i++) p[i] = 0;
		for(int i = 1; i <= n; i++)
			if(a[i] & pos)
				p[i] = i;
		for(int i = 1; i <= n; i++)
			if(!p[i])
				p[i] = p[i - 1];
		for(int i = 1; i <= n; i++)
		{
			if(p[i] - p[i - 1]) cnt[f] += p[i] - p[i - 1], f ^= 1; 
			ans += 1ll * cnt[f ^ 1] * pos;
		}
	}
	cout << ans;
	return 0;
}