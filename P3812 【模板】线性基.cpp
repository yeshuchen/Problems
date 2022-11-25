#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, ans;
int p[64];
inline void add(int x)
{
	for(int i = 62; i >= 0; i--)
	{
		if(!(x >> i)) continue;
		if(!p[i]) {p[i] = x; break;}
		x ^= p[i];
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		add(x);
	}
	for(int i = 62; i >= 0; i--)
		if((ans ^ p[i]) > ans)
			ans ^= p[i];
	cout << ans;
	return 0;
}