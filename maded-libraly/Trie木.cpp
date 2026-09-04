// 共通接頭辞
// Trie木のルート(index 0)は空文字列である
struct Trie {
  struct Node {
    map<char,ll> to;
    ll cnt;
    ll par; // 親ノードのindex (rootなら-1)
    char pc; // 親から自分に来る際の文字
    Node(): cnt(0), par(-1), pc(0) {}
  };
  vector<Node> d;
  Trie(): d(1) {}
  void add(const string& s) {
    ll v = 0;
    for (char c : s) {
      if (!d[v].to.count(c)) {
        d[v].to[c] = d.size();
        d.push_back(Node());
        d.back().par = v;
        d.back().pc = c;
      }
      v = d[v].to[c];
    }
    d[v].cnt++;
  }

  // sに対応するノードのindexを返す。存在しなければ-1
  ll find(const string& s) const {
    ll v = 0;
    for (char c : s) {
      auto it = d[v].to.find(c);
      if (it == d[v].to.end()) return -1;
      v = it->second;
    }
    return v;
  }

  // indexに対応する文字列を取得する。
  string getString(ll idx) const {
    string s;
    while (idx > 0) {
      s += d[idx].pc;
      idx = d[idx].par;
    }
    reverse(s.begin(), s.end());
    return s;
  }
};