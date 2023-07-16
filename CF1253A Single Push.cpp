#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[100005], b[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int d[1005];
		memset(d, 0, sizeof(d));
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cin >> b[i];
		for(int i = 1; i <= n; i++)
			a[i] = b[i] - a[i];
		bool flag = 0;
		for(int i = 1; i <= n; i++)
			if(a[i] < 0)
			{
				flag = 1;
				break;
			}
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			if(!d[a[i]] && a[i]) d[a[i]] = 1, cnt++;
		if(cnt > 1 || flag)
		{
			cout << "NO\n";
			goto end;
		}
		cnt = 0;
		a[n + 1] = 0;
		for(int i = 1; i <= n + 1; i++)
			if(!a[i] && a[i - 1])
				cnt++;
		if(cnt > 1)
		{
			cout << "NO\n";
			goto end;
		}
		cout << "YES\n";
		end:;
	}
	return 0;
}