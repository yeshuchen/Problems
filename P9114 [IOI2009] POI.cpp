#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int val[2005];
struct player{
	int pos, cnt, sol;
	int sit[2005];
}p[2005];
inline bool cmp(player x, player y)
{
	if(x.cnt != y.cnt) return x.cnt > y.cnt;
	if(x.sol != y.sol) return x.sol > y.sol;
	return x.pos < y.pos;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		p[i].pos = i;
		for(int j = 1; j <= m; j++)
			cin >> p[i].sit[j];
	}
	for(int j = 1; j <= m; j++)
		for(int i = 1; i <= n; i++)
			val[j] += !p[i].sit[j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			p[i].cnt += p[i].sit[j] * val[j];
			p[i].sol += p[i].sit[j];
		}
	sort(p + 1, p + n + 1, cmp);
	for(int i = 1; i <= n; i++)
		if(p[i].pos == k)
			cout << p[i].cnt << ' ' << i;
	return 0;
}