#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int ch[N][15], t[N];
int T, cnt;
void insert(string s)
{
    int pos = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(!ch[pos][s[i] - '0'])
            ch[pos][s[i] - '0'] = ++cnt;
        pos = ch[pos][s[i] - '0'];
        t[pos]++;
    }
}
bool ask(string s)
{
    int pos = 0;
    for(int i = 0; i < s.size(); i++)
        pos = ch[pos][s[i] - '0'];
    if(t[pos] > 1) return true;
    else return false;
}
string s[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n; cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> s[i];
            insert(s[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            if(ask(s[i]))
            {
                cout << "NO\n";
                goto end;
            }
        }
        cout << "YES\n";
        end:;
        for(int i = 1; i <= cnt; i++) t[i] = 0;
        for(int i = 0; i <= cnt; i++)
            for(int j = 0; j <= 9; j++)
                ch[i][j] = 0;
    }
    return 0;
}