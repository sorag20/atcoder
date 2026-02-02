// 遅延セグメント木の設定
// 区間加算、区間和
using S = ll;  // 区間の値の型（総和）
using F = ll;  // 作用の型（加算値）
// 区間をマージする関数（総和を求める）
S op(S l, S r) { return l + r; }
// 単位元（総和の単位元は0）
S e() { return 0; }
// 作用を区間に適用する関数
// f: 加算値, x: 区間の現在の値, len: 区間の長さ
S mapping(F f, S x) { return x + f; }
// 作用同士を合成する関数（加算の合成）
F composition(F f, F g) { return f + g; }
// 作用の単位元（加算の単位元は0）
F id() { return 0; }

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n;
    cin >> n;
    vl a(n); cin>>a;

    // 遅延セグメント木の初期化
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
    rep(i,n) {
        seg.set(i, a[i]);
    }
    rep(i,n) {
        ll now = seg.get(i);
        ll reachable = min(i + now + 1, n);
        if (reachable>i+1) {
            seg.apply(i + 1, reachable, 1);
            seg.set(i, now - (reachable - i - 1));
        }
    }
}
    // 使用例:
    // 区間加算: seg.apply(l, r, x); // [l, r)にxを加算
    // 区間取得: seg.prod(l, r);     // [l, r)の総和を取得
    // 一点取得: seg.get(i);         // a[i]の値を取得
    // 一点更新: seg.set(i, x);      // a[i]をxに更新


    
//区間最大値や区間最小値を求める場合
    using S = ll;
    using F = pair<ll, ll>;  // {更新値(LLONG_MINなら更新なし), 加算値}

    const ll F_UPDATE_NONE = LLONG_MIN;

    // 区間をマージする関数
    S op(S l, S r) { return l + r; }  // または max(l, r), min(l, r)

    // 単位元
    S e() { return 0; }

    // 作用を区間に適用する関数
    S mapping(F f, S x) {
        ll update_val = f.first;
        ll add_val = f.second;
        
        if (update_val != F_UPDATE_NONE) {
            // 更新がある場合：上書きしてから加算
            return update_val + add_val;
        }
        // 更新がない場合：加算のみ
        return x + add_val;
    }

    // 作用同士を合成する関数
    F composition(F f, F g) {
        ll f_update = f.first;
        ll f_add = f.second;
        ll g_update = g.first;
        ll g_add = g.second;
        
        if (f_update != F_UPDATE_NONE) {
            // fで更新する場合：gは無視してfの更新値+両方の加算値
            return {f_update, f_add + g_add};
        }
        if (g_update != F_UPDATE_NONE) {
            // fは加算のみ、gで更新する場合
            return {g_update, f_add + g_add};
        }
        // 両方とも加算のみ
        return {F_UPDATE_NONE, f_add + g_add};
    }

    // 作用の単位元
    F id() { return {F_UPDATE_NONE, 0}; }
