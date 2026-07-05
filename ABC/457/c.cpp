#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 入力をとる
    long long n, k; cin>> n >> k;
    vector<vector<int>> a(n);
    vector<long long> l(n);
    for (int i = 0; i < n; i++) {
        cin>> l[i];
        for (int j = 0; j < l[i]; j++) {
            int x; cin>>x;
            a[i].push_back(x);
        }
    }
    vector<int> c(n);
    int ans = -1;
    for (int i = 0; i < n;i++) {
        cin>>c[i];
        long long temp = c[i] * l[i];
        if (temp >= k) {
            if (temp >= l[i]) {
                k = k % l[i];
                if (k == 0) k = l[i];
            }
            k--;
            ans = a[i][k];
            break;
        }
        k -= temp;
    }
    cout << ans << endl;

    return 0;
}
