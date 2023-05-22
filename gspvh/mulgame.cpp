#include <bits/stdc++.h>

#define name "mulgame"
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

bool winable[1000003];

bool ans;

void solve(int x, bool res) {
	if (x <= 1) {	
		ans = res;
		return ;
	}
	if (res) return solve((x + 8) / 9, !res);
	else return solve((x + 1) / 2, !res);
}

bool sol() {
	int x; cin >> x;
	solve(x, 1);
	return ans;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) cout << (!sol() ? "La premiere joueuse gagne." : "La deuxieme joueuse gagne.") << '\n';
}