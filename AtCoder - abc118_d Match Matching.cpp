#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[15], f[5001][10001];
int spt[15] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) cin >> a[i];
	sort(a + 1, a + m + 1);
	f[0][0] = 1;
	for(int i = 1; i <= 5000; i++)
		for(int j = 1; j <= m; j++)
			for(int k = n; k >= spt[a[j]]; k--)
				f[i][k] |= f[i - 1][k - spt[a[j]]];
	for(int i = 5000; i >= 1; i--)
		if(f[i][n])
		{
			int tmp = n;
			for(int pos = i; pos; pos--)
				for(int j = m; j; j--)
				{
					if(tmp < spt[a[j]]) continue;
					if(f[pos - 1][tmp - spt[a[j]]])
					{
						tmp -= spt[a[j]];
						cout << a[j];
						break;
					}
				}
			break;
		}
	return 0;
}