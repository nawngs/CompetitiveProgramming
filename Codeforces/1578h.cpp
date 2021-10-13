#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

ll pos[10005], f[10005][10005];

string s;

ll sol(ll l, ll r) {
	//cout << l << " " << r << '\n';
	if (l + 1 == r && s[l] == '(' && s[r] == ')') {
		f[l][r] = 0;
		return f[l][r];
	}
	int i = l + 1;
	while (i < r) {
		//cout << i << '\n';
		if (s[i] == '(') {
			sol(i, pos[i]);
			i = pos[i] + 1;
			continue;
		}
		if (s[i] == '-') {
			sol(i + 2, pos[i + 2]);
			f[pos[i - 1]][pos[i + 2]] = max(f[pos[i - 1]][i - 1] + 1, f[i + 2][pos[i + 2]]);
			i = pos[i + 2] + 1;
		}
	}
	return f[l][r];
}

int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	cin >> s;
	s = '(' + s + ')';
	ll n = s.size();
	s = ' ' + s;
	stack < int > st;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') st.push(i);
		if (s[i] == ')') {
			pos[i] = st.top();
			pos[st.top()] = i;
			st.pop();
		}
	}
	//cout << n << '\n';
	cout << sol(1, n);
}
