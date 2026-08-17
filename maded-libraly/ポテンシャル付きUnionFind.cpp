
template <typename T>
struct WeightedDSU {
  public:
    WeightedDSU() : _n(0) {}
    explicit WeightedDSU(int n) : _n(n), parent_or_size(n, -1), potential(n, T(0)) {}

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
    std::vector<int> parent_or_size;
    std::vector<T> potential;

    T potential_of(int a) {
        leader(a);
        return potential[a];
    }
};
