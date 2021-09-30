#include <bits/stdc++.h>

using namespace std;

long long n, a[5005], am[5005], duong[5005], cnt_am = 0, cnt_duong = 0;

long long ans = 1e18;	

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < 0) am[++ cnt_am] = a[i];
		else duong[++ cnt_duong] = a[i];
	}
	sort(am + 1, am + cnt_am + 1, greater < int >());
	sort(duong + 1, duong + cnt_duong + 1);
	if (cnt_duong == 0) {
		sort(am + 1, am + cnt_am + 1, greater < int >());
		for (int i = 0; i <= cnt_am; i += 2) {
			long long maxa = -1e18, mina = 1e18;
			for (int j = 1; j <= i; j++) {	
				maxa = max(maxa, am[j] + am[i - j + 1]);
				mina = min(mina, am[j] + am[i - j + 1]);
			}
			for (int j = i + 1; j <= cnt_am; j++) {
				maxa = max(maxa, am[j]);
				mina = min(mina, am[j]);
			}
			//cout << maxa << " " << mina << '\n';
			ans = min(ans, maxa - mina);
		}
		cout << ans << '\n';
		return 0;
	}
	if (cnt_am == 0) {
		sort(duong + 1, duong + cnt_duong + 1);
		for (int i = 0; i <= cnt_duong; i += 2) {
			long long maxa = -1e18, mina = 1e18;
			for (int j = 1; j <= i; j++) {	
				maxa = max(maxa, duong[j] + duong[i - j + 1]);
				mina = min(mina, duong[j] + duong[i - j + 1]);
			}
			for (int j = i + 1; j <= cnt_duong; j++) {
				maxa = max(maxa, duong[j]);
				mina = min(mina, duong[j]);
			}
			ans = min(ans, maxa - mina);
		}
		cout << ans << '\n';
		return 0;
	}
	sort(am + 1, am + cnt_am + 1);
	sort(duong + 1, duong + cnt_duong + 1, greater<int>());
	long long maxa = -1e18, mina = 1e18;
	for (int i = 1; i <= min(cnt_duong, cnt_am); i++) {
		maxa = max(maxa, am[i] + duong[i]);
		mina = min(mina, am[i] + duong[i]);
	}
	if (cnt_duong < cnt_am) {
		long long tmpmax = maxa, tmpmina = mina;
		for (int i = cnt_duong + 1; i <= cnt_am; i++) {
			if (i == cnt_am - i + cnt_duong + 1) {
				tmpmax = max(tmpmax, am[i]);
				tmpmina = min(tmpmina, am[i]);
			}
			else {
				tmpmax = max(tmpmax, am[i] + am[cnt_duong - i + cnt_am + 1]);
				tmpmina = min(tmpmina, am[i] + am[cnt_duong - i + cnt_am + 1]);
			}
		}
		for (int i = cnt_duong + 1; i <= cnt_am; i++) {
			maxa = max(maxa, am[i]);
			mina = min(mina, am[i]);
		}	
		cout << min(maxa - mina, tmpmax - tmpmina) << '\n';
		return 0;
	}
	if (cnt_am < cnt_duong) {
		long long tmpmax = maxa, tmpmina = mina;
		for (int i = cnt_am + 1; i <= cnt_duong; i++) {
			if (i == cnt_duong - i + cnt_am + 1) {
				tmpmax = max(tmpmax, duong[i]);
				tmpmina = min(tmpmina, duong[i]);
			}
			else {
				tmpmax = max(tmpmax, duong[i] + duong[cnt_duong - i + cnt_am + 1]);
				tmpmina = min(tmpmina, duong[i] + duong[cnt_duong - i + cnt_am + 1]);
			}
		}
		for (int i = cnt_am + 1; i <= cnt_duong; i++) {
			maxa = max(maxa, duong[i]);
			mina = min(mina, duong[i]);
		}	
		cout << min(maxa - mina, tmpmax - tmpmina) << '\n';
		return 0;
	}
}