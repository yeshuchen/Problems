#include<bits/stdc++.h>
using namespace std;
int n, h[100005], f[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> h[i];
	f[2] = abs(h[2] - h[1]);
	for(int i = 3; i <= n; i++)
		f[i] = min(f[i - 1] + abs(h[i] - h[i - 1]), f[i - 2] + abs(h[i] - h[i - 2]));
	cout << f[n];
	return 0;
}