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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, p;

string s;

bool a[1003][1003];

int dp[(1 << 17)];

bitset < (1 << 17) > cur, correct;

vector < int > pos[17];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> p >> s;
	for (int i = 0; i < p; i++)
		for (int j = 0; j < p; j++) 
			cin >> a[i][j];
	for (int i = 0; i < sz(s); i++) 
		pos[s[i] - 'a'].push_back(i);
	correct = 0; correct = ~correct;
	for (int i = 0; i < p; i++) 
		for (int j = i; j < p; j++) {
			if (a[i][j]) continue;
			cur = 0; cur = ~cur;
			int curi = 0, curj = 0;
			while (1) {
				if (i == j && curi == curj) curj ++;
				if (curi >= sz(pos[i]) || curj >= sz(pos[j])) break;
				if (pos[i][curi] > pos[j][curj]) 
					while (curj < sz(pos[j]) - 1 && pos[j][curj + 1] < pos[i][curi]) curj ++;
				else
					while (curi < sz(pos[i]) - 1 && pos[i][curi + 1] < pos[j][curj]) curi ++;
				int bit = 0;
				for (int k = min(pos[i][curi], pos[j][curj]) + 1; k < max(pos[j][curj], pos[i][curi]); k++)
					bit |= (1 << (s[k] - 'a'));
				cur[bit] = 0;
				if (pos[i][curi] < pos[j][curj]) curi ++;
				else curj ++;
			}
			cur[0] = 1;
			for (int mask = 1; mask < (1 << p); mask++) {
				if (cur[mask]) continue;
				for (int bit = 0; bit < p; bit++) {
					if (bit == i || bit == j || (mask >> bit & 1)) continue;
					cur[mask ^ (1 << bit)] = 0;
				}
			}
			correct &= cur;
		}
	int ans = n;
	dp[0] = n;
	for (int i = 1; i < (1 << p); i++) {
		if (!correct[i]) continue;
		dp[i] = INF;
		for (int j = 0; j < p; j++) {
			if ((i >> j & 1) && correct[i ^ (1 << j)]) {
				dp[i] = dp[i ^ (1 << j)] - sz(pos[j]);
				break;
			}
		}
		ans = min(ans, dp[i]);
	}
	cout << ans;
}