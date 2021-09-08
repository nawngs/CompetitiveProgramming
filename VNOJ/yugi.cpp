#include <bits/stdc++.h>

using namespace std;

struct Dsu {
	vector < int > par;
	void init(int n) {
		par.resize(n + 5, 0);
		for (int i = 1; i <= n; i++) par[i] = -1;
	}
	int find_root(int u) {
		return par[u] < 0 ? u : par[u] = find_root(par[u]);
	}
	bool join(int u, int v) {
		int root_u = find_root(u);
		int root_v = find_root(v);
		if (root_u == root_v) return false;
		if (par[root_u] < par[root_v]) swap(par[root_u], par[root_v]);
		par[root_v] += par[root_u];
		par[root_u] = root_v;
		return true;
	}
} dsu;

int n, k, a[205][205];

bool calc (int x) {
	dsu.init(n);
	int cnt = n;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i][j] < x && dsu.join(i, j)) {
				//join(i, j);
				cnt --;
			}  
		}
	}
	return cnt >= k;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) cin >> a[i][j];

	int l = 0, r = 32767, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		bool temp = calc(mid);
		if (temp) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
}