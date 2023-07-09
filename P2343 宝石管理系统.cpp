#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, m, cnt;
int ch[N][2];
int tot[N];
void insert(int x)
{
    int node = 0;
    for(int i = 30; i >= 0; i--)
    {
        bool p = (x & (1 << i));
        if(!ch[node][p])
            ch[node][p] = ++cnt; 
        node = ch[node][p];
        tot[node]++;
    }
}
void del(int x)
{
    int node = 0;
    for(int i = 30; i >= 0; i--)
    {
        bool p = (x & (1 << i));
        node = ch[node][p];
        tot[node]--;
    }
}
int askrank(int x)
{
    int node = 0, ans = 0;
    for(int i = 30; i >= 0; i--)
    {
        bool p = (x & (1 << i));
        if(p) ans += tot[ch[node][0]];
        if(!ch[node][p]) break;
        node = ch[node][p];
    }
    return ans;
}
const int maxn = 1e7 + 1;
int Rank(int x)
{
    int node = 0, ans = 0;
    x++;
    for(int i = 30; i >= 0; i--)
    {
        if(tot[ch[node][0]] < x) x -= tot[ch[node][0]], node = ch[node][1], ans += (1 << i);
        else node = ch[node][0];
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    insert(0); insert(INT_MAX);
	for(int i = 1, x; i <= n; i++)
		cin >> x, insert(x);
    for(int i = 1; i <= m; i++)
    {
        int op, x;
        cin >> op >> x;
		if(op == 1) cout << Rank(n - x + 1) << '\n';
        if(op == 2) insert(x), n++;
    }
    return 0;
}