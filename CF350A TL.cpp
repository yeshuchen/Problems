#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[105], b[105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	if(b[1] <= a[n] || a[1] > (b[1] - 1) / 2) cout << -1;
	for(int i = a[n]; i < b[1]; i++)
		if(i / 2 >= a[1])
		{
			cout << i;
			return 0;
		}
	return 0;
}