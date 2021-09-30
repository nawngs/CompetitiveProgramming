#include <bits/stdc++.h>

#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

int n, m, a[1005][1005], f[1005][1005];

void bfs() {
	queue < pii > q;
	memset(f, 255, sizeof(f));
	f[1][1] = 0;
	q.push({1, 1});
	while (q.size()) {
		pii tam = q.front();
		q.pop();
		//cout << tam.fi << " " << tam.se << " " << f[tam.fi][tam.se] << '\n';
		if (a[tam.fi][tam.se] == 1) {
			for (int i = tam.fi - 1; i >= 1; i--) {
				if (f[i][tam.se] == -1) {
					f[i][tam.se] = f[tam.fi][tam.se] + 1;
					q.push({i, tam.se});
				}
				if (a[i][tam.se] == 1) break;
			}
			for (int i = tam.fi + 1; i <= n; i++) {
				if (f[i][tam.se] == -1) {
					f[i][tam.se] = f[tam.fi][tam.se] + 1;
					q.push({i, tam.se});
				}
				if (a[i][tam.se] == 1) break;
			}
			for (int i = tam.se - 1; i >= 1; i--) {
				if (f[tam.fi][i] == -1) {
					f[tam.fi][i] = f[tam.fi][tam.se] + 1;
					q.push({tam.fi, i});
				}
				if (a[tam.fi][i] == 1) break;
			}
			for (int i = tam.se + 1; i <= m; i++) {
				if (f[tam.fi][i] == -1) {
					f[tam.fi][i] = f[tam.fi][tam.se] + 1;
					q.push({tam.fi, i});
				}
				if (a[tam.fi][i] == 1) break;
			}
		}
		else {
			if (tam.fi > 1 && f[tam.fi - 1][tam.se] == -1) {
				f[tam.fi - 1][tam.se] = f[tam.fi][tam.se] + 1;
				q.push({tam.fi - 1, tam.se});
			}
			if (tam.fi < n && f[tam.fi + 1][tam.se] == -1) {
				f[tam.fi + 1][tam.se] = f[tam.fi][tam.se] + 1;
				q.push({tam.fi + 1, tam.se});
			}
			if (tam.se > 1 && f[tam.fi][tam.se - 1] == -1) {
				f[tam.fi][tam.se - 1] = f[tam.fi][tam.se] + 1;
				q.push({tam.fi, tam.se - 1});
			}
			if (tam.se < m && f[tam.fi][tam.se + 1] == -1) {
				f[tam.fi][tam.se + 1] = f[tam.fi][tam.se] + 1;
				q.push({tam.fi, tam.se + 1});
			}
		}
		if (f[n][m] != -1) {
			cout << f[n][m] << '\n';
			return;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	bfs();
}