#include <bits/stdc++.h>

#define name "slom"
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

int k, pre[100003][35], nxt[100003];

bool active[100003];

char res[100003];

string s;


int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> k >> s;
	int n = sz(s); s = ' ' + s;
	for (int i = n; i > (n + 1) / 2; i--) {
		nxt[i] = 2 * (n - i + 1);
		active[2 * (n - i + 1)] = 1;
	}
	int pos = 1;
	for (int i = 1; i <= (n + 1) / 2; i++) {
		while (active[pos]) pos ++;
		nxt[i] = pos;
		active[pos] = 1;
	}
	for (int i = 1; i <= n; i++)
		pre[nxt[i]][0] = i;
	for (int j = 1; j <= 30; j++)
		for (int i = 1; i <= n; i++) 
			pre[i][j] = pre[pre[i][j - 1]][j - 1];
	for (int i = 1; i <= n; i++) {
		int pos = i;
		for (int j = 30; j >= 0; j--) {
			if (k >> j & 1) pos = pre[pos][j];
		}
		res[pos] = s[i];
	}
	for (int i = 1; i <= n; i++) cout << res[i];
}