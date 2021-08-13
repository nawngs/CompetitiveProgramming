//link: https://drive.google.com/file/d/1oebYf14qC6b-EqzMIGblmX34UDgKxbQu/view
#include <bits/stdc++.h>

using namespace std;

int n, m, l, r;

int main(){
	cin >> n >> m;
	l = 1;
	r = n;
	//memset(check, )
	for(int i = 1; i <= m; i++){
		string s1, s2, s3, s4;
		int x;
		cin >> s1 >> s2 >> s3 >> s4 >> x;
		//cout << s3 << '\n';
		if(s3 == "right") l = max(l, x + 1);
		if(s3 == "left") r = min(r, x - 1);
	}
	//cout << max(-1, r - l + 1);
	if(r - l + 1 >= 1) cout << r- l + 1;
	else cout << -1;
}
