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
	string finp = NAME2 + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	//freopen(fout.c_str(), "w", stdout);
}

pll edges[100003];

ll n, k, d[300003];

vector < pll > adj[300003];

int main() {
	fast;
	//fre();
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		ll b;
		cin >> b;
		if (b == 4) {
			edges[i].fi = 1;
			edges[i].se = 4;
			continue;
		}
		ll l = 3, r = 1e8, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (mid * mid >= b) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		ll val = 3 + (ans - 3) * 4;
		if (b >= ans * ans - (ans - 1)) val += 4;
		else val += 2;
		edges[i].fi = b - val;
		edges[i].se = b;
	}
	vector < ll > roi_rac;
	roi_rac.push_back(1);
	roi_rac.push_back(n);
	for (int i = 1; i <= k; i++) {
		roi_rac.push_back(edges[i].fi);
		roi_rac.push_back(edges[i].se);
	}
	sort(roi_rac.begin(), roi_rac.end());
	roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	ll fn = lower_bound(roi_rac.begin(), roi_rac.end(), n) - roi_rac.begin() + 1;
	adj[1].push_back({fn, n - 1});
	for (int i = 1; i <= k; i++) {
		edges[i].fi = lower_bound(roi_rac.begin(), roi_rac.end(), edges[i].fi) - roi_rac.begin() + 1;
		edges[i].se = lower_bound(roi_rac.begin(), roi_rac.end(), edges[i].se) - roi_rac.begin() + 1;
		adj[1].push_back({edges[i].fi, roi_rac[edges[i].fi - 1] - 1});
		adj[1].push_back({edges[i].se, roi_rac[edges[i].se - 1] - 1});
		adj[fn].push_back({edges[i].fi, abs(n - roi_rac[edges[i].fi - 1])});
		adj[fn].push_back({edges[i].se, abs(n - roi_rac[edges[i].se - 1])});
		adj[edges[i].fi].push_back({fn, abs(n - roi_rac[edges[i].fi - 1])});
		adj[edges[i].se].push_back({fn, abs(n - roi_rac[edges[i].se - 1])});
		adj[edges[i].fi].push_back({edges[i].se, 1});
		adj[edges[i].se].push_back({edges[i].fi, 1});
	}
	for (int i = 1; i < roi_rac.size(); i++) {
		adj[i].push_back({i + 1, roi_rac[i] - roi_rac[i - 1]});
		adj[i + 1].push_back({i, roi_rac[i] - roi_rac[i - 1]});
	}
	priority_queue < pll, vector < pll > , greater < pll > > heap;	
	for (int i = 1; i <= roi_rac.size(); i++) d[i] = LINF;
	d[1] = 0;
	heap.push({0, 1});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != d[u.se]) continue;
		//cout << u.fi << " " << roi_rac[u.se - 1] << '\n';
		for (auto v : adj[u.se]) {
			if (d[v.fi] > d[u.se] + v.se) {
				d[v.fi] = d[u.se] + v.se;
				heap.push({d[v.fi], v.fi});
			}
		}
	}
	cout << d[fn];
}