#include <bits/stdc++.h>
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
using namespace std;

int main()
{
    int n; cin>>n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int l; cin>>l;
        for (int j = 0; j < l; j++) {
            int x; cin>>x;
            a[i].push_back(x);
        }
    }
    int x, y; cin>>x>>y;
    x--;y--;
    cout << a[x][y] << endl;

    return 0;
}
