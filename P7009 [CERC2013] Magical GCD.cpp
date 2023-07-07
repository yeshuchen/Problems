#include<bits/stdc++.h>
using namespace std;
int n, T;
long long f[100005][20];
inline long long query(int l, int r)
{
	int k = log2(r - l + 1);
	return __gcd(f[l][k], f[r - (1 << k) + 1][k]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		long long ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> f[i][0];
		for(int j = 1; j < 18; j++)
			for(int i = 1; i + (1 << j) - 1 <= n; i++)
				f[i][j] = __gcd(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
		for(int i = 1; i <= n; i++)
		{
			long long gcd = f[i][0], L = i;
			while(L >= 1)
			{
				gcd = __gcd(gcd, f[L][0]);
				int l = 1, r = L;
				while(l <= r) 
				{
					int mid = l + r >> 1;
					if(query(mid, i) == gcd) r = (L = mid) - 1;
					else l = mid + 1;
				}
				ans = max(ans, gcd * (i - L + 1));
				L--;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}