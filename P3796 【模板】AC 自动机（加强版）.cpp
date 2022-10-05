#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
int n, cnt;
string S[N];
int ch[N][26];
int f[N], c[N], ed[N];
inline void insert(string s, int id)
{
    int p = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(!ch[p][s[i] - 'a']) ch[p][s[i] - 'a'] = ++cnt;
        p = ch[p][s[i] - 'a'];
    }
    ed[p] = id;
}
inline void build()
{
    queue<int> q;
    for(int i = 0; i < 26; i++)
        if(ch[0][i])
            q.push(ch[0][i]);
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        for(int i = 0; i < 26; i++)
        {
            if(ch[x][i]) f[ch[x][i]] = ch[f[x]][i], q.push(ch[x][i]);
            else ch[x][i] = ch[f[x]][i];
        }
    }
}
int main()
{
    while(cin >> n)
    {
        string s;
        int ans = 0;
        if(!n) break;
        cnt = 0;
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        memset(ch, 0, sizeof(ch));
        memset(ed, 0, sizeof(ed));
        for(int i = 1; i <= n; i++)
            cin >> S[i], insert(S[i], i);
        cin >> s; build();
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int tmp = p = ch[p][s[i] - 'a'];
            while(tmp) c[ed[tmp]]++, tmp = f[tmp];
        }
        for(int i = 1; i <= n; i++) ans = max(ans, c[i]);
        cout << ans << '\n';
        for(int i = 1; i <= n; i++)
            if(c[i] == ans)
                cout << S[i] << '\n';
    }
    return 0;
}