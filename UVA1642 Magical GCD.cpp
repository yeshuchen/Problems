#include<bits/stdc++.h>
#define int long long
using namespace std;
int T, n;
int a[100005], b[100005], pos[100005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int ans = 0, num = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= num; j++)
			{
				b[j] = __gcd(b[j], a[i]);
				if(b[j] == b[j - 1])
				{
					for(int k = j; k < num; k++)
						b[k] = b[k + 1], pos[k] = pos[k + 1];
					j--; num--;
				}
			}
			b[++num] = a[i], pos[num] = i;
			for(int j = 1; j <= num; j++)
				ans = max(ans, (i - pos[j] + 1) * b[j]);
		}
		cout << ans << '\n';
	}
	return 0;
}