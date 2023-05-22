#include <bits/stdc++.h>

#define name "kittens"
#define test "test"
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
const int NMAX = 1E6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, cnt = 0, oper[NMAX + 3], dp[22];

map < vector < int >, int > f;

vector < int > g, vec[NMAX + 3];

vector < int > a, b;

int bs(int val) {
	int l = 0, r = sz(b) - 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (b[mid] < val) {
			ans = b[mid];
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

void sol() {
	cin >> n;
	a.resize(n); b.clear();
	for (auto &x : a) cin >> x;
	if (n <= 7) {
		if (f.find(a) == f.end()) cout << "5 or more" << '\n';
		else cout << oper[f[a]] << '\n';
		return ;
	}
	dp[n - 1] = 0; b.push_back(a.back()); dp[n] = 0;
	for (int i = n - 2; i >= 0; i--) {
		int val = bs(a[i]);
		if (val == -1) {
			dp[i] = dp[i + 1];
			b.push_back(a[i]);	
			sort(b.begin(), b.end());		
			continue;
		}
		dp[i] = INF;
		for (int j = i; j < n; j++) {
			if (a[j] < a[i] || bs(a[j]) != val) break;
			dp[i] = min(dp[i], dp[j + 1] + 1);
		}
		b.push_back(a[i]);
		sort(b.begin(), b.end());
	}
	if (dp[0] > 4) cout << "5 or more" << '\n';
	else cout << dp[0] << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	for (int len = 1; len <= 7; len++) {
		g.clear();
		for (int j = 1; j <= len; j++) g.push_back(j);
		f[g] = ++ cnt; oper[cnt] = 0; vec[cnt] = g;
		queue < int > que; que.push(cnt);
		while (!que.empty()) {
			int x = que.front(); que.pop();
			if (oper[x] > 3) break;
			g = vec[x];
			// cout << x << " " << oper[x] << '\n';
			// for (auto x : g) cout << x << " ";
			// cout << '\n';
			for (int l = 0; l < len; l++)
				for (int r = l; r < len; r++) 
					for (int i = 0; i < len; i++) {
						vector < int > newg; newg.clear();
						for (int j = 0; j < i; j++) {
							if (l <= j && j <= r) continue;
							newg.push_back(g[j]);
						}
						for (int j = l; j <= r; j++) newg.push_back(g[j]);
						for (int j = i; j < len; j++) {
							if (l <= j && j <= r) continue;
							newg.push_back(g[j]);
						}
						if (f.find(newg) != f.end()) continue;
						f[newg] = ++ cnt; oper[cnt] = oper[x] + 1; vec[cnt] = newg;
						que.push(cnt);
					}
		}
	}
	int t; cin >> t; while (t --) sol();
}