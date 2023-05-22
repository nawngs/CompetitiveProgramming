#include <iostream>
#include <algorithm>
#include <climits>

const int maxn = 3000+5;
const int inf = INT_MIN;

int T;
int n, m;
int a[maxn][maxn], d[maxn][maxn];
int arrow_left[maxn], arrow_right[maxn];
int ans, now;
int diff, diff1, diff2;

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				std::cin >> a[i][j];
			}
		}
		ans = 1;
		if (m > 1) {
			ans = std::max(ans, 2);
			for (int i = 1; i <= n; i++) {
				now = 2;
				diff = a[i][2]-a[i][1];
				for (int j = 3; j <= m; j++) {
					if (a[i][j] - a[i][j-1] == diff) {
						now++;
					} else {
						diff = a[i][j] - a[i][j-1];
						now = 2;
					}
					ans = std::max(ans, now);
				}
			}
		}
		if (n > 1) {
			ans = std::max(ans, 2);
			for (int j = 1; j <= m; j++) {
				now = 2;
				diff = a[2][j]-a[1][j];
				for (int i = 3; i <= n; i++) {
					if (a[i][j] - a[i-1][j] == diff) {
						now++;
					} else {
						diff = a[i][j] - a[i-1][j];
						now = 2;
					}
					ans = std::max(ans, now);
				}
			}
		}
		if (n > 1 && m > 1) {
			ans = std::max(ans, 4);
			for (int i = 1; i <= n-1; i++) {
				now = 4;
				diff1 = a[i][2] - a[i][1], diff2 = a[i+1][2] - a[i+1][1];
				for (int j = 3; j <= m; j++) {
					if (a[i][j] - a[i][j-1] == diff1 && a[i+1][j] - a[i+1][j-1] == diff2) {
						now+=2;
					} else {
						diff1 = a[i][j] - a[i][j-1], diff2 = a[i+1][j] - a[i+1][j-1];
						now = 4;
					}
					ans = std::max(ans, now);
				}
			}
			for (int j = 1; j <= m-1; j++) {
				now = 4;
				diff1 = a[2][j] - a[1][j], diff2 = a[2][j+1] - a[1][j+1];
				for (int i = 3; i <= n; i++) {
					if (a[i][j] - a[i-1][j] == diff1 && a[i][j+1] - a[i-1][j+1] == diff2) {
						now+=2;
					} else {
						diff1 = a[i][j] - a[i-1][j], diff2 = a[i][j+1] - a[i-1][j+1];
						now = 4;
					}
					ans = std::max(ans, now);
				}
			}
		}
		if (n >= 3 && m >= 3) {
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= m; j++) {
					d[i][j] = 0;
				}
			}
			for (int i = n-1; i >= 2; i--) {
				for (int j = 2; j <= m-1; j++) {
					int yes = 1;
					if (a[i-1][j+1] - a[i-1][j] != a[i-1][j] - a[i-1][j-1]) {
						yes = 0;
					}
					if (a[i][j+1] - a[i][j] != a[i][j] - a[i][j-1]) {
						yes = 0;
					}
					if (a[i+1][j+1] - a[i+1][j] != a[i+1][j] - a[i+1][j-1]) {
						yes = 0;
					}
					if (a[i+1][j-1] - a[i][j-1] != a[i][j-1] - a[i-1][j-1]) {
						yes = 0;
					}
					if (a[i+1][j] - a[i][j] != a[i][j] - a[i-1][j]) {
						yes = 0;
					}
					if (a[i+1][j+1] - a[i][j+1] != a[i][j+1] - a[i-1][j+1]) {
						yes = 0;
					}
					if (yes) {
						d[i][j] = d[i+1][j] + 1;
					} else {
						d[i][j] = 0;
					}
				}
			}
			for (int i = 2; i <= n-1; i++) {
				d[i][1] = inf;
				d[i][m] = inf;
				for (int j = 2; j <= m-1; j++) {
					if (d[i][j-1] < d[i][j]) {
						arrow_left[j] = j-1;
					} else {
						arrow_left[j] = arrow_left[j-1];
						while (d[i][arrow_left[j]] >= d[i][j]) {
							arrow_left[j] = arrow_left[arrow_left[j]];
						}
					}
				}
				for (int j = m-1; j >= 2; j--) {
					if (d[i][j+1] < d[i][j]) {
						arrow_right[j] = j+1;
					} else {
						arrow_right[j] = arrow_right[j+1];
						while (d[i][arrow_right[j]] >= d[i][j]) {
							arrow_right[j] = arrow_right[arrow_right[j]];
						}
					}
				}
				for (int j = 2; j <= m-1; j++) {
					if (d[i][j] > 0) ans = std::max(ans, (d[i][j]+2)*(arrow_right[j]-arrow_left[j]+1));
				}
			}
		}
		std::cout << ans << '\n';
	}
}