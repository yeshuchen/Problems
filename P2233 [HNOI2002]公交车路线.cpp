#include<bits/stdc++.h>
using namespace std;
struct matrix{
	int c, r;
	int a[10][10];
	matrix(){memset(a, 0, sizeof a);}
}a;
matrix operator * (matrix a, matrix b)
{
	matrix base;
	base.r = a.r; base.c = b.c;
	for(int i = 1; i <= a.r; i++)
		for(int j = 1; j <= b.c; j++)
			for(int k = 1; k <= a.c; k++)
				base.a[i][j] = (base.a[i][j] + a.a[i][k] * b.a[k][j]) % 1000;
	return base;
}
matrix ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n; 
	ans.a[1][1] = 1;
	ans.r = 1; ans.c = 8;
	matrix a, base;
	a.r = a.c = base.r = base.c = 8;
	for(int i = 1; i <= 8; i++)
		a.a[(i == 8 ? 1 : i + 1)][i] = a.a[(i == 1 ? 8 : i - 1)][i] = 1, base.a[i][i] = 1;
	a.a[5][4] = a.a[5][6] = 0;
	while(n)
	{
		if(n & 1) base = base * a;
		a = a * a;
		n >>= 1;
	}
	ans = ans * base;
	cout << ans.a[1][5];
	return 0;
}