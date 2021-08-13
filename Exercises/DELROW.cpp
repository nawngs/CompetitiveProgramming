#include <bits/stdc++.h>

using namespace std;

int n, m;

string s[5003], temp[5003];

vector < string > f[5003];

bool check(int x){
	vector < string > str;
	str.clear();
	for(int i = 1; i <= m; i++){
		str.push_back(f[i][n - x - 1]);
		//cout << f[i][x] << '\n';
	}
	sort(str.begin(), str.end());	
	//cout << str[0] << '\n';
	for(int i = 1; i < str.size(); i++)
		if(str[i] == str[i - 1]) return false;
	return true;
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = " " + s[i];
		//cout << s[i] << '\n';
	}
	//for(int j = 1; j <= m; j++) f[j][n] = "";
	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= m; j++){
			temp[j] = temp[j] + s[i][j];
			f[j].push_back(temp[j]);
		}
	}
	int l = 0, r = n - 1, mid, ans;
	while(l <= r){
		mid = (l + r) / 2;
		bool tmp = check(mid);
		if(tmp){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}