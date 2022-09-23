#include<bits/stdc++.h>
using namespace std;
long long T, n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n;
        if(n == 4 || n == 10) cout << n + 1 << '\n';
        else cout << n - 1 << '\n'; 
    }
    return 0;
}