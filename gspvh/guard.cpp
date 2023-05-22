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

const string NAME = "guard";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, q, k, valid[nmax + 3];

ll dp[nmax + 3];

ll s[nmax + 3], cnt[nmax + 3];

vector < int > b[nmax + 3];

void sol() {
	cin >> n >> k >> q;
	for (int i = 1; i <= q; i++)
		cin >> s[i];
	for (int i = 1; i <= q; i++) {
		int k; cin >> k;
		b[i].resize(k);
		for (int &x : b[i]) cin >> x;
	}
	for (int i = 1; i <= n; i++)
		cnt[i] = 0;
	int l = 1, diff = 0;
	for (int r = 1; r <= q; r++) {
		for (auto x : b[r]) {
			cnt[x] ++;
			if (cnt[x] == 1) diff ++;
		}
		while (diff > k) {
			for (auto x : b[l]) {
				cnt[x] --;
				if (cnt[x] == 0) diff --;
			}
			l ++;
		}
		valid[r] = l;
	}
	dp[1] = 0;
	deque < pll > dq;
	dq.push_back({0, 1});
	for (int i = 2; i <= q; i++) {
		ll temp = dp[i - 1] + s[i];
		while (dq.size() && dq.back().fi > temp) 
			dq.pop_back();
		dq.push_back({temp, i});
		while (dq.front().se < valid[i]) dq.pop_front();
		dp[i] = dq.front().fi;
	}
	for (int i = 1; i <= n; i++) {
		
	}
	cout << dp[q] << ' ';
}

int main() {
	fast;
	fre();
	int O; cin >> O;
	int t = 1; cin >> t;
	while (t --) sol();
}
