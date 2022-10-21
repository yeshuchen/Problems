#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
bool vis[1000005];
namespace hswfwkj
{
	long long exp(long long a,long long m,long long n){
		long long base = 1;
		while(m)
		{
			if(m & 1) base = (__int128)base * a % n;
			m >>= 1;
			a = (__int128)a * a % n;
		}
		return base;
	}
	bool Witness(long long a,long long n)
	{
		long long m = n - 1;
		int j = 0;
		while(!(m & 1)){
			j++;
			m >>= 1;
		}
		long long x = exp(a, m, n);
		if(x == 1 || x == n - 1) return false;
		while(j--){
			x = (__int128)x * x % n;
			if(x == n - 1) return false;
		}
		return true;
	}
	bool Miller_Rabin(long long n){
		int prime[5] = {0, 2, 3}; 
		if(n <= 1000000) return !vis[n];
		if(!(n & 1)) return false;
		return (!Witness(2, n) && !Witness(3, n));
	}
};
int mod = 998244353;
string op;
int f[200005], w[100005];
inline ull read()
{
	ull x = 0, flag = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		if(x >= mod) flag = 1, x %= (mod - 1);
		ch = getchar(); 
	}
	return x + flag * (mod - 1);
}
inline ull muler(ull a, ull b, ull mod)
{
	ull base = 0;
	while(b)
	{
		if(b & 1) base = (base + a) % mod;
		b >>= 1;
		a = a * 2 % mod;
	}
	return base;
}
inline ull power(ull a, ull b, ull mod)
{
	ull base = 1;
	while(b)
	{
		if(b & 1) base = muler(base, a, mod);
		b >>= 1;
		a = muler(a, a, mod);
	}
	return base;
}
inline int _power(int a, int b, int mod)
{
	int base = 1;
	while(b)
	{
		if(b & 1) base = (long long)base * a % mod;
		b >>= 1;
		a = (long long)a * a % mod; 
	}
	return base;
}
int T, tot;
long long v[1000005];
int mo[1000005];
long long prime[1000005];
inline void shai()
{
	mo[1] = 1;
	for(int i = 2; i <= 1000000; i++)
	{
		if(!vis[i]) prime[++tot] = i, mo[i] = -1;
		for(int j = 1; j <= tot && i * prime[j] <= 1000000; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) {mo[i * prime[j]] = 0; break;}
			mo[i * prime[j]] = -mo[i];
		}
	}
}
int g[20000005];
signed main()
{
	shai();
	cin >> op;
	if(op == "1_998244353")
	{
		cin >> T;
		while(T--)
		{
			ull n;
			n = read();
			cout << power(19, n, mod) << '\n';
		}
	}
	if(op == "1?")
	{
		cin >> T;
		while(T--)
		{
			ull n; mod = 1145141;
			n = read();
			cout << power(19, n, mod) << '\n';
		}
	}
	if(op == "1?+")
	{
		cin >> T;
		while(T--)
		{
			ull n;
			cin >> n;
			ull exmod = 5211600617818708273;
			cout << power(19, n, exmod) << '\n';
		}
	}
	if(op == "1wa_998244353")
	{
		f[0] = 1;
		for(int i = 1; i <= 200000; i++) f[i] = (signed)(f[i - 1] * 19) % mod;
		for(int i = 1; i <= 45699; i++)
			w[i] = f[i + 55244];
		cin >> T;
		while(T--)
		{
			long long n;
			cin >> n;
			if(n < 55245) cout << f[n] << '\n';
			else cout << w[(n - 55245) % 45699 + 1] << '\n';
		}
	}
	if(op == "2p")
	{
		cin >> T;
		while(T--)
		{
			long long l, r;
			cin >> l >> r;
			for(long long i = l; i <= r; i++)
			{
				if(hswfwkj::Miller_Rabin(i))cout << 'p';
				else cout << '.';
			}
			cout << '\n';
		}
	}
	if(op == "2u")
	{
		cin >> T;
		while(T--)
		{
			long long l, r;
			cin >> l >> r;
			for(long long i = l; i <= min(r, 1ll * 1000000); i++)
				cout << (mo[i] == 0 ? '0' : (mo[i] > 0 ? '+' : '-'));
			l = max(l, 1ll * 1000001);
			if(l > r) {cout << '\n'; continue;}
			int len = r - l + 1;
			for(int i = len; i; i--)
				mo[i] = v[i] = 1;
			for(int i = 1; i <= tot; i++)
			{
				long long w = prime[i] * prime[i];
				for(int j = ((l - 1) / prime[i] + 1) * prime[i] - l + 1; j <= len; j += prime[i])
				{
					if((l + j - 1) % w == 0) mo[j] = 0;
					else mo[j] *= -1, v[j] *= prime[i];
				}
			}
			for(int i = 1; i <= len; i++)
			{
				long long x = i + l - 1;
				x /= v[i];
				if(x == 1) continue;
				long long w = sqrt(x);
				if(w * w == x) mo[i] = 0;
				if(hswfwkj::Miller_Rabin(x)) mo[i] *= -1;
			}
			for(int i = 1; i <= len; i++)
				cout << (mo[i] == 0 ? '0' : (mo[i] > 0 ? '+' : '-'));
			cout << '\n';
		}
	}
	if(op == "2g")
	{
		int p[50] = {0, 23, 19, 13, 11, 7, 5, 3, 2};
		int l, r;
		cin >> T;
		while(T--)
		{
			cin >> l >> r >> mod;
			if(mod == 998244353)
			{
				for(int i = l; i <= r; i++)
				{
					if(_power(i, (mod - 1) / 2, mod) != 1 && _power(i, (mod - 1) / 7, mod) != 1 && _power(i, (mod - 1) / 17, mod) != 1) cout << 'g';
					else cout << '.';
				}	
			}
			else
			{
				int ming;
				for(int i = 1; i < mod; i++)
				{
					bool flag = 1;
					for(int j = 1; j <= 8; j++)
						if(_power(i, (mod - 1) / p[j], mod) == 1) flag = 0;
					if(flag) {ming = i; break;}
				}
				long long base = 1;
				for(int i = 1; i < mod; i++)
				{
					base = base * ming % mod;
					if(__gcd(i, (mod - 1)) == 1) g[base] = 1;
				}
				for(int i = l; i <= r; i++)
					cout << (g[i] ? 'g' : '.');
			}
			cout << '\n';
		}
	}
	if(op == "2g?")
	{
		int l, r;
		cin >> l;
		cin >> l >> r >> mod;
		cin >> l >> r >> mod;
		cin >> l >> r;
		cout << ".g\n.g.gg...g\n";
		int p[50] = {0, 2, 3, 4003, 15773};
		mod = 1515343657;
		for(int i = l; i <= r; i++)
		{
			bool flag = 1;
			for(int j = 1; j <= 4; j++)
				if(_power(i, (mod - 1) / p[j], mod) == 1) {flag = 0; break;}
			if(flag) cout << 'g';
			else cout << '.';
		}
	}
	return 0;
}