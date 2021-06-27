#include <bits/stdc++.h>

using namespace std;

string s, t;
long long z[2000005], z_rev[2000005];

void build_z(string s, long long z[]){
	long long n = s.size();
	 z[0] = n;
	long long l = -1, r = -1;
	for(int i = 1; i < n; i++){
		if(i > r){
			l = i, r = i - 1;
			while(r < n - 1 && s[r + 1] == s[r - l + 1]) r ++;
			z[i] = r - l + 1;	
		}
		else{
			if(z[i - l] < r - i + 1) z[i] = z[i - l];
			else{
				l = i;
				while(r < n - 1 && s[r + 1] == s[r - l + 1]) r++;
				z[i] = r - l + 1;
			}
		}
	}
}

int main(){
	cin >> s >> t;
	s = s + s;

	string t_rev = t;
	reverse(t_rev.begin(), t_rev.end());
	string s_rev = s;
	reverse(s_rev.begin(), s_rev.end());
	string str = t + "#" + s;
	string str_rev = t_rev + "#" + s_rev;
	build_z(str, z);
	build_z(str_rev, z_rev);
	long long t_len = t.size();
	long long s_len = s.size();
	long long ans = 0;
	//cout << str << '\n';
	for(int i = t_len + 1; i < str.size() - t_len; i++){
		if(z[i] >= t_len) ans += t_len;
		else{
			long long last = i + t_len - 1;
			long long last_rev = s_len - (last - t_len) + 1 + t_len;
			//if(i == 10) cout << z[i] << " " << last_rev - (t_len - z[i]) << '\n';
			if(z[i] + z_rev[last_rev] + 1 == t_len) ans ++;
		}
	}
	cout << ans;
}