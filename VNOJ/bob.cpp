#include <bits/stdc++.h>

using namespace std;

int n, m, a[1005][1005], cnt_row[1005][1005], cnt_col[1005][1005], it[8005];

long long s[1005][1005];

void update (int node, int l, int r, int val, int pos) {
	if (pos < l || pos > r) return ;
	//cout << l << " " << r << " " << it[node] << " " << val << '\n';
	it[node] = min(it[node], val);
	if (l == r) return;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, val, pos);
	update(node * 2 + 1, mid + 1, r, val, pos);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u || l > r) return n + 1;
	if (u <= l && r <= v) return it[node];
	//cout << l << " " << r << " " << it[node] << '\n';
	int mid = (l + r) / 2;
	return min(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v)); 
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) cin >> a[i][j];

	for (int i = 1; i <= n; i++) a[i][m + 1] = a[i][0] = 1e9 + 7;
	for (int i = 1; i <= m; i++) a[n + 1][i] = a[0][i] = 1e9 + 7;

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j --) {
			if (a[i][j] == a[i][j + 1]) cnt_row[i][j] = cnt_row[i][j + 1] + 1;
			else cnt_row[i][j] = 1;
			//cout << i << " " << j << " " << cnt_row[i][j] << '\n';
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == a[i - 1][j]) cnt_col[i][j] = cnt_col[i - 1][j] + 1;
			else cnt_col[i][j] = 1;
		}
	}
	long long ans = 0;
	for (int j = 1; j <= m; j++) {
		int r;
		for (int i = 1; i <= 8 * n; i++) it[i] = n + 1;
		for (int i = n; i >= 1; i--) {
			if (a[i][j] != a[i + 1][j]) r = i;
			
			int tam = query(1, 1, n, 1, cnt_row[i][j] - 1);
			if (tam <= r) s[i][j] = cnt_row[i][j] * (tam - i) + s[tam][j]; 
			else s[i][j] = cnt_row[i][j] * (r - i + 1);
			//cout << j << " " << i << " " << r << " " << tam << " " << s[i][j] << '\n';
			ans += s[i][j];
			update(1, 1, n, i, cnt_row[i][j]);
		}
	}
	cout << ans;
}

