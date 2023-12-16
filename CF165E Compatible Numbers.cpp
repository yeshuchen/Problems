#include<bits/stdc++.h>
using namespace std;
int n, a[1 << 22], f[1 << 22];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], f[a[i]] = a[i];
	for(int i = 0; i < (1 << 22); i++)
	{
		for(int j = 0; j <= 21; j++)
			if((i & (1 << j)) && f[i ^ (1 << j)])
				f[i] = f[i ^ (1 << j)];
	}
	for(int i = 1; i <= n; i++)
	{
		int x = ((1 << 22) - 1) ^ a[i];
		cout << (f[x] ? f[x] : -1) << ' ';
	}
	return 0;
}