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
ll kousa_kousuu(ll l, ll r, ll d) {//初項,末項,交差 で等差数列の項数を求める
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

#define out(v) {cout<<v<<endl;}
#define v_cout(v){ll n = size(v);rep(i,n)cout<<v[i]<<' ';cout<<endl;}//一次元配列を出力する
#define vv_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){cout<<v[i][j]<<' ';}cout<<endl;}}//二次元配列を出力する
#define vvv_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){ rep(k,(ll)size(v[i][j])) {cout<<v[i][j][k]<<' ';}cout<<endl;}}}//三次元配列を出力する
#define vs_cout(v){ll n = size(v);rep(i,n)cout<<v[i]<<endl;cout<<endl;}
#define vvs_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){cout<<v[i][j]<<endl;}cout<<endl;}}
#define vvvs_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){ rep(k,(ll)size(v[i][j])) {cout<<v[i][j][k]<<endl;}cout<<endl;}}}
#define vmint_cout(v){ll n = size(v);rep(i,n)cout<<v[i].val()<<endl;}//mint一次元配列を出力する
#define vvmint_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){cout<<v[i][j].val()<<' ';}cout<<endl;}}//mint二次元配列を出力する

static const ll N = 50;
static const ll NN = N * N;
using Bits = bitset<NN>;

static const ll DX[4] = {1, -1, 0, 0};
static const ll DY[4] = {0, 0, 1, -1};

ll n, M;
ld R;
vs grid;
vvl occ; // -1 = free

inline ll idx(ll x, ll y) { return x * N + y; }
inline bool isFree(ll x, ll y) { return grid[x][y] == '.' && occ[x][y] == -1; }

struct ActiveGroup {
    vc<P> cells;
    ll V, T, maxL;
};
unordered_map<ll, ActiveGroup> active;

// A partial region grown so far, plus enough bookkeeping to extend it by one more cell.
struct BeamState {
    vc<P> cells;
    Bits inRegion;
    vc<P> frontier;
    Bits inFrontier;
    ll perimeter = 0;
};

ll neighborsInRegion(const Bits &inRegion, ll x, ll y) {
    ll c = 0;
    rep(d, 4) {
        ll nx = x + DX[d], ny = y + DY[d];
        if (!out_grid(nx, ny, n, n) && inRegion.test(idx(nx, ny))) c++;
    }
    return c;
}

BeamState makeInitial(P seed) {
    BeamState s;
    s.cells.pb(seed);
    s.inRegion.set(idx(seed.first, seed.second));
    s.perimeter = 4;
    rep(d, 4) {
        ll nx = seed.first + DX[d], ny = seed.second + DY[d];
        if (out_grid(nx, ny, n, n) || !isFree(nx, ny)) continue;
        s.inFrontier.set(idx(nx, ny));
        s.frontier.pb({(int)nx, (int)ny});
    }
    return s;
}

// Adds cell c to state s (copy-on-write), updating the perimeter via the standard
// polyomino delta: +4 for the new cell, -2 for each neighbor already in the region.
BeamState expandState(const BeamState &s, P c) {
    BeamState ns = s;
    ll k = neighborsInRegion(ns.inRegion, c.first, c.second);
    ns.perimeter += 4 - 2 * k;
    ns.cells.pb(c);
    ns.inRegion.set(idx(c.first, c.second));
    ns.inFrontier.reset(idx(c.first, c.second));
    rep(i, (ll)ns.frontier.size()) {
        if (ns.frontier[i] == c) {
            ns.frontier[i] = ns.frontier.back();
            ns.frontier.pob();
            break;
        }
    }
    rep(d, 4) {
        ll nx = c.first + DX[d], ny = c.second + DY[d];
        if (out_grid(nx, ny, n, n) || !isFree(nx, ny)) continue;
        ll id = idx(nx, ny);
        if (ns.inRegion.test(id) || ns.inFrontier.test(id)) continue;
        ns.inFrontier.set(id);
        ns.frontier.pb({(int)nx, (int)ny});
    }
    return ns;
}

BeamState growRegion(P seed, ll p, ll beamWidth, ll branch) {
    vc<BeamState> beam{makeInitial(seed)};
    while ((ll)beam[0].cells.size() < p) {
        vc<pair<ll, BeamState>> candidates;
        for (auto &st : beam) {
            vc<pair<ll, P>> scored;
            scored.reserve(st.frontier.size());
            for (auto &c : st.frontier) {
                ll k = neighborsInRegion(st.inRegion, c.first, c.second);
                scored.pb({4 - 2 * k, c});
            }
            sort(all(scored), [](const auto &a, const auto &b) { return a.first < b.first; });
            ll take = min((ll)scored.size(), branch);
            rep(i, take) {
                BeamState ns = expandState(st, scored[i].second);
                candidates.pb({ns.perimeter, move(ns)});
            }
        }
        if (candidates.empty()) break; // free component exhausted (shouldn't happen if size >= p)
        sort(all(candidates), [](const auto &a, const auto &b) { return a.first < b.first; });
        vc<BeamState> newBeam;
        newBeam.reserve(min((size_t)beamWidth, candidates.size()));
        for (auto &pr : candidates) {
            if ((ll)newBeam.size() >= beamWidth) break;
            newBeam.pb(move(pr.second));
        }
        beam = move(newBeam);
    }
    return beam[0];
}

ll boundaryLen(const vc<P> &cells) {
    Bits inR;
    for (auto &c : cells) inR.set(idx(c.first, c.second));
    ll L = 0;
    for (auto &c : cells) {
        rep(d, 4) {
            ll nx = c.first + DX[d], ny = c.second + DY[d];
            if (out_grid(nx, ny, n, n) || !inR.test(idx(nx, ny))) L++;
        }
    }
    return L;
}

ld compactness(ll p, ll L) {
    if (L <= 0) return 0.0;
    return 4.0 * sqrtl((ld)p) / (ld)L;
}


ll roundPayment(ll V, ll p, ll L) {
    if (L <= 0) return 0;
    __int128 sq = (__int128)64 * V * V * p;
    auto lowerOk = [&](ll nn) -> bool {
        __int128 t = (__int128)(2 * nn - 1) * L;
        return t <= 0 || t * t <= sq;
    };
    auto upperOk = [&](ll nn) -> bool {
        __int128 t = (__int128)(2 * nn + 1) * L;
        return sq < t * t;
    };
    ll nres = max(0LL, (ll)llroundl((ld)V * 4.0 * sqrtl((ld)p) / (ld)L));
    while (!lowerOk(nres)) nres--;
    while (!upperOk(nres)) nres++;
    return nres;
}

ll moveCostOf(ll V, ll Rmilli) {
    return max((ll)(((__int128)2 * V * Rmilli + 1000) / 2000), 1LL);
}

struct SearchResult {
    bool found = false;
    vc<P> region;
    ll perimeter = 0;
};


SearchResult findBestRegion(ll p, ll beamWidth, ll branch, ll maxAttempts, ld earlyExitC) {
    vl dist(NN, -1);
    queue<ll> q;
    rep(x, n) rep(y, n) if (!isFree(x, y)) { dist[idx(x, y)] = 0; q.push(idx(x, y)); }
    while (!q.empty()) {
        ll cur = q.front(); q.pop();
        ll cx = cur / N, cy = cur % N;
        rep(d, 4) {
            ll nx = cx + DX[d], ny = cy + DY[d];
            if (out_grid(nx, ny, n, n)) continue;
            ll nid = idx(nx, ny);
            if (dist[nid] == -1) { dist[nid] = dist[cur] + 1; q.push(nid); }
        }
    }

    vb visited(NN, false);
    SearchResult best;
    best.perimeter = LLONG_MAX;
    vc<pair<ll, P>> bigCompSeeds; // (size, seed)

    rep(x, n) {
        rep(y, n) {
            if (visited[idx(x, y)] || !isFree(x, y)) continue;
            vc<P> comp;
            P seedInterior = {(int)x, (int)y};
            ll bestDist = -1;
            ll minSum = LLONG_MAX, maxSum = LLONG_MIN, minDiff = LLONG_MAX, maxDiff = LLONG_MIN;
            P cornerTL{}, cornerBR{}, cornerTR{}, cornerBL{};
            queue<ll> cq;
            cq.push(idx(x, y));
            visited[idx(x, y)] = true;
            while (!cq.empty()) {
                ll cur = cq.front(); cq.pop();
                ll cx = cur / N, cy = cur % N;
                comp.pb({(int)cx, (int)cy});
                if (chmax(bestDist, dist[cur])) seedInterior = {(int)cx, (int)cy};
                ll s = cx + cy, df = cx - cy;
                if (chmin(minSum, s)) cornerTL = {(int)cx, (int)cy};
                if (chmax(maxSum, s)) cornerBR = {(int)cx, (int)cy};
                if (chmin(minDiff, df)) cornerTR = {(int)cx, (int)cy};
                if (chmax(maxDiff, df)) cornerBL = {(int)cx, (int)cy};
                rep(d, 4) {
                    ll nx = cx + DX[d], ny = cy + DY[d];
                    if (out_grid(nx, ny, n, n) || visited[idx(nx, ny)] || !isFree(nx, ny)) continue;
                    visited[idx(nx, ny)] = true;
                    cq.push(idx(nx, ny));
                }
            }
            if ((ll)comp.size() < p) continue;
            if ((ll)comp.size() == p) {
                ll L = boundaryLen(comp);
                if (chmin(best.perimeter, L)) { best.region = comp; best.found = true; }
            } else {
                ll sz = (ll)comp.size();
                for (P sd : {cornerTL, cornerBR, cornerTR, cornerBL, seedInterior})
                    bigCompSeeds.pb({sz, sd});
            }
        }
    }

    stable_sort(all(bigCompSeeds), [](const auto &a, const auto &b) { return a.first > b.first; });
    ll attempts = 0;
    for (auto &ps : bigCompSeeds) {
        if (attempts >= maxAttempts) break;
        if (best.found && compactness(p, best.perimeter) >= earlyExitC) break;
        BeamState result = growRegion(ps.second, p, beamWidth, branch);
        if ((ll)result.cells.size() == p) {
            if (chmin(best.perimeter, result.perimeter)) {
                best.region = result.cells;
                best.found = true;
            }
        }
        attempts++;
    }
    return best;
}


static const ll RESERVED = -2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto startTime = chrono::steady_clock::now();

    cin >> n >> M >> R;
    ll Rmilli = (ll)llroundl(R * 1000);
    grid.resize(n);
    rep(i, n) cin >> grid[i];
    occ.assign(n, vl(n, -1));

    rep(turn, M) {
        ll gi, S, T, p, V;
        cin >> gi >> S >> T >> p >> V;

        vl toRemove;
        for (auto &kv : active)
            if (kv.second.T < S) toRemove.pb(kv.first);
        for (ll j : toRemove) {
            for (auto &c : active[j].cells) occ[c.first][c.second] = -1;
            active.erase(j);
        }

        const ld TIME_BUDGET = 3.0;
        ld elapsed = chrono::duration<double>(chrono::steady_clock::now() - startTime).count();
        ld frac = max((ld)0.0, (TIME_BUDGET - elapsed) / TIME_BUDGET);
        ll beamWidth = max(1LL, (ll)llroundl(8 * frac));
        ll branch = max(1LL, (ll)llroundl(4 * frac));
        ll maxAttempts = max(1LL, (ll)llroundl(16 * frac));
        const ld earlyExitC = 0.99;

        SearchResult best = findBestRegion(p, beamWidth, branch, maxAttempts, earlyExitC);
        SearchResult directBest = best;
        ll directFee = directBest.found ? roundPayment(V, p, directBest.perimeter) : 0;
        ld directC = directBest.found ? compactness(p, directBest.perimeter) : 0.0;

        const ld PROACTIVE_DEFRAG_C = 0.6;
        ll moveGroupId = -1;
        vc<P> moveGroupNewRegion;
        ll moveGroupNewPerimeter = 0;
        if (!best.found || directC < PROACTIVE_DEFRAG_C) {
            const ll DEFRAG_CANDIDATES = 6;
            ll dBeamWidth = max(1LL, beamWidth / 2);
            ll dBranch = max(1LL, branch / 2);
            ll dMaxAttempts = max(1LL, maxAttempts / 2);
            const ld dEarlyExitC = 0.9;

            set<ll> borderers;
            rep(x, n) rep(y, n) {
                if (!isFree(x, y)) continue;
                rep(d, 4) {
                    ll nx = x + DX[d], ny = y + DY[d];
                    if (out_grid(nx, ny, n, n)) continue;
                    ll gid = occ[nx][ny];
                    if (gid != -1) borderers.insert(gid);
                }
            }
            vl candidates(all(borderers));
            sort(all(candidates), [&](ll a, ll b) {
                return moveCostOf(active[a].V, Rmilli) < moveCostOf(active[b].V, Rmilli);
            });
            if ((ll)candidates.size() > DEFRAG_CANDIDATES) candidates.resize(DEFRAG_CANDIDATES);

            ll bestImprovement = 0; // over directFee (0 if the direct search found nothing)
            for (ll g : candidates) {
                vc<P> gCells = active[g].cells;
                ll gP = (ll)gCells.size();
                for (auto &c : gCells) occ[c.first][c.second] = -1;

                SearchResult r1 = findBestRegion(p, dBeamWidth, dBranch, dMaxAttempts, dEarlyExitC);
                if (r1.found) {
                    for (auto &c : r1.region) occ[c.first][c.second] = RESERVED;
                    SearchResult r2 = findBestRegion(gP, dBeamWidth, dBranch, dMaxAttempts, dEarlyExitC);
                    for (auto &c : r1.region) occ[c.first][c.second] = -1;

                    if (r2.found) {
                        ll feeIncoming = roundPayment(V, p, r1.perimeter);
                        ll mCost = moveCostOf(active[g].V, Rmilli);
                        ll newMaxLg = max(active[g].maxL, r2.perimeter);
                        ll oldFeeG = roundPayment(active[g].V, gP, active[g].maxL);
                        ll newFeeG = roundPayment(active[g].V, gP, newMaxLg);
                        ll feeLossG = oldFeeG - newFeeG;
                        ll improvement = feeIncoming - mCost - feeLossG - directFee;
                        if (improvement > bestImprovement) {
                            bestImprovement = improvement;
                            moveGroupId = g;
                            moveGroupNewRegion = r2.region;
                            moveGroupNewPerimeter = r2.perimeter;
                            best = r1;
                        }
                    }
                }
                for (auto &c : gCells) occ[c.first][c.second] = g;
            }
            if (moveGroupId == -1) best = directBest; // no beneficial move: keep the direct answer
        }

        ostringstream oss;
        if (moveGroupId != -1) {
            oss << 1 << "\n" << moveGroupId << "\n";
            for (auto &c : moveGroupNewRegion) oss << c.first << " " << c.second << "\n";
            for (auto &c : active[moveGroupId].cells) occ[c.first][c.second] = -1;
            for (auto &c : moveGroupNewRegion) occ[c.first][c.second] = moveGroupId;
            active[moveGroupId].cells = moveGroupNewRegion;
            chmax(active[moveGroupId].maxL, moveGroupNewPerimeter);
        } else {
            oss << 0 << "\n";
        }
        if (best.found) {
            oss << "Yes\n";
            for (auto &c : best.region) oss << c.first << " " << c.second << "\n";
            for (auto &c : best.region) occ[c.first][c.second] = gi;
            active[gi] = ActiveGroup{best.region, V, T, best.perimeter};
        } else {
            oss << "No\n";
        }
        cout << oss.str();
        cout.flush();
    }

    return 0;
}
