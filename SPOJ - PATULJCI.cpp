#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, m, c, tot;
int a[N], tmp[N];
vector<int> v[N];
int ask(int x, int l, int r)
{
	return (upper_bound(v[x].begin(), v[x].end(), r) - v[x].begin()) - (lower_bound(v[x].begin(), v[x].end(), l) - v[x].begin());
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> c;
	int sz = sqrt(n);
	for(int i = 1; i <= n; i++)
		cin >> a[i], v[a[i]].push_back(i);
	for(int i = 1; i <= c; i++)
		if(v[i].size() >= sz) tmp[++tot] = i;
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		int l, r, flag = 0;
		cin >> l >> r;
		int len = (r - l + 1);
		if(len <= 2 * sz)
		{
			for(int j = l; j <= r; j++)
			{
				int x = ask(a[j], l, r);
				if(x > len / 2)
				{
					flag = 1;
					cout << "yes " << a[j] << '\n';
					break;
				}
			}
		}
		else
		{
			for(int j = 1; j <= tot; j++)
			{
				int x = ask(tmp[j], l, r);
				if(x > len / 2)
				{
					flag = 1;
					cout << "yes " << tmp[j] << '\n';
					break;
				}
			}
		}
		if(!flag) cout << "no\n";
	}
	return 0;
} 