#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, int >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "medxor";
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

ll a, b, c, d;

vector < pll > patternab, patterncd, finalpattern;

void find_pattern(ll a, ll b, vector < pll > &pattern) {
	bool different = 0;
	ll cura = 0, curb = 0;	
	pattern.push_back({a, 0});
	if (a == b) return ;
	pattern.push_back({b, 0});
	for (int i = 62; i >= 0; i--) {
		if (!different) {
			if ((a >> i & 1) != (b >> i & 1)) different = 1;
			if ((a >> i & 1)) cura ^= (1ll << i);
			if ((b >> i & 1)) curb ^= (1ll << i);
			continue;
		}
		if (!(a >> i & 1))
			pattern.push_back({cura ^ (1ll << i), i});
		if ((b >> i & 1)) 
			pattern.push_back({curb, i});
		if ((a >> i & 1)) cura ^= (1ll << i);
		if ((b >> i & 1)) curb ^= (1ll << i);
	}
	//pattern.push_back({cura, 0});
	//pattern.push_back({curb, 0});
}

inline bool isEqual(const pll &x, const pll &y) {
   if (x == y) return true;
   if (x.second < y.second) return false;
   return x.first == (y.first >> x.second << x.second);
}


void sol() {
	cin >> a >> b >> c >> d;
	patternab.clear(); patterncd.clear(); finalpattern.clear();
	find_pattern(a, b, patternab);
	find_pattern(c, d, patterncd);
	for (auto x : patternab) 
		for (auto y : patterncd) {
			ll tam = max(x.se, y.se);
			ll val1 = x.fi, val2 = y.fi;
			val1 >>= tam; val1 <<= tam;
			val2 >>= tam; val2 <<= tam;
			finalpattern.push_back({(val1 ^ val2), tam});
		}
	sort(finalpattern.begin(), finalpattern.end(), [&](pll &x, pll &y) {
		return (x.fi < y.fi) || (x.fi == y.fi && x.se > y.se);
	});
	finalpattern.erase(unique(finalpattern.begin(), finalpattern.end(), isEqual), finalpattern.end());
	finalpattern = finalpattern;
 	unsigned ll sze = 0;
 	for (auto x : finalpattern)
 		sze += (1ll << x.se);
 	unsigned ll med = (sze + 1) / 2;
 	for (auto x : finalpattern) {
 		if ((unsigned ll)(1ll << x.se) < med) {
 			med -= (unsigned ll)(1ll << x.se);
 			continue;
 		}
 		ll res = x.fi;
 		for (int i = x.se - 1; i >= 0; i--) {
	 		if (med > (unsigned ll)(1ll << i)) {
	 			med -= (unsigned ll)(1ll << i);
	 			res ^= (1ll << i);
	 		}
	 	}
 		cout << res << '\n';
 		return ;
 	}
 	
}	

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
