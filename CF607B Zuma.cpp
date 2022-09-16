#include<bits/stdc++.h>
using namespace std;
int n;
int a[505];
int f[505][505];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        f[i][i] = 1;
    for(int len = 2; len <= n; len++)
        for(int i = 1; i <= n; i++)
        {
            int j = i + len - 1;
            if(j > n) break;
            f[i][j] = 1145141919;
            if(a[i] == a[j]) f[i][j] = max(f[i + 1][j - 1], 1);
            for(int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
        }
    cout << f[1][n];
    return 0;
}