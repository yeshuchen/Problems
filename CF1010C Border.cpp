#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, k;
int a[N], vis[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int gcd = a[1];
	for(int i = 2; i <= n; i++)
		gcd = __gcd(gcd, a[i]);
	gcd %= k; vis[0] = 1;
	int p = gcd;
	while(!vis[p])
	{
		vis[p] = 1;
		p += gcd;
		p %= k;
	}
	int res = 0;
	for(int i = 0; i < k; i++)
		if(vis[i])	
			res++;
	cout << res << '\n';
	for(int i = 0; i < k; i++)
		if(vis[i])
			cout << i << ' ';
	return 0;
}