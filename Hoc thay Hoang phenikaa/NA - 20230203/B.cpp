
  	                                                                                                      #include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[200003], cnt[200003][2], deg[200003];

vector < pii > chan, le;

vector < int > adj[200003];

multiset < pii, greater < pii > > ms;

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cnt[i][0] = cnt[i][1] = 0;
	chan.clear(); le.clear();
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
		cnt[a[i]][i & 1] ++;
	}
	for (int i = 1; i <= n; i++) {
		le.pb({cnt[i][1], i});
		chan.pb({cnt[i][0], i});
	}
	sort(le.begin(), le.end(), greater < pii >()); 
	sort(chan.begin(), chan.end(), greater < pii >());
	int res = INF;
	for (int i = 0; i < min(sz(le), 8); i++)
		for (int j = 0; j < min(sz(chan), 8); j++) {
			if (le[i].se == chan[j].se) continue;
			for (int p = 1; p <= n; p++) {
				adj[p].clear();
				deg[p] = 0;
			}
			int total = (n / 2 - chan[j].fi) + ((n + 1) / 2 - le[i].fi);
			for (int p = 1; p <= n; p+=2) {
				if (p > 1 && a[p] == chan[j].se && a[p - 1] == le[i].se) {
					adj[p].pb(p - 1);
					adj[p - 1].pb(p);
					deg[p] ++; deg[p - 1] ++;
				}
				if (p < n && a[p] == chan[j].se && a[p + 1] == le[i].se) {
					adj[p].pb(p + 1);
					adj[p + 1].pb(p);
					deg[p] ++; deg[p + 1] ++;
				}
			}
			for (int p = 1; p <= n; p++) 
				if (deg[p] > 0) ms.insert({deg[p], p});
			while (!ms.empty()) {
				pii it = *ms.begin(); ms.erase(ms.begin());
				total ++;
				deg[it.se] = 0;
				for (auto x : adj[it.se]) {
					pii temp = {deg[x], x};
					if (temp.fi == 0) continue;
					ms.erase(ms.find(temp));
					temp.fi --; deg[x] --;
					if (temp.fi != 0) ms.insert(temp);
				}
			}
			res = min(res, total);
		}
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}