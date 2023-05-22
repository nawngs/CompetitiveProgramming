//link: https://oj.vnoi.info/problem/twosum
#include <bits/stdc++.h>

using namespace std;

int n, a[5005], s[5005];

bool bs(int x, int l, int r){
	int mid;
	while(l <= r){
		int mid = (l + r) / 2;
		if(s[mid] == x){
			return true;
		}
		if(s[mid] > x){
			r = mid - 1;
		}
		if(s[mid] < x) l = mid + 1;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			int sum = s[j] - s[i - 1];
			if(sum % 2 == 1) continue;
			sum /= 2;
			if(bs(sum + s[i - 1], i, j)) ans = max(ans, j - i + 1);
		}
	}
	cout << ans;
}