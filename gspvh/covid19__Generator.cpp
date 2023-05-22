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

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

long long get_random(long long l, long long r) {
    return l + (rd() % (r - l + 1));
}

bool used[1003];

int main() {
	fast;
	//fre();
	int n = get_random(3, 10), k = get_random(1, n - 1), q = get_random(1, 10);
	cout << n << " " << k << " " << q << '\n';
	while (k --) {
		while (1) {
			int x = get_random(1, n);
			if (used[x]) continue;
			cout << x << " ";
			used[x] = 1;
			break;
		}
	}
	cout << '\n';
	while (q--) {
		int tmp = get_random(1, 2);
		if (tmp == 1) {
			cout << 'P' << " ";
			int p = get_random(1, n - 1);
			cout << p << " " << get_random(p + 1, n) << '\n';
		}
		else {
			cout << "D" << ' ';
			int p = get_random(1, n - 1);
			cout << p << " " << get_random(p + 1, n) << '\n';
		}
	}
}
