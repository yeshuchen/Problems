#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, a[1005];
int f[31][31][31][31][31];
inline int dfs(int i, int j, int k, int l, int p)
{
    if(!i && !j && !k && !l && !p) return 1;
    int t = f[i][j][k][l][p];
    if(t) return t;
    if(i > j) t += dfs(i - 1, j, k, l, p);
    if(j > k) t += dfs(i, j - 1, k, l, p);
    if(k > l) t += dfs(i, j, k - 1, l, p);
    if(l > p) t += dfs(i, j, k, l - 1, p);
    if(p) t += dfs(i, j, k, l, p - 1);
    f[i][j][k][l][p] = t;  
    return t;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(cin >> n)
    {
        if(!n) break;
        memset(f, 0, sizeof(f));
        a[1] = a[2] = a[3] = a[4] = a[5] = 0;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        dfs(a[1], a[2], a[3], a[4], a[5]);
        cout << f[a[1]][a[2]][a[3]][a[4]][a[5]] << '\n';
    }
    return 0;
}