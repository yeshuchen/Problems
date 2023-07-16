#include<bits/stdc++.h>
using namespace std;
int n;
bool vis[2000005];
int a[200005];
map<int, int> m;
vector<int> ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	long long cnt = 0, len = 0;
	for(int i = 1; i <= n; i++)
	{
		len++;
		if(a[i] < 0)
		{
			if(!m[-a[i]])
			{
				cout << -1;
				return 0;
			}
			if(m[-a[i]]) m[-a[i]] = 0, cnt--;
			if(!cnt)
			{
				for(int j = i - len + 1; j <= i; j++) m[a[j]] = vis[abs(a[j])] = 0;
				ans.push_back(len);
				len = 0;
			}
		}
		else
		{
			if(m[a[i]] || vis[a[i]])
			{
				cout << -1;
				return 0;
			}
			m[a[i]] = vis[a[i]] = 1;
			cnt++;
		}
	}
	if(cnt)
	{
		cout << -1;
		return 0;
	}
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	return 0;
}