#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e8;
struct bignum
{
	int length;
	int a[10005];
	bignum operator - (const int &num)
	{
		bignum p; p.length = length; memcpy(p.a, a, sizeof(p.a));
		p.a[length]--;
		for(int i = length; i >= 1; i--)
			if(p.a[i] < 0) p.a[i - 1]--, p.a[i] += 10;
		if(p.a[1] == 0)
		{
			for(int i = 1; i < p.length; i++)
				p.a[i] = p.a[i + 1];
			p.length--;
		}
		return p;
	}
	bignum operator / (const int &num)
	{
		bignum p; int mid = 0, pos = 1;
		for(int i = 1; i <= length; i++)
		{
			p.a[i] = (mid * 10 + a[i]) / num;
			mid = (mid * 10 + a[i]) % num;
		}
		while(!p.a[pos] && pos <= length) pos++;
		if(pos > length)
		{
			p.length = 1, p.a[1] = 0;
			return p;
		}
		p.length = length - pos + 1;
		for(int i = 1; i <= p.length; i++)
			p.a[i] = p.a[i + pos - 1];
		return p;
	}
	bool operator == (const bignum &w)
	{
		if(w.length != length) return false;
		for(int i = 1; i <= length; i++)
			if(a[i] != w.a[i]) return false;
		return true;
	}
	inline void write()
	{
		for(int i = 1; i <= length; i++)
			cout << a[i];
	}
};
struct matrix
{
	int col, row;
	int a[3][3];
	inline void init()
	{
		col = row = 0;
		memset(a, 0, sizeof(a));
	}
	matrix operator *(const matrix &p)
	{
		matrix base; base.init();
		base.col = p.col; base.row = row;
		for(int i = 1; i <= row; i++)
			for(int j = 1; j <= p.col; j++)
				for(int k = 1; k <= col; k++)
					base.a[i][j] = (base.a[i][j] + a[i][k] * p.a[k][j]) % mod;
		return base;
	}
};
inline matrix power(matrix a, bignum b)
{
	matrix base;
	base.init(); base.row = base.col = 2;
	base.a[1][1] = base.a[2][2] = 1;
	bignum st;
	st.length = 1;
	st.a[1] = 0;
	while(!(b == st))
	{
		if(b.a[b.length] % 2 == 1) base = base * a;
		b = b / 2;
		a = a * a;
	}
	return base;
}
string s;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	bignum n; matrix ans, mid; ans.init(); mid.init();
	ans.row = 1; ans.col = 2; ans.a[1][1] = 1; ans.a[1][2] = 1;
	mid.row = 2; mid.col = 2; mid.a[1][1] = mid.a[1][2] = mid.a[2][1] = 1;
	cin >> s; n.length = s.size();
	for(int i = 0; i < s.size(); i++)
		n.a[i + 1] = s[i] - '0';
	ans = ans * power(mid, n - 1);
	cout << ans.a[1][1];
	return 0;
}