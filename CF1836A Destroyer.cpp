#include<bits/stdc++.h>
using namespace std;
int T;
int a[100005], d[105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		memset(d, 0, sizeof(d));
		for(int i = 1; i <= n; i++)
			cin >> a[i], d[a[i]]++;
		sort(a + 1, a + n + 1);
		if(a[1] != 0) {cout << "NO\n"; continue;}
		for(int i = 1; i < n; i++)
			if(d[a[i]] < d[a[i + 1]] || a[i + 1] - a[i] > 1)
			{
				cout << "NO\n";
				goto end;
			}
		cout << "YES\n";
		end:;
	}
	return 0;
}