#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int x, cnt[15];
int c[7] = {1869, 8196, 1986, 1698, 6891, 1689, 1968};
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s;
	for(int i = 0; i < s.size(); i++)
		cnt[s[i] - '0']++;
	cnt[1]--; cnt[6]--; cnt[8]--; cnt[9]--;
	for(int i = 1; i <= 9; i++)
	{
		for(int j = 1; j <= cnt[i]; j++)
			x = ((x << 1) + (x << 3) + i % 10) % 7, cout << i;
	}
	cout << c[x * 10000 % 7];
	for(int i = 1; i <= cnt[0]; i++) cout << 0;
	return 0;
}