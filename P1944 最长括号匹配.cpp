#include<bits/stdc++.h>
using namespace std;
int maxn;
int f[1000005];
int main()
{
    string s;
    cin >> s;
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '[')
        {
            f[i] = 0;
            continue;
        }
        if(s[i] == ')' && s[i - 1 - f[i - 1]] == '(' || s[i] == ']' && s[i - 1 - f[i - 1]] == '[') f[i] = max(f[i], f[max(i - 2 - f[i - 1], 0)] + f[i - 1] + 2);
    }
    for(int i = 1; i < s.size(); i++)
        maxn = max(maxn, f[i]);
    for(int i = 1; i < s.size(); i++)
        if(f[i] == maxn)
        {
            for(int j = i - maxn + 1; j <= i; j++)
                cout << s[j];
            return 0;
        }
}
//f[i]表示以i结尾的最长括号匹配的长度