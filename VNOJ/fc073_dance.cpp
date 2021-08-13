//link: https://oj.vnoi.info/problem/fc073_dance
#include <bits/stdc++.h>

using namespace std;

int n, k;
vector < int > b, g;

int bs1(int x){
	int l = 0, r = g.size() - 1, mid, ans = -1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(g[mid] >= x){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

int bs2(int x){
	int l = 0, r = g.size() - 1, mid, ans = -1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(g[mid] <= x){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(x <= 0) g.push_back(abs(x));
		else b.push_back(x);
	}
	sort(b.begin(), b.end());
	sort(g.begin(), g.end());
	int ans = 0;
	for(int i = 0; i < b.size(); i++){
		int ltemp = bs1(b[i] - k);
		int rtemp = bs2(b[i]);
		if(ltemp != -1 && rtemp != -1 && rtemp >= ltemp) ans += rtemp - ltemp + 1;
	}
	cout << ans;
}