#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
string nt, mt;
int n, m, a, b, c, d;
struct node{
	int r, c;
	int p[3][3];
	friend node operator *(node x, node y)
	{
		node z;
		z.r = x.r; z.c = y.c;
		z.p[1][1] = (x.p[1][1] * y.p[1][1] + x.p[1][2] * y.p[2][1]) % mod;
		z.p[2][1] = (x.p[2][1] * y.p[1][1] + x.p[2][2] * y.p[2][1]) % mod;
		z.p[1][2] = x.p[1][2];
		z.p[2][2] = x.p[2][2];
		return z;
	}
}st, z1, z2;
inline int read(string s)
{
	int x = 0, flag = 0;
	for(int i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		x = (x << 1) + (x << 3) + (ch ^ 48);
		if(x >= mod)
		{
			if(a > 1) flag = 1, x %= (mod - 1);
			else x %= mod;
		}
	}
	return x + flag * (mod - 1);
}
inline node power(node a, int b)
{
	node base;
	base.r = a.r; base.c = a.c;
	base.p[2][1] = base.p[1][2] = 0;
	base.p[1][1] = base.p[2][2] = 1;
	while(b)
	{
		if(b & 1) base = base * a;
		b >>= 1;
		a = a * a;
	}
	return base;
}
signed main()
{
	cin >> nt >> mt;
	cin >> a >> b >> c >> d;
	n = read(nt); m = read(mt);
	st.r = 1; st.c = 2;
	z1.r = z1.c = z2.r = z2.c = 2;
	z1.p[1][1] = a; z1.p[2][1] = b; 
	z2.p[1][1] = c; z2.p[2][1] = d;
	z1.p[1][2] = z2.p[1][2] = 0;
	z1.p[2][2] = z2.p[2][2] = 1;
	st.p[1][1] = st.p[1][2] = 1;
	z1 = power(z1, m - 1);
	node ed = power(z1 * z2, n - 1);
	ed = ed * z1;
	st = st * ed;
	cout << st.p[1][1];
}