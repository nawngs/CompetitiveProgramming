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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const char vowel[] = {'U', 'E', 'O', 'A', 'I'};
const char consonant[] = {'B', 'C', 'D', 'F', 'G', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'S', 'T', 'V', 'X', 'Z', 'H', 'R', 'W', 'Y'};

using vi = vector < int >;

char newv[26];

bool adj[26][26];

string s;

bool ok = 1;

vi vec[2];

vector < pair < vi, vi > > a;

int color[26];

bool dp[29][29];

int trace[29][29];

void dfs(int u) {
	vec[color[u]].pb(u);
	for (int v = 0; v < 26; v++) if (adj[u][v]) {
		if (color[v] == -1) {
			color[v] = color[u] ^ 1;
			dfs(v);
		}
		if (color[u] == color[v]) {
			ok = false;
			return ;
		}
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	getline(cin, s);
	int n = s.size();
	for (int i = 1; i < n; i++) if (s[i] != ' ') {
		if (s[i - 1] != ' ') adj[s[i] - 'A'][s[i - 1] - 'A'] = 1; //cout << s[i] - 'A' << " " << s[i - 1] - 'A' << '\n';}
		if (i < n - 1 && s[i + 1] != ' ') adj[s[i] - 'A'][s[i + 1] - 'A'] = 1; //cout << s[i] - 'A' << " " << s[i + 1] - 'A' << '\n';}
	}
	memset(color, 255, sizeof(color));
	for (int i = 0; i < 26; i++) if (color[i] == -1) {
		vec[0].clear(); vec[1].clear();
		color[i] = 0; dfs(i);
		if (!ok) {
			cout << "impossible";
			return 0;
		}
		a.pb({vec[0], vec[1]});
	}
	dp[0][SZE(a[0].fi)] = 1; trace[0][SZE(a[0].fi)] = 1; 
	dp[0][SZE(a[0].se)] = 1; trace[0][SZE(a[0].se)] = 2;
	for (int i = 1; i < a.size(); i++) {
		for (int j = 0; j < 26; j++) if (dp[i - 1][j]) { 
			dp[i][j + SZE(a[i].fi)] = 1; trace[i][j + SZE(a[i].fi)] = 1;
			dp[i][j + SZE(a[i].se)] = 1; trace[i][j + SZE(a[i].se)] = 2;
		}
	}
	if (!dp[SZE(a) - 1][5]) {
		cout << "impossible";
		return 0;
	}
	int curv = 0, curc = 0, val = 5, pos = SZE(a) - 1;
	while (pos >= 0) {
		if (trace[pos][val] == 2) swap(a[pos].fi, a[pos].se);
		//cout << val << ' ' << a[pos].fi.size() << '\n';
		for (auto x : a[pos].fi) {
			newv[x] = vowel[curv ++];
		}
		for (auto x : a[pos].se) {
			newv[x] = consonant[curc ++];
		}
		val -= SZE(a[pos].fi); pos --;
	}
	for (auto &x : s) if (x != ' ') x = newv[x - 'A'];
	cout << s;
}