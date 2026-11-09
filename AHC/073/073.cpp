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

lP adjust_middle(ll i, ll j, lP from, ll n) {
    if (i*2 - from.first < 0) {
        i++;
    }
    if (j*2 - from.second < 0) {
        j++;
    }
    if (i*2 - from.first >= n) {
        i--;
    }
    if (j*2 - from.second >= n) {
        j--;
    }
    return {i, j};
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n,m,k,t;
    cin >> n >> m >> k >> t;
    lP s; cin >> s.first >> s.second;
    vc<lP> g(m);
    rep(i,m) cin >> g[i].first >> g[i].second;
    ll best_score = 1e18;
    ll cnt = 140000;
    set<lP> magic_pos;
    ll ni = n/2, nj = n/2;
    rep(i,k) {
        magic_pos.insert({ni, nj});
        ni++;
        nj++;
    }

    ll start_temp = 1000;
    ll end_temp = 1;

    rep(i,cnt) {
        lP now = s;
        ll now_score = 0;
        set<lP> next_magic_pos;

        for (auto &magic_pos_ele : magic_pos) {
            lP for_next = magic_pos_ele;
            if (rand() % 2 == 0) {
                for_next.first = rand() % n;
            } else {
                for_next.second = rand() % n;
            }
            next_magic_pos.insert(for_next);
        }

        set<lP> for_use_magic_pos = next_magic_pos;

        rep(i,m) {
            lP p = g[i];
            ll now_dist = manhattan(now.first, p.first, now.second, p.second);
            lP best_magic = {-1, -1};
            for (auto &magic_pos_ele : for_use_magic_pos) {
                if (p.first > now.first){
                    if (magic_pos_ele.first < now.first || magic_pos_ele.first > p.first) {
                        continue;
                    }
                } else if (p.first < now.first) {
                    if (magic_pos_ele.first > now.first || magic_pos_ele.first < p.first) {
                        continue;
                    }
                }
                if (p.second > now.second) {
                    if (magic_pos_ele.second < now.second || magic_pos_ele.second > p.second) {
                        continue;
                    }
                } else if (p.second < now.second) {
                    if (magic_pos_ele.second > now.second || magic_pos_ele.second < p.second) {
                        continue;
                    }
                }
                lP moved_pos = {2*magic_pos_ele.first - now.first, 2*magic_pos_ele.second - now.second};
                if (moved_pos.first < 0 || moved_pos.first >= n || moved_pos.second < 0 || moved_pos.second >= n) {
                    continue;
                }
                ll dist_sum = 1 + manhattan(moved_pos.first, p.first, moved_pos.second, p.second);
                if (dist_sum < now_dist) {
                    now_dist = dist_sum;
                    best_magic = magic_pos_ele;
                }
            }
            if (best_magic.first != -1) {
                for_use_magic_pos.insert({now.first, now.second});
                for_use_magic_pos.erase(best_magic);
                //string temp = "J ";
                //temp+= to_string(best_magic.first) + " " + to_string(best_magic.second);
                now = {2*best_magic.first - now.first, 2*best_magic.second - now.second};
                // ans.push_back(temp);
                now_score++;
            }
            while(p != now) {
                if (p.first < now.first) {
                    now.first--;
                } else if (p.first > now.first) {
                    now.first++;
                } else if (p.second < now.second) {
                    now.second--;
                } else if (p.second > now.second) {
                    now.second++;
                }
                now_score++;
            }
            now = p;
        }

        bool is_best = now_score < best_score;
        //out("now_score: " << now_score);
        /*
        for (auto &p : next_magic_pos) {
            cout << p.first << " " << p.second << endl;
        }
            */
        if (is_best) {
            ll temp = start_temp + (end_temp - start_temp) * i / cnt;
            double prob = exp((best_score - now_score) / (double)temp);
            bool accept =  prob > (rand() % 10000) / 10000.0;
            if (accept) {
                magic_pos = next_magic_pos;
                best_score = now_score;
            }
        }
    }


    for (auto &p : magic_pos) {
        cout << p.first << " " << p.second << endl;
    }

    lP now = s;
    vs ans;
    rep(i,m) {
        lP p = g[i];
        ll now_dist = manhattan(now.first, p.first, now.second, p.second);
        lP best_magic = {-1, -1};
        for (auto &magic_pos_ele : magic_pos) {

            if (p.first > now.first){
                if (magic_pos_ele.first < now.first || magic_pos_ele.first > p.first) {
                    continue;
                }
            } else if (p.first < now.first) {
                if (magic_pos_ele.first > now.first || magic_pos_ele.first < p.first) {
                    continue;
                }
            }
            if (p.second > now.second) {
                if (magic_pos_ele.second < now.second || magic_pos_ele.second > p.second) {
                    continue;
                }
            } else if (p.second < now.second) {
                if (magic_pos_ele.second > now.second || magic_pos_ele.second < p.second) {
                    continue;
                }
            }
            lP moved_pos = {2*magic_pos_ele.first - now.first, 2*magic_pos_ele.second - now.second};
            if (moved_pos.first < 0 || moved_pos.first >= n || moved_pos.second < 0 || moved_pos.second >= n) {
                continue;
            }
            ll dist_sum = 1 + manhattan(moved_pos.first, p.first, moved_pos.second, p.second);
            if (dist_sum < now_dist) {
                now_dist = dist_sum;
                best_magic = magic_pos_ele;
            }
        }
        if (best_magic.first != -1) {
            magic_pos.insert({now.first, now.second});
            magic_pos.erase(best_magic);
            string temp = "J ";
            temp+= to_string(best_magic.first) + " " + to_string(best_magic.second);
            now = {2*best_magic.first - now.first, 2*best_magic.second - now.second};
            ans.push_back(temp);
            t--;
            if (t < 0) {
                return 0;
            }
        }
        while(p != now) {
            if (p.first < now.first) {
                ans.push_back("U");
                now.first--;
            } else if (p.first > now.first) {
                ans.push_back("D");
                now.first++;
            } else if (p.second < now.second) {
                ans.push_back("L");
                now.second--;
            } else if (p.second > now.second) {
                ans.push_back("R");
                now.second++;
            }
            t--;
            if (t < 0) {
                return 0; 
            }
        }
        now = p;
    }

    for (auto &s : ans) {
        cout << s << endl;
    }

    




    return 0;
}
