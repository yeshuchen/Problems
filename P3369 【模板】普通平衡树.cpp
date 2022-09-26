#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, cnt;
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
    cin >> n;
    insert(0); insert(INT_MAX);
    while(n--)
    {
        int op, x;
        cin >> op >> x;
        if(op == 1) insert(x + maxn);
        if(op == 2) del(x + maxn);
        if(op == 3) cout << askrank(x + maxn) << '\n';
        if(op == 4) cout << Rank(x) - maxn << '\n';
        if(op == 5) cout << Rank(askrank(x + maxn) - 1) - maxn << '\n';
        if(op == 6) cout << Rank(askrank(x + maxn + 1)) - maxn << '\n';
    }
    return 0;
}