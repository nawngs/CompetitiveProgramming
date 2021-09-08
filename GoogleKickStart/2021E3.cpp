#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair < int, int >

using namespace std;


int t, n, m, l[1005][1005], r[1005][1005], up[1005][1005], d[1005][1005], ans;

string s[1005];

void bfs() {
	queue < pii > q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] != '.' && s[i][j] != '#') q.push({i, j});
		}
	}
	while (q.size()) {
		auto u = q.front();
		q.pop();
		pii pos1, pos2;
		pos1.fi = u.fi;
		pos1.se = r[u.fi][u.se] - (u.se - l[u.fi][u.se]);
		if (s[pos1.fi][pos1.se] == '.') {
			ans ++;
			s[pos1.fi][pos1.se] = s[u.fi][u.se];
			q.push(pos1);
		}
		pos2.fi = d[u.fi][u.se] - (u.fi - up[u.fi][u.se]);
		pos2.se = u.se; 
		if (s[pos2.fi][pos2.se] == '.') {
			ans ++;
			s[pos2.fi][pos2.se] = s[u.fi][u.se];
			q.push(pos2);
		}
	}
}

void sol(int pos) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
	}

	for (int i = 1; i <= n; i++) {
		l[i][1] = 1;
		r[i][m] = m;
	}

	for (int i = 1; i <= n; i++) 
		for (int j = 2; j <= m; j++) 
			l[i][j] = s[i][j - 1] == '#' ? j : l[i][j - 1];

	for (int i = 1; i <= n; i++) 
		for (int j = m - 1; j >= 1; j--) 
			r[i][j] = s[i][j + 1] == '#' ? j : r[i][j + 1];

	for (int i = 1; i <= m; i++) {
		up[1][i] = 1;
		d[n][i] = n;
	}

	for (int i = 1; i <= m; i++) 
		for (int j = 2; j <= n; j++) 
			up[j][i] = s[j - 1][i] == '#' ? j : up[j - 1][i];
	
	for (int i = 1; i <= m; i++) 
		for (int j = n - 1; j >= 1; j--) 
			d[j][i] = s[j + 1][i] == '#' ? j : d[j + 1][i];

	ans = 0;
	bfs();
	cout << "Case #" << pos << ": " << ans << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cout << s[i][j];
		cout << '\n';
	}
}

int main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		sol(i);
	}
}