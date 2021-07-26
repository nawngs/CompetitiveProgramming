#include <bits/stdc++.h>

using namespace std;

int m, n, a[1005][1005], lu[1005][1005], ru[1005][1005], ld[1005][1005], rd[1005][1005], ans = 0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("HT.INP", "r", stdin);
	freopen("HT.OUT", "w", stdout);
	cin >> m >> n;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++) cin >> a[i][j];

	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			if(a[i][j] == 1) lu[i][j] = min(lu[i - 1][j], lu[i][j - 1]) + 1;
	
	for(int i = m; i >= 1; i--)
		for(int j = 1; j <= n; j++)
			if(a[i][j] == 1) ld[i][j] = min(ld[i + 1][j], ld[i][j - 1]) + 1;

	for(int i = 1; i <= m; i++)
		for(int j = n; j >= 1; j--) 
			if(a[i][j] == 1) ru[i][j] = min(ru[i - 1][j], ru[i][j + 1]) + 1;

	for(int i = m; i >= 1; i--)
		for(int j = n; j >= 1; j --)
			if(a[i][j] == 1) rd[i][j] = min(rd[i + 1][j], rd[i][j + 1]) + 1;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) 
			if(a[i][j] == 1) ans = max(ans, min(lu[i][j], min(ld[i][j], min(ru[i][j], rd[i][j]))));

	cout << ans - 1;
}