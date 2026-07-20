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
#define vmint_cout(v){ll n = size(v);rep(i,n)cout<<v[i].val()<<endl;}//mint一次元配列を出力する
#define vvmint_cout(v){ll n = size(v);rep(i,n){rep(j,(ll)size(v[i])){cout<<v[i][j].val()<<' ';}cout<<endl;}}//mint二次元配列を出力する


static ll N;

struct Op {
    char d; // 'V' or 'H'
    ll r, c, h, w;
};

int main() {
    auto t_start = chrono::steady_clock::now();
    const double TIME_LIMIT = 1.8; // seconds
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> N;
    ll n2 = N * N;
    vl initGrid(n2);
    rep(i, N) rep(j, N) {
        ll x; cin >> x;
        initGrid[i * N + j] = x;
    }
    vs vwall(N);      // vwall[i] length N-1: wall to the right of (i,j)
    rep(i, N) cin >> vwall[i];
    vs hwall(N - 1);  // hwall[i] length N: wall below (i,j)
    rep(i, N - 1) cin >> hwall[i];

    auto idx = [&](ll r, ll c) { return r * N + c; };

    // adjacency list: (neighbor id) for each cell, built from open (wall-free) edges
    vvl adj(n2);
    rep(i, N) rep(j, N) {
        ll id = idx(i, j);
        if (j + 1 < N && vwall[i][j] == '0') {
            ll id2 = idx(i, j + 1);
            adj[id].pb(id2);
            adj[id2].pb(id);
        }
        if (i + 1 < N && hwall[i][j] == '0') {
            ll id2 = idx(i + 1, j);
            adj[id].pb(id2);
            adj[id2].pb(id);
        }
    }

    mt19937 rng(12345);

    auto buildTree = [&](ll root, vl &parent, vl &depth) {
        parent.assign(n2, -2);
        depth.assign(n2, -1);
        parent[root] = -1;
        depth[root] = 0;
        vl order;
        order.pb(root);
        for (size_t head = 0; head < order.size(); head++) {
            ll u = order[head];
            vl nbrs = adj[u];
            shuffle(all(nbrs), rng);
            for (ll v : nbrs) {
                if (parent[v] == -2) {
                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    order.pb(v);
                }
            }
        }
    };

    auto postOrderOf = [&](ll root, vl &parent) {
        vvl children(n2);
        rep(v, n2) if (parent[v] >= 0) children[parent[v]].pb(v);
        vl order;
        order.reserve(n2);
        vc<lP> st; // (node, next child index to process)
        st.pb({root, 0});
        while (!st.empty()) {
            auto &[node, ci] = st.back();
            if (ci < (ll)children[node].size()) {
                ll nxt = children[node][ci];
                ci++;
                st.pb({nxt, 0});
            } else {
                order.pb(node);
                st.pob();
            }
        }
        return order;
    };

    vl bfsParent(n2), bfsStamp(n2, -1), bfsDist(n2), bfsTurns(n2);
    vl bfsQueue(n2);
    ll bfsStampCounter = 0;
    // Among ALL shortest paths from u to v (over the currently-unprocessed
    // subgraph), reconstruct the one with the fewest direction changes. This
    // never changes the path LENGTH (still a plain unweighted-BFS distance),
    // only which of possibly-several equally-short paths is chosen -- and it
    // directly maximizes straight-run length, which is exactly what
    // compressRun turns into fewer operations. Implemented as: (1) a normal
    // BFS to get dist[] for every reachable cell, then (2) a DAG-DP over the
    // shortest-path edges (x -> y with dist[y] = dist[x]+1), processed in
    // non-decreasing dist order (guaranteed by BFS queue insertion order),
    // choosing for each y the predecessor that minimizes total turns so far.
    auto shortestPath = [&](ll u, ll v, vl &processed) {
        bfsStampCounter++;
        ll qh = 0, qt = 0;
        bfsQueue[qt++] = u;
        bfsStamp[u] = bfsStampCounter;
        bfsDist[u] = 0;
        while (qh < qt) {
            ll cur = bfsQueue[qh++];
            if (cur == v) break;
            for (ll nx : adj[cur]) {
                if (processed[nx]) continue;
                if (bfsStamp[nx] == bfsStampCounter) continue;
                bfsStamp[nx] = bfsStampCounter;
                bfsDist[nx] = bfsDist[cur] + 1;
                bfsQueue[qt++] = nx;
            }
        }

        bfsParent[u] = -1;
        bfsTurns[u] = 0;
        for (ll i = 1; i < qt; i++) bfsTurns[bfsQueue[i]] = -1; // sentinel: unrelaxed

        for (ll i = 0; i < qt; i++) {
            ll x = bfsQueue[i];
            if (x == v) break; // v's own predecessors (smaller dist) are all
                                // already relaxed by this point; no need to
                                // expand v itself as a source.
            for (ll y : adj[x]) {
                if (bfsStamp[y] != bfsStampCounter) continue;
                if (bfsDist[y] != bfsDist[x] + 1) continue;
                ll px = bfsParent[x];
                ll turnCost = (px == -1) ? 0 : ((x - px) == (y - x) ? 0 : 1);
                ll cand = bfsTurns[x] + turnCost;
                if (bfsTurns[y] == -1 || cand < bfsTurns[y]) {
                    bfsTurns[y] = cand;
                    bfsParent[y] = x;
                }
            }
        }

        vl path;
        for (ll cur = v; cur != -1; cur = bfsParent[cur]) path.pb(cur);
        reverse(all(path));
        return path;
    };

    auto simulate = [&](vl &postOrder) {
        vl grid = initGrid;
        vl pos(n2);
        rep(c, n2) pos[grid[c]] = c;
        vl processed(n2, 0);
        vc<Op> ops;

        auto compressRun = [&](vl &cells) {
            ll D = (ll)cells.size() - 1;
            if (D == 0) return;
            bool horizontal = (cells[0] / N == cells[1] / N); // same row => run along columns
            ll fixed = horizontal ? (cells[0] / N) : (cells[0] % N);
            ll posInRun = 0, d = D;
            while (d > 0) {
                ll s = (d == 1) ? 1 : d / 2;
                for (ll k = 0; k < s; k++) {
                    ll p0 = cells[posInRun + k];
                    ll p1 = cells[posInRun + s + k];
                    ll val0 = grid[p0], val1 = grid[p1];
                    grid[p0] = val1; grid[p1] = val0;
                    pos[val0] = p1; pos[val1] = p0;
                }
                ll cA = horizontal ? (cells[posInRun] % N) : (cells[posInRun] / N);
                ll cB = horizontal ? (cells[posInRun + 2 * s - 1] % N) : (cells[posInRun + 2 * s - 1] / N);
                ll opStart = min(cA, cB);
                Op op;
                if (horizontal) {
                    op.d = 'H'; op.r = fixed; op.c = opStart; op.h = 1; op.w = 2 * s;
                } else {
                    op.d = 'V'; op.r = opStart; op.c = fixed; op.h = 2 * s; op.w = 1;
                }
                ops.pb(op);
                posInRun += s;
                d -= s;
            }
        };

        for (ll v : postOrder) {
            ll want = v; // target value for cell id v equals v itself
            ll u = pos[want];
            if (u == v) { processed[v] = 1; continue; }
            vl path = shortestPath(u, v, processed);
            size_t i = 0;
            while (i + 1 < path.size()) {
                size_t j = i + 1;
                ll dr = path[i + 1] / N - path[i] / N;
                ll dc = path[i + 1] % N - path[i] % N;
                while (j + 1 < path.size()) {
                    ll dr2 = path[j + 1] / N - path[j] / N;
                    ll dc2 = path[j + 1] % N - path[j] % N;
                    if (dr2 != dr || dc2 != dc) break;
                    j++;
                }
                vl runCells(path.begin() + i, path.begin() + j + 1);
                compressRun(runCells);
                i = j;
            }
            processed[v] = 1;
        }
        return ops;
    };

    auto elapsed = [&]() {
        return chrono::duration<double>(chrono::steady_clock::now() - t_start).count();
    };

    // --- simulated annealing over (root, shuffle-seed) spanning tree choice ---
    uniform_int_distribution<ll> cellDist(0, n2 - 1);
    uniform_real_distribution<double> uni(0.0, 1.0);

    ll curRoot = 0;
    ull curSeed = 12345;

    auto evalState = [&](ll root, ull seed, vc<Op> &outOps) {
        rng.seed(seed);
        vl parent, depth;
        buildTree(root, parent, depth);
        vl post = postOrderOf(root, parent);
        outOps = simulate(post);
        return (ll)outOps.size();
    };

    vc<Op> curOps;
    ll curCost = evalState(curRoot, curSeed, curOps);
    vc<Op> bestOps = curOps;
    ll bestCost = curCost;

    double T0 = max(1.0, curCost * 0.05);
    double T1 = 0.01;

    while (elapsed() < TIME_LIMIT) {
        double t = elapsed() / TIME_LIMIT;
        double temp = T0 * pow(T1 / T0, t);

        ll nextRoot = curRoot;
        ull nextSeed = curSeed;
        if (uni(rng) < 0.3) {
            // jump to a random root (or a random neighbor of current root)
            if (uni(rng) < 0.5 && !adj[curRoot].empty()) {
                nextRoot = adj[curRoot][rng() % adj[curRoot].size()];
            } else {
                nextRoot = cellDist(rng);
            }
        } else {
            nextSeed = (ull)rng();
        }

        vc<Op> candOps;
        ll candCost = evalState(nextRoot, nextSeed, candOps);

        double delta = (double)(candCost - curCost);
        bool accept = (delta <= 0) || (uni(rng) < exp(-delta / max(temp, 1e-9)));
        if (accept) {
            curRoot = nextRoot;
            curSeed = nextSeed;
            curCost = candCost;
            curOps = candOps;
            if (candCost < bestCost) {
                bestCost = candCost;
                bestOps = candOps;
            }
        }
    }
    ostringstream oss;
    for (auto &op : bestOps) {
        oss << op.d << " " << op.r << " " << op.c << " " << op.h << " " << op.w << "\n";
    }
    cout << oss.str();
    return 0;
}
