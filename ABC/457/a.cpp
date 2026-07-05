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
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin>>a[i];
    }
    int x; cin>>x;
    cout << a[x] << endl;

    return 0;
}
