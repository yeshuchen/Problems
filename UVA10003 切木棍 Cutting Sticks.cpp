#include<bits/stdc++.h>
using namespace std;
int n, k;
int p[55];
int f[105][105];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(cin >> n)
    {
        if(!n) break;
        cin >> k;
        for(int i = 1; i <= k; i++)
            cin >> p[i], f[i][i + 1] = 0;
        p[k + 1] = n;
        f[0][1] = 0;
        for(int len = 2; len <= k + 1; len++)
            for(int i = 0; i <= k + 1; i++)
            {
                int j = i + len;
                if(j > k + 1) break;
                int minn = INT_MAX;
                for(int l = i + 1; l < j; l++)
                    minn = min(minn, f[i][l] + f[l][j]);
                f[i][j] = minn + p[j] - p[i];
            }
        cout << "The minimum cutting is " << f[0][k + 1] << ".\n";
    }
    return 0;
}