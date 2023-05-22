#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Line {
	ll a, b;
};

ll n, a[200003], s[200003], ss[200003];

Line it[800003];

vector < pair < long long, long long > > v;
 
double get_x(double a1, double b1, double a2, double b2) {
	return (b2-b1)/(a1-a2);
}
 
double get_x(pair < long long, long long > a, pair < long long, long long > b) {
	return get_x(a.first,a.second,b.first,b.second);
}
 
long long evaluate(pair < long long, long long > a, long long x) {
	return (long long)(a.first*x+a.second);
}
 
void add_line(pair < long long, long long > a) {
	while(v.size()>=2 && get_x(a,v[v.size()-2])>get_x(v[v.size()-1],v[v.size()-2])) v.pop_back();
	v.push_back(a);
}
 
long long get_max(long long x) {
	int i,left,right,middle;
	if(v.size()==1) return evaluate(v[0],x);
	if(x<get_x(v[v.size()-1],v[v.size()-2])) return evaluate(v[v.size()-1],x);
	left=(-1);
	right=v.size()-2;
	while(right-left>1) {
		middle=(left+right)>>1;
		if(x>=get_x(v[middle],v[middle+1])) right=middle;
		else left=middle;
	}
	return evaluate(v[right],x);
}

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		ss[i] = ss[i - 1] + s[i];
	}
	ll res = 0;
	add_line({0, 0});
	for (int i = 1; i <= n; i++) {
		res = max(res, get_max(s[i]) + i * s[i] - ss[i - 1]);
		add_line({-i, ss[i - 1]});
	}
	cout << res;
}
