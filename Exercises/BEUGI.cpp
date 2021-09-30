#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")

#include <bits/stdc++.h>
 
using namespace std;
 
long long n, a[1000005], b[1000005], k;
 
long long ans = 0;
 
vector < long long > wao, bao, wquan, bquan;
 
long long bs(vector < long long > a, long long val) {
	long long l = 0, r = a.size() - 1, mid, res = -1;
	while (l <= r) {
		//cout << l << " " << r << " " << mid << " " << a[mid] << " " << val << "\n";
		mid = (l + r) / 2;
		if (a[mid] <= val) {
			res = mid;
			l = mid + 1;
		} 
		else r = mid - 1;
	}
	return res;
}
 
long long bs2(vector < long long > a, long long val) {
	long long l = 0, r = a.size() - 1, mid, ans = -1;
	while (l <= r) {
		//cout << mid << '\n';
		mid = (l + r) / 2;
		if (a[mid] >= val) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		long long x;
		cin >> x;
		if (x == 0) wao.push_back(a[i]);
		else bao.push_back(a[i]);
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		long long x;
		cin >> x;
		if (x == 0) wquan.push_back(a[i]);
		else bquan.push_back(a[i]);
	}
	sort(wquan.begin(),wquan.end());
	sort(bquan.begin(),bquan.end());	
 	//cout << 1323 << '\n';
 	//cout << bquan[1] << '\n';
	for (int i = 0; i < wao.size(); i++) {
		long long temp1 = bs2(bquan, wao[i] - k);
		long long temp2 = bs(bquan, wao[i] + k);
		if (temp1 == -1 || temp2 == -1 || temp1 > temp2) continue;
		ans += temp2 - temp1 + 1;
	}
	for (int i = 0; i < bao.size(); i++) {
		long long temp1 = bs2(wquan, bao[i] - k);
		long long temp2 = bs(wquan, bao[i] + k);
		if (temp1 == -1 || temp2 == -1 || temp1 > temp2) continue;
		ans += temp2 - temp1 + 1;
	}
	cout << ans;
}