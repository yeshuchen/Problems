#include<bits/stdc++.h>
using namespace std;
int n, m, cnt;
int a[4][1000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[x][y] ^ 1;
        if(a[x][y])
        {
            if(x == 1) cnt += (a[x + 1][y] + a[x + 1][y - 1] + a[x + 1][y + 1]);
            else cnt += (a[x - 1][y] + a[x - 1][y - 1] + a[x - 1][y + 1]);
        }
        else
        {
            if(x == 1) cnt -= (a[x + 1][y] + a[x + 1][y - 1] + a[x + 1][y + 1]);
            else cnt -= (a[x - 1][y] + a[x - 1][y - 1] + a[x - 1][y + 1]);
        }
        if(!cnt) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}