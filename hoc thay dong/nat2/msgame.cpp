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

int a[10003];

ll dp[10003][10003];

int st[10003][15], n, k;

int get(int l, int r) {
    if (l > r) return 0;
	int k = __lg(r - l + 1);
	if (a[st[l][k]] > a[st[r - (1 << k) + 1][k]]) return st[l][k];
	else return st[r - (1 << k) + 1][k];
}

void solve(int l, int r) {
	if (l == r) {
		dp[l][1] = a[l];
		return ;
	}
	if (l > r) return ;
	int mid = get(l, r);
	solve(l, mid - 1), solve(mid + 1, r);
	int lnode = get(l, mid - 1), rnode = get(mid + 1, r);
	for (int i = 0; i <= max(0, mid - l); i++)
		for (int j = 0; j <= max(0, r - mid); j++) {
			dp[mid][i + j] = min(dp[mid][i + j], dp[lnode][i] + dp[rnode][j] + 1ll * j * 1ll * i * 1ll * a[mid]);
		}
	for (int i = r - l + 1; i >= 1; i--)
		dp[mid][i] = min(dp[mid][i], dp[mid][i - 1] + 1ll * a[mid] * 1ll * i);
}

int main() {
	fast;
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st[i][0] = i;
	}
    double time_use;     
	clock_t start, end;   
    start = clock();
	for (int j = 1; j <= 14; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			if (a[st[i][j - 1]] > a[st[i + (1 << (j - 1))][j - 1]]) st[i][j] = st[i][j - 1];
			else st[i][j] = st[i + (1 << (j - 1))][j - 1];
		}
	}

	for (int i = 0; i <= n; i++)
		for (int j = 1; j <= k; j++)
			dp[i][j] = LINF;
	solve(1, n);
	cout << dp[get(1, n)][k] << '\n';
	end = clock();
	time_use = double(end - start) / CLOCKS_PER_SEC;
	cerr << fixed << setprecision(6) << time_use << '\n';
}
