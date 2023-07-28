#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[400005], cnt[400005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		bool flag = 0;
		long long res = 0;
		cin >> n;
		for(int i = 0; i <= n; i++) cnt[i] = 0;
		for(int i = 1; i <= n; i++)
			cin >> a[i], cnt[a[i]]++;
		stack<int> s;
		for(int i = 0; i <= n; i++)
		{
			if(flag)
			{
				cout << -1 << ' ';
				continue;
			}
			if(cnt[i])
			{
				cout << res + cnt[i] << ' ';
				for(int j = 1; j < cnt[i]; j++) s.push(i);
			}
			else
			{
				cout << res << ' ';
				if(s.empty())
				{
					flag = 1;
					continue;
				}
				res += i - s.top();
				s.pop();
			}
		}
		cout << '\n';
	}
	return 0;
}