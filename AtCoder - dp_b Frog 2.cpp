#include<bits/stdc++.h>
using namespace std;
int n, k, h[100005], f[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> h[i];
	for(int i = 2; i <= n; i++)
	{
		f[i] = INT_MAX;
		for(int j = max(i - k, 1); j < i; j++)
			f[i] = min(f[i], f[j] + abs(h[j] - h[i]));
	}
	cout << f[n];
	return 0;
}