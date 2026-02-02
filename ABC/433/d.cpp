#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <regex>
#include <math.h>
#include <random>
#include <algorithm>
#define ll long long
#define ld long double
#define P pair<int, int>
#define lP pair<ll, ll>
using namespace std;
using namespace atcoder;
//-------------1.型系---------------
//ll const INF = 2e18;

//using mint = modint998244353;
//using mint = modint1000000007;
using mint = modint;
//mint::set_mod(m); // main関数内で書く
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<class T> using pq = priority_queue<T, vc<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;//小さい順

//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>; using vvvvl = vv<vvl>;
using vs = vc<string>; using vvs = vv<string>;
using vb = vc<bool>; using vvb = vv<bool>; using vvvb = vv<bool>;
using vld = vc<ld>; using vvld = vv<ld>; using vvvld = vv<vld>;
using vmint = vc<mint>; using vvmint = vv<mint>; using vvvmint = vv<vmint>;
#define rep(i,x) for(ll i=0;i<x;i++)
template<class T>istream& operator>>(istream& i, vc<T>& v) { rep(j, (ll)size(v))i >> v[j]; return i; }

//--------3.コード短縮化---------
#define pb push_back
#define eb emplace_back
#define em emplace
#define pob pop_back

#define rrep(i,x) for(ll i=1;i<=x;i++)
#define drep(i,x) for(ll i=x-1;i>=0;i--)
#define nfor(i,s,n) for(ll i=s;i<n;i++)//i=s,s+1...n-1 ノーマルfor
#define dfor(i,s,n) for(ll i = (s)-1; i>=n;i--)//s-1スタートでnまで落ちる

#define all(x) begin(x), end(x)
#define gall(x) begin(x), end(x), greater<>()

void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define YN {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl

#define vc_unique(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define vc_rotate(v) rotate(v.begin(),v.begin()+1,v.end());

#define pop_cnt(s) ll(popcount(uint64_t(s)))
#define next_p(v) next_permutation(v.begin(),v.end())

//---------4.グリッド系----------
//vl dx = { 1,0,-1,0 };//vl dx={1,1,0,-1,-1,-1,0,1};
//vl dy = { 0,1,0,-1 };//vl dy={0,1,1,1,0,-1,-1,-1};

bool out_grid(ll i, ll j, ll h, ll w) {//trueならcontinue
    return (!(0 <= i && i < h && 0 <= j && j < w));
}

#define vvl_rotate(v) {ll n = size(v);vvl nx(n,vl(n));rep(i,n)rep(j,n)nx[j][n-i-1]=v[i][j];swap(nx,v);}//時計回りに90°回転
#define vvl_rrotate(v) {ll n = size(v);vvl nx(n,vl(n));rep(i,n)rep(j,n)nx[n-j-1][i]=v[i][j];swap(nx,v);}//反時計周りに90°回転

#define vs_rotate(v) {ll n = size(v);vs nx(n,string(n,'.'));rep(i,n)rep(j,n)nx[j][n-i-1]=v[i][j];swap(nx,v);}//文字列版 時計回りに90°回転
#define vs_rrotate(v) {ll n = size(v);vs nx(n,string(n,'.'));rep(i,n)rep(j,n)nx[n-j-1][i]=v[i][j];swap(nx,v);}//文字列版　反時計周りに90°回転

#define vvl_tenti(v) {ll n = size(v);vvl nx(n,vl(n));rep(i,n)rep(j,n)nx[j][i]=v[i][j];swap(nx,v);}
#define vs_tenti(v) {ll n = size(v); vs nx(n, string(n,'.')); rep(i, n)rep(j, n)nx[j][i] = v[i][j]; swap(nx, v);}

//-----------5.数学系--------------
#define euclid(x,y) ((x)*(x)+(y)*(y))//ユークリッド距離 sqrtはしてないなので注意
#define manhattan(x1,x2,y1,y2) (abs(x1-x2)+abs(y1-y2)) // マンハッタン距離 = |x1-x2|+|y1-y2|

template<class T>T tousa_sum1(T l, T d, T r) {//初項,公差,末項 で総和を求める
    T wide = (r - l) / d + 1;
    return (l + r) * wide / 2;
}
template<class T>T tousa_sum2(T a, T d, T n) {//初項,交差,項数 で総和を求める
    return (a * 2 + d * (n - 1)) * n / 2;
}
ll kousa_kousuu(ll l, ll r, ll d) {//初項,末項,交差 で等差数列の項数を求める
    return (r - l) / d + 1;
}
mint touhi_sum(mint a, mint r, ll n) {//初項,公比,項数で等比数列の総和を求める
    if (r == 1) {
        return a * n;
    }
    mint bunsi = a * (r.pow(n) - mint(1));
    mint bunbo = r - 1;
    return bunsi / bunbo;
}

ll nc2(ll x) { return x * (x - 1) / 2; }
ll nc3(ll x) { return x * (x - 1) * (x - 2) / 6; }

//-----------6.デバックや出力系------------------
void print(ld x) { printf("%.20Lf\n", x); }

#define v_cout(v){ll n = size(v);rep(i,n)cout<<v[i]<<endl;}//一次元配列を出力する
#define vv_cout(v){ll n = size(v);rep(i,n){rep(j,size(v[i])){cout<<v[i][j]<<' ';}cout<<endl;}}//二次元配列を出力する

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n,m;
    cin >> n >>m;
    mint::set_mod(m);
    vc<mint> a(n);
    vv <ll> as(11);
    rep(i,n) {
        ll x;
        cin>>x;
        a[i] = x;
        as[to_string(x).size()].pb(x%m);
    }

    mint now = 1;
    ll ans = 0;
    rep(i, 11) {
        unordered_map<ll, ll> mp;
        for (auto x: as[i]) mp[x]++;
        rep(j,n) {
            ans += mp[(-now*a[j]).val()];
        }
        now *= 10;
    }
    cout << ans << endl;

    return 0;
}
