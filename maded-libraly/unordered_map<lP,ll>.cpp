// unordered_map<lP, ll>は、Pairに対するhashの特殊化を持っていないため、そのままでは使えない。
// Pairを1つのllにパックしてunordered_mapのキーにする
// offsetは絶対値の最大より大きくする
// 値の絶対値が10^9ほどまでなら可能。
const ll offset = 2e7, W = 4 * offset + 1;
auto encode = [&](ll x, ll y) ->ll {
    return (x + offset) * W + (y + offset);
};


//unordered_map<ll, ll> dir_cnt;
//dir_cnt[encode(d.x, d.y)]++;