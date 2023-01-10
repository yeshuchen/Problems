#include<bits/stdc++.h>
using namespace std;
int T;
int a[100005];
long long xr[100005], sum[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int n, q, l, r;
		cin >> n >> q;
		for(int i = 1; i <= n; i++)
		{ 
			cin >> a[i];
			sum[i] = sum[i - 1]; sum[i] += a[i];
			xr[i] = xr[i - 1]; xr[i] ^= a[i];
		}
		cin >> l >> r;
		long long ans = sum[n] - xr[n];
		for(int i = 1; i <= n; i++)
		{
			int L = i, R = n;
			while(L < R)
			{
				int mid = L + R >> 1;
				if((sum[mid] - sum[i - 1]) - (xr[mid] ^ xr[i - 1]) != ans) L = mid + 1;
				else R = mid;
			}
			if(L - i < r - l && sum[L] - sum[i - 1] - (xr[L] ^ xr[i - 1]) == ans)
				l = i, r = L;
		}
		cout << l << ' ' << r << '\n';
	}
	return 0;
}