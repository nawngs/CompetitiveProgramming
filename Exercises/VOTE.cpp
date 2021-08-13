#include <bits/stdc++.h>

using namespace std;

int n, cnt[5005], res = 0;

char a[5005][5005];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			cnt[j] += (a[i][j] == 'X');
			res = max(res, cnt[j]);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) if(cnt[i] == res) ans ++;
	cout << ans << " " << res << '\n';
	for(int i = 1; i <= n; i++) if(cnt[i] == res) cout << i << ' ';
}