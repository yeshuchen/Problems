#include<bits/stdc++.h>
using namespace std;
int T, n;
int p[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++) p[i] = 0;
		if(n == 1)
		{
			cout << 1 << '\n';
			continue;
		}
		if(n == 2)
		{
			cout << 1 << ' ' << 2 << '\n';
			continue;
		}
		int cnt = 2;
		p[n] = 3;
		if(n & 1) p[(n + 1) / 2] = 1;
		else p[n / 2] = 1;
		for(int i = 1; i <= n; i++)
		{
			if(p[i]) continue;
			p[i] = cnt;
			if(cnt == 2) cnt += 2;
			else cnt++;
		}
		for(int i = 1; i <= n; i++) cout << p[i] << ' ';
		cout << '\n';
	}
	return 0;
}