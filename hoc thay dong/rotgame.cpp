// dinhmanhhungwillwinioi2024
#include <bits/stdc++.h>
using namespace std;

const int N = 103;

int n, a[3][N];

vector<int> ans;

void xoay(const int &pos) {
	ans.emplace_back(pos);
	swap(a[1][pos], a[2][pos]);
	swap(a[1][pos], a[1][pos + 1]);
	swap(a[1][pos + 1], a[2][pos + 1]);
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	if (n == 2) {
		int ans = a[1][1] + a[1][2], steps = 0;
		for (int k = 1; k <= 3; k++) {
			xoay(1);
			if (a[1][1] + a[1][2] > ans) {
				ans = a[1][1] + a[1][2];
				steps = k;
			}
		}
		cout << steps << '\n';
		for (int i = 1; i <= steps; i++)
			cout << 1 << ' ';
	} else {
		while (true) {
			bool found = false;
			
			for (int i = 1; i <= n; i++) {
				int pos = -1;
				for (int j = 1; j <= n; j++)
					if (a[1][i] < a[2][j] && (pos == -1 || a[2][pos] < a[2][j]))
						pos = j;
				if (pos == -1) continue;
				found = true;
				if (pos == i) {
					if (pos == 1) {
						for (int p: {2, 2, 1, 2, 2, 2, 1})
							xoay(p);
					} else if (pos == n) {
						for (int p: {2, 1, 2, 2, 2})
							xoay(n - p);
					} else {
						for (int p: {1, 1, 1, 0, 1, 0, 0, 0})
							xoay(pos - p);
					}
				} else {
					if (pos > i) {
						for (int j = i; j < pos; j++)
							xoay(j);
					} else {
						for (int j = i - 1; j >= pos; j--)
							xoay(j), xoay(j), xoay(j);
					}
				}
				break;
			}
			
			if (found == false) break;
		}
		cout << ans.size() << '\n';
			for (int x: ans) cout << x << ' ';
	}
	return 0;
}