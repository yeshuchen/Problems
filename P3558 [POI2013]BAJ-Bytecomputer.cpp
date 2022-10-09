#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, a[N];
int f[N][4];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	f[1][0] = f[1][1] = f[1][2] = INT_MAX;
	if(a[1] == 1) f[1][2] = 0;
	if(a[1] == 0) f[1][1] = 0;
	if(a[1] == -1) f[1][0] = 0;
	for(int i = 2; i <= n; i++)
	{
		f[i][0] = f[i][1] = f[i][2] = INT_MAX;
		if(a[i] == -1) f[i][0] = f[i - 1][0], f[i][2] = f[i - 1][2] + 2;
		if(a[i] == 0) f[i][0] = f[i - 1][0] + 1, f[i][1] = min(f[i - 1][0], f[i - 1][1]), f[i][2] = f[i - 1][2] + 1;
		if(a[i] == 1) f[i][0] = f[i - 1][0] + 2, f[i][1] = f[i - 1][0] + 1, f[i][2] = min(min(f[i - 1][0], f[i - 1][1]), f[i - 1][2]);
	}
	if(min(f[n][0], min(f[n][1], f[n][2])) >= INT_MAX) cout << "BRAK";
	else cout << min(f[n][0], min(f[n][1], f[n][2]));
	return 0;
}