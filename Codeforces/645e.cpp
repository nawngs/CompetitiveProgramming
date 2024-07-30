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

int n, k, dp[26];

pii lst[26];

string s;

deque < int > dq;

void calc(int v) {
	int temp = 0;
	for (int i = 0; i < k; i++) temp = (temp + dp[i]) % MOD;
	dp[v] = (temp + 1) % MOD;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k >> s;
	int m = s.size();
	for (int i = 0; i < k; i++) lst[i] = {-1, i};
	for (int i = 0; i < m; i++) lst[s[i] - 'a'].fi = i;
	sort(lst, lst + k);
	for (int i = 0; i < k; i++) dq.push_back(lst[i].se);
	for (int i = 0; i < m; i++) calc(s[i] - 'a');	
	for (int i = 0; i < n; i++) {
		int u = dq.front();
		calc(u);
		dq.pop_front(); dq.push_back(u);
	}
	for (int i = 1; i < k; i++) dp[i] = (dp[i] + dp[i - 1]) % MOD;
	cout << (dp[k - 1] + 1) % MOD;
}