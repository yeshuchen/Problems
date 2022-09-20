#include <bits/stdc++.h>

using namespace std;

#define lep(i, l, r) for(int i = (l); i <= (r); i ++)
#define rep(i, l, r) for(int i = (l); i >= (r); i --)
#define Lep(i, l, r) for(int i = (l); i <  (r); i ++)
#define Rep(i, l, r) for(int i = (l - 1); i >= (r); i --)
#define debug(...) fprintf (stderr, __VA_ARGS__)
#define pb push_back
#define fi first
#define se second
#define gc getchar
#define pc putchar

using i64 = long long;
using uint = unsigned int;
using ui64 = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;

template<typename A, typename B>
inline void Min(A &x, B y) { x = x < y ? x : y; }
template<typename A, typename B>
inline void Max(A &x, B y) { x = x > y ? x : y; }
template<typename T> inline void read(T &x) {
	x = 0; char a = gc(); bool f = 0;
	for (; ! isdigit(a); a = gc()) if (a == '-') f = 1;
	for (; isdigit(a); a = gc()) x = x * 10 + a - '0';
	if (f) x = -x;
}

const int P = 998244353;
inline int mod(int x) { return x + (x >> 31 & P); }
inline void sub(int &x, int y) { x = mod(x - y); }
inline void pls(int &x, int y) { x = mod(x + y - P); }
inline int add(int x, int y) { return mod(x + y - P); }
inline int dec(int x, int y) { return mod(x - y); }
inline int power(int x, int k) {
	int res = 1; if (k < 0) k += P - 1;
	while (k) { if (k & 1) res = 1ll * res * x % P; x = 1ll * x * x % P; k >>= 1; }
	return res;
}

const int Case = 10; /// Modified

template<typename in_value, typename out_type>
out_type convert(const in_value & t){
	stringstream stream;
	stream << t; out_type result; stream >> result; return result;
}

string makein(int x) { return "data/" + convert<int, string> (x) + ".in"; }
string makeout(int x) { return "data/" + convert<int, string> (x) + ".out"; }

