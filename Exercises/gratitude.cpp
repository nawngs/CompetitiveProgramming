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

const string NAME = "gratitude";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k;

pair < string, int > s[100003];

vector < pair < string, pii > > temp;

int main() {
	fast;
	//fre();
	cin >> n >> k;
	for (int i = 1; i <= 3 * n + 1; i++) {
		getline(cin, s[i].fi);
		s[i].se = i;
	}
	sort(s + 1, s + 3 * n + 2);
	int dem = 1, last = s[1].se;
	for (int i = 2; i <= 3 * n + 1; i++) {
		if (s[i].fi == s[i - 1].fi) {
			dem ++;
			last = max(last, s[i].se);
		}
		else {
			temp.push_back({s[i - 1].fi, {dem, last}});
			dem = 1;
			last = s[i].se;
		}
	}
	temp.push_back({s[3 * n + 1].fi, {dem, last}});
	sort(temp.begin(), temp.end(), [&](pair < string, pii > &x, pair < string, pii > &y) {
		return (x.se.fi > y.se.fi) || (x.se.fi == y.se.fi && x.se.se > y.se.se);
	});
	for (int i = 0; i < min(k, (int)temp.size()); i++) cout << temp[i].fi << '\n';
}
