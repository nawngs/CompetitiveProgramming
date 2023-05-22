#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c)	for(auto &(i) : (c))
#define x     first
#define y     second
#define pb  push_back
#define PB  pop_back()
#define iOS  ios_base::sync_with_stdio
#define mp(a,b) make_pair(a,b)
#define sqr(a)  ((1LL * (a) * (a)))
#define all(a)  a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl                                                                 
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a) 
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define double long double
typedef pair<int,int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>	os;
typedef long long ll;
inline bool isprime(int x){
	for(int i = 2;i * i <= x && i < x;i ++ )
		if(x % i == 0)	return false;
	return true;
}
const int maxn = 2e4 + 10, maxl = 17, mod = 1e9 + 7;
int a[maxn];
vector<int> p;
typedef vector<int> vi;
vi rmq[maxn][maxl];
int lg[maxn], pw[maxn];
inline vi LCM(vi a, vi b){
	vi c(p.size());
	For(i,0,p.size())
		c[i] = max(a[i], b[i]);
	return c;
}
inline vi tovi(int a){
	vi v;
	For(i,0,p.size()){
		int x = 0;
		while(a % p[i] == 0)
			a /= p[i], x ++ ;
		v.pb(x);
	}
	return v;
}
inline vi RMQ(int l,int r){
	int g = lg[r-l+1];
	return LCM(rmq[l][g],rmq[r - pw[g] + 1][g]);
}
inline bool cmp(const vi &a,const vi &b){
	double x = .0, y = .0;
	For(i,0,p.size()){
		For(j,0,a[i])
			x += log((double)p[i]);
		For(j,0,b[i])
			y += log((double)p[i]);
	}
	return x < y;
}
vi ans[maxn];
int ANS[maxn];
inline void toint(int x){
	ANS[x] = 1;
	For(i,0,p.size())
		For(j,0,ans[x][i])
			ANS[x] = (1LL * ANS[x] * p[i])%mod;
}
int main(int argc,char ** argv){
	iOS(false);
	For(i,2,60)
		if(isprime(i))
			p.pb(i);
	fill(ans,ans+maxn,vi(p.size(),7));
	int LG = 0, cur = 1;
	For(i,0,maxn){
		pw[i] = 1 << i;
		while(cur * 2 <= i)
			cur *= 2, LG ++ ;
		lg[i] = LG;
	}
	int n,m;
	cin >> n >> m;
	For(i,0,n)
		cin >> a[i];
	For(j,0,maxl)
		For(i,0,n)if(i + pw[j] <=n){
			if(!j)
				rmq[i][j] = tovi(a[i]);
			else
				rmq[i][j] = LCM(rmq[i][j-1], rmq[i + pw[j-1]][j-1]);
		}
	For(i,0,n){
		int ls = i;
		vi v = tovi(a[i]);
		int l,r,mid	;
		while(ls < n-1){
			l = ls + 1, r = n-1;
			while(l < r){
				mid = (l+r)/2;
				if(RMQ(i,mid) == v)
					l = mid + 1;
				else
					r = mid;
			}
			l = min(l,n-1);
			ans[l - i] = min(ans[l - i], v, cmp);
			v = RMQ(i,l);
			ls = l;
		}
		ans[n - i] = min(ans[n - i], v, cmp);
	}
	rof(i,maxn-2,0){
		ans[i] = min(ans[i], ans[i+1], cmp);
		toint(i);
	}
	int x;
	while(m--){
		cin >> x;
		cout << ANS[x] << endl;
	}
}

