#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const ll SZE = 450;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, q, a[200003];

namespace sub1 {
	void solve() {
		while (q--) {
			int t;
			cin >> t;
			if (t == 1) {
				int l, r, v;
				cin >> l >> r >> v;
				for (int i = l; i <= r; i++) a[i] += 1ll * v;
			}
			else {
				int l, r;
				cin >> l >> r;
				vector < ll > temp;
				for (int i = l; i <= r; i++) temp.push_back(a[i]);
				sort(temp.begin(), temp.end());
				ll dem = 1, ans = -1;
				for (int i = 1; i < temp.size(); i++) {
					if (temp[i] == temp[i - 1]) dem ++;
					else {
						if (dem > (r - l + 1) / 2) ans = temp[i - 1];
						dem = 1;
					}
				}
				if (dem > (r - l + 1) / 2) ans = temp.back();
				if (ans == -1) cout << "IMPOSSIBLE" << '\n';
				else cout << ans << '\n';
			}
		}
	}
}

namespace ac {
	map < int, vector < int > > f;
	vector < int > bigaf;
	int get(int x, int low, int high) {
		int l = 0, r = f[x].size() - 1, mid, ans = -1, res = -1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (f[x][mid] >= low) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		l = 0, r = f[x].size() - 1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (f[x][mid] <= high) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (ans == -1 || res == -1) return 0;
		return res - ans + 1;
	}
	void solve() {
		for (int i = 1; i <= n; i++) f[a[i]].push_back(i);
		for (auto x : f) 
			if (x.se.size() > SZE) bigaf.push_back(x.fi);
		while (q--) {
			int t, l, r;
			cin >> t >> l >> r;
			if ((r - l + 1) >= 2 * SZE) {
				int ans = -1;
				for (auto x : bigaf) 
					if (get(x, l, r) > (r - l + 1) / 2) {
						ans = x;
						break;
					}
				if (ans == -1) cout << "IMPOSSIBLE" << '\n';
				else cout << ans << '\n';
			}
			else {
				vector < int > temp;
				for (int i = l; i <= r; i++) temp.push_back(a[i]);
				sort(temp.begin(), temp.end());
				ll dem = 1, ans = -1;
				for (int i = 1; i < temp.size(); i++) {
					if (temp[i] == temp[i - 1]) dem ++;
					else {
						if (dem > (r - l + 1) / 2) ans = temp[i - 1];
						dem = 1;
					}
				}
				if (dem > (r - l + 1) / 2) ans = temp.back();
				if (ans == -1) cout << "IMPOSSIBLE" << '\n';
				else cout << ans << '\n';
			}
		}
	}
}

int main() { 
	fast;
	//fre();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 1000 && q <= 1000) sub1::solve();
	else ac::solve();
}
 