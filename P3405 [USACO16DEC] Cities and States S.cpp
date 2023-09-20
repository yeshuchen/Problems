#include<bits/stdc++.h>
#define int long long
using namespace std;
int vis[676][676], n, ans;
signed main() {
    string a, b;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        int x = (a[0] - 'A') * 26 + a[1] - 'A';
        int y = (b[0] - 'A') * 26 + b[1] - 'A';
        if (x != y) vis[x][y]++;
    }
	for(int i = 0; i <= 675; i++)
		for(int j = 0; j <= 675; j++)
			ans += vis[i][j] * vis[j][i];
    cout << ans / 2;
    return 0;
}
