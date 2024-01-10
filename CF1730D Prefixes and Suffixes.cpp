#include<bits/stdc++.h>
using namespace std;
int T, n;
int mp[900];
char s[200005], t[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> s + 1 >> t + 1;
		reverse(t + 1, t + n + 1);
		for(int i = 1; i <= n; i++)
		{
			if(s[i] > t[i]) swap(s[i], t[i]);
			mp[((s[i] - 'a') * 26 + t[i] - 'a')]++;
		}
		int res = -1, flag = 0;
		for(int i = 0; i <= 26 * 26; i++)
		{
			if(mp[i] & 1)
			{
				if(res != -1)
					flag = 1;
				res = i;
			}
			mp[i] = 0;
		}
		if(flag) cout << "NO\n";
		else if(res == -1 || res / 26 == res % 26) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}