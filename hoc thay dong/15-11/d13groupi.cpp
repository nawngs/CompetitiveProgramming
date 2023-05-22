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

ll n, m, CanGo[53], best = 0, in_max_clique = 0;

void find_max_clique(ll cur, ll left) {
	if (__builtin_popcountll(cur) + __builtin_popcountll(left) < __builtin_popcountll(best)) return ;
	if (left == 0) {
		if (__builtin_popcountll(cur) > __builtin_popcountll(best)) {
			in_max_clique = cur;
			best = cur;
		}
		else if (__builtin_popcountll(cur) == __builtin_popcountll(best)) in_max_clique |= cur;
		return ;
	}
	int i = __builtin_ctzll(left);
	find_max_clique(cur ^ (1ll << i), (left & CanGo[i]));
	find_max_clique(cur, left ^ (1ll << i));
}

void print(ll szel, ll l) {
	// best = 0;
	// find_max_clique(0, l);
	// cout << __builtin_popcountll(best) << " ";
	//  best = 0;
	// find_max_clique(0, (1ll << n) - 1 - l);
	//  cout << __builtin_popcountll(best) << " ";
	// cout << l << " " << (1ll << n) - 1 - l << '\n';
	cout << __builtin_popcountll(l) << '\n';
		for (int i = 0; i < n; i++)
			if ((l >> i) & 1) 
				cout << i + 1 << ' ';
}

int main() {
	fast;
	//fre();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		ll u, v; cin >> u >> v;
		u--; v--;
		CanGo[u] |= (1ll << v);
		CanGo[v] |= (1ll << u);
	}
	find_max_clique(0, (1ll << n) - 1);
	ll goat = best;
	ll l = best, r = (1ll << n) - 1 - l;
	ll szel = __builtin_popcountll(best);
	best = 0;
	find_max_clique(0, r);
	ll szer = __builtin_popcountll(best);
	ll moved = 0;
	while (szel > szer) {
		int i = __builtin_ctzll(l);
		l ^= (1ll << i); r ^= (1ll << i);
		moved ^= (1ll << i);
		szel --;
		best = 0;
		find_max_clique(0, r);
		szer = __builtin_popcountll(best);
	}
	//cout << szel << " " << szer << '\n';
	if (szel == szer) {
		print(szel, l);
	}
	else {
		bool correct = 0;
		for (int i = 0; i < n; i++) {
			if ((moved >> i) & 1 && !((in_max_clique >> i) & 1)) {
				szel ++;
				l ^= (1ll << i);
				r ^= (1ll << i);
				correct = 1;
				break;
			} 
		}
		if (correct) {
			print(szel, l);
			return 0;
		}
		while (szel < szer) {
			for (int i = 0; i < n; i++) {
				if (!((goat >> i) & 1) && ((in_max_clique >> i) & 1)) {
					l ^= (1ll << i);
					r ^= (1ll << i);
					best = 0;
					ll cur = in_max_clique;
					find_max_clique(0, l);
					if (__builtin_popcountll(best) > szel) {
						l ^= (1ll << i);
						r ^= (1ll << i);
						in_max_clique = cur;
						continue;
					}
 					best = 0;
					find_max_clique(0, r);
					szer = __builtin_popcountll(best);
					break;
				}
			}
		}
		//cout << (1ll << n) - 1 - l << " " << r << '\n';
		print(szel, l);
	}
}
