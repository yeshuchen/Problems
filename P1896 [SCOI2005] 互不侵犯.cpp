#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, k, ans;
int f[10][1024][105];
inline int c(int x)
{
    int res = 0;
    for(int i = 0; i < n; i++)
        if(x & (1 << i))
            res++;
    return res;
}
int K;
inline bool ck(int x){return !(((x << 1) & x) || ((x >> 1) & x));}
inline bool check(int x, int y){return (((x << 1) & y) || ((x >> 1) & y) || (x & y));}
signed main()
{
    cin >> n >> K;
    for(int i = 0; i < (1 << n); i++)
    {  
        if(ck(i))
            f[1][i][c(i)] = 1;
    }
    for(int i = 2; i <= n; i++)
        for(int j = 0; j < (1 << n); j++)
            for(int k = 0; k < (1 << n); k++)
            {
                if(check(j, k) || !ck(j) || !ck(k)) continue;
                for(int l = K; l >= c(j) + c(k); l--)
                    f[i][k][l] += f[i - 1][j][l - c(k)];
            }
    for(int i = 0; i < (1 << n); i++)
        ans += f[n][i][K];
    cout << ans;
    return 0;
}