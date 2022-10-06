#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, cnt;
int ed[N], fa[N];
int ch[N][26];
inline void insert(string s)
{
    int node = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(!ch[node][s[i] - 'a']) ch[node][s[i] - 'a'] = ++cnt;
        node = ch[node][s[i] - 'a'];
    }
    ed[node]++;
}
inline void build()
{
    queue<int> q;
    for(int i = 0; i < 26; i++)
        if(ch[0][i])
            q.push(ch[0][i]);
    while(!q.empty())
    {
        int t = q.front(); q.pop();
        for(int i = 0; i < 26; i++)
        {
            if(ch[t][i]) fa[ch[t][i]] = ch[fa[t]][i], q.push(ch[t][i]);
            else ch[t][i] = ch[fa[t]][i];
        }
    }
}
int p, ans;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        insert(s);
    } 
    cin >> s; build();
    for(int i = 0 ; i < s.size(); i++)
    {
        int tmp = p = ch[p][s[i] - 'a'];
        while(ed[tmp] != -1) ans += ed[tmp], ed[tmp] = -1, tmp = fa[tmp];
    }
    cout << ans;
    return 0;
}