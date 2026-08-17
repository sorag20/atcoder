// 区間加算　区間和取得
/* この場合、初期化は、
vl a(n);
cin >> a;
vector<S> init(n);
rep(i, n) init[i] = {a[i], 1};
lazy_segtree<S, op, e, F, mapping, composition, id> seg(init);
の様にする。
*/
struct S {
    ll sum;  // 区間の総和
    ll size; // 区間の長さ
};
using F = ll;  // 作用の型（加算値）

// 区間をマージする関数
S op(S l, S r) { return {l.sum + r.sum, l.size + r.size}; }
// 単位元
S e() { return {0, 0}; }
// 作用を区間に適用する関数
S mapping(F f, S x) { return {x.sum + f * x.size, x.size}; }
// 作用同士を合成する関数
F composition(F f, F g) { return f + g; }
// 作用の単位元
F id() { return 0; }


// 区間加算　区間最大値
using S = ll;  // 区間の最大値
using F = ll;  // 作用の型（加算値）

// 区間をマージする関数（最大値を求める）
S op(S l, S r) { return max(l, r); }
// 単位元（最大値の単位元は-INF）
S e() { return -1e18; }
// 作用を区間に適用する関数（値に加算値を足す）
S mapping(F f, S x) { return x + f; }
// 作用同士を合成する関数（加算の合成）
F composition(F f, F g) { return f + g; }
// 作用の単位元
F id() { return 0; }


// 区間加算　区間最小値
using S = ll;  // 区間の最大値
using F = ll;  // 作用の型（加算値）

// 区間をマージする関数（最大値を求める）
S op(S l, S r) { return min(l, r); }
// 単位元（最大値の単位元は-INF）
S e() { return 1e18; }
// 作用を区間に適用する関数（値に加算値を足す）
S mapping(F f, S x) { return x + f; }
// 作用同士を合成する関数（加算の合成）
F composition(F f, F g) { return f + g; }
// 作用の単位元
F id() { return 0; }


// 区間更新　区間和取得
struct S{
    long long value;
    ll size;
};
using F = long long;
const F ID = 8e18;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){
    if(f != ID) x.value = f*x.size;
    return x;
}
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }


// 区間更新　区間最大値
using S = ll;  // 区間の最大値
using F = ll;  // 作用の型（更新値）
const ll INF = 1e18;

// 区間をマージする関数（最大値を求める）
S op(S l, S r) { return max(l, r); }
// 単位元（最大値の単位元は-INF）
S e() { return -INF; }
// 作用を区間に適用する関数（値を更新値で置き換える）
S mapping(F f, S x) {
    if (f == INF) return x;  // 作用がid()なら何もしない
    return f;  // 更新値で上書き
}
// 作用同士を合成する関数（新しい更新値で上書き）
F composition(F f, F g) {
    if (f == INF) return g;  // fがid()ならgを返す
    return f;  // 新しい作用fで上書き
}
// 作用の単位元（更新しないことを表す特別な値）
F id() { return INF; }


// 区間更新　区間最小値
using S = ll;  // 区間の最小値
using F = ll;  // 作用の型（更新値）
const ll INF = 1e18;

// 区間をマージする関数（最小値を求める）
S op(S l, S r) { return min(l, r); }
// 単位元（最小値の単位元はINF）
S e() { return INF; }
// 作用を区間に適用する関数（値を更新値で置き換える）
S mapping(F f, S x) {
    if (f == INF) return x;  // 作用がid()なら何もしない
    return f;  // 更新値で上書き
}
// 作用同士を合成する関数（新しい更新値で上書き）
F composition(F f, F g) {
    if (f == INF) return g;  // fがid()ならgを返す
    return f;  // 新しい作用fで上書き
}
// 作用の単位元（更新しないことを表す特別な値）
F id() { return INF; }

// 使用例:
// 区間加算: seg.apply(l, r, x); // [l, r)にxを加算
// [l, r)の総和を取得
// 一点取得: seg.get(i);         // a[i]の値を取得
// 一点更新: seg.set(i, x);      // a[i]をxに更新

