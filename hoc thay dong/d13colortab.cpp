#include<bits/stdc++.h>

#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int m, n;

pii pre[55][55];

int a[55][55];

pii cnt[103];

vector < pair < pii, pii > > ans;

void bfs(int x, int y, int co) {
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) pre[i][j] = {-1, -1};
	pre[x][y] = {x, y};
	queue < pii > q;
	q.push({x, y});
	while (!q.empty()) {
		int i = q.front().fi, j = q.front().se; q.pop();
		if (a[i][j] == co && j > y) {
			//if (x == 2 && y ==4) cout << x << " " << y << " " << i << " " << j  << '\n';
			vector < pii > pos;
			pos.push_back({i, j});
			while (pos.back() != make_pair(x, y)) 
				pos.push_back(pre[pos.back().fi][pos.back().se]);
			reverse(pos.begin(), pos.end());
			for (int i = 0; i < pos.size() - 1; i++)
				ans.push_back({pos[i], pos[i + 1]});
			for (int i = pos.size() - 2; i > 0; i--)
				ans.push_back({pos[i], pos[i - 1]});
			swap(a[x][y], a[i][j]);
			return ;
		}
		for (int p = 0; p < 8; p++) {
			int newi = i + dx[p], newj = j + dy[p];
			if (newi < 1 || newj < 1 || newi > m || newj > n || pre[newi][newj] != make_pair(-1, -1)) continue;
			pre[newi][newj] = make_pair(i, j);
			q.push({newi, newj});
		}
	}
}

void solve() {
	cin >> m >> n;
	for (int i = 1; i <= 2 * n; i++) cnt[i] = {0, i};
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j]; cnt[a[i][j]].fi ++;
		}
	for (int col = 1; col < n; col++) {
		sort(cnt + 1, cnt + 2 * n + 1);
		bool th = false;
		for (int i = 1; i <= 2 * n; i++) {
			for (int j = i + 1; j <= 2 * n; j++) {
				if (cnt[i].fi + cnt[j].fi == m && cnt[i].fi != 0) {
					for (int p = 1; p <= m; p++) {
						if (a[p][col] == cnt[i].se) cnt[i].fi --;
						if (a[p][col] == cnt[j].se) cnt[j].fi --;
					}
					
					int p = 1;
					while (cnt[i].fi > 0) {
						while (a[p][col] == cnt[i].se || a[p][col] == cnt[j].se) p ++;
						bfs(p, col, cnt[i].se);
						cnt[i].fi --;
					}
					while (cnt[j].fi > 0) {
						while (a[p][col] == cnt[i].se || a[p][col] == cnt[j].se) p ++;
						bfs(p, col, cnt[j].se);
						cnt[j].fi --;
					}
					th = true;
					break;
				}
			}
			if (th) break;
		}
		if (th) continue;
		for (int i = 1; i <= 2 * n; i++) {
			if (cnt[i].fi + cnt[i + 1].fi + cnt[2 * n].fi > m && cnt[i].fi != 0 && cnt[i + 1].fi != 0) {
				for (int p = 1; p <= m; p++) {
					if (a[p][col] == cnt[i].se) cnt[i].fi --;
					if (a[p][col] == cnt[i + 1].se) cnt[i + 1].fi --;
				}
				int p = 1;
				while (cnt[i].fi > 0) {
					while (a[p][col] == cnt[i].se || a[p][col] == cnt[i + 1].se) p++;
					bfs(p, col, cnt[i].se);
					cnt[i].fi --;
				}
				while (cnt[i + 1].fi > 0) {
					while (a[p][col] == cnt[i].se || a[p][col] == cnt[i + 1].se) p++;
					bfs(p, col, cnt[i + 1].se);
					cnt[i + 1].fi --;
				}
				while (p <= m) {
					while (p <= m && (a[p][col] == cnt[i].se || a[p][col] == cnt[i + 1].se)) p++;
					if (p > m) break;
					if (a[p][col] == cnt[2 * n].se) {
						cnt[2 * n].fi --;
						p ++;
						continue;
					}
					if (p <= m) {
						bfs(p, col, cnt[2 * n].se);
						cnt[2 * n].fi --;
						p ++;
					}
				}
				break;
			}
		}
	}
	/*for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
		cout << '\n';
	}
	reverse(ans.begin(), ans.end());
	for (auto x : ans) {
		swap(a[x.fi.fi][x.fi.se], a[x.se.fi][x.se.se]);
	}*/
	// for (int i = 1; i <= m; i++) {
		// for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
		// cout << '\n';
	// }
	cout << ans.size() << '\n';
	for (auto x : ans) 
		cout << x.fi.fi << " " << x.fi.se << " " << x.se.fi << " " << x.se.se << '\n';
	ans.clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
}