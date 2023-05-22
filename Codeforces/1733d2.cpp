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
	vector < int > pos;
	for (int i = 0; i < n; i++) 
		if (s1[i] != s2[i]) pos.push_back(i);
	
	if (pos.size() % 2 == 1) {
		cout << -1 << '\n';
		return ;
	}	
	int cnt = 0;
	for (int i = 1; i < n; i++) if ((s1[i] != s2[i]) && (s1[i - 1] != s2[i - 1])) cnt ++;
	if (cnt == 1 && pos.size() == 2) {
		int ans = x;
		if (n > 2) ans = min(ans, y * 2);
		cout << ans << '\n';
		return ;
	}
	int res = (pos.size() / 2) * y, ans = 0;
	vector < int > newpos;
	for (auto i : pos) {
		if (newpos.size() && i - newpos.back() == 1) {
			ans += min(x, 2 * y);
			newpos.pop_back();
		} 
		else newpos.push_back(i);
	}
	if (newpos.size()) for (int i = 1; i < newpos.size(); i+=2) ans += min(y, (newpos[i] - newpos[i - 1]) * x);
	cout << min(res, ans) << '\n';
}

main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
