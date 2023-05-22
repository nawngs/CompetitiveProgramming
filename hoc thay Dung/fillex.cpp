#include <bits/stdc++.h>

#define name "test"
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

struct Data {
	int sze, l, r;
	Data(int _sze = 0, int _l = 0, int _r = 0) {
		sze = _sze, l = _l, r = _r;
	}
};

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	char c; // 0 min, 1 max
	stack < int > bieuthuc;
	stack < Data > val;
	while (cin >> c) {
		if (c == 'm') {
			char type; cin >> type;
			if (type == 'i') bieuthuc.push(0);
			else bieuthuc.push(1);
			char s; cin >> s >> s;
			continue;
		}
		if (c == '?') val.push(Data(1, 1, 1));
		if (c == ')') {
			int type = bieuthuc.top(); bieuthuc.pop();
			Data valr = val.top(); val.pop();
			Data vall = val.top(); val.pop();
			Data res;
			res.sze = vall.sze + valr.sze;
			if (type == 0) { // lay min
				res.l = min(vall.l, valr.l);
				res.r = vall.r + valr.r - 1;
			}
			else {
				res.l = vall.l + valr.l;
				res.r = max(valr.sze + vall.r, vall.sze + valr.r);
			}
			val.push(res);
		}
	}
	cout << val.top().r - val.top().l + 1;
}