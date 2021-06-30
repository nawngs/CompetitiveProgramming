#include <bits/stdc++.h>

using namespace std;

string a, b;
int z[200005];

int main(){
	cin >> a >> b;
	string c = "";
	c = b + "#" + a;
	//cout << c << '\n';
	int n = c.size();
	z[0] = n;
	int l, r;
	l = r = -1;
	for(int i = 1; i < n; i++){
		if(r < i){
			l = i;
			r = i - 1;
			while(r < n - 1 && c[r + 1] == c[r - l + 1]) r++;
			z[i] = r - l + 1;
		}
		else{
			if(z[i - l] < r - i + 1) z[i] = z[i - l];
			else{
				l = i;
				while(r < n - 1 && c[r + 1] == c[r - l + 1]) r++;
				z[i] = r - l + 1;
			}
		}
	}
	for(int i = b.size() + 1; i < n; i++){
		//cout << i << " " << z[i] << '\n';
		if(i + z[i] == n || i == n - 1){
			//cout << i << '\n';
			cout << a;
			for(int j = z[i]; j < b.size(); j++) cout << b[j];
			return 0;
		}
	}
}