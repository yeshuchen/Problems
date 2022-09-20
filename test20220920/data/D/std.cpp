#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace fast_IO {
 const int IN_LEN = 50000000, OUT_LEN = 50000000;
 char ibuf[IN_LEN], obuf[OUT_LEN], *ih = ibuf + IN_LEN, *oh = obuf;
 char *lastin = ibuf + IN_LEN;
 const char *lastout = ibuf + OUT_LEN - 1;
 inline char getchar_() {
 if (ih == lastin)lastin = ibuf + fread(ibuf, 1, IN_LEN, stdin), ih = ibuf;
 return (*ih++);
 }
 inline void putchar_(const char x) {
 if (ih == lastout)fwrite(obuf, 1, oh - obuf, stdout), oh = obuf;
 *oh++ = x;
 }
 inline void flush() { fwrite(obuf, 1, oh - obuf, stdout); }
}
using namespace fast_IO;
#define getchar() getchar_()
#define putchar(x) putchar_((x))
inline int read () {
 int ret = 0; char c = getchar();
 while (c < '0' || c > '9') c = getchar();
 while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
 return ret;
}
void out (int x) { if (x >= 10) out(x / 10); putchar(x % 10 + '0'); }
const int MAXN = 3e5 + 10;
int n, m;
multiset<int> a_big[MAXN], a_small[MAXN];
multiset<int> big, small;
int maxt, ans;
void add(int x) {
if(big.size() < n) {
big.insert(x);
ans += x;
} else {
int mmin = *big.begin();
if(x > mmin) {
ans -= mmin; ans += x;
small.insert(mmin);
big.erase(big.begin());
big.insert(x);
} else {
small.insert(x);
}
}
}
void del(int x) {
if(big.find(x) != big.end()) {
ans -= x;
big.erase(big.find(x));
if(!small.empty()) {
auto it = small.end(); it--;
int mmax = *it;
small.erase(it);
big.insert(mmax);
ans += mmax;
}
} else {
small.erase(small.find(x));
}
}
signed main() {
n = read(); m = read();
for(int i = 1; i <= m; i++) {
int op = 0;
char ch = getchar();
while(ch < 'A' || ch > 'Z') ch = getchar();
if(ch == 'B') op = 1;
else if(ch == 'R') op = 2;
int t = read(), p = read(); maxt = max(maxt, t);
if(op == 1) {
if(a_big[t].size() < t) {
a_big[t].insert(p);
add(p);
} else {
int mmin = *a_big[t].begin();
if(p > mmin) {
del(mmin);
a_small[t].insert(mmin);
a_big[t].erase(a_big[t].begin());
add(p);
a_big[t].insert(p);
} else {
a_small[t].insert(p);
}
}
} else {
if(a_big[t].find(p) != a_big[t].end()){
a_big[t].erase(a_big[t].find(p));
del(p);
if(!a_small[t].empty()) {
auto it = a_small[t].end(); it--;
int mmax = *it;
a_small[t].erase(it);
a_big[t].insert(mmax);
add(mmax);
}
} else {
a_small[t].erase(a_small[t].find(p));
}
}
out(ans); putchar('\n');
}
flush();
return 0;
}
