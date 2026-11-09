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
#define lll __int128_t // 約-1.7*10^38 ~ 1.7*10^38
#define ulll __uint128_t // 約0 ~ 3.4*10^38
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
#define drep(i,x) for(ll i=(x)-1;i>=0;i--)
#define nfor(i,s,n) for(ll i=s;i<=n;i++)//i=s,s+1...n ノーマルfor
#define dfor(i,s,n) for(ll i = s; i>=n;i--)//sスタートでnまで落ちる

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
#define next_p(v) next_permutation(v.begin(),v.end())
#define parity(s) (__builtin_parity(s)) // 1のビット数が奇数個ならTrue, 偶数個ならFalseを返す。

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
ll pw(ll x, ll p) {ll res = 1;rep(i,p) res *= x;return res; }

ll tousa_sum1(ll l, ll d, ll r) {//初項,公差,末項 で総和を求める
    ll wide = (r - l) / d + 1;
    return (l + r) * wide / 2;
}
ll tousa_sum2(ll a, ll d, ll n) {//初項,交差,項数 で総和を求める
    return (a * 2 + d * (n - 1)) * n / 2;
}
ll tousa_kousuu(ll l, ll r, ll d) {//初項,末項,交差 で等差数列の項数を求める
    return (r - l) / d + 1;
}
ll touhi_sum(ll a, ll r, ll n) {//初項,公比,項数で等比数列の総和を求める
    if (r == 1) {
        return a * n;
    }
    ll bunsi = a * (pw(r, n) - 1LL);
    ll bunbo = r - 1;
    return bunsi / bunbo;
}

ll nc2(ll x) { return x * (x - 1) / 2; }
ll nc3(ll x) { return x * (x - 1) * (x - 2) / 6; }

// C++の三角関数の引数はradian
ld radian(ld deg) { return deg * (numbers::pi / 180.0); }
ld degree(ld rad) { return rad*(180.0/numbers::pi); }

//-----------6.デバックや出力系------------------
void print(ld x) { printf("%.20Lf\n", x); }

ostream& operator<<(ostream& os, __uint128_t v) {
    if (v == 0) return os << '0';
    string s;
    while (v > 0) { s += char('0' + (int)(v % 10)); v /= 10; }
    reverse(s.begin(), s.end());
    return os << s;
}
ostream& operator<<(ostream& os, __int128_t v) {
    if (v < 0) { os << '-'; return os << (__uint128_t)(-v); }
    return os << (__uint128_t)v;
}

#define out(v) {cout<<v<<endl;}
#define v_cout(v){ll n = size(v);rep(i,n)cout<<v[i]<<' ';cout<<endl;}//一次元配列を出力する
#define vv_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){cout<<v[i][j]<<' ';}cout<<endl;}}//二次元配列を出力する
#define vvv_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){ rep(k,(ll)size(v[i][j])) {cout<<v[i][j][k]<<' ';}cout<<endl;}}}//三次元配列を出力する
#define vs_cout(v){ll n = size(v);rep(i,n)cout<<v[i]<<endl;cout<<endl;}
#define vvs_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){cout<<v[i][j]<<endl;}cout<<endl;}}
#define vvvs_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){ rep(k,(ll)size(v[i][j])) {cout<<v[i][j][k]<<endl;}cout<<endl;}}}
#define vmint_cout(v){ll n = size(v);rep(i,n)cout<<v[i].val()<<endl;}//mint一次元配列を出力する
#define vvmint_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){cout<<v[i][j].val()<<' ';}cout<<endl;}}//mint二次元配列を出力する


namespace sol {
struct Timer {
    chrono::steady_clock::time_point st = chrono::steady_clock::now();
    double sec() const { return chrono::duration<double>(chrono::steady_clock::now() - st).count(); }
};
struct Rng {
    uint64_t x = 88172645463325252ULL;
    uint64_t next() { x ^= x << 7; x ^= x >> 9; return x; }
    int nextInt(int n) { return (int)(next() % (uint64_t)n); }
    double nextDouble() { return (next() >> 11) * (1.0 / 9007199254740992.0); }
};

const double TIME_GROUP = 0.3;  // 方式Aの焼きなまし終了時刻
const double TIME_LIMIT = 1.3;  // 方式Bの焼きなまし終了時刻
const double TIME_PM_A = 1.5;   // 方式Aの過去改変BFS終了時刻
const double TIME_PM_B = 1.75;  // 方式Bの過去改変BFS終了時刻
const int CAP = 7; // 土台(高々1)+塔 <= 8 を保証
const int DI[4] = {-1, 1, 0, 0}, DJ[4] = {0, 0, -1, 1};
const char DCH[4] = {'U', 'D', 'L', 'R'};
const int INFD = 1 << 28;

int N, K, NN, S;
vector<char> isFloor;
vector<int> nestPos, nestColor, occ0, sPos, sCol;
vector<vector<int>> D; // D[a][b]: aからbへの近似最短手数(初期盤面の踏み台効果込み)
vector<int> Dp;        // Dp[(a*NN+b)*2+par]: 手数の偶奇がparの近似最短手数
vector<vector<int>> nb; // 同色の近いスライム
Rng rng;

struct Op { int p, k, d, l; };

int stepCell(int u, int d, int l) {
    int i = u / N + DI[d] * l, j = u % N + DJ[d] * l;
    if (i < 0 || i >= N || j < 0 || j >= N) return -1;
    return i * N + j;
}
int dirTo(int from, int to) {
    int di = to / N - from / N, dj = to % N - from % N;
    if (di < 0) return 0;
    if (di > 0) return 1;
    if (dj < 0) return 2;
    return 3;
}

void computeDist() {
    Dp.assign((size_t)NN * NN * 2, INFD);
    vector<int> q(NN * 2);
    rep(a, NN) {
        if (!isFloor[a]) continue;
        int* dist = &Dp[(size_t)a * NN * 2];
        int qh = 0, qt = 0;
        dist[a * 2] = 0; q[qt++] = (int)a * 2;
        while (qh < qt) {
            int st = q[qh++];
            int u = st >> 1, par = st & 1;
            int range = (u == a) ? 1 : 1 + occ0[u];
            rep(d, 4) for (int l = 1; l <= range; l++) {
                int v = stepCell(u, (int)d, l);
                if (v < 0 || !isFloor[v]) break;
                int ns = v * 2 + (par ^ 1);
                if (dist[ns] == INFD) { dist[ns] = dist[st] + 1; q[qt++] = ns; }
            }
        }
    }
    D.assign(NN, vector<int>(NN, INFD));
    rep(a, NN) rep(b, NN) D[a][b] = min(Dp[((size_t)a * NN + b) * 2], Dp[((size_t)a * NN + b) * 2 + 1]);
}

// ---- 厳密シミュレータ(検証用) ----
ll simulate(const vector<Op>& ops) {
    if (ops.size() > 100000) return LLONG_MAX;
    vector<vector<int>> st(NN);
    rep(i, S) st[sPos[i]].push_back(sCol[i]);
    ll rec = 0;
    for (auto& o : ops) {
        int h = (int)st[o.p].size();
        if (!isFloor[o.p] || o.k < 0 || o.k >= h || o.l < 1 || o.l > o.k + 1) return LLONG_MAX;
        int q = o.p;
        for (int l = 1; l <= o.l; l++) {
            q = stepCell(o.p, o.d, l);
            if (q < 0 || !isFloor[q]) return LLONG_MAX;
        }
        if ((int)st[q].size() + h - o.k > 8) return LLONG_MAX;
        vector<int> blk(st[o.p].begin() + o.k, st[o.p].end());
        st[o.p].resize(o.k);
        reverse(blk.begin(), blk.end());
        st[q].insert(st[q].end(), blk.begin(), blk.end());
        for (int p : {o.p, q}) {
            int c = nestColor[p];
            if (c < 0) continue;
            while (!st[p].empty() && st[p].back() == c) { st[p].pop_back(); rec++; }
        }
    }
    return (ll)ops.size() + 100000LL * (S - rec);
}

//==================== 方式A: 同色グループ ====================
vector<vector<int>> grp;
vector<int> gOf, gCost, freeG;

int groupCost(const vector<int>& g) {
    if (g.empty()) return 0;
    int c = 0;
    for (size_t i = 0; i + 1 < g.size(); i++) c += D[sPos[g[i]]][sPos[g[i + 1]]];
    c += D[sPos[g.back()]][nestPos[sCol[g[0]]]];
    return c;
}
int idxIn(const vector<int>& g, int s) {
    rep(i, (ll)g.size()) if (g[i] == s) return (int)i;
    return -1;
}
void setGroup(int id, vector<int>&& g, int cost) {
    grp[id] = std::move(g);
    gCost[id] = cost;
    for (int s : grp[id]) gOf[s] = id;
    if (grp[id].empty()) freeG.push_back(id);
}
int newGroupId() {
    while (!freeG.empty()) {
        int id = freeG.back(); freeG.pop_back();
        if (grp[id].empty()) return id;
    }
    grp.emplace_back(); gCost.push_back(0);
    return (int)grp.size() - 1;
}

void annealGroups(const Timer& timer, double endTime) {
    gOf.assign(S, -1);
    rep(s, S) {
        int id = newGroupId();
        vector<int> g = {(int)s};
        int c = groupCost(g);
        setGroup(id, std::move(g), c);
    }
    ll cur = 0;
    for (int c : gCost) cur += c;
    ll best = cur;
    vector<vector<int>> bestGrp = grp;

    nb.assign(S, {});
    rep(s, S) {
        vector<pair<int, int>> cand;
        rep(t, S) if (t != s && sCol[t] == sCol[s])
            cand.push_back({D[sPos[s]][sPos[t]] + D[sPos[t]][sPos[s]], (int)t});
        sort(cand.begin(), cand.end());
        for (size_t i = 0; i < cand.size() && i < 12; i++) nb[s].push_back(cand[i].second);
    }

    const double T0 = 3.0, T1 = 0.05;
    double startT = timer.sec(), T = T0;
    ll iter = 0;
    while (true) {
        if ((iter & 255) == 0) {
            double p = (timer.sec() - startT) / (endTime - startT);
            if (p >= 1.0) break;
            T = T0 * pow(T1 / T0, p);
        }
        iter++;
        int s = rng.nextInt(S);
        int type = rng.nextInt(10);
        int a = gOf[s];
        if (type < 5) {
            vector<int> na = grp[a];
            na.erase(na.begin() + idxIn(na, s));
            bool toNew = nb[s].empty() || rng.nextInt(10) == 0;
            if (toNew) {
                if (na.empty()) continue;
                vector<int> ng = {s};
                int ca = groupCost(na), cn = groupCost(ng);
                int delta = ca + cn - gCost[a];
                if (delta <= 0 || rng.nextDouble() < exp(-delta / T)) {
                    setGroup(a, std::move(na), ca);
                    int id = newGroupId();
                    setGroup(id, std::move(ng), cn);
                    cur += delta;
                }
            } else {
                int t = nb[s][rng.nextInt((int)nb[s].size())];
                int b = gOf[t];
                if (b == a) {
                    int pos = idxIn(na, t) + rng.nextInt(2);
                    na.insert(na.begin() + pos, s);
                    int ca = groupCost(na);
                    int delta = ca - gCost[a];
                    if (delta <= 0 || rng.nextDouble() < exp(-delta / T)) {
                        setGroup(a, std::move(na), ca);
                        cur += delta;
                    }
                } else {
                    if ((int)grp[b].size() >= CAP) continue;
                    vector<int> ngb = grp[b];
                    int pos = idxIn(ngb, t) + rng.nextInt(2);
                    ngb.insert(ngb.begin() + pos, s);
                    int ca = groupCost(na), cb = groupCost(ngb);
                    int delta = ca + cb - gCost[a] - gCost[b];
                    if (delta <= 0 || rng.nextDouble() < exp(-delta / T)) {
                        setGroup(b, std::move(ngb), cb);
                        setGroup(a, std::move(na), ca);
                        cur += delta;
                    }
                }
            }
        } else if (type < 8) {
            if (nb[s].empty()) continue;
            int t = nb[s][rng.nextInt((int)nb[s].size())];
            int b = gOf[t];
            if (a == b) {
                vector<int> na = grp[a];
                swap(na[idxIn(na, s)], na[idxIn(na, t)]);
                int ca = groupCost(na);
                int delta = ca - gCost[a];
                if (delta <= 0 || rng.nextDouble() < exp(-delta / T)) {
                    setGroup(a, std::move(na), ca);
                    cur += delta;
                }
            } else {
                vector<int> na = grp[a], ngb = grp[b];
                na[idxIn(na, s)] = t;
                ngb[idxIn(ngb, t)] = s;
                int ca = groupCost(na), cb = groupCost(ngb);
                int delta = ca + cb - gCost[a] - gCost[b];
                if (delta <= 0 || rng.nextDouble() < exp(-delta / T)) {
                    setGroup(a, std::move(na), ca);
                    setGroup(b, std::move(ngb), cb);
                    cur += delta;
                }
            }
        } else {
            int sz = (int)grp[a].size();
            if (sz < 2) continue;
            int i = rng.nextInt(sz), j = rng.nextInt(sz);
            if (i == j) continue;
            if (i > j) swap(i, j);
            vector<int> na = grp[a];
            reverse(na.begin() + i, na.begin() + j + 1);
            int ca = groupCost(na);
            int delta = ca - gCost[a];
            if (delta <= 0 || rng.nextDouble() < exp(-delta / T)) {
                setGroup(a, std::move(na), ca);
                cur += delta;
            }
        }
        if (cur < best) { best = cur; bestGrp = grp; }
    }
    grp = bestGrp;
    cerr << "[A] iter " << iter << " best est " << best << endl;
}

vector<int> H; // 移動中の塔/バス以外のスライム数

bool bfsPath(int from, int to, int h, int c, bool allowNest, vector<pair<int, int>>& path) {
    vector<int> dist(NN, -1), par(NN, -1), pd(NN, -1), pl(NN, -1);
    vector<int> q; q.reserve(NN);
    dist[from] = 0; q.push_back(from);
    for (size_t qh = 0; qh < q.size(); qh++) {
        int u = q[qh];
        if (u == to) break;
        int range = H[u] + 1;
        rep(d, 4) for (int l = 1; l <= range; l++) {
            int v = stepCell(u, (int)d, l);
            if (v < 0 || !isFloor[v]) break;
            if (dist[v] != -1) continue;
            if (H[v] + h > 8) continue;
            if (!allowNest && v == nestPos[c] && v != to) continue;
            dist[v] = dist[u] + 1; par[v] = u; pd[v] = (int)d; pl[v] = l;
            q.push_back(v);
        }
    }
    path.clear();
    if (dist[to] == -1) return false;
    for (int v = to; v != from; v = par[v]) path.push_back({pd[v], pl[v]});
    reverse(path.begin(), path.end());
    return true;
}

// 1グループ分を現在の盤面Hで実行し, opsに追記する
bool executeGroupOne(const vector<int>& g, vector<Op>& ops) {
    vector<pair<int, int>> path;
    int c = sCol[g[0]];
    int cur = -1, h = 0;
    for (size_t idx = 0; idx <= g.size(); idx++) {
        bool isNest = (idx == g.size());
        int t = isNest ? nestPos[c] : sPos[g[idx]];
        if (h == 0) {
            if (isNest) break;
            cur = t; H[t]--; h = 1;
            continue;
        }
        if (!bfsPath(cur, t, h, c, false, path) && !bfsPath(cur, t, h, c, true, path)) return false;
        for (auto [d, l] : path) {
            ops.push_back({cur, H[cur], d, l});
            cur = stepCell(cur, d, l);
            if (cur == nestPos[c]) { h = 0; break; }
        }
        if (isNest) { h = 0; continue; }
        if (h == 0) { cur = t; H[t]--; h = 1; }
        else { H[t]--; h++; }
    }
    return true;
}

vector<Op> executeGroups() {
    vector<Op> ops;
    H = occ0;
    for (auto& g : grp) if (!g.empty()) executeGroupOne(g, ops);
    return ops;
}

// ---- 過去改変BFS ----
// 各ユニット(グループ/バス)は回収されるまでスライムが動かないので、操作列を過去(ユニット境界)へ挿入できる。
// 早い時刻ほど盤面にスライム(踏み台)が多く残っており、BFSの経路が短くなりうる。
// 挿入すると後続の操作から見てそのユニットのスライムが先に消えるため、そのマスを出発する操作の k を1減らす。
// 後続操作で l == k+1 (踏み台をフルに使用) のものがあるマスのスライムは先に消せないので、その位置より前には挿入しない。
// exec(u, ops): 現在のHでユニットuを実行してopsに追記(Hからuのスライムを除く)。失敗ならfalse
template <class Exec>
vector<Op> pastModify(const vector<vector<int>>& unitCells, Exec&& exec, const Timer& timer, double endTime, ll& gainOut) {
    int U = (int)unitCells.size();
    vector<int> tl;              // タイムライン上のユニット
    vector<vector<Op>> tlOps;    // 各ユニットの操作列
    vector<int> Hend = occ0;     // 全ユニット実行後の盤面
    vector<int> lastTight(NN), Hi(NN);
    vector<char> inR(NN), mine(NN, 0);
    gainOut = 0;
    rep(u, U) {
        const vector<int>& cells = unitCells[u];
        if (cells.empty()) continue;
        int m = (int)tl.size();
        // 末尾に置く場合(通常の実行)
        H = Hend;
        vector<Op> bestOps;
        if (!exec((int)u, bestOps)) return {};
        int bestPos = m;
        ll endCost = (ll)bestOps.size();
        // 挿入可能な最も早い位置
        fill(lastTight.begin(), lastTight.end(), -1);
        rep(j, m) for (const Op& o : tlOps[j]) if (o.l == o.k + 1) lastTight[o.p] = (int)j;
        int lo = 0;
        for (int x : cells) lo = max(lo, lastTight[x] + 1);
        // 関連マス: 末尾実行時の経路の周辺(ここが変わらない境界は評価を省略)
        fill(inR.begin(), inR.end(), 0);
        auto mark = [&](int p) {
            int pi = p / N, pj = p % N;
            for (int di = -2; di <= 2; di++) for (int dj = -2; dj <= 2; dj++) {
                if (abs(di) + abs(dj) > 2) continue;
                int qi = pi + di, qj = pj + dj;
                if (0 <= qi && qi < N && 0 <= qj && qj < N) inR[qi * N + qj] = 1;
            }
        };
        for (int x : cells) mark(x);
        for (const Op& o : bestOps) { mark(o.p); mark(stepCell(o.p, o.d, o.l)); }
        double deadline = timer.sec() + max(0.0, endTime - timer.sec()) / (double)(U - u);
        Hi = Hend;
        vector<Op> o2;
        for (int i = m - 1; i >= lo; i--) {
            bool rel = false;
            for (int x : unitCells[tl[i]]) { Hi[x]++; if (inR[x]) rel = true; }
            if (!rel) continue;
            if (timer.sec() > deadline) break;
            H = Hi;
            o2.clear();
            if (exec((int)u, o2) && o2.size() < bestOps.size()) { bestOps = o2; bestPos = i; }
        }
        gainOut += endCost - (ll)bestOps.size();
        // 後続操作のkを補正して挿入
        for (int x : cells) mine[x] = 1;
        for (int j = bestPos; j < m; j++) for (Op& o : tlOps[j]) if (mine[o.p]) o.k--;
        for (int x : cells) { mine[x] = 0; Hend[x]--; }
        tl.insert(tl.begin() + bestPos, (int)u);
        tlOps.insert(tlOps.begin() + bestPos, std::move(bestOps));
    }
    vector<Op> ops;
    for (auto& v : tlOps) ops.insert(ops.end(), v.begin(), v.end());
    return ops;
}

//==================== 方式B: 色混在バス ====================
struct LineCell { int y, dd, dir; }; // yから巣へdir方向にdd
vector<vector<LineCell>> lineCells;   // 色ごと
vector<vector<int>> adjCells;
vector<vector<int>> nbAll;            // 色を問わない近いスライム

// バスの中身: v[0..h) を両端キューとみなし, flag=true なら v[h-1] が物理的な上
struct BusSt {
    int x = -1, h = 0;
    int v[9];
    bool flag = true;
    int runTop(bool f, int c) const {
        int r = 0;
        if (f) { for (int i = h - 1; i >= 0 && v[i] == c; i--) r++; }
        else { for (int i = 0; i < h && v[i] == c; i++) r++; }
        return r;
    }
    void popTop(bool f, int p) {
        if (f) h -= p;
        else { for (int i = p; i < h; i++) v[i - p] = v[i]; h -= p; }
    }
    void pushTop(bool f, int c) {
        if (f) v[h++] = c;
        else { for (int i = h; i > 0; i--) v[i] = v[i - 1]; v[0] = c; h++; }
    }
};

const int EV_PICK = 0, EV_DEL = 1;
struct Ev { int type, id, end; }; // pick: id=スライム, end=入れたい端(0:先頭,1:末尾) / del: id=色

struct Option {
    int cost = INFD, mode = -1, y = -1, par = 0, q = 0, dir = -1, dd = 0;
};
// mode: 0=P1(着地回収) 1=P2(飛び乗り回収) 2=回収済み(真下にいる) 3=T1(上端を投げる) 4=T2(巣へ着地)

template <class DF, class HB>
Option pickOption(const BusSt& b, int s, int e, DF&& df, HB&&) {
    Option best, any;
    int sc = sPos[s];
    if (b.x == sc) { Option o; o.cost = 0; o.mode = 2; return o; }
    auto consider = [&](Option o, int end) {
        if (o.cost < any.cost) any = o;
        if (end == e && o.cost < best.cost) best = o;
    };
    rep(par, 2) {
        int t = df(sc, (int)par);
        if (t >= INFD) continue;
        bool f2 = b.flag ^ (bool)par;
        int bottomEnd = f2 ? 0 : 1;
        Option o; o.cost = t; o.mode = 0; o.y = sc; o.par = (int)par;
        consider(o, bottomEnd);
    }
    for (int y : adjCells[sc]) rep(par, 2) {
        int t = df(y, (int)par);
        if (t >= INFD) continue;
        bool f2 = b.flag ^ (bool)par;
        int topEnd = f2 ? 1 : 0;
        Option o; o.cost = t + 1; o.mode = 1; o.y = y; o.par = (int)par;
        consider(o, topEnd);
    }
    return best.cost < INFD ? best : any;
}

template <class DF, class HB>
Option deliverOption(const BusSt& b, int c, DF&& df, HB&& hb) {
    Option best;
    auto better = [&](const Option& o) {
        return o.cost < best.cost || (o.cost == best.cost && o.q > best.q);
    };
    int np = nestPos[c];
    rep(par, 2) {
        int t = df(np, (int)par);
        if (t >= INFD || t == 0) continue;
        bool f2 = b.flag ^ (bool)par;
        int p = b.runTop(f2, c);
        if (p == 0) continue;
        Option o; o.cost = t; o.mode = 4; o.y = np; o.par = (int)par; o.q = p;
        if (better(o)) best = o;
    }
    for (const LineCell& lc : lineCells[c]) rep(par, 2) {
        int t = df(lc.y, (int)par);
        if (t >= INFD || t + 1 > best.cost) continue;
        bool f2 = b.flag ^ (bool)par;
        int p = b.runTop(f2, c);
        if (p == 0) continue;
        int q = min(p, hb(lc.y) + b.h - lc.dd + 1); // k=土台+残り >= dd-1
        if (q <= 0) continue;
        Option o; o.cost = t + 1; o.mode = 3; o.y = lc.y; o.par = (int)par; o.q = q; o.dir = lc.dir; o.dd = lc.dd;
        if (better(o)) best = o;
    }
    return best;
}

// ---- 近似評価 ----
vector<int> pickStamp; int stampCnt = 0;

struct ApproxDF {
    const int* row;
    int operator()(int y, int par) const { return row[y * 2 + par]; }
};

void applyDeliverApprox(BusSt& b, const Option& o) {
    b.x = o.y;
    b.flag ^= (bool)o.par;
    b.popTop(b.flag, o.q);
}

int evalBus(const vector<Ev>& evs) {
    if (evs.empty()) return 0;
    stampCnt++;
    BusSt b;
    int cost = 0;
    auto hb = [&](int y) { return (occ0[y] && pickStamp[y] != stampCnt) ? 1 : 0; };
    auto deliverColor = [&](int c) -> bool {
        rep(it, 4) {
            if (b.h == 0) return true;
            ApproxDF df{&Dp[(size_t)b.x * NN * 2]};
            Option o = deliverOption(b, c, df, hb);
            if (o.cost >= INFD) return true;
            cost += o.cost;
            applyDeliverApprox(b, o);
        }
        return true;
    };
    for (const Ev& ev : evs) {
        if (ev.type == EV_PICK) {
            int s = ev.id;
            if (b.h == 0) {
                b.x = sPos[s]; b.h = 1; b.v[0] = sCol[s]; b.flag = true;
                pickStamp[sPos[s]] = stampCnt;
                continue;
            }
            if (b.h >= CAP) return INFD;
            ApproxDF df{&Dp[(size_t)b.x * NN * 2]};
            Option o = pickOption(b, s, ev.end, df, hb);
            if (o.cost >= INFD) return INFD;
            cost += o.cost;
            if (o.mode == 2) { b.pushTop(!b.flag, sCol[s]); }
            else if (o.mode == 0) { b.flag ^= (bool)o.par; b.x = sPos[s]; b.pushTop(!b.flag, sCol[s]); }
            else { b.flag ^= (bool)o.par; b.x = o.y; b.pushTop(b.flag, sCol[s]); }
            pickStamp[sPos[s]] = stampCnt;
        } else {
            deliverColor(ev.id);
        }
    }
    // 残りを配達
    int guard = 0;
    while (b.h > 0) {
        if (++guard > 40) return INFD;
        ApproxDF df{&Dp[(size_t)b.x * NN * 2]};
        Option o1 = deliverOption(b, b.v[0], df, hb);
        Option o2 = deliverOption(b, b.v[b.h - 1], df, hb);
        Option& o = (o2.cost < o1.cost) ? o2 : o1;
        if (o.cost >= INFD) return INFD;
        cost += o.cost;
        applyDeliverApprox(b, o);
    }
    return cost;
}

// ---- 焼きなまし状態 ----
vector<vector<Ev>> buses;
vector<int> busCost, bOf, freeB;

bool hasPick(const vector<Ev>& e) {
    for (auto& x : e) if (x.type == EV_PICK) return true;
    return false;
}
void setBus(int id, vector<Ev>&& e, int cost) {
    if (!hasPick(e)) e.clear();
    buses[id] = std::move(e);
    busCost[id] = buses[id].empty() ? 0 : cost;
    for (auto& x : buses[id]) if (x.type == EV_PICK) bOf[x.id] = id;
    if (buses[id].empty()) freeB.push_back(id);
}
int newBusId() {
    while (!freeB.empty()) {
        int id = freeB.back(); freeB.pop_back();
        if (buses[id].empty()) return id;
    }
    buses.emplace_back(); busCost.push_back(0);
    return (int)buses.size() - 1;
}
int pickIdx(const vector<Ev>& e, int s) {
    rep(i, (ll)e.size()) if (e[i].type == EV_PICK && e[i].id == s) return (int)i;
    return -1;
}

void annealBuses(const Timer& timer, double endTime) {
    pickStamp.assign(NN, 0);
    bOf.assign(S, -1);
    // 初期解: 方式Aのグループ
    for (auto& g : grp) {
        if (g.empty()) continue;
        vector<Ev> e;
        for (int s : g) e.push_back({EV_PICK, s, 0});
        int id = newBusId();
        int c = evalBus(e);
        if (c >= INFD) {
            // 念のため: 評価不能なら1匹ずつに分ける
            for (int s : g) {
                vector<Ev> e1 = {{EV_PICK, s, 0}};
                int id1 = (s == g[0]) ? id : newBusId();
                int c1 = evalBus(e1);
                setBus(id1, std::move(e1), c1);
            }
            continue;
        }
        setBus(id, std::move(e), c);
    }
    nbAll.assign(S, {});
    rep(s, S) {
        vector<pair<int, int>> cand;
        rep(t, S) if (t != s) cand.push_back({D[sPos[s]][sPos[t]] + D[sPos[t]][sPos[s]], (int)t});
        sort(cand.begin(), cand.end());
        for (size_t i = 0; i < cand.size() && i < 16; i++) nbAll[s].push_back(cand[i].second);
    }
    ll cur = 0;
    for (int c : busCost) cur += c;
    ll best = cur;
    vector<vector<Ev>> bestBuses = buses;
    cerr << "[B] init " << cur << endl;

    const double T0 = 2.0, T1 = 0.1;
    double startT = timer.sec(), T = T0;
    ll iter = 0, acc = 0;
    auto accept = [&](ll delta) { return delta <= 0 || rng.nextDouble() < exp(-delta / T); };
    while (true) {
        if ((iter & 127) == 0) {
            double p = (timer.sec() - startT) / (endTime - startT);
            if (p >= 1.0) break;
            T = T0 * pow(T1 / T0, p);
        }
        iter++;
        int s = rng.nextInt(S);
        int a = bOf[s];
        int type = rng.nextInt(100);
        if (type < 35) {
            // 回収イベントの移動
            vector<Ev> na = buses[a];
            int ia = pickIdx(na, s);
            Ev ev = na[ia];
            na.erase(na.begin() + ia);
            if (rng.nextInt(4) == 0) ev.end ^= 1;
            if (rng.nextInt(20) == 0) {
                vector<Ev> nn = {ev};
                int ca = hasPick(na) ? evalBus(na) : 0;
                if (ca >= INFD) continue;
                int cn = evalBus(nn);
                ll delta = (ll)ca + cn - busCost[a];
                if (accept(delta)) {
                    setBus(a, std::move(na), ca);
                    int id = newBusId();
                    setBus(id, std::move(nn), cn);
                    cur += delta; acc++;
                }
            } else {
                int t = nbAll[s][rng.nextInt((int)nbAll[s].size())];
                int b = bOf[t];
                if (b == a) {
                    int pos = pickIdx(na, t) + rng.nextInt(2);
                    na.insert(na.begin() + pos, ev);
                    int ca = evalBus(na);
                    if (ca >= INFD) continue;
                    ll delta = (ll)ca - busCost[a];
                    if (accept(delta)) { setBus(a, std::move(na), ca); cur += delta; acc++; }
                } else {
                    vector<Ev> nbb = buses[b];
                    int pos = pickIdx(nbb, t) + rng.nextInt(2);
                    nbb.insert(nbb.begin() + pos, ev);
                    int cb = evalBus(nbb);
                    if (cb >= INFD) continue;
                    int ca = hasPick(na) ? evalBus(na) : 0;
                    if (ca >= INFD) continue;
                    ll delta = (ll)ca + cb - busCost[a] - busCost[b];
                    if (accept(delta)) {
                        setBus(b, std::move(nbb), cb);
                        setBus(a, std::move(na), ca);
                        cur += delta; acc++;
                    }
                }
            }
        } else if (type < 50) {
            // 回収イベントの交換
            int t = nbAll[s][rng.nextInt((int)nbAll[s].size())];
            int b = bOf[t];
            if (a == b) {
                vector<Ev> na = buses[a];
                swap(na[pickIdx(na, s)], na[pickIdx(na, t)]);
                int ca = evalBus(na);
                if (ca >= INFD) continue;
                ll delta = (ll)ca - busCost[a];
                if (accept(delta)) { setBus(a, std::move(na), ca); cur += delta; acc++; }
            } else {
                vector<Ev> na = buses[a], nbb = buses[b];
                int ia = pickIdx(na, s), ib = pickIdx(nbb, t);
                swap(na[ia], nbb[ib]);
                int ca = evalBus(na);
                if (ca >= INFD) continue;
                int cb = evalBus(nbb);
                if (cb >= INFD) continue;
                ll delta = (ll)ca + cb - busCost[a] - busCost[b];
                if (accept(delta)) {
                    setBus(a, std::move(na), ca);
                    setBus(b, std::move(nbb), cb);
                    cur += delta; acc++;
                }
            }
        } else if (type < 65) {
            // 挿入端の反転
            vector<Ev> na = buses[a];
            na[pickIdx(na, s)].end ^= 1;
            int ca = evalBus(na);
            if (ca >= INFD) continue;
            ll delta = (ll)ca - busCost[a];
            if (accept(delta)) { setBus(a, std::move(na), ca); cur += delta; acc++; }
        } else if (type < 80) {
            // 配達イベントの挿入
            vector<Ev> na = buses[a];
            vector<int> picks;
            for (auto& x : na) if (x.type == EV_PICK) picks.push_back(sCol[x.id]);
            int c = picks[rng.nextInt((int)picks.size())];
            int pos = rng.nextInt((int)na.size() + 1);
            na.insert(na.begin() + pos, Ev{EV_DEL, c, 0});
            int ca = evalBus(na);
            if (ca >= INFD) continue;
            ll delta = (ll)ca - busCost[a];
            if (accept(delta)) { setBus(a, std::move(na), ca); cur += delta; acc++; }
        } else {
            // 配達イベントの削除 / 移動
            vector<Ev> na = buses[a];
            vector<int> dels;
            rep(i, (ll)na.size()) if (na[i].type == EV_DEL) dels.push_back((int)i);
            if (dels.empty()) continue;
            int i = dels[rng.nextInt((int)dels.size())];
            Ev ev = na[i];
            na.erase(na.begin() + i);
            if (type >= 90) na.insert(na.begin() + rng.nextInt((int)na.size() + 1), ev);
            int ca = evalBus(na);
            if (ca >= INFD) continue;
            ll delta = (ll)ca - busCost[a];
            if (accept(delta)) { setBus(a, std::move(na), ca); cur += delta; acc++; }
        }
        if (cur < best) { best = cur; bestBuses = buses; }
    }
    buses = bestBuses;
    cerr << "[B] iter " << iter << " acc " << acc << " best est " << best << endl;
}

// ---- 実盤面での実行 ----
struct LiveBFS {
    vector<int> dist, prv, pd, pl;
    void run(int from, int h) {
        dist.assign(NN * 2, INFD); prv.assign(NN * 2, -1); pd.assign(NN * 2, -1); pl.assign(NN * 2, -1);
        vector<int> q; q.reserve(NN * 2);
        dist[from * 2] = 0; q.push_back(from * 2);
        for (size_t qh = 0; qh < q.size(); qh++) {
            int st = q[qh];
            int u = st >> 1, par = st & 1;
            int range = H[u] + 1;
            rep(d, 4) for (int l = 1; l <= range; l++) {
                int v = stepCell(u, (int)d, l);
                if (v < 0 || !isFloor[v]) break;
                if (H[v] + h > 8) continue;
                int ns = v * 2 + (par ^ 1);
                if (dist[ns] != INFD) continue;
                dist[ns] = dist[st] + 1; prv[ns] = st; pd[ns] = (int)d; pl[ns] = l;
                q.push_back(ns);
            }
        }
    }
    vector<pair<int, int>> path(int y, int par) const {
        vector<pair<int, int>> res;
        for (int st = y * 2 + par; prv[st] != -1; st = prv[st]) res.push_back({pd[st], pl[st]});
        reverse(res.begin(), res.end());
        return res;
    }
};

struct BusExec {
    vector<Op>& ops;
    BusSt b;
    LiveBFS bfs;
    bool failed = false;
    explicit BusExec(vector<Op>& o) : ops(o) {}

    void autoDeliver(int cell) {
        int c = nestColor[cell];
        if (c < 0 || b.h == 0) return;
        int p = b.runTop(b.flag, c);
        if (p > 0) b.popTop(b.flag, p);
    }
    // バスをpath通りに動かす。途中で空になったらfalse
    bool walk(const vector<pair<int, int>>& path) {
        for (auto [d, l] : path) {
            ops.push_back({b.x, H[b.x], d, l});
            b.x = stepCell(b.x, d, l);
            b.flag = !b.flag;
            autoDeliver(b.x);
            if (b.h == 0) return false;
        }
        return true;
    }
    int df(int y, int par) const { return bfs.dist[y * 2 + par]; }
    void startAt(int s) {
        b.x = sPos[s]; b.h = 1; b.v[0] = sCol[s]; b.flag = true;
        H[sPos[s]]--;
    }
    // 1回の配達を試みる。何か進展があればtrue
    bool deliverOnce(int c) {
        if (b.h == 0) return false;
        bfs.run(b.x, b.h);
        auto hb = [&](int y) { return H[y]; };
        auto dff = [&](int y, int par) { return df(y, par); };
        Option o = deliverOption(b, c, dff, hb);
        if (o.cost >= INFD) return false;
        int before = b.h;
        if (!walk(bfs.path(o.y, o.par))) return true;
        if (o.mode == 3) {
            int p = b.runTop(b.flag, c);
            int q = min(p, H[b.x] + b.h - o.dd + 1);
            if (q > 0) {
                ops.push_back({b.x, H[b.x] + b.h - q, o.dir, o.dd});
                b.popTop(b.flag, q);
                autoDeliver(b.x);
            }
        }
        return b.h < before;
    }
    void deliverColor(int c) {
        rep(it, 6) {
            if (b.h == 0 || (b.runTop(true, c) == 0 && b.runTop(false, c) == 0)) return;
            if (!deliverOnce(c)) return;
        }
    }
    // 端の色のうち一番安く配達できるものを1回配達
    bool flushOnce() {
        if (b.h == 0) return false;
        bfs.run(b.x, b.h);
        auto hb = [&](int y) { return H[y]; };
        auto dff = [&](int y, int par) { return df(y, par); };
        Option o1 = deliverOption(b, b.v[0], dff, hb);
        Option o2 = deliverOption(b, b.v[b.h - 1], dff, hb);
        int c = (o2.cost < o1.cost) ? b.v[b.h - 1] : b.v[0];
        return deliverOnce(c);
    }
    void flushAll() {
        int guard = 0;
        while (b.h > 0) {
            if (++guard > 200 || ops.size() > 100000) { failed = true; return; }
            if (!flushOnce()) { failed = true; return; }
        }
    }
    void pick(int s, int e) {
        int sc = sPos[s];
        if (b.h == 0) { startAt(s); return; }
        int guard = 0;
        while (b.h >= CAP) {
            if (++guard > 50 || !flushOnce()) { failed = true; return; }
        }
        if (b.h == 0) { startAt(s); return; }
        if (b.x == sc) { H[sc]--; b.pushTop(!b.flag, sCol[s]); return; }
        bfs.run(b.x, b.h);
        auto hb = [&](int y) { return H[y]; };
        auto dff = [&](int y, int par) { return df(y, par); };
        Option o = pickOption(b, s, e, dff, hb);
        if (o.cost >= INFD) { failed = true; return; }
        if (!walk(bfs.path(o.y, o.par))) { startAt(s); return; }
        if (o.mode == 0) {
            H[sc]--; b.pushTop(!b.flag, sCol[s]);
        } else {
            ops.push_back({sc, 0, dirTo(sc, b.x), 1});
            H[sc]--; b.pushTop(b.flag, sCol[s]);
            autoDeliver(b.x);
        }
    }
};

bool executeBusOne(const vector<Ev>& evs, vector<Op>& ops) {
    BusExec ex(ops);
    for (const Ev& ev : evs) {
        if (ev.type == EV_PICK) ex.pick(ev.id, ev.end);
        else ex.deliverColor(ev.id);
        if (ex.failed) return false;
    }
    ex.flushAll();
    return !ex.failed;
}

vector<Op> executeBuses() {
    vector<Op> ops;
    H = occ0;
    for (auto& evs : buses) {
        if (evs.empty()) continue;
        if (!executeBusOne(evs, ops)) return {};
    }
    return ops;
}

void solve() {
    Timer timer;
    cin >> N >> K;
    NN = N * N;
    vector<string> G(N);
    rep(i, N) cin >> G[i];
    isFloor.assign(NN, 0); occ0.assign(NN, 0); nestPos.assign(K, -1); nestColor.assign(NN, -1);
    rep(i, N) rep(j, N) {
        char ch = G[i][j];
        int p = (int)(i * N + j);
        if (ch == '#') continue;
        isFloor[p] = 1;
        if ('a' <= ch && ch <= 'l') { occ0[p] = 1; sPos.push_back(p); sCol.push_back(ch - 'a'); }
        else if ('A' <= ch && ch <= 'L') { nestPos[ch - 'A'] = p; nestColor[p] = ch - 'A'; }
    }
    S = (int)sPos.size();
    adjCells.assign(NN, {});
    rep(u, NN) if (isFloor[u]) rep(d, 4) {
        int v = stepCell((int)u, (int)d, 1);
        if (v >= 0 && isFloor[v]) adjCells[u].push_back(v);
    }
    lineCells.assign(K, {});
    rep(c, K) rep(d, 4) for (int l = 1; l <= 8; l++) {
        int y = stepCell(nestPos[c], (int)d, l);
        if (y < 0 || !isFloor[y]) break;
        lineCells[c].push_back({y, l, (int)(d ^ 1)}); // 0<->1, 2<->3 が逆方向
    }
    computeDist();

    annealGroups(timer, TIME_GROUP);
    vector<Op> opsA = executeGroups();
    ll scoreA = simulate(opsA);

    annealBuses(timer, TIME_LIMIT);
    vector<Op> opsB = executeBuses();
    ll scoreB = opsB.empty() ? LLONG_MAX : simulate(opsB);

    // 過去改変BFS(方式A)
    vector<vector<int>> cellsA(grp.size());
    rep(i, (ll)grp.size()) for (int s : grp[i]) cellsA[i].push_back(sPos[s]);
    ll gainA = 0;
    vector<Op> opsPA = pastModify(cellsA, [&](int u, vector<Op>& o) { return executeGroupOne(grp[u], o); }, timer, TIME_PM_A, gainA);
    ll scorePA = opsPA.empty() ? LLONG_MAX : simulate(opsPA);
    // 過去改変BFS(方式B)
    vector<vector<int>> cellsB(buses.size());
    rep(i, (ll)buses.size()) for (auto& e : buses[i]) if (e.type == EV_PICK) cellsB[i].push_back(sPos[e.id]);
    ll gainB = 0;
    vector<Op> opsPB = pastModify(cellsB, [&](int u, vector<Op>& o) { return executeBusOne(buses[u], o); }, timer, TIME_PM_B, gainB);
    ll scorePB = opsPB.empty() ? LLONG_MAX : simulate(opsPB);

    auto show = [](ll v) { return v == LLONG_MAX ? -1LL : v; };
    cerr << "scoreA " << show(scoreA) << " scoreB " << show(scoreB) << " scorePA " << show(scorePA) << " scorePB " << show(scorePB)
         << " gainA " << gainA << " gainB " << gainB << " time " << timer.sec() << endl;
    vector<pair<ll, const vector<Op>*>> cands = {{scoreA, &opsA}, {scoreB, &opsB}, {scorePA, &opsPA}, {scorePB, &opsPB}};
    const vector<Op>* chosen = &opsA;
    ll bestScore = LLONG_MAX;
    for (auto& [sc, p] : cands) if (sc < bestScore) { bestScore = sc; chosen = p; }
    const vector<Op>& ops = *chosen;
    string buf;
    for (auto& o : ops) {
        buf += to_string(o.p / N) + ' ' + to_string(o.p % N) + ' ' + to_string(o.k) + ' ' + DCH[o.d] + ' ' + to_string(o.l) + '\n';
    }
    cout << buf;
}
} // namespace sol

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    sol::solve();
    return 0;
}
