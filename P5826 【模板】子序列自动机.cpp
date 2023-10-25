#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 1e6 + 5;
int type;
int n, q, m;
int a[N], b[M];
vector<int> v[N];
int main()
{
	cin >> type >> n >> q >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], v[a[i]].push_back(i);
	for(int i = 1; i <= q; i++)
	{
		int num, x, pos = 0;
		cin >> num; bool flag = 0;
		for(int j = 1; j <= num; j++)
		{
			cin >> x;
			if(flag) continue;
			pos = upper_bound(v[x].begin(), v[x].end(), pos) - v[x].begin();
			if(pos >= v[x].size()) flag = 1;
			else pos = v[x][pos];
		}
		cout << (flag ? "No\n" : "Yes\n");
	}
	return 0;
}