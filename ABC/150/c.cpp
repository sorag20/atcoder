#include <atcoder/modint>
#include <iostream>

using namespace std;
using namespace atcoder;

using mint = modint998244353;
// or: typedef modint998244353 mint;

int main() {
    // print sum of array (mod 998244353)
    int n;
    cin >> n;
    mint sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << sum.val() << endl;
}