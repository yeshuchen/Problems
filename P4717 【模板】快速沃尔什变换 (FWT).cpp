#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5, mod = 998244353;
int n;
ll a[N], b[N], A[N], B[N];
int ksm(ll a, int b)
{
	ll base = 1;
	while(b)
	{
		if(b & 1) base = base * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return base;
}
void init() {for(int i = 0; i < n; i++) a[i] = A[i], b[i] = B[i];}
void get() {for(int i = 0; i < n; i++) a[i] = a[i] * b[i] % mod;}
void OR(ll *f, int x = 1)
{
	for(int o = 2, k = 1; o <= n; o <<= 1, k <<= 1)
		for(int i = 0; i < n; i += o)
			for(int j = 0; j < k; j++)
				f[i + j + k] = (f[i + j + k] + f[i + j] * x % mod) % mod;
}
void AND(ll *f, int x = 1)
{
	for(int o = 2, k = 1; o <= n; o <<= 1, k <<= 1)
		for(int i = 0; i < n; i += o)
			for(int j = 0; j < k; j++)
				f[i + j] = (f[i + j] + f[i + j + k] * x % mod) % mod;
}
void XOR(ll *f, int x = 1)
{
	for(int o = 2, k = 1; o <= n; o <<= 1, k <<= 1)
		for(int i = 0; i < n; i += o)
			for(int j = 0; j < k; j++)
			{
				f[i + j] = (f[i + j] + f[i + j + k]) % mod;
				f[i + j + k] = ((f[i + j] - f[i + j + k] - f[i + j + k]) % mod + mod) % mod;
				f[i + j] = (f[i + j] * x) % mod; f[i + j + k] = (f[i + j + k] * x) % mod;
			}
}			
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; n = (1 << n);
	for(int i = 0; i < n; i++) cin >> A[i];
	for(int i = 0; i < n; i++) cin >> B[i];
	init(); OR(a); OR(b); get(); OR(a, mod - 1);
	for(int i = 0; i < n; i++) cout << a[i] << (i == n - 1 ? '\n' : ' ');
	init(); AND(a); AND(b); get(); AND(a, mod - 1);
	for(int i = 0; i < n; i++) cout << a[i] << (i == n - 1 ? '\n' : ' ');
	init(); XOR(a); XOR(b); get(); XOR(a, ksm(2, mod - 2));
	for(int i = 0; i < n; i++) cout << a[i] << ' ';
	return 0;
}