#include<bits/stdc++.h>
using namespace std;
int n, m;
char c[1010];
bitset<2010> matrix[2010];
inline int Gauss()
{
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int cur = i;
		while(cur <= m && !matrix[cur].test(i)) cur++;
		if(cur > m) return 0;
		ans = max(ans, cur);
		if(i != cur) swap(matrix[cur], matrix[i]);
		for(int j = 1; j <= m; j++)
			if(i != j && matrix[j].test(i))
				matrix[j] ^= matrix[i];
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		bool f;
		cin >> c + 1 >> f;
		for(int j = 1; j <= n; j++)
			matrix[i].set(j, c[j] == '1');
		matrix[i].set(0, f);
	}
	int res = Gauss();
	if(res)
	{
		cout << res << '\n';
		for(int i = 1; i <= n; i++)
			cout << (matrix[i].test(0) ? "?y7M#\n" : "Earth\n");
	}
	else cout << "Cannot Determine";
	return 0;
}