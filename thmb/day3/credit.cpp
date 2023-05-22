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

const string NAME = "credit";
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

struct Subject {
	ll a, b, id;
} a[300003];

int n, k;

int main() {
	fast;
	//fre();
	int O;
	cin >> O;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].a >> a[i].b;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, [&] (Subject &x, Subject &y) {
		return x.b < y.b;
	});
	multiset < ll > ms;
	ll s_ms = 0, cnt = 0;
	for (int i = n; i >= 1; i--) {
		ms.insert(a[i].a);
		s_ms += a[i].a;
		while (ms.size() > k - cnt) {
			s_ms -= *ms.rbegin();
			ms.erase(*ms.rbegin());
		}
	}
	ll pre_s = 0, ans = INF;
	int pos, cntres;
	for (int i = 0; i <= n; i++) {
		if (ms.size() == k - cnt) {
			if (ans > pre_s + a[i].b + s_ms) {
				ans = pre_s + a[i].b + s_ms;
				pos = i;
				cntres = cnt;
			}
		}
		if (i == 0) cnt ++;
		cnt ++;
		if (cnt > k) break;
		if (i != n && ms.count(a[i + 1].a)) {
			ms.erase(a[i + 1].a);
			s_ms -= a[i + 1].a;
		}
		if (i != 0) {
			pre_s += a[i].a;
			ms.insert(a[i].b - a[i].a);
			s_ms += a[i].b - a[i].a;
		}
		while (ms.size() > k - cnt) {
			s_ms -= *ms.rbegin();
			ms.erase(*ms.rbegin());
		}
	}
	cout << ans << '\n';
	vector < int > res(n + 1);
	res[a[pos].id] = 2;
	multiset < pll > getans; 
	for (int i = 1; i < pos; i++) {
		res[a[i].id] = 1;
		getans.insert({a[i].b - a[i].a, i});
		while (getans.size() > k - cntres) getans.erase(*getans.rbegin());
	}
	for (int i = pos + 1; i <= n; i++) {
		res[a[i].id] = 0;
		getans.insert({a[i].a, i});
		while (getans.size() > k - cntres) getans.erase(*getans.rbegin());
	}
	while (getans.size()) {
		pll tam = *getans.begin();
		if (tam.se < pos) res[a[tam.se].id] = 2;
		else res[a[tam.se].id] = 1;
		getans.erase(*getans.begin());	
	}
	for (int i = 1; i <= n; i++) cout << res[i];
}