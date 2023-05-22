#include <bits/stdc++.h>

#define name ""
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

int n, k, nxt[NMAX + 3];

bool valid[(1 << 20)];

string s;

void sol() {
	cin >> n >> k >> s;
	int val = min(k, (int)ceil(log2(n - k + 2)));
	int pre = k - val;
	for (int i = 0; i <= n; i++) valid[i] = 1;
	nxt[n] = INF;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0') nxt[i] = i;
		else nxt[i] = nxt[i + 1];
	}
	for (int i = 0; i < n - k + 1; i++) {
		if (nxt[i] - i < pre) continue;
		int msk = 0;
		for (int j = i + pre; j < i + k; j++) {
			msk = msk * 2 + (s[j] - '0');
		}
		valid[(((1 << val) - 1) ^ msk)] = 0;
	}
	int res = -1;
	for (int i = 0; i < (1 << val); i++) {
		if (valid[i]) {
			res = i;
			break;
		}
	}
	if (res == -1) cout << "NO" << '\n';
	else {
		cout << "YES\n";
		for (int i = 1; i <= pre; i++) cout << 0;
		for (int i = val - 1; i >= 0; i--) 
			cout << (res >> i & 1);
		cout << '\n';
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}