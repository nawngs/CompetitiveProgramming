#include<bits/stdc++.h>
using namespace std;

#define db(val) "["#val" = "<<(val)<<"] "
#define FOR(i,l,r) for(int i=(l);i<=(r);i++)
#define FOD(i,l,r) for(int i=(l);i>=(r);i--)
#define REP(i,l,r) for(int i=(l);i<(r);i++)

#define task "MINSTR"

#define all(v) v.begin(),v.end()
#define uniq(v) v.resize(unique(all(v))-v.begin())
#define siz(v) (int32_t)(v.size())

#define left L392324
#define data UWU
#define right H392324

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

using ll=long long;
using pii=pair<int,int>;

template<class T,class U> void MAX(T &x,U y){if(x<y)x=y;}
template<class T,class U> void MIN(T &x,U y){if(y<x)x=y;}

inline ll rand(ll l,ll r){
   return uniform_int_distribution<ll>(l,r)(rd);
}

void RESET();
void AC();

void sinhtest(){
   ofstream cout("input.txt");

   cout.close();
}

int32_t main(){
   cin.tie(0)->ios::sync_with_stdio(0);

//   sinhtest();

   /// [=============================]
         constexpr bool MULTITEST=0;
   /// [=============================]

   ll TESTCASES=1;
   if(MULTITEST)cin>>TESTCASES;

   FOR(test,1,TESTCASES){
      RESET();
      AC();
      cout<<'\n';
   }
}

void RESET(){

}

#define int long long

const int M=1e4+5,N=1e5+5;
const int mod=1e9+7;
const int base=31,num_mod=2;

int pw[N];

struct hs{

vector<int> value={0};
int n;

hs(){
   n=0;
}

void add(const char &x){
   value.push_back(0);
   ++n;
   REP(i,0,num_mod){
      value[n]=1ll*(1ll*value[n-1]*base+x-'a'+1)%mod;
   }
}

int get(int l,int r){
   if(l>r)return 0;
   return (value[r]-value[l-1]*pw[r-l+1]+mod*mod)%mod;
}

};

bool suf[N];
hs b[M];
hs init;
int m,n;

bool ok(int len){
   FOR(i,0,n+1)suf[i]=1;
   set<int> existed;
   FOR(i,1,m){
      int n=b[i].n;
      for(int j=1;j+len-1<=n;j++){
         existed.insert(b[i].get(j,j+len-1));
      }
   }
   FOD(i,n,1){
      int xet_len=min(i+len-1,n)-i+1;
      int xet=init.get(i,min(i+len-1,n));
      if(xet_len<len)xet=xet*pw[len-xet_len]+init.get(1,len-xet_len);
      bool cur=(existed.find(xet)==existed.end());
      suf[i]=(suf[i+1]&cur);
   }
   bool pre=1;
   FOR(i,1,n){
      bool cur=1;
      if(i>=len){
         int xet=init.get(i-len+1,i);
         cur=(existed.find(xet)==existed.end());
      }
      pre&=cur;
      if(pre&&suf[i+1])
         return 1;
   }
   return 0;
}

void AC(){
   pw[0]=1;
   REP(i,1,N)pw[i]=pw[i-1]*base%mod;
   cin>>n>>m;
   FOR(i,1,n){
      char x;cin>>x;
      init.add(x);
   }
   FOR(i,1,m){
      string s;cin>>s;
      for(char x:s)b[i].add(x);
   }
   int l=1,r=n,ans=n+1;
   while(l<=r){
      int mid=(l+r)/2;
      if(ok(mid)){
         ans=mid;
         r=mid-1;
      }else l=mid+1;
   }
   cout<<ans-1;
}