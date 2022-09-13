#include<bits/stdc++.h>
using namespace std;
int n, k;
int f[105][105];
struct node{
    int h, w;
}a[10005];
inline bool cmp(node x, node y){return x.h < y.h;}
int main()
{
    cin >> n >> k;
    k = n - k;
    for(int i = 1; i <= n; i++)
        cin >> a[i].h >> a[i].w;
    sort(a + 1,a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
        f[i][1] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 2; j <= i; j++)
        {
            f[i][j] = INT_MAX;
            for(int k = j - 1; k < i; k++)
                f[i][j] = min(f[i][j], f[k][j - 1] + abs(a[i].w - a[k].w));
        }
    int ans = INT_MAX;
    for(int i = k; i <= n; i++)
        ans = min(ans, f[i][k]);
    cout << ans;
    return 0;
}
// f[i][j] 表示从前 i 本书里取 j 本，且必须选第 i 本书的最小不整齐度