#include <bits/stdc++.h>

using namespace std;

int n, m, a[130][130], f[130][130], ans = 1, pos;

void bfs(int x, int y){
	if(f[x][y] != -1) return ;
	//cout << x << " " << y << '\n';
	if(a[x + 1][y] > a[x][y] 
	&& a[x - 1][y] > a[x][y]
	&& a[x][y + 1] > a[x][y] 
	&& a[x][y - 1] > a[x][y]){
		f[x][y] = 1;
		return ;
	}
	int mina = min(a[x + 1][y], min(a[x - 1][y], min(a[x][y + 1], a[x][y - 1])));
	if(a[x + 1][y] == mina){
		bfs(x + 1, y);
		f[x][y] = f[x + 1][y] + 1;
		return ;
	}
	if(a[x - 1][y] == mina){
		bfs(x - 1, y);
		f[x][y] = f[x - 1][y] + 1;
		return ;
	}
	if(a[x][y + 1] == mina){
		bfs(x, y + 1);
		f[x][y] = f[x][y + 1] + 1;
		return ;
	}
	if(a[x][y - 1] == mina){
		bfs(x, y - 1);
		f[x][y] = f[x][y - 1] + 1;
		return ;
	}

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("Bila.inp", "r", stdin);
	freopen("Bila.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) cin >> a[i][j];

	for(int i = 1; i <= n; i++){
		a[i][0] = 1e9;
		a[i][m + 1] = 1e9;
	}
	for(int i = 1; i <= m; i++){
		a[0][i] = 1e9;
		a[n + 1][i] = 1e9;
	}

	memset(f, 255, sizeof(f));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			bfs(i, j);
			if(ans < f[i][j]){
				ans = f[i][j];
				pos = a[i][j];
			}
			else if(ans == f[i][j]) pos = min(pos, a[i][j]);
		}
	}
	cout << ans << " " << pos;
}