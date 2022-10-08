#include<bits/stdc++.h>
using namespace std;
const int N = (1 << 16);
int n, ans;
int f[N][17];
string s[20];
bool check(string a, string b){return a[a.size() - 1] == b[0];}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	for(int i = 0; i < n; i++)
		f[(1 << i)][i + 1] = s[i + 1].size();
	for(int i = 1; i < (1 << n); i++)
		for(int j = 1; j <= n; j++)
		{
			if(i & (1 << j - 1))
				for(int k = 1; k <= n; k++)
				{
					if(k == j) continue;
					if((i & (1 << k - 1)) && check(s[k], s[j]))
						f[i][j] = max(f[i][j], f[i ^ (1 << j - 1)][k] + (int)s[j].size());
				}
			ans = max(ans, f[i][j]);
		}
	cout << ans;
	return 0;
}