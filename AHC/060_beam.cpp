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
#define ldP pair<ld, ld>
using namespace std;
using namespace atcoder;
//-------------1.型系---------------
//ll const INF = 2e18;

//using mint = modint998244353;
using mint = modint1000000007;
//using mint = modint;
//mint::set_mod(m); // main関数内で書く
template<typename T> using vc = vector<T>;
template<typename T> using vvc = vc<vc<T>>;
template<class T> using pq = priority_queue<T, vc<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;//小さい順

//-------------2.配列系--------------
using vl = vc<ll>; using vvl = vvc<ll>; using vvvl = vvc<vl>; using vvvvl = vvc<vvl>;
using vs = vc<string>; using vvs = vvc<string>;
using vb = vc<bool>; using vvb = vvc<bool>; using vvvb = vvc<bool>;
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

void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define YN {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl

// ↓必ず、直前にsort(all(v));を入れないとuniqueが正しく動作しない
#define vc_unique(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define vc_rotate(v) rotate(v.begin(),v.begin()+1,v.end());

#define pop_cnt(s) ((ll)__builtin_popcountll(s))
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
ll pw(ll x, ll p) {ll res = 1;rep(i,p) res *= x;return res; }

//-----------6.デバックや出力系------------------
void print(ld x) { printf("%.20Lf\n", x); }

#define v_cout(v){ll n = size(v);rep(i,n)cout<<v[i]<<' ';cout<<endl;}//一次元配列を出力する
#define vv_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){cout<<v[i][j]<<' ';}cout<<endl;}}//二次元配列を出力する
#define vvv_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){ rep(k,(ll)size(v[i][j])) {cout<<v[i][j][k]<<' ';}cout<<endl;}}}//三次元配列を出力する
#define vmint_cout(v){ll n = size(v);rep(i,n)cout<<v[i].val()<<endl;}//mint一次元配列を出力する
#define vvmint_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){cout<<v[i][j].val()<<' ';}cout<<endl;}}//mint二次元配列を出力する

// ビームサーチ用の状態
struct State {
    ll pos;          // 現在位置
    ll prev_pos;     // 前の位置(戻れない)
    string cone;     // 現在のコーン(手元のアイスの並び)
    bitset<100> tree_red; // 各木がRed(true)かWhite(false)か
    vector<set<string>> inventory; // 各ショップの在庫集合
    ll score;        // スコア(在庫集合の合計サイズ)
    double eval;     // 評価値
    vl actions;      // 行動履歴

    bool operator<(const State& other) const {
        return eval < other.eval;
    }
    bool operator>(const State& other) const {
        return eval > other.eval;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n,m,k,t;
    cin >> n >> m >> k >> t;
    vvl g(n);
    rep(i,m) {
        ll a,b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }

    // 座標を読み込む(不要だが念のため)
    vl x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];

    const ll BEAM_WIDTH = 100; // ビーム幅
    const ll MAX_DEPTH = 500; // 探索する深さ

    auto random_gen = mt19937(42);

    // 初期状態
    State init;
    init.pos = 0;
    init.prev_pos = -1;
    init.cone = "";
    init.tree_red.reset(); // 全ての木が白
    init.inventory = vector<set<string>>(k);
    init.score = 0;
    init.eval = 0;

    vector<State> current_beam;
    current_beam.pb(init);

    vl best_actions;
    ll best_score = 0;

    rep(depth, MAX_DEPTH) {
        vector<State> next_beam;

        for (const State& cur : current_beam) {
            // 行動1: 移動して収穫または納品
            for (ll next_v : g[cur.pos]) {
                if (next_v == cur.prev_pos) continue; // 前の位置には戻れない

                State nxt = cur;
                nxt.prev_pos = cur.pos;
                nxt.pos = next_v;
                nxt.actions.pb(next_v);  // 行動を記録

                if (next_v >= k) {
                    // アイスクリームの木: 収穫
                    if (nxt.tree_red[next_v - k]) {
                        nxt.cone += 'R';
                    } else {
                        nxt.cone += 'W';
                    }
                } else {
                    // アイスクリームショップ: 納品
                    if (nxt.inventory[next_v].find(nxt.cone) == nxt.inventory[next_v].end()) {
                        nxt.inventory[next_v].insert(nxt.cone);
                        nxt.score++;
                    }
                    nxt.cone = "";
                }

                // 評価値: スコア + コーンの長さボーナス + 多様性ボーナス
                nxt.eval = nxt.score * 100 + nxt.cone.size() * 10;

                next_beam.pb(nxt);
            }

            // 行動2: Whiteの木をRedに変更(現在位置がWhiteの木の場合のみ)
            if (cur.pos >= k) {
                ll bit_idx = cur.pos - k;
                if (!cur.tree_red[bit_idx]) {
                    State nxt = cur;
                    nxt.tree_red[bit_idx] = true;
                    nxt.actions.pb(-1);  // 行動2を記録
                    // Redに変更することで将来的な多様性が増す可能性があるのでボーナス
                    nxt.eval = nxt.score * 100 + 50;
                    next_beam.pb(nxt);
                }
            }
        }

        // 評価値でソートしてビーム幅まで絞る
        sort(all(next_beam), greater<State>());
        if (next_beam.size() > BEAM_WIDTH) {
            next_beam.resize(BEAM_WIDTH);
        }

        current_beam = next_beam;

        if (current_beam.empty()) break;

        // ベストスコア更新
        if (current_beam[0].score > best_score) {
            best_score = current_beam[0].score;
        }
    }

    // ベストな状態の行動履歴を出力
    State final_state = current_beam[0];
    for (ll action : final_state.actions) {
        cout << action << endl;
    }

    // 最終的に、貪欲法で残りのステップを埋める
    ll steps = final_state.actions.size();

    while (steps < t) {
        bool found = false;
        for (ll next_v : g[final_state.pos]) {
            if (next_v != final_state.prev_pos) {
                cout << next_v << endl;

                if (next_v >= k) {
                    // 収穫時に行動2を挟む可能性
                    if (!final_state.tree_red[next_v - k] && random_gen() % 3 == 0 && steps + 1 < t) {
                        cout << -1 << endl;
                        final_state.tree_red[next_v - k] = true;
                        steps++;
                    }
                }

                final_state.prev_pos = final_state.pos;
                final_state.pos = next_v;
                steps++;
                found = true;
                break;
            }
        }
        if (!found) break;
    }

    return 0;
}
