#include<bits/stdc++.h>
using namespace std;
int k, f[2005][2005];
char s[2005], t[2005];
int main()
{
    scanf("%s%s", s + 1, t + 1);
    cin >> k;
    int n = strlen(s + 1);
    int m = strlen(t + 1);
    for(int i = 1; i <= n; i++)
        f[i][0] = f[i - 1][0] + k;
    for(int i = 1; i <= m; i++)
        f[0][i] = f[0][i - 1] + k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            f[i][j] = min(min(f[i - 1][j] + k, f[i][j - 1] + k), f[i - 1][j - 1] + abs(s[i] - t[j]));
    cout << f[n][m];
    return 0;
}
//设f[i][j]表示A[1-i]和B[1-j]的最小距离