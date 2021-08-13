#include <bits/stdc++.h>

using namespace std;

int n, k, a[1005], ans = 0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("Strawberry.Inp", "r", stdin);
	freopen("Strawberry.Out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1000; i >= 1; i--){
		int cnt = 0;
		vector < int > odd;
		odd.clear();
		for(int j = 1; j <= n; j++){
			cnt += a[j] / i;
			odd.push_back(a[j] % i);
		}
		//cout << i << " " << cnt << '\n';
		for(int j = 1; j <= cnt; j++) odd.push_back(i);
		sort(odd.begin(), odd.end());
		//cout << odd[0] << '\n';
		int sum = 0;
		int r = odd.size() - k - 1;
		int l = max(0, r - k + 1);
		//cout << odd.size() - 1 - r + 1 << '\n';
		for(int j = r; j >= l; j --) sum += odd[j];
		ans = max(ans, sum);
	}
	cout << ans;
}