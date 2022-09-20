#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> g;
int n, m;
struct node{
    int x, w;
}a[100005];
int beiyong[100005];
int ans, b[100005], c[100005];
inline bool cmp(node x, node y){return x.x < y.x;}
inline bool cmp1(node x, node y){return x.w < y.w;}
inline void add(int x, int k)
{
    while(x <= n)
    {
        c[x] += k;
        x += (x & -x);
    }
}
inline void add2(int x,int k){while(x <= n) beiyong[x]+=k, x += (x & -x);}
inline int ask(int x)
{
    int res = 0;
    while(x) res += c[x], x -= (x & -x);
    return res;
}
inline int ask2(int x){int res = 0; while(x) res += beiyong[x], x -= (x & -x); return res;}
void DEL(int p)
{
    int val = a[p].w;
    int w = lower_bound(b + 1, b + n + 1, val) - b;
    add(w, -val); add2(w, -1);
}
signed main()
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].w;
    sort(a + 1, a + n + 1, cmp);
    int pos = n;
    for(int i = 1; i <= n; i++)
        if(a[i].x > m)
        {
            pos = i - 1;
            break;
        }
    for(int i = 1; i <= pos; i++)
        b[i] = a[i].w;
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= pos; i++)
        add(i, b[i]), add2(i, 1);
    for(int i = pos; i; i--)
    {
        int l = 1, r = n, sh = m - a[i].x;
        while(l <= r)
        {
            int mid = l + r >> 1;
            if(ask(mid) > sh) r = mid - 1;
            else l = mid + 1;
        }
        ans = max(ans, ask2(l - 1));
        DEL(i);
    }
    cout << ans << '\n';
    return 0;
}
/*
贪心+排序
树状数组维护即可
*/