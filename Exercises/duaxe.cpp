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

const string NAME = "duaxe";
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

struct Racer {
	int circle, pos, time, id;
} Car[103];

int k, n, m, cur[103];

bool CanMove[103];

int main() {
	fast;
	fre();
	cin >> k >> n >> m;
	for (int i = 1; i <= n; i++) {
		cur[i] = k;
		CanMove[i] = 1;
		Car[i].circle = Car[i].pos = Car[i].time = 0;
		Car[i].id = i;
	}
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		//if (!CanMove[x]) continue;
		int pre = y - 1;
		if (pre == 0) pre += k;
		if (cur[x] != pre) {
			//CanMove[x] = false;
			continue;
		}	
		cur[x] ++;
		if (cur[x] > k) cur[x] -= k;
		if (cur[x] == 1) Car[x].circle ++;
		Car[x].pos = cur[x];
		Car[x].time = i;
	}
	sort(Car + 1, Car + n + 1, [&](Racer &x, Racer &y) {
		if (x.circle != y.circle) return x.circle > y.circle;
		if (x.pos != y.pos) return x.pos > y.pos;
		return x.time < y.time;
	});
	for (int i = 1; i <= n; i++)
		cout << Car[i].id << " ";
}
