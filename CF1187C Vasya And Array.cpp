#include<bits/stdc++.h>
using namespace std;
int n, m;
int t[1005], l[1005], r[1005], a[1005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		a[i] = n - i + 1;
	for(int i = 1; i <= m; i++)
	{
		cin >> t[i] >> l[i] >> r[i];
		if(t[i] == 1)
			for(int j = l[i]; a[j] != n - j + 1 || j <= r[i]; j++)
				a[j] = a[l[i]];
	}
	for(int i = 1; i <= m; i++)
	{
		if(!t[i])
		{
			bool flag = 0;
			for(int j = l[i]; j < r[i]; j++)
				if(a[j] > a[j + 1])
					flag = 1;
			if(!flag)
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	for(int i = 1; i <= n; i++)
		cout << a[i] << ' '; 
	return 0;
}