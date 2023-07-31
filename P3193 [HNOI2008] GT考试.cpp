#include<bits/stdc++.h>
using namespace std;
int n, m, mod;
char c[25];
int nxt[25];
struct mat
{
	int r, c;
	int arr[25][25];
	inline void init() {memset(arr, 0, sizeof(arr));}
	mat operator * (const mat &f)
	{
		mat g; g.init();
		g.r = r; g.c = f.c;
		for(int i = 0; i < r; i++)
			for(int j = 0; j < g.c; j++)
				for(int k = 0; k < c; k++)
					g.arr[i][j] = (g.arr[i][j] + arr[i][k] * f.arr[k][j]) % mod;
		return g;
	}
} ans, bc, base;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> mod;
	for(int i = 1; i <= m; i++)
		cin >> c[i];
	nxt[1] = 0;
	bc.init(); ans.init(); base.init();
	ans.r = 1; ans.c = m;
	for(int i = 2; i <= m; i++)
	{
		int j = nxt[i - 1]; nxt[i] = 0;
		while(j && c[j + 1] != c[i]) j = nxt[j];
		if(c[j + 1] == c[i]) nxt[i] = j + 1;
	}
	for(int i = 0; i < m; i++)
		for(char ch = '0'; ch <= '9'; ch++)
		{
			int j = i, res = 0;
			while(c[j + 1] != ch && j) j = nxt[j];
			if(c[j + 1] == ch) res = j + 1;
			bc.arr[i][res]++;
			if(i == 0) ans.arr[0][res]++;
		}	
	bc.r = bc.c = base.r = base.c = m;
	for(int i = 0; i < m; i++) base.arr[i][i] = 1;
	n--;
	while(n)
	{
		if(n & 1) base = base * bc;
		bc = bc * bc;
		n >>= 1;
	}
	int cnt = 0;
	ans = ans * base;
	for(int i = 0; i < ans.c; i++)
		cnt = (cnt + ans.arr[0][i]) % mod;
	cout << cnt;
	return 0;
}