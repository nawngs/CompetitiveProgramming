#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, x, y;

string s1, s2;

void sol() {
	cin >> n >> x >> y >> s1 >> s2;
	int dem = 0;
	for (int i = 0; i < n; i++) dem += (s1[i] != s2[i]);
	if (dem % 2 == 1) {
		cout << -1 << '\n';
		return ;
	}
	int cnt = 0;	
	for (int i = 1; i < n; i++) if ((s1[i] != s2[i]) && (s1[i - 1] != s2[i - 1])) cnt ++;
	if (cnt == 1 && dem == 2) {
		int ans = x;
		if (n > 2) ans = min(ans, y * 2);
		cout << ans << '\n';
	}
	else cout << (dem / 2) * y << '\n';
}

main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
