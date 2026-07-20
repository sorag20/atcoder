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
#define ull unsigned long long // 約1.84*10^19
#define ld long double
#define P pair<int, int>
#define lP pair<ll, ll>
#define ldP pair<ld, ld>
using namespace std;
using namespace atcoder;
//-------------1.型系---------------
//ll const INF = 2e18;

using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m); // main関数内で書く
template<typename T> using vc = vector<T>;
template<typename T> using vvc = vc<vc<T>>;
template<class T> using pq = priority_queue<T, vc<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;//小さい順

//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vvc<ll>; using vvvl = vvc<vl>; using vvvvl = vvc<vvl>;
using vs = vc<string>; using vvs = vvc<string>;
using vb = vc<bool>; using vvb = vvc<bool>; using vvvb = vvc<vb>;
using vld = vc<ld>; using vvld = vvc<ld>; using vvvld = vvc<vld>;
using vmint = vc<mint>; using vvmint = vvc<mint>; using vvvmint = vvc<vmint>;
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

bool chmin(ll &a, ll b) { if (a > b) { a = b; return true; } return false; }
bool chmax(ll &a, ll b) { if (a < b) { a = b; return true; } return false; }

#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
#define YN {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl;

// ↓必ず、直前にsort(all(v));を入れないとuniqueが正しく動作しない
#define vc_unique(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define vc_rotate(v) rotate(v.begin(),v.begin()+1,v.end());

// 文字列のrotate
//rotate(n.begin(), n.begin()+1 ,n.end());

#define pop_cnt(s) ((ll)__builtin_popcountll(s))
#define parity(s) (__builtin_parity(s)) // 1のビット数が奇数個ならTrue, 偶数個ならFalseを返す。
#define next_p(v) next_permutation(v.begin(),v.end())

//---------4.グリッド系----------
//vl dx = { 1,0,-1,0 };//vl dx={1,1,0,-1,-1,-1,0,1};
//vl dy = { 0,1,0,-1 };//vl dy={0,1,1,1,0,-1,-1,-1};

bool out_grid(ll i, ll j, ll h, ll w) {//trueならcontinue
    return (!(0 <= i && i < h && 0 <= j && j < w));
}

#define vvl_rotate(v) {ll h = size(v);ll w = (h>0)?size(v[0]):0;vvl nx(w,vl(h));rep(i,h)rep(j,w)nx[j][h-i-1]=v[i][j];swap(nx,v);}//時計回りに90°回転
#define vvl_rrotate(v) {ll h = size(v);ll w = (h>0)?size(v[0]):0;vvl nx(w,vl(h));rep(i,h)rep(j,w)nx[w-j-1][i]=v[i][j];swap(nx,v);}//反時計周りに90°回転

#define vs_rotate(v) {ll h = size(v);ll w = (h>0)?size(v[0]):0;vs nx(w,string(h,'.'));rep(i,h)rep(j,w)nx[j][h-i-1]=v[i][j];swap(nx,v);}//文字列版 時計回りに90°回転
#define vs_rrotate(v) {ll h = size(v);ll w = (h>0)?size(v[0]):0;vs nx(w,string(h,'.'));rep(i,h)rep(j,w)nx[w-j-1][i]=v[i][j];swap(nx,v);}//文字列版　反時計周りに90°回転

#define vvl_tenti(v) {ll h = size(v);ll w = (h>0)?size(v[0]):0;vvl nx(w,vl(h));rep(i,h)rep(j,w)nx[j][i]=v[i][j];swap(nx,v);}
#define vs_tenti(v) {ll h = size(v);ll w = (h>0)?size(v[0]):0;vs nx(w,string(h,'.'));rep(i,h)rep(j,w)nx[j][i] = v[i][j]; swap(nx, v);}

//-----------5.数学系--------------
#define euclid(x,y) ((x)*(x)+(y)*(y))//ユークリッド距離 sqrtはしてないなので注意
#define manhattan(x1,x2,y1,y2) (abs(x1-x2)+abs(y1-y2)) // マンハッタン距離 = |x1-x2|+|y1-y2|

ll tousa_sum1(ll l, ll d, ll r) {//初項,公差,末項 で総和を求める
    ll wide = (r - l) / d + 1;
    return (l + r) * wide / 2;
}
ll tousa_sum2(ll a, ll d, ll n) {//初項,交差,項数 で総和を求める
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
ll pw(ll x, ll p) {ll res = 1;rep(i,p) res *= x;return res; }

//-----------6.デバックや出力系------------------
void print(ld x) { printf("%.20Lf\n", x); }

#define out(v) {cout<<v<<endl;}
#define v_cout(v){ll n = size(v);rep(i,n)cout<<v[i]<<' ';cout<<endl;}//一次元配列を出力する
#define vv_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){cout<<v[i][j]<<' ';}cout<<endl;}}//二次元配列を出力する
#define vvv_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){ rep(k,(ll)size(v[i][j])) {cout<<v[i][j][k]<<' ';}cout<<endl;}}}//三次元配列を出力する
#define vmint_cout(v){ll n = size(v);rep(i,n)cout<<v[i].val()<<endl;}//mint一次元配列を出力する
#define vvmint_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){cout<<v[i][j].val()<<' ';}cout<<endl;}}//mint二次元配列を出力する
template<class T>
struct NDPrefixSum {
    int dim;
    vector<int> sz;      // 各次元の大きさ
    vector<int> stride;  // 1次元配列へのインデックス変換用
    vector<T> dat;

    NDPrefixSum(const vector<int>& s) : dim((int)s.size()), sz(s), stride(dim) {
        int tot = 1;
        for (int i = dim - 1; i >= 0; i--) {
            stride[i] = tot;
            tot *= (sz[i] + 1);
        }
        dat.assign(tot, T());
    }

    // 座標→1次元インデックス
    int id(const vector<int>& p) const {
        int res = 0;
        for (int i = 0; i < dim; i++) res += p[i] * stride[i];
        return res;
    }

    // 0-indexed座標pにvalを加算 (build()より前に呼ぶこと)
    void add(vector<int> p, T val) {
        for (int& x : p) x++;   // 内部的には1-indexedにずらして持つ
        dat[id(p)] += val;
    }

    // 累積和を構築する。add()を全て呼び終えてから1回だけ呼ぶ
    void build() {
        vector<int> p(dim);
        for (int d = 0; d < dim; d++) {
            function<void(int)> dfs = [&](int dep) {
                if (dep == dim) {
                    for (int x = 1; x <= sz[d]; x++) {
                        p[d] = x;
                        auto q = p;
                        q[d]--;
                        dat[id(p)] += dat[id(q)];
                    }
                    return;
                }
                if (dep == d) { dfs(dep + 1); return; }
                for (p[dep] = 0; p[dep] <= sz[dep]; p[dep]++) dfs(dep + 1);
            };
            dfs(0);
        }
    }

    // [L, R] (0-indexed, 両端含む) の総和を返す。build()の後に呼ぶこと
    T query(const vector<int>& L, const vector<int>& R) const {
        for (int i = 0; i < dim; i++)
            if (L[i] > R[i]) return T();  // いずれかの次元で範囲が空なら答えは0

        T ans = T();
        int ALL = 1 << dim;
        vector<int> p(dim);

        for (int mask = 0; mask < ALL; mask++) {
            bool ok = true;
            for (int i = 0; i < dim; i++) {
                if (mask >> i & 1) {
                    if (L[i] == 0) { ok = false; break; }
                    p[i] = L[i];
                } else {
                    p[i] = R[i] + 1;
                }
            }
            if (!ok) continue;

            if (__builtin_popcount(mask) & 1) ans -= dat[id(p)];
            else ans += dat[id(p)];
        }
        return ans;
    }
};

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n;
    cin >> n;
    NDPrefixSum<ll> ps({10,10,10,10,10,10});
    rep(i,n) {
        string s; ll v;
        cin>>s>>v;
        vc<int> p(6);
        rep(j,6) p[j] = s[j] - '0';
        ps.add(p,v);
    }

    ps.build();
    ll q; cin>>q;


    while(q--) {
        string x,y; cin>>x>>y;
        vc<int> l(6), r(6);
        rep(i,6) {
            l[i] = x[i] - '0';
            r[i] = y[i] - '0';
        }
        out(ps.query(l,r))
    }
    return 0;
}
