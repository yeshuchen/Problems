#include<bits/stdc++.h>
using namespace std;
int n, a, b, c;
int f[4005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> a >> b >> c;
	for(int i = 1; i <= n; i++) f[i] = INT_MIN;
	for(int i = min(min(a, b), c); i <= n; i++)
	{
		if(i >= a && f[i - a] != INT_MIN) f[i] = max(f[i], f[i - a] + 1);
		if(i >= b && f[i - b] != INT_MIN) f[i] = max(f[i], f[i - b] + 1);
		if(i >= c && f[i - c] != INT_MIN) f[i] = max(f[i], f[i - c] + 1);
	}
	cout << f[n];
	return 0;
}