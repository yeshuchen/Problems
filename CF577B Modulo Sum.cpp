#include<bits/stdc++.h>
using namespace std;
int n, m;
int f[1005][1005];
int a[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i], a[i] %= m;
	if(n > m) {cout << "YES"; return 0;}
	for(int i = 1; i <= n; i++)
	{
		f[i][a[i]] = 1;
		for(int j = 0; j < m; j++)
			if(f[i - 1][j])
				f[i][j] = f[i][(j + a[i]) % m] = 1;
	}
	if(f[n][0]) cout << "YES";
	else cout << "NO";
	return 0;
}