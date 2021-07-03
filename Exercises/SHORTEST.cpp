//bfs
#include <bits/stdc++.h>
#define pii pair< int , int >
#define fi first
#define se second

using namespace std;

const int x[4] = {-1, 0, 0, 1};
const int y[4] = {0, -1, 1, 0};
int n, m, a[1005][1005], d[1005][1005];

int bfs(){
	queue < pii > que;
	d[1][1] = 1;
	que.push({1, 1});
	while(que.size() > 0){
		pii u = que.front();
		que.pop();
		for(int i = 0; i < 4; i++){
			int newx = u.fi + x[i];
			int newy = u.se + y[i];
			if(newx > 0 && newy > 0 && newx <= n && newy <= m && d[newx][newy] == -1 && a[newx][newy] != 1){
				d[newx][newy] = d[u.fi][u.se] + 1;
				que.push({newx, newy});
			}
		}
	}
	return d[n][m];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("SHORTEST.INP", "r", stdin);
	freopen("SHORTEST.OUT", "w", stdout);
	memset(d, 255, sizeof(d));
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) cin >> a[i][j];
	cout << bfs() << '\n';
}