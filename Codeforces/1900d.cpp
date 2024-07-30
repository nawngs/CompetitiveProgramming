#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 8e4;
const int M = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[N + 3];

ll f[M + 5];

vector < int > divi[M + 3], id[M + 5];

void init() {
	for (int i = 1; i <= M; i++)
		for (int j = i; j <= M; j+=i) divi[j].pb(i);
}

void sol() {
	for (int i = 1; i <= M; i++) id[i].clear(), f[i] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) for (auto x : divi[a[i]]) id[x].pb(i);
	ll res = 0;
	for (int t = M; t >= 1; t--) {
		for (int i = 1; i < id[t].size(); i++) {
			f[t] += 1ll * i * (n - id[t][i]);
		}
		for (int i = 2 * t; i <= M; i+=t) f[t] -= f[i];
		res += 1ll * t * f[t];
	}
	cout << res << '\n';
	return ;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	init();
	int t; cin >> t; while (t --) sol();
}