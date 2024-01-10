#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, mod = 998244353;
int n, a[N], f[N];
map<int, int> mp;
void merge(int x, int y) {f[x] = y;}
int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; int cnt = n - 1;
	for(int i = 1; i <= n; i++) cin >> a[i], f[i] = i;
	for(int i = 1; i <= n; i++)
	{
		if(mp[a[i]])
		{
			int x = mp[a[i]];
			while(find(x) != find(i))
			{
				int y = find(x);
				merge(y, find(y + 1));
				cnt--;
			}
		}
		mp[a[i]] = i;
	}	
	int ans = 1;
	for(int i = 1; i <= cnt; i++) ans = ans * 2 % mod;
	cout << ans;
	return 0;
}