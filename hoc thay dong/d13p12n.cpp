#include <bits/stdc++.h>

#define ld double

using namespace std;

const int NMAX = 40325;
const double INF = 1E9 + 7;
const ld EPS = 1E-130;

int ss, LAST;

ld f[163][NMAX + 3];

int id[87654324], n, pw[15], a[15];

int get(int x, int i) {
	return (x / pw[n - i]) % 10;
}

int change(int x, int i) {
	int pre = get(x, i - 1), cur = get(x, i);
	return x - pre * pw[n - i + 1] - cur * pw[n - i] + cur * pw[n - i + 1] + pre * pw[n - i];
}

ld dp(int s, int cur) {
	int state = id[s], old = s;
	if (cur > 155) return 0;
	// cout << state << " " << cur << " " << f[cur][state] << '\n';
	if (f[cur][state] >= 0) return f[cur][state];
	if (s == LAST) return cur;
	if (cur % 2 == 0) {
		ld res = INF;
		for (int i = 2; i <= n; i++) if (get(old, i - 1) > get(old, i)) 
			res = min(res, dp(change(s, i), cur + 1));
		f[cur][state] = res;
		// cout << cur << " " << state << " " << res << '\n';
		return res;
	}
	ld res = 0;
	for (int i = 2; i <= n; i++) res += dp(change(s, i), cur + 1);
	res /= (1.0 * (n - 1));
	// cout << cur << " " << state << " " << res << '\n';
	return f[cur][state] = res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int c; cin >> c;
		ss = ss * 10 + c;
		LAST = LAST * 10 + i;
	}
	pw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 10;
	for (int i = 1; i <= n; i++) a[i] = i;
	int cur = 0;
	do {
		int val = 0;
		for (int i = 1; i <=n; i++) val = val * 10 + a[i];
		id[val] = ++ cur;
	} while (next_permutation(a + 1, a + n + 1));
	memset(f, 255, sizeof(f));
	cout << fixed << setprecision(5) << dp(ss, 0);
}