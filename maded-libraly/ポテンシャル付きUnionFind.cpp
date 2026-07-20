
// ポテンシャル(重み)付き Union-Find
// value(v) を各頂点に割り当てられる値として、
//   merge(a, b, w) : value(b) - value(a) = w となるように a, b を併合する
//   diff(a, b)     : value(b) - value(a) を返す (呼ぶ前に same(a, b) が true であること)
template <typename T>
struct WeightedDSU {
  public:
    WeightedDSU() : _n(0) {}
    explicit WeightedDSU(int n) : _n(n), parent_or_size(n, -1), potential(n, T(0)) {}

    // value(b) - value(a) = w となるように併合する
    // 既に同じ連結成分に属していて矛盾する場合は false を返す(この場合併合されない)
    bool merge(int a, int b, T w) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        T pa = potential_of(a), pb = potential_of(b);
        int x = leader(a), y = leader(b);
        if (x == y) return pa + w == pb;
        w += pa - pb;
        if (-parent_or_size[x] < -parent_or_size[y]) {
            std::swap(x, y);
            w = -w;
        }
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        potential[y] = w;
        return true;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    // value(b) - value(a) を返す。same(a, b) == true のときのみ有効
    T diff(int a, int b) {
        assert(same(a, b));
        return potential_of(b) - potential_of(a);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        int p = parent_or_size[a];
        int r = leader(p);
        potential[a] += potential[p];
        parent_or_size[a] = r;
        return r;
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
    // potential[v] = value(v) - value(parent_or_size[v]) (leader() 呼び出しで根からの差分に更新される)
    std::vector<T> potential;

    T potential_of(int a) {
        leader(a);
        return potential[a];
    }
};
