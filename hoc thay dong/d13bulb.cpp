#include <bits/stdc++.h>

using namespace std;

int n, m, k;

string s1, s2;

bitset < 10003 > a[203];

int main() {
	cin >> m >> n >> k;
	cin >> s1 >> s2; s1 = ' ' + s1; s2 = ' ' + s2;
	for (int i = 1; i <= k; i++) {
		int u, v; cin >> u >> v;
		a[u][i] = 1;
		a[v + m][i] = 1;
	}
	for (int i = 1; i <= m + n; i++) 
		a[i][0] = (s2[i] != s1[i] ? 1 : 0);
	for (int i = 1; i <= m + n; i++) 
		for (int j = 1; j <= k; j++) if (a[i][j] == 1) {
			for (int p = 1; p <= m + n; p++)
				if (a[p][j] == 1 && p != i) a[p] ^= a[i];
			break;
		}
	vector < int > res;
	for (int i = 1; i <= m + n; i++) if (a[i][0]) {
		bool th = false;
		for (int j = 1; j <= k; j++)
			if (a[i][j]) {
				res.push_back(j);
				th = true;
				break;
			}
		if (!th) {
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << res.size() << '\n';
	for (auto x : res) cout << x << " ";
}