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

const double TIME_LIMIT = 1.8;
const int CAP = 7; // 土台(高々1)+塔 <= 8 を保証
const int DI[4] = {-1, 1, 0, 0}, DJ[4] = {0, 0, -1, 1};
const char DCH[4] = {'U', 'D', 'L', 'R'};
const int INFD = 1 << 28;

int N, K, NN, S;
vector<char> isFloor;
vector<int> nestPos, occ0, sPos, sCol;
vector<vector<int>> D; // D[a][b]: aからbへの近似最短手数(初期盤面の踏み台効果込み)
vector<vector<int>> nb; // 同色の近いスライム

int stepCell(int u, int d, int l) {
    int i = u / N + DI[d] * l, j = u % N + DJ[d] * l;
    if (i < 0 || i >= N || j < 0 || j >= N) return -1;
    return i * N + j;
}

void computeDist() {
    D.assign(NN, vector<int>(NN, INFD));
    vector<int> q(NN);
    rep(a, NN) {
        if (!isFloor[a]) continue;
        vector<int>& dist = D[a];
        int qh = 0, qt = 0;
        dist[a] = 0; q[qt++] = (int)a;
        while (qh < qt) {
            int u = q[qh++];
            int range = (u == a) ? 1 : 1 + occ0[u];
            rep(d, 4) for (int l = 1; l <= range; l++) {
                int v = stepCell(u, (int)d, l);
                if (v < 0 || !isFloor[v]) break;
                if (dist[v] == INFD) { dist[v] = dist[u] + 1; q[qt++] = v; }
            }
        }
    }
}

// ---- 焼きなまし状態 ----
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

void anneal(const Timer& timer) {
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
    cerr << "init cost " << cur << endl;

    // 近傍候補
    nb.assign(S, {});
    rep(s, S) {
        vector<pair<int, int>> cand;
        rep(t, S) if (t != s && sCol[t] == sCol[s])
            cand.push_back({D[sPos[s]][sPos[t]] + D[sPos[t]][sPos[s]], (int)t});
        sort(cand.begin(), cand.end());
        for (size_t i = 0; i < cand.size() && i < 12; i++) nb[s].push_back(cand[i].second);
    }

    Rng rng;
    const double T0 = 3.0, T1 = 0.05;
    double startT = timer.sec(), T = T0;
    ll iter = 0, acc = 0;
    while (true) {
        if ((iter & 255) == 0) {
            double p = (timer.sec() - startT) / (TIME_LIMIT - startT);
            if (p >= 1.0) break;
            T = T0 * pow(T1 / T0, p);
        }
        iter++;
        int s = rng.nextInt(S);
        int type = rng.nextInt(10);
        int a = gOf[s];
        if (type < 5) {
            // 移動: sを別の位置へ
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
                    cur += delta; acc++;
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
                        cur += delta; acc++;
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
                        cur += delta; acc++;
                    }
                }
            }
        } else if (type < 8) {
            // 交換: sと近くの同色スライムtを入れ替え
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
                    cur += delta; acc++;
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
                    cur += delta; acc++;
                }
            }
        } else {
            // 区間反転
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
                cur += delta; acc++;
            }
        }
        if (cur < best) { best = cur; bestGrp = grp; }
    }
    grp = bestGrp;
    cerr << "iter " << iter << " acc " << acc << " best est " << best << endl;
}

// ---- 実盤面シミュレーション ----
struct Op { int p, k, d, l; };
vector<Op> ops;
vector<int> H; // 移動中の塔以外のスライム数

// curからtへ高さhの塔(自色c)を運ぶ経路。(方向,距離)列を返す。到達不能なら空でfalse
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

void execute() {
    H = occ0;
    vector<int> order;
    rep(id, (ll)grp.size()) if (!grp[id].empty()) order.push_back((int)id);
    vector<pair<int, int>> path;
    for (int id : order) {
        const vector<int>& g = grp[id];
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
            if (!bfsPath(cur, t, h, c, false, path)) bfsPath(cur, t, h, c, true, path);
            for (auto [d, l] : path) {
                ops.push_back({cur, H[cur], d, l});
                cur = stepCell(cur, d, l);
                if (cur == nestPos[c]) { h = 0; break; } // 帰巣
            }
            if (isNest) { h = 0; continue; }
            if (h == 0) { cur = t; H[t]--; h = 1; } // 途中で帰巣した場合はtから再出発
            else { H[t]--; h++; }
        }
    }
}

void solve() {
    Timer timer;
    cin >> N >> K;
    NN = N * N;
    vector<string> G(N);
    rep(i, N) cin >> G[i];
    isFloor.assign(NN, 0); occ0.assign(NN, 0); nestPos.assign(K, -1);
    rep(i, N) rep(j, N) {
        char ch = G[i][j];
        int p = (int)(i * N + j);
        if (ch == '#') continue;
        isFloor[p] = 1;
        if ('a' <= ch && ch <= 'l') { occ0[p] = 1; sPos.push_back(p); sCol.push_back(ch - 'a'); }
        else if ('A' <= ch && ch <= 'L') nestPos[ch - 'A'] = p;
    }
    S = (int)sPos.size();
    computeDist();
    anneal(timer);
    execute();
    cerr << "T " << ops.size() << " time " << timer.sec() << endl;
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
