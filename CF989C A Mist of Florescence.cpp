#include<bits/stdc++.h>
using namespace std;
int a, b, c, d;
char ch[55][55];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> c >> d;
	cout << 36 <<' ' << 50 <<'\n';
	a--; b--; c--; d--;
    for(int i = 1; i <= 36; i++)
        for(int j = 1; j <= 50; j++)
            ch[i][j] = (i - 1) / 9 + 'A';
	for(int i = 11; i <= 17; i += 2)
		for(int j = 2; j <= 50; j += 2)
		{
			if(!a) break;
			ch[i][j] = 'A';
			a--;
		}
	for(int i = 20; i <= 26; i += 2)
		for(int j = 2; j <= 50; j += 2)
		{
			if(!b) break;
			ch[i][j] = 'B';
			b--;
		}
	for(int i = 29; i <= 35; i += 2)
		for(int j = 2; j <= 50; j += 2)
		{
			if(!c) break;
			ch[i][j] = 'C';
			c--;
		}
	for(int i = 2; i <= 8; i += 2)
		for(int j = 2; j <= 50; j += 2)
		{
			if(!d) break;
			ch[i][j] = 'D';
			d--;
		}
	for(int i = 1; i <= 36; i++)
    {
        for(int j = 1; j <= 50; j++)
            cout << ch[i][j];
        cout << '\n';
    }
    return 0;
}