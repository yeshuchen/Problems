#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int T, n;
int p[N], mn_pre[N], mx_pre[N], mn_suf[N], mx_suf[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> p[i];
			mn_pre[i] = mn_pre[i - 1];
			if(!mn_pre[i]) mn_pre[i] = i;
			else if(p[mn_pre[i]] > p[i]) mn_pre[i] = i;
			mx_pre[i] = mx_pre[i - 1];
			if(!mx_pre[i]) mx_pre[i] = i;
			else if(p[mx_pre[i]] < p[i]) mx_pre[i] = i;
		}
		mn_suf[n + 1] = mx_suf[n + 1] = 0;
		for(int i = n; i; i--)
		{
			mn_suf[i] = mn_suf[i + 1];
			if(!mn_suf[i]) mn_suf[i] = i;
			else if(p[mn_suf[i]] > p[i]) mn_suf[i] = i;
			mx_suf[i] = mx_suf[i + 1];
			if(!mx_suf[i]) mx_suf[i] = i;
			else if(p[mx_suf[i]] < p[i]) mx_suf[i] = i;
		}
		int p = mn_pre[n], flag = 1, ans = 0;
		while(p)
		{
			ans++;
			p = (flag ? mx_pre[p - 1] : mn_pre[p - 1]);
			flag ^= 1;
		}
		p = mn_suf[1]; flag = 1;
		while(p)
		{
			ans++;
			p = (flag ? mx_suf[p + 1] : mn_suf[p + 1]);
			flag ^= 1;
		}
		cout << ans - 2 << '\n';
	}
	return 0;
}