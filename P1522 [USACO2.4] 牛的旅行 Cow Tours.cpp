#include<bits/stdc++.h>
const double inf = 1e9;
using namespace std;
int n;
int x[155], y[155];
double f[155][155];
inline double dis(int i, int j)
{
	return sqrt(1.0 * 1ll * (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
int res;
bool vis[155];
vector<int> v[155];
inline void dfs(int x)
{
	if(vis[x]) return;
	vis[x] = 1;
	v[res].push_back(x);
	for(int i = 1; i <= n; i++)
		if(f[x][i] != inf)
			dfs(i);
}
double D[155];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			char c;
			f[i][j] = f[j][i] = inf;
			cin >> c;
			if(c == '1' || i == j) f[i][j] = f[j][i] = dis(i, j);
		}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(f[i][k] != inf && f[k][j] != inf)
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	for(int i = 1; i <= n; i++)
		if(!vis[i])
			res++, dfs(i);
	for(int i = 1; i <= res; i++)
		for(int j = 0; j < v[i].size(); j++)
			for(int k = j + 1; k < v[i].size(); k++)
				D[i] = max(D[i], f[v[i][j]][v[i][k]]);
	double ans = INT_MAX;
	for(int i = 1; i <= res; i++)	
		for(int j = i + 1; j <= res; j++)
		{
			int leni = v[i].size(), lenj = v[j].size();
			for(int k = 0; k < leni; k++)
				for(int l = 0; l < lenj; l++)
				{
					int x = v[i][k], y = v[j][l];
					double res = dis(x, y), d = 0;
					for(int p = 0; p < leni; p++)
						d = max(d, f[v[i][p]][x]);
					res += d; d = 0;
					for(int p = 0; p < lenj; p++)
						d = max(d, f[v[j][p]][y]);
					res += d;
					res = max(res, D[i]);
					res = max(res, D[j]);
					ans = min(ans, res);
				}
		}
	printf("%.6lf", ans);
	return 0;
}