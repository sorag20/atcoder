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

#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
#define YN {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl;

// ↓必ず、直前にsort(all(v));を入れないとuniqueが正しく動作しない
#define vc_unique(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define vc_rotate(v) rotate(v.begin(),v.begin()+1,v.end());

#define pop_cnt(s) ((ll)__builtin_popcountll(s))
#define next_p(v) next_permutation(v.begin(),v.end())

//---------4.グリッド系----------
vl dx = { 1,0,-1,0 };//vl dx={1,1,0,-1,-1,-1,0,1};
vl dy = { 0,1,0,-1 };//vl dy={0,1,1,1,0,-1,-1,-1};

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

#define out(v) {cout<<v<<endl;}
#define v_cout(v){ll n = size(v);rep(i,n)cout<<v[i]<<' ';cout<<endl;}//一次元配列を出力する
#define vv_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){cout<<v[i][j]<<' ';}cout<<endl;}}//二次元配列を出力する
#define vvv_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){ rep(k,(ll)size(v[i][j])) {cout<<v[i][j][k]<<' ';}cout<<endl;}}}//三次元配列を出力する
#define vmint_cout(v){ll n = size(v);rep(i,n)cout<<v[i].val()<<endl;}//mint一次元配列を出力する
#define vvmint_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){cout<<v[i][j].val()<<' ';}cout<<endl;}}//mint二次元配列を出力する

// AI関連の関数（将来の改善用にコメントアウトして保持）
/*
// AIプレイヤーpのマス(i,j)に対する評価値を計算
ld calc_eval(ll p, ll i, ll j, ll n, ll m, ll u, vvl& v, vvl& o, vvl& l, vvld& internal_setting) {
    ld wa = internal_setting[p][0];
    ld wb = internal_setting[p][1];
    ld wc = internal_setting[p][2];
    ld wd = internal_setting[p][3];

    ll owner = o[i][j];
    ll level = l[i][j];
    ld value = v[i][j];

    // 誰の領土でもない場合
    if (owner == -1) {
        return value * wa;
    }
    // 自分の領土の場合（プレイヤーpは1-indexed: p+1）
    else if (owner == p + 1) {
        if (level < u) {
            return value * wb;
        } else {
            return 0;
        }
    }
    // 他のプレイヤーの領土の場合
    else {
        if (level == 1) {
            return value * wc;
        } else {
            return value * wd;
        }
    }
}

// プレイヤーpの移動可能なマスを列挙
vc<lP> get_movable(ll px, ll py, ll n, set<lP>& occupied) {
    vc<lP> movable;
    vl dx = {1, 0, -1, 0};
    vl dy = {0, 1, 0, -1};

    rep(i, 4) {
        ll nx = px + dx[i];
        ll ny = py + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (occupied.find({nx, ny}) != occupied.end()) continue;
        movable.pb({nx, ny});
    }

    return movable;
}

// ゲーム状態を更新する（移動後の領土とレベルの変化）
void update_game_state(ll player_id, ll x, ll y, ll u, vvl& o, vvl& l) {
    // player_idは0-indexed (0が自分、1以降がAI)
    ll owner = o[x][y];
    ll level = l[x][y];

    if (owner == -1) {
        // 誰の領土でもない場合: 自分の領土になる(レベル1)
        o[x][y] = player_id;
        l[x][y] = 1;
    } else if (owner == player_id) {
        // 自分の領土の場合: レベルをuまで上げる
        if (level < u) {
            l[x][y] = level + 1;
        }
    } else {
        // 他のプレイヤーの領土の場合: レベルを下げる
        if (level == 1) {
            // レベル1なら奪い取る
            o[x][y] = player_id;
            l[x][y] = 1;
        } else {
            // レベル2以上ならレベルを1下げる
            l[x][y] = level - 1;
        }
    }
}

// AIプレイヤーpの行動を決定
lP decide_ai_move(ll p, vc<lP>& exy, ll n, ll m, ll u, vvl& v, vvl& o, vvl& l,
                  vvld& internal_setting, set<lP>& occupied, ld r1, ld r2) {
    ll px = exy[p + 1].first;
    ll py = exy[p + 1].second;
    ld eps = internal_setting[p][4];

    // 移動可能なマスを取得
    vc<lP> movable = get_movable(px, py, n, occupied);

    if (movable.empty()) {
        return {px, py}; // 移動できない場合は現在位置を返す
    }

    // ランダム行動 vs 貪欲行動の決定
    if (r1 < eps) {
        // ランダム行動
        ll idx = (ll)(r2 * movable.size());
        return movable[idx];
    } else {
        // 貪欲行動
        ld max_eval = -1e18;
        vc<lP> best_moves;

        for (auto [i, j] : movable) {
            ld eval = calc_eval(p, i, j, n, m, u, v, o, l, internal_setting);
            if (eval > max_eval) {
                max_eval = eval;
                best_moves.clear();
                best_moves.pb({i, j});
            } else if (abs(eval - max_eval) < 1e-9) {
                best_moves.pb({i, j});
            }
        }

        ll idx = (ll)(r2 * best_moves.size());
        return best_moves[idx];
    }
}
*/

int main()
{
    ll n,m,t,u;
    cin >> n >> m>> t>>u;
    vvl v(n,vl(n));
    cin>>v;
    vc<lP> exy(m);
    set<lP> st;
    rep(i,m) {
        ll row,col; cin>>row>>col;
        exy[i] = {row,col};
        st.insert({row,col});
    }
    lP me = {exy[0].first, exy[0].second};
    auto random_ct = mt19937(10);

    vc<lP> txy(m);
    vvl o(n,vl(n,-1));
    vvl l(n,vl(n,0));

    rep(i,m) {
        ll x = exy[i].first;
        ll y = exy[i].second;
        o[x][y] = i;
        l[x][y] = 1;
    }
    ll turn_count = 0;
    while(t--) {
        if (turn_count > 0) {
            rep(i,m) {
                ll x,y; cin>>x>>y;
                txy[i] = {x,y};
            }

            st.clear();
            rep(i,m) {
                ll x,y; cin>>x>>y;
                exy[i] = {x,y};
                st.insert({x,y});
            }
            me = {exy[0].first, exy[0].second};

            rep(i,n) {
                rep(j,n) {
                    ll k; cin>>k;
                    o[i][j] = k;
                }
            }

            rep(i,n) {
                rep(j,n) {
                    ll k; cin>>k;
                    l[i][j] = k;
                }
            }
        }

       // プレイヤー0の移動を決定（他のプレイヤーの位置を避ける）
        ll nrow, ncol;
        while(1) {
            ll di = random_ct()%4;
            nrow = me.first + dx[di];
            ncol = me.second + dy[di];
            if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= n) continue;

            bool occupied = false;
            rep(i,m) {
                if (i == 0) continue;
                if (exy[i].first == nrow && exy[i].second == ncol) {
                    occupied = true;
                    break;
                }
            }
            if (!occupied) {
                break;
            }
        }

        cout << nrow << " " << ncol << endl;
        cout.flush();
        me = {nrow, ncol};
        turn_count++;
    }

    return 0;
}
