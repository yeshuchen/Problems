#include<bits/stdc++.h>
using namespace std;
int n, m;
int f[15];
int ans1, ans2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 9; j++)
		{
			f[j] = (1ll * f[j] * 10 % m + j) % m;
			if(!f[j]) ans1 = j, ans2 = i;
		}
	if(!ans1) {cout << -1; return 0;}
	for(int i = 1; i <= ans2; i++) cout << ans1;
	return 0;
}