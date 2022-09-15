#include<bits/stdc++.h>
using namespace std;
int n, m;
int f[1005][1005];
int a[105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    for(int len = 2; len <= n; len++)
        for(int i = 1; i <= n; i++)
        {
            int j = i + len - 1, flag = 1;
            if(j > n)continue;
            for(int k = 1; k <= m; k++)
                if(a[k] >= i && a[k] <= j)
                {
                    if(flag)f[i][j] = 1145141919, flag = 0;
                    f[i][j] = min(f[i][j], f[i][a[k] - 1] + f[a[k] + 1][j] + len - 1);
                }
        }
    cout << f[1][n];
    return 0;
}
//设f[i][j]为在[i,j]区间内的最少人次