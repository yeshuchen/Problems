#include<bits/stdc++.h>
using namespace std;
int T, n, x;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--)
    {
        bool flag = 0;
        cin >> n >> x;
        for(int i = 1; i <= n; i++)
        {
            int val;
            cin >> val;
            if(x % val != 0 || x / val > 0) flag = 1;
        }
        cout << (flag ? "Yes\n" : "No\n");
    }
    return 0;
}