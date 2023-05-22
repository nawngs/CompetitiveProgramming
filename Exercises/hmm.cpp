#include <bits/stdc++.h>

using namespace std;

int cnt[13], a[13];

bool used[13];

void back_track(int pos, int n) {
	if (pos == n + 1) {
		a[0] = a[n + 1] = 0;
		int dem = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i - 1] < a[i] && a[i] > a[i + 1]) dem ++;
		}
		cnt[dem] ++;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (used[i]) continue;
		a[pos] = i;
		used[i] = 1;
		back_track(pos + 1, n);
		used[i] = 0;
	}
}

int main() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j <= i; j++) cnt[j] = 0;
		back_track(1, i);
		for (int j = 0; j <= i; j++) cout << i << " " << j << " " << cnt[j] << '\n';
	}
}