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
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

string s, t;

bool used[26];

int num[26], n;

vector < int > exist;

void sol() {
	cin >> n >> s;
	exist.clear();
	memset(used, 0, sizeof(used));
	for (auto c : s) used[c - 'a'] = 1;
	int cur = 0;
	for (int i = 0; i < 26; i++) if (used[i]) num[i] = cur ++, exist.pb(i);
	cur --;
	for (auto c : s) cout << (char)('a' + exist[cur - num[c - 'a']]);
	cout << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}