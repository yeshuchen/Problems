#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int l[N], r[N], f[N][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> l[i] >> r[i];
	f[1][0] = 2 * r[1] - l[1] - 1;
	f[1][1] = r[1] - 1;
	for(int i = 2; i <= n; i++)
	{ 
		if(l[i - 1] <= r[i]) f[i][0] = f[i - 1][0] + 2 * r[i] - l[i] - l[i - 1], f[i][1] = f[i - 1][0] + r[i] - l[i - 1] + max(2 * (l[i - 1] - l[i]), 0);
		else f[i][0] = f[i - 1][0] + l[i - 1] - l[i], f[i][1] = f[i - 1][0] + l[i - 1] + r[i] - 2 * l[i];
		if(r[i - 1] <= r[i]) f[i][0] = min(f[i][0], f[i - 1][1] + 2 * r[i] - r[i - 1] - l[i]), f[i][1] = min(f[i][1], f[i - 1][1] + r[i] - r[i - 1] + max(2 * (r[i - 1] - l[i]), 0));
		else f[i][0] = min(f[i][0], f[i - 1][1] + r[i - 1] - l[i]), f[i][1] = min(f[i][1], f[i - 1][1] + r[i - 1] + r[i] - 2 * l[i]);
		f[i][0]++; f[i][1]++;
	}
	cout << min(f[n][0] + n - l[n], f[n][1] + n - r[n]);
	return 0;
}