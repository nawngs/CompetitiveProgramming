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

ll n, k, sze[262150];

pll a[262150];

vector < ll > points[262150], total;

void sol() {
	cin >> n >> k;
	k = n - k + 1;
	total.clear();
	for (int i = 0; i <= n + 1; i++) points[i].clear();
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		a[i].fi = min(a[i].fi, n + 1);
		points[a[i].fi].push_back(a[i].se);
		total.push_back(a[i].se);
	}
	if (k <= 0) {
		cout << 0 << '\n';
		return ;
	}
	sort(total.begin(), total.end());
	for (int i = 1; i <= n + 1; i++) sort(points[i].begin(), points[i].end());
	ll res = LINF;
	sze[0] = points[0].size();
	for (int i = 1; i <= n; i++) {
		sze[i] = sze[i - 1] + points[i].size();
		if (sze[i] < k) continue;
		if (i >= 2 && sze[i - 2] >= k) {
			ll cur = 0;
			for (int j = 0; j < i; j++) cur += total[j];
			res = min(res, cur);
			break;
		}
		ll val = k - (i >= 2 ? sze[i - 2] : 0);
		ll cur = 0; 
		if (i < val) continue;
		vector < ll > rem;
		priority_queue < ll > heap;
		for (int v = i - 1; v <= i; v++) 
			for (auto x : points[v]) {
				cur += x;
				heap.push(x);
				while ((int)heap.size() > val) {
					rem.push_back(heap.top());
					cur -= heap.top();
					heap.pop();
				}
			}
		for (int v = 0; v <= n + 1; v++) {
			if (v == i - 1 || v == i) continue;
			for (auto x : points[v]) rem.push_back(x);
		}
		sort(rem.begin(), rem.end());
		for (int j = 0; j < i - val; j++) cur += rem[j];
		res = min(res, cur);
	}
	cout << (res >= LINF ? -1 : res) << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
