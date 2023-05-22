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

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k, p[400003][20], q, c[100003], d[100003], R[400003], st[400003][20];

pii a[100003];

int get(int l, int r) {
	int k = log2(r - l + 1);
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
	//fast;
	cin >> n >> q >> k;
	memset(p, 255, sizeof(p));
	memset(R, 255, sizeof(R));
	memset(st, 255, sizeof(st));
	vector < int > roi_rac;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		a[i].se --;
		roi_rac.push_back(a[i].fi);
		roi_rac.push_back(a[i].se);
	}
	for (int i = 1; i <= q; i++) {
		cin >> c[i] >> d[i];
		d[i] --;
		roi_rac.push_back(c[i]);
		roi_rac.push_back(d[i]);
	}
	sort(roi_rac.begin(), roi_rac.end());
	roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	for (int i = 1; i <= n; i++) {
		a[i].fi = lower_bound(roi_rac.begin(), roi_rac.end(), a[i].fi) - roi_rac.begin();
		a[i].se = lower_bound(roi_rac.begin(), roi_rac.end(), a[i].se) - roi_rac.begin();
	}
	for (int i = 1; i <= q; i++) {
		c[i] = lower_bound(roi_rac.begin(), roi_rac.end(), c[i]) - roi_rac.begin();
		d[i] = lower_bound(roi_rac.begin(), roi_rac.end(), d[i]) - roi_rac.begin();
	}
	sort(a + 1, a + n + 1);
	int l = 0;
	for (int i = 0; i < roi_rac.size(); i++) {
		if (i > 0 && p[i - 1][0] >= i) p[i][0] = p[i - 1][0];
		while (l < n && a[l + 1].fi <= i) {
			p[i][0] = max(p[i][0], a[l + 1].se);
			l ++;
		}
		//cout << roi_rac[i] << " " << roi_rac[p[i][0]] << '\n';
	}
	for (int j = 1; j <= 19; j++) 
		for (int i = 0; i < roi_rac.size(); i++) {
			if (p[i][j - 1] < roi_rac.size() && p[i][j - 1] != -1) {
				p[i][j] = p[p[i][j - 1]][j - 1];
				if (p[i][j - 1] < roi_rac.size() - 1 && roi_rac[p[i][j] + 1] - roi_rac[p[i][j]] == 1)
					p[i][j] = max(p[i][j], p[p[i][j - 1] + 1][j - 1]);
			}
			else p[i][j] = p[i][j - 1];
		}
	for (int i = 0; i < roi_rac.size(); i++) {
		int pos = i;
		int tam = k;
		int ans = -1;
		for (int j = 19; j >= 0; j--) if (tam >= (1 << j) && p[pos][j] != -1) {
			tam -= (1 << j);
			ans = p[pos][j];
			pos = p[pos][j] + 1;
		}
		R[i] = ans;
		//cout << roi_rac[i] << " " << roi_rac[R[i]] << '\n';
		st[i][0] = (R[i] == -1 ? -INF : roi_rac[R[i]] - roi_rac[i]);
	}
	for (int j = 1; j <= 19; j++) 
		for (int i = 0; i + (1 << j) - 1 < roi_rac.size(); i++) st[i][j] = max(st[i][j - 1], st[i + (1 << j) - 1][j - 1]);
	for (int i = 1; i <= q; i++) {
		if (R[c[i]] >= d[i]) {
			cout << roi_rac[d[i]] - roi_rac[c[i]] + 1 << '\n';
			continue;
		}
		int res = 0;
		int l = c[i], r = d[i], mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (R[mid] <= d[i]) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		//cout << ans << " " << roi_rac[ans + 1] << '\n';
		res = get(c[i], ans);
		if (ans + 1 <= d[i]) res = max(res, roi_rac[d[i]] - roi_rac[ans + 1]);
		//res = max(get(c[i], ans), roi_rac[d[i]] - roi_rac[ans + 1]);
		cout << res + 1 << '\n';
	}
}