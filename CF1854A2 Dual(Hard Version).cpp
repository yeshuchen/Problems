#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[25];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int mx = -20, mn = 20;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]), mn = min(mn, a[i]);
		if(mx <= 0)
		{
			cout << n - 1 << '\n';
			for(int i = n - 1; i; i--)
				cout << i << ' ' << i + 1 << '\n';
			continue;
		}
		if(mn >= 0)
		{
			cout << n - 1 << '\n';
			for(int i = 1; i < n; i++)
				cout << i + 1 << ' ' << i << '\n';
			continue;
		}
		int c = 0, pos;
		for(int i = 1; i <= n; i++)
		{
			c += (a[i] <= 0);
			if(a[i] == mx) pos = i;
		}
		int cnt = 0, tmp = mx;
		while(mx < abs(mn)) mx *= 2, cnt++;
		if(c <= 32 - n - cnt)
		{
			cout << n + c + cnt - 1 << '\n';
			for(int i = 1; i <= cnt; i++) cout << pos << ' ' << pos << '\n';
			for(int i = 1; i <= n; i++)
				if(a[i] <= 0) cout << i << ' ' << pos << '\n';
			for(int i = 1; i < n; i++) cout << i + 1 << ' ' << i << '\n';
		}
		else
		{
			cnt = 0;
			for(int i = 1; i <= n; i++)
				if(a[i] == mn) pos = i;
			while(tmp > abs(mn)) mn *= 2, cnt++;
			cout << 2 * n + cnt - c - 1 << '\n';
			for(int i = 1; i <= cnt; i++) cout << pos << ' ' << pos << '\n';
			for(int i = 1; i <= n; i++)
				if(a[i] > 0) cout << i << ' ' << pos << '\n';
			for(int i = n - 1; i; i--) cout << i << ' ' << i + 1 << '\n';
		}
	}
	return 0;
}