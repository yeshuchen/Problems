#include<bits/stdc++.h>
using namespace std;
int T;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> s;
        int r1 = s.find('r'), r2 = s.find('R');
        int g1 = s.find('g'), g2 = s.find('G');
        int b1 = s.find('b'), b2 = s.find('B');
        if(r1 > r2 || g1 > g2 || b1 > b2)cout << "NO\n";
        else cout << "YES\n";

    }
    return 0;
}