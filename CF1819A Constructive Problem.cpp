#include<bits/stdc++.h>
using namespace std;
int T, n;
int d[200005], a[200005], f[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int cnt = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if(a[i] <= n) d[a[i]] = 1;
		}
		int MEX;
		for(int i = 0; i <= n; i++)
			if(!d[i])
			{
				MEX = i;
				break;
			}
		vector<int> v;
		for(int i = 0; i <= n; i++) d[i] = 0;
		for(int i = 1; i <= n; i++)
			if(a[i] == MEX + 1)
				v.push_back(i);
		if(MEX == n) {cout << "No\n"; continue;}
		if(v.empty()) {cout << "Yes\n"; continue;}
		for(int i = v[0]; i <= v[v.size() - 1]; i++)
			a[i] = MEX;
		for(int i = 1; i <= n; i++)
			if(a[i] <= n) d[a[i]] = 1;
		for(int i = 0; i <= n; i++)
			if(!d[i])
			{
				MEX = i;
				break;
			}
		if(MEX != a[v[0]] + 1) cout << "No\n";
		else cout << "Yes\n";
		for(int i = 0; i <= n; i++) d[i] = 0;
	}
	return 0;
}