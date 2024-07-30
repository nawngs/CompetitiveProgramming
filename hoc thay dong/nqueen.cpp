// [+] dinhmanhhungwillwinioi2024
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1003;

bool vs[N];

int a[N], row[N], col[N], n, m;

int cc[N], cp[N], ncp[N], ncc[N];

#define cc(x) cc[(x) + n + 1]
#define ncc(x) ncc[(x) + n + 1]

void solve() {
	m = 0;
	int num_cheo = n * 2;
	fill(vs + 1, vs + n + 1, false);
	fill(ncc + 2, ncc + n * 2 + 1, -1);
	fill(ncp + 2, ncp + n * 2 + 1, -1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i]) {
			vs[a[i]] = true;
			ncp[a[i] + i]++;
			ncc(a[i] - i)++;
		} else row[++m] = i;
	}
	for (int i = 1, p = 0; i <= n; i++)
		if (!vs[i]) col[++p] = i;
	while (true) {
		int collision = 0;
		for (int i = 2; i <= num_cheo; i++) 
			cc[i] = ncc[i], cp[i] = ncp[i];
		for (int i = 1; i <= m; i++) 
			++cp[col[i] + row[i]], ++cc(col[i] - row[i]);
		for (int i = 2; i <= num_cheo; i++) 
			collision += max(0, cc[i]) + max(0, cp[i]);
		
		if (collision == 0) break;
		while (true) {
			int num_swap = 0;
			for (int i = 1; i <= m; i++) {
				for (int j = i + 1; j <= m; j++) {
					int pre_collision = collision;
					cp[col[i] + row[i]]--;
					collision -= (cp[col[i] + row[i]] != -1);
					cc(col[i] - row[i])--;
					collision -= (cc(col[i] - row[i]) != -1);
					cp[col[j] + row[j]]--;
					collision -= (cp[col[j] + row[j]] != -1);
					cc(col[j] - row[j])--;
					collision -= (cc(col[j] - row[j]) != -1);
					swap(col[i], col[j]);
					++cp[col[i] + row[i]];
					collision += (cp[col[i] + row[i]] != 0);
					++cc(col[i] - row[i]);
					collision += (cc(col[i] - row[i]) != 0);
					++cp[col[j] + row[j]];
					collision += (cp[col[j] + row[j]] != 0);
					++cc(col[j] - row[j]);
					collision += (cc(col[j] - row[j]) != 0);
					if (collision >= pre_collision) {
						cp[col[i] + row[i]]--;
						collision -= (cp[col[i] + row[i]] != -1);
						cc(col[i] - row[i])--;
						collision -= (cc(col[i] - row[i]) != -1);
						cp[col[j] + row[j]]--;
						collision -= (cp[col[j] + row[j]] != -1);
						cc(col[j] - row[j])--;
						collision -= (cc(col[j] - row[j]) != -1);
						swap(col[i], col[j]);
						++cp[col[i] + row[i]];
						collision += (cp[col[i] + row[i]] != 0);
						++cc(col[i] - row[i]);
						collision += (cc(col[i] - row[i]) != 0);
						++cp[col[j] + row[j]];
						collision += (cp[col[j] + row[j]] != 0);
						++cc(col[j] - row[j]);
						collision += (cc(col[j] - row[j]) != 0);
					} else {
						++num_swap;
						if (collision == 0) goto siu;
					}
				}
			} 
			if (num_swap == 0) break;
		}
		if (collision == 0) break;
		shuffle(col + 1, col + m + 1, rng);
	}
	siu:;
	for (int i = 1; i <= m; i++)
		a[row[i]] = col[i];
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> n) solve(), cout << '\n';
	return 0;
}