//link: https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/B
#include <bits/stdc++.h>

using namespace std;

int t, n, cnt_row_x[53], cnt_row_o[53], cnt_col_x[53], cnt_col_o[53];
string s[53];

void sol(int index) {
	memset(cnt_col_o, 0, sizeof(cnt_col_o));
	memset(cnt_col_x, 0, sizeof(cnt_col_x));
	memset(cnt_row_o, 0, sizeof(cnt_row_o));
	memset(cnt_row_x, 0, sizeof(cnt_row_x));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
		for (int j = 1; j <= n; j++) {
			if (s[i][j] == 'X') cnt_row_x[i] ++;
			if (s[i][j] == 'O') cnt_row_o[i] ++;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[j][i] == 'X') cnt_col_x[i] ++;
			if (s[j][i] == 'O') cnt_col_o[i] ++;
		}
	}
	int ans = 1e9 + 7, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt_col_o[i] == 0) {
			if (ans > n - cnt_col_x[i]) {
				ans = n - cnt_col_x[i];
				cnt = 1;
			}
			else  if(ans == n - cnt_col_x[i]) cnt ++;
		}

		if (cnt_row_o[i] == 0) {
			if (ans > n - cnt_row_x[i]) {
				ans = n - cnt_row_x[i];
				cnt = 1;
			}
			else  if(ans == n - cnt_row_x[i]) cnt ++;
		}
	}
	cout << "Case #" << index << ": ";
	if (ans == 1e9 + 7) {
		cout << "Impossible" << '\n';
		return ;
	}
	if (ans == 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (s[i][j] == '.' 
					&& cnt_col_o[i] == 0 && n - cnt_col_x[i] == 1
					&& cnt_row_o[j] == 0 && n - cnt_row_x[j] == 1) {
					cnt --;
				}
			}
		}
	}
	cout << ans << " " << cnt;
	cout << '\n';
	return ;
}

int main() {
	freopen("CSANG.inp", "r", stdin);
	freopen("CSANG.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) 
		sol(i);
	
}