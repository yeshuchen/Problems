#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int f[105][105][105];
int nxt[N], pos[105][105];
char s[N], t[N], vir[N];
struct node {
	int x, y, z;
} mv[105][105][105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s + 1 >> t + 1 >> vir + 1;
	int len = strlen(vir + 1);
	for(int i = 2; i <= len; i++)
	{
		int p = nxt[i - 1];
		while(p && vir[p + 1] != vir[i]) p = nxt[p];
		if(vir[p + 1] == vir[i]) nxt[i] = p + 1;
	}
	for(char ch = 'A'; ch <= 'Z'; ch++)
		for(int i = 0; i < len; i++)
		{
			int p = i;
			while(p && vir[p + 1] != ch) p = nxt[p];
			if(vir[p + 1] == ch) pos[i][ch - 'A'] = p + 1;
		}
	int n = strlen(s + 1), m = strlen(t + 1);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			for(int k = 0; k < len; k++)
			{
				if(s[i + 1] == t[j + 1])
				{
					int p = pos[k][s[i + 1] - 'A'];
					int &res = f[i + 1][j + 1][p];
					if(p < len && f[i][j][k] >= res)
					{
						res = f[i][j][k] + 1;
						mv[i + 1][j + 1][p] = {i, j, k};
					}
				}
				if(f[i][j][k] >= f[i + 1][j][k])
				{
					f[i + 1][j][k] = f[i][j][k];
					mv[i + 1][j][k] = {i, j, k};
				}
				if(f[i][j][k] >= f[i][j + 1][k])
				{
					f[i][j + 1][k] = f[i][j][k];
					mv[i][j + 1][k] = {i, j, k};
				}
			}
	for(int i = 1; i < n; i++)
		for(int k = 0; k < len; k++)
			if(f[i][m][k] >= f[i + 1][m][k])
				f[i + 1][m][k] = f[i][m][k], mv[i + 1][m][k] = {i, m, k};
	for(int i = 1; i < m; i++)
		for(int k = 0; k < len; k++)
			if(f[n][i][k] >= f[n][i + 1][k])
				f[n][i + 1][k] = f[n][i][k], mv[n][i + 1][k] = {n, i, k};
	int ans = 0; stack<char> stk;
	for(int i = 0; i < len; i++)
		if(f[n][m][ans] < f[n][m][i])
			ans = i;
	if(!f[n][m][ans]) {cout << 0; return 0;}
	int i = n, j = m, k = ans;
	while(f[i][j][k])
	{
		int i1 = mv[i][j][k].x, j1 = mv[i][j][k].y, k1 = mv[i][j][k].z;
		if(f[i][j][k] != f[i1][j1][k1]) stk.push(s[i]);
		i = i1; j = j1; k = k1;
	}
	while(!stk.empty()) cout << stk.top(), stk.pop();
	return 0;
}