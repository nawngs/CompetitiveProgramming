#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
int t, n, a[100005];
 
void sol() {
	cin >> n;
	int le = 0, chan = 0;
	queue < int > even;
	queue < int > odd;
	queue < int > tameven;
	queue < int > tamodd;
	//odd.clear();
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) even.push(i);
		else odd.push(i);
		le += (a[i] % 2 == 1);
		chan += (a[i] % 2 == 0);
	}
	tamodd = odd;
	tameven = even;
	long long cnt, ans = 1e18 + 7;
	//dau chan
	if (chan >= le) {
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if ((i + 1) % 2 != a[i] % 2) {
				if((i + 1) % 2 == 0) {
					//cout << i << " " << a[i] << " " << even.front() << '\n';
					if (!even.size()) {
						cnt = 1e18 + 7;
						break;
					}
					cnt += even.front() - i;
					a[even.front()] = 1;
					even.pop();
				}
				else {
					//cout << i << " " << a[i] << " " << odd.front() << '\n';
					if (!odd.size()) {
						cnt = 1e18 + 7;
						break;
					}
					cnt += odd.front() - i;
					a[odd.front()] = 0;
					odd.pop();
				}
			}
			if (i >= odd.front() && odd.size()) odd.pop();
			if (i >= even.front() && even.size()) even.pop();
		}
		ans = min(ans, cnt);
	}
	//dau le
	if (le >= chan) {
		cnt = 0;
		odd = tamodd;
		even = tameven;
		for (int i = 1; i <= n; i++) {
			if (i % 2 != a[i] % 2) {
				if(i % 2 == 0) {
					//cout << i << " " << a[i] << " " << even.front() << '\n';
					if (!even.size()) {
						cnt = 1e18 + 7;
						break;
					}
					cnt += even.front() - i;
					a[even.front()] = 1;
					even.pop();
				}
				else {
					if (!odd.size()) {
						cnt = 1e18 + 7;
						break;
					}
					//cout << i <<  " " << a[i] <<  " " << odd.front() << '\n';
					cnt += odd.front() - i;
					a[odd.front()] = 0;
					odd.pop();
				}
			}
			if (i >= odd.front() && odd.size()) odd.pop();
			if (i >= even.front() && even.size()) even.pop();
		}
		ans = min(ans, cnt);
	}
	if (ans == 1e18 + 7) cout << -1 << '\n';
	else cout << ans << '\n';
	return ;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t --) sol();
}