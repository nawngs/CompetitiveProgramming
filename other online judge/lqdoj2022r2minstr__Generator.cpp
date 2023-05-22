///sinhtest.cpp
#include<bits/stdc++.h>
using namespace std;

#define db(val) "["#val" = "<<(val)<<"] "
#define FOR(i,l,r) for(int i=(l);i<=(r);i++)
#define FOD(i,l,r) for(int i=(l);i>=(r);i--)
#define REP(i,l,r) for(int i=(l);i<(r);i++)

#define all(v) v.begin(),v.end()
#define uniq(v) v.resize(unique(all(v))-v.begin())

mt19937_64 random(chrono::steady_clock::now().time_since_epoch().count());

using ll=long long;

template<class T,class U> void MAX(T &x,U y){if(x<y)x=y;}
template<class T,class U> void MIN(T &x,U y){if(y<x)x=y;}

inline ll rand(ll l,ll r){
   return uniform_int_distribution<ll>(l,r)(random);
}

int32_t main(){
   cin.tie(0)->ios::sync_with_stdio(0);

//   freopen("test_input.inp","w",stdout);

   const int lim=500;

   int n,m;
   n=rand(1,lim);
   m=rand(1,lim);
   cout<<n<<' '<<m<<'\n';
   FOR(i,1,n)cout<<char(rand('a','z'));
   cout<<'\n';
   FOR(i,1,m){
      int sz=rand(1,lim);
      FOR(i,1,sz)cout<<char(rand('a','z'));
      cout<<'\n';
   }
}