#pragma GCC optimize ("O3")
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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, p, a[100005], b[100005], c[100005], cnt[100005], dem = 0;

bool check[100005], checka[100005];

void sol() {
	cin >> n >> m >> p;
	memset(check, 1, sizeof(check));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (checka[a[i]] == false) dem ++;
		checka[a[i]] = true;
		cnt[a[i]] ++;
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		check[b[i]] = false;
	}
	for (int i = 1; i <= p; i++) cin >> c[i];
	int ans = 0, l = 1, r = 1, kt = 0;
	while (r <= p) {
		if (check[c[r]]) {
			if (checka[c[r]]) {
				cnt[c[r]] --;
				if (cnt[c[r]] == 0) kt ++;
			}
			//cout << r << " " << l << " " << kt << " " << dem << '\n';
			if (kt == dem) ans = max(ans, r - l + 1);
			r ++;
		}
		else {
			for (int i = l; i < r; i++) if (checka[c[i]]) cnt[c[i]] ++;
			kt = 0;
			r ++;
			l = r;
		}
	}
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
