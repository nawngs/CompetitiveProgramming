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

int n, m;

ld h[200003], up[200003], down[200003], max_h[200003], min_h[200003];

bool check(ld x) {
	max_h[1] = h[1] + x;
	min_h[1] = h[1] - x;
	for (int i = 2; i <= n; i++) {
		max_h[i] = min(h[i] + x, max_h[i - 1] + up[i - 1]);
		min_h[i] = max(h[i] - x, min_h[i - 1] - down[i - 1]);
		if (max_h[i] < min_h[i]) return false;
	}
	return true;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		up[i] = down[i] = INF;
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		ld u, d;
		cin >> a >> b >> u >> d;
		if (a > b) {
			swap(a, b);
			swap(u, d);
		}
		for (int j = a; j < b; j++) {
			up[j] = min(up[j], u);
			down[j] = min(down[j], d);
		}
	}
	ld l = 0, r = INF, mid, ans;
	while (l < r - ESP) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid;
		}
		else l = mid;
	}
	cout << fixed << setprecision(6) << ans << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
