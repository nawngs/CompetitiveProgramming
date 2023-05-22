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

int h, k;

vector < ll > a;

ld calc(pii x) {
	return (ld)x.fi / (ld)x.se;
}

main() {
	fast;
	//fre();
	cin >> h >> k;
	for (int i = 1; i <= k; i++) {
		pii p, xy = {0, 1}, uv = {1, 0};
		ll cur = 1;
		cin >> p.fi >> p.se;
		ld gt = calc(p);
		while (1) {
			pii temp = {xy.fi + uv.fi, xy.se + uv.se};
			ld val = calc(temp);
			if (val == gt)
				break;
			if (gt < val) {
				uv = temp;
				cur *= 2;
			}
			else {
				xy = temp;
				cur = cur * 2 + 1;
			}
		}
		//int cur; cin >> cur;
		a.push_back(cur);
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	//erase(unique(a.begin(), a.end()), a.end());
	deque < int > q;
	ll res = 0, pre = -1;
	while (1) {
        if (a.size() == 1 && !q.size()) break;
        if (!a.size() && q.size() == 1) break;
        if (a.size() == 1 && q.size() == 1 && a.back() == q.front()) break;
		if (q.empty() || (!a.empty() && a.back() > q.front())) {
			if (a.back() != pre) {
				if ((q.empty()) || (q.back() != a.back() / 2))
					q.push_back(a.back() / 2);
				res ++;
				pre = a.back();
			}
			a.pop_back();
		}
		else {
			if (q.front() != pre) {
				if (q.back() != q.front() / 2)
					q.push_back(q.front() / 2);
				res ++;
				pre = q.front();
			}
			q.pop_front();
		}
		if (a.size() + q.size() == 1) break;
	}
	for (int i = 1; i <= n; i++)
		
	cout << res << '\n';
}