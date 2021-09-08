#include <bits/stdc++.h>

using namespace std;

int t, cnt[35];

string del (string s, char ch) {
	string ans = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ch) ans += s[i];
	}
	return ans;
}

string create(string a, string b) {
	string ans = a;
	for (int i = 0; i <= b.size(); i++) {
		a = del(a, b[i]);
		ans += a;
	}
	return ans;
}

void solve () {
	string s;
	cin >> s;
	string tams = s;
	memset(cnt, 0, sizeof(cnt));
	int nums = 0;
	for (int i = 0; i < s.size(); i++) {
		if (cnt[s[i] - 'a'] == 0) nums ++;
		cnt[s[i] - 'a'] ++;
	}
	string ans = "";
	int dem = 0, sizes = 0;
	while (1) {
		if (s == "") break;
		int r = s.size() - 1;
		if (cnt[s[r] - 'a'] % (nums - dem) != 0) {
			cout << -1 << '\n';
			return ;
		}
		ans = s[r] + ans;
		sizes += cnt[s[r] - 'a'] / (nums - dem);
		dem ++;
		s = del(s, s[r]);
	}
	string res = "";
	for (int i = 0; i < sizes; i++) res += tams[i];
	string news = create(res, ans);
	if (news == tams) cout << res << " " << ans << '\n';
	else cout << -1 << '\n';
}

int main() {
	cin >> t;
	while (t --) {
		solve();
	}
}