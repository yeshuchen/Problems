#include<bits/stdc++.h>
using namespace std;
int T;
int temp[100005], pos[100005];
int a[100005];
long long xr[100005], sum[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int n, q, l, r, tot = 0;
		cin >> n >> q;
		for(int i = 1; i <= n; i++)
		{ 
			cin >> a[i];
			if(a[i] > 0)
				temp[++tot] = a[i], pos[tot] = i;
		}
		for(int i = 1; i <= tot; i++)
		{
			sum[i] = sum[i - 1]; sum[i] += temp[i];
			xr[i] = xr[i - 1]; xr[i] ^= temp[i];
		}
		while(q--)
		{
			cin >> l >> r;
			int p = l;
			l = lower_bound(pos + 1, pos + tot + 1, l) - pos;
			r = upper_bound(pos + 1, pos + tot + 1, r) - pos - 1;
			if(l > r) {cout << p << ' ' << p << '\n'; continue;}
			int L = l, R = r;
			long long ans = (sum[r] - sum[l - 1]) - (xr[r] ^ xr[l - 1]);
			for(int i = l; i <= r; i++)
			{
				if((sum[r] - sum[i - 1]) - (xr[r] ^ xr[i - 1]) != ans) break;
				for(int j = r; j >= i; j--)
				{
					if((sum[j] - sum[i - 1]) - (xr[j] ^ xr[i - 1]) != ans) break;
					if(pos[R] - pos[L] > pos[j] - pos[i]) L = i, R = j;
				}
			}
			cout << pos[L] << ' ' << pos[R] << '\n';
		}
	}
	return 0;
}