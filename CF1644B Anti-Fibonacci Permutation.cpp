#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[10006];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            a[i] = n - i + 1;
        for(int i = 1; i <= n; i++)
            cout << a[i] << ' ';
        cout << '\n';
        for(int i = 2; i <= n; i++)
        {
            swap(a[i], a[i - 1]);
            for(int j = 1; j <= n; j++)
                cout << a[j] << ' ';
            swap(a[i], a[i - 1]);
            cout << '\n';
        }
    }
    return 0;
}