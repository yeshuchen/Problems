#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e7 + 5;
int n, m, cnt;
int past[N], ch[N][2];
int a[N], root[N];
inline int change(int v, int x, int ps)
{
    int node = ++cnt;
    int rt = node;
    for(int i = 30; i >= 0; i--)
    {
        if(x & (1 << i))
        {
            ch[node][1] = ++cnt;
            ch[node][0] = ch[v][0];
            node = ch[node][1];
            v = ch[v][1];
        }
        else
        {
            ch[node][0] = ++cnt;
            ch[node][1] = ch[v][1];  
            node = ch[node][0];
            v = ch[v][0];
        }
        past[node] = ps;
    }
    return rt;
}
inline int ask(int l, int r, int x)
{
    int ans = 0;
    int node = root[r - 1];
    for(int i = 30; i >= 0; i--)
    {
        if(x & (1 << i))
        {
            if(past[ch[node][0]] >= l - 1 && ch[node][0]) node = ch[node][0], ans += (1 << i);
            else node = ch[node][1];
        }
        else
        {
            if(past[ch[node][1]] >= l - 1 && ch[node][1]) node = ch[node][1], ans += (1 << i);
            else node = ch[node][0];
        }
    }    
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i], a[i] ^= a[i - 1];
    root[0] = change(0, 0, 0);
    for(int i = 1; i <= n; i++)
        root[i] = change(root[i - 1], a[i], i);
    for(int i = 1; i <= m; i++)
    {
        char op;
        int l, r, x;
        cin >> op;
        if(op == 'A')
        {
            cin >> x; n++;
            a[n] = x ^ a[n - 1];
            root[n] = change(root[n - 1], a[n], n);
        }
        else    
        {
            cin >> l >> r >> x;
            cout << ask(l, r, x ^ a[n]) << '\n';
        }
    }
    return 0;
}