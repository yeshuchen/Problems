#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		if(a[n]) {cout << "NO\n"; continue;}
		cout << "YES\n";
		int cnt = 0;
		for(int i = n; i >= 1; i--)
		{
			if(a[i])
			{
				cnt++;
				if(!a[i - 1]) cout << cnt << ' ';
				else cout << 0 << ' ';
			}
			else cnt = 0, cout << 0 << ' ';
		}
		cout << '\n';
	}
	return 0;
}