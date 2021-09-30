#include <bits/stdc++.h>

using namespace std;

int q, n, a[20005];

char digit[30];

void sol() {
	cin >> n;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 26 && i != 1) {
			cout << -1 << '\n';
			return;
		}
		if (a[i] > 26) {
			cout << -1 << '\n';
			return ;
		}
	}
 	string ans = "z";
 	a[1] --;
 	for (int i = 1; i <= n; i++) {
 		if (i % 2 == 1) {
 			for (int j = a[i]; j >= 1; j--) {
 				//cout << digit[j] << '\n';
 				ans += digit[j];
 			}
 		}
 		else {
 			if (ans[ans.size() - 1] == 'z') {
 				cout << -1 << '\n';
 				return ;
 			}
 			for (int j = 2; j <= a[i]; j++) {
 				ans += digit[j];
 			}
 			if ((a[i] + 1 > a[i + 1]) || i == n) ans += digit[a[i] + 1];
 			else ans += digit[a[i + 1] + 1];
 		}
 	}
 	cout << ans << '\n';
}

int main() {
	cin >> q;
	for (int i = 1; i <= 28; i++) {
		char c = 'a' + i - 1;
		digit[i] = c;
	}
	while (q --) sol();
}
