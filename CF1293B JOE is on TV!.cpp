#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double ans = 0.0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        ans += 1.0 / (n - i + 1);
    cout << ans;
}