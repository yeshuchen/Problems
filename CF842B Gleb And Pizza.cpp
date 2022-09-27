#include<bits/stdc++.h>
using namespace std;
int n, r, d, ans;
double di(int x, int y)
{
    return sqrt(x * x * 1.0 + y * y * 1.0);
}
int main()
{
    cin >> r >> d;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x, y, l;
        cin >> x >> y >> l;
        double dis = di(x, y);
        if(dis - l >= r - d && dis + l <= r) ans++;
    }
    cout << ans;
    return 0;
}