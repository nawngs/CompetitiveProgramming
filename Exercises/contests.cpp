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

const string NAME = "contests";
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

int n, k;

vector < pii > cnt;

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		cnt.push_back({s.size(), i});
	}
	sort(cnt.begin(), cnt.end(), [](pii &x, pii &y) {
		return (x.fi < y.fi) || (x.fi == y.fi && x.se < y.se);
	});
	int j = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (j < i) j = i;
		while (j < n && cnt[j + 1].fi == cnt[i].fi && cnt[j + 1].se - cnt[i].se <= k) j ++;
		ans += j - i;
	}
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
