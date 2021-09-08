#include <bits/stdc++.h>

using namespace std;

int t;

const int nmax = 60;

string s, pow2[nmax + 5];

string change(long long x) {
	string ans = "";
	while (x > 0) {
		char temp = '0' + (x % 10);
		ans = temp + ans;
		x /= 10;
	}
	return ans;
}

void build_pow() {
	long long temp = 1;
	pow2[0] = "1";
	for (int i = 1; i <= nmax; i++) {
		temp *= 2;
		//cout << temp << " " << change(temp) << '\n';
		pow2[i] = change(temp);
	}
}

int get (string a, string b) {
	int la = 0, lb = 0, sizea = a.size(), sizeb = b.size();
	int res = 0;
	while (la <= sizea - 1 && lb <= sizeb - 1) {
		if (a[la] == b[lb]) {
			la ++;
			lb ++;
			continue;
		}
		else {
			res ++;
			la ++;
		}
	}
	return res + sizea - la + sizeb - lb;
}

void solve() {
	cin >> s;
	int ans = 1e9;
	for (int i = 0; i <= nmax; i++) {
		//cout << pow2[i] << '\n';
		//if (i == 10) cout << get(s, pow2[i]) << '\n';
		//if (get(s, pow2[i]) == 0) cout << i << '\n';
		ans = min(ans, get(s, pow2[i]));
	}
	cout << ans << '\n';
}

int main() {
	build_pow();
	cin >> t;
	while (t --) {
		solve();
	}
}