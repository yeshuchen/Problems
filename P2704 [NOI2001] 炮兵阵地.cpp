#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans;
int f[105][105][105];
int tot, temp[105];
char ch[505][505];
inline int c(int x)
{
    int res = 0;
    while(x)
    {
        x -= (x & -x);
        res++;
    }
    return res;
}
inline bool ck(int w){return ((w << 1) & w) || ((w << 2) & w) || ((w >> 1) & w) || ((w >> 2) & w);}
inline bool check(int x, int y){return !(x & y);}
inline bool chec(int x, int row)
{
    for(int i = 0; i < m; i++)
        if(x & (1 << i) && ch[row][i + 1] == 'H')
            return true;
    return false;
}
signed main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> ch[i][j];
    for(int i = 0; i < (1 << m); i++)
        if(!ck(i)) temp[++tot] = i;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= tot; j++)
        {
            if(chec(temp[j], i - 2)) continue;
            for(int k = 1; k <= tot; k++)
            {
                if(chec(temp[k], i - 1)) continue;
                for(int l = 1; l <= tot; l++)
                {
                    if(chec(temp[l], i)) continue;
                    if(!check(temp[j], temp[k]) || !check(temp[k], temp[l]) || !check(temp[j], temp[l])) continue;
                    f[i][l][k] = max(f[i][l][k], f[i - 1][k][j] + c(temp[l]));
                }
            }
        }
    for(int i = 1; i <= tot; i++)
        for(int j = 1; j <= tot; j++)
            ans = max(ans, f[n][j][i]);
    cout << ans;
}