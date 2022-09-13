#include<bits/stdc++.h>
using namespace std;
char s[100005];
int f[1005][1005];
int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for(int i = 1; i <= n; i++)
        f[i][i] = 0;
    for(int i = 1; i < n; i++)
        f[i][i + 1] = (s[i] != s[i + 1]);
    for(int len = 3; len <= n; len++)
        for(int l = 1; l <= n; l++)
        {
            int r = l + len - 1;
            if(r > n)break;
            f[l][r] = min(f[l][r - 1], f[l + 1][r]) + 1;
            if(s[l] == s[r]) f[l][r] = min(f[l][r], f[l + 1][r - 1]);
            else f[l][r] = min(f[l][r], f[l + 1][r - 1] + 2);
        }
    cout << f[1][n];
    return 0;
}