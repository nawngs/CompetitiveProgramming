#include <bits/stdc++.h>

#define name "eksplozija"
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

string s, t;

ll hashs[3000003], cur[3000003], pre[3000003], pw;

bool deleted[3000003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> s >> t; 
	int n = sz(s), m = sz(t); 
	s = ' ' + s; t = ' ' + t;
	ll hasht = 0;
	for (int i = 1; i <= m; i++) 
		hasht = (hasht * BASE + t[i]) % MOD;
	ll pw = 1;
	for (int i = 1; i <= m; i++) 
		pw = (pw * BASE) % MOD;
	int cnt = 0;
	cur[0] = 0;
	for (int i = 1; i <= n; i++) {
		cnt ++;
		cur[cnt] = i;
		hashs[cnt] = (hashs[cnt - 1] * BASE + s[i]) % MOD;
		if (cnt >= m) {
			ll val = (hashs[cnt] - hashs[cnt - m] * pw + MOD * MOD) % MOD;
			if (val == hasht) {
				for (int j = cnt; j >= cnt - m + 1; j--) deleted[cur[j]] = 1;
				cnt -= m;
			}
		}
	}
	string res = "";
	for (int i = 1; i <= n; i++)
		if (!deleted[i]) res += s[i];
	if (res == "") cout << "miss you baby";
	else cout << res;
}