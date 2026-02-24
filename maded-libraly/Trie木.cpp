// 共通接頭辞
// Trie木のルート(index 0)は空文字列である
struct Trie {
  struct Node {
    map<char,int> to;
    int cnt;
    Node(): cnt(0) {}
  };
  vector<Node> d;
  Trie(): d(1) {}
  void add(const string& s) {
    int v = 0;
    for (char c : s) {
      if (!d[v].to.count(c)) {
        d[v].to[c] = d.size();
        d.push_back(Node());
      }
      v = d[v].to[c];
    }
    d[v].cnt++;
  }
};
