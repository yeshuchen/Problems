#include<bits/stdc++.h>
using namespace std;
char s[1000006], t[1000006];
int nxt[1000006];
int main()
{
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    int n = strlen(s + 1);
    int m = strlen(t + 1);
    for(int i = 2; i <= m; i++)
    {
        int w = nxt[i - 1];
        while(w && t[w + 1] != t[i])w = nxt[w];
        nxt[i] = (t[w + 1] == t[i] ? w + 1 : 0);
    }
    int p = 0;
    for(int i = 1; i <= n; i++)
    {
        while(p && s[i] != t[p + 1]) p = nxt[p];
        if(t[p + 1] == s[i])p++;
        if(p == m)
            cout << i - m + 1 << '\n';
    }
    for(int i = 1; i <= m; i++)
        cout << nxt[i] << ' ';
    return 0;
}