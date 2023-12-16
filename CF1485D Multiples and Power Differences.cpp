#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[505][505];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++, cout << '\n')
		for(int j = 1; j <= m; j++)
		{
			if(i + j & 1) cout << 720720 << ' ';
			else cout << 720720 + pow(a[i][j], 4) << ' ';
		}
	return 0;
}