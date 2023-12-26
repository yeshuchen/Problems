#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int T, n;
int a[N], b[N], d[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		vector<int> v;
		cin >> n;
		for(int i = 1; i <= n; i++) d[i] = 0;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cin >> b[i];
		for(int i = 1; i <= n; i++)
			if(a[i] > b[i]) d[b[i]]++, d[a[i]]--;
		for(int i = 1; i <= n; i++) d[i] += d[i - 1];
		for(int i = 1; i <= n; i++)
		{
			bool flag = 1;
			for(int j = i; j <= n; j += i)
				flag &= !d[j];
			if(flag) v.push_back(i);
		}
		cout << v.size() << '\n';
		for(int x : v) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}