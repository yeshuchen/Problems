#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int T, n, m;
int a[N], cnt[N];
int get(int x)
{
	return cnt[x] - cnt[x - 1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		for(int i = 1; i <= m; i++) cnt[i] = 0;
		for(int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
		for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
		if(!cnt[1]) {cout << "No\n"; goto end;}
		for(int i = 1; i <= m; i++)
		{
			for(int j = i; j <= m; j += i)
				if(cnt[min(j + i - 1, m)] - cnt[j - 1])
					if(get(i) && !get(j / i))
					{
						cout << "No\n";
						goto end;
					}
		}
		cout << "Yes\n";
		end:;
	}
	return 0;
}