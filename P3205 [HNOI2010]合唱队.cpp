#include<bits/stdc++.h>
using namespace std;
int n, a[1005];
int f[1006][1006][2];
const int mod = 19650827;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        f[i][i][0] = 1;
    for(int len = 2; len <= n; len++)
        for(int i = 1; i <= n; i++)
        {
            int j = i + len - 1;
            if(a[i] < a[i + 1]) f[i][j][0] += f[i + 1][j][0];
            if(a[i] < a[j]) f[i][j][0] += f[i + 1][j][1];
            if(a[j] > a[i]) f[i][j][1] += f[i][j - 1][0];
            if(a[j] > a[j - 1]) f[i][j][1] += f[i][j - 1][1];
            f[i][j][0] %= mod; f[i][j][1] %= mod;
        }
    cout << (f[1][n][0] + f[1][n][1]) % mod;
    return 0;
}
/*
f[i][j][0]表示第i人从左边进去的方案数
f[i][j][1]表示第j人从右边进去的方案数
*/