#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <queue>
#include <utility>
#include <map>
#include <regex>
#include <math.h>
#include <random>
#include <algorithm>
#define pb push_back
#define all(x) begin(x), end(x)
#define gall(x) begin(x), end(x), greater<>()
#define ll long long
#define rep(i,x) for(int i=0;i<x;i++)
#define P pair<int, int>
#define lP pair<ll, ll>
using namespace std;
using namespace atcoder;


int main()
{
    ll n,m,k;
    cin >> n>>m>>k;
    int ans = 0;
    vector<vector<int>> x(m);
    vector<char> s(m);
    rep(j, m)
    {
        int c;
        cin >> c;
        rep(k, c)
        {
            int X;
            cin >> X;
            X--;
            x[j].push_back(X);
        }
        char S;
        cin >> S;
        s[j] = S;
    }
    rep(i, 1 << n)
    {
        vector<int> a(n,0);
        rep(j, n)
        {
            if (i&(1<<j)) {
                a[j] = 1;
            }
        }
        bool f = true;
        rep(j, m)
        {
            int c = x[j].size();
            int k_cnt = 0;
            rep(l, c) {
                if (a[x[j][l]] == 1)
                    {
                        k_cnt++;
                    }
                }
            if (s[j] == 'o')
            {   
                if (k_cnt<k) {
                    f = false;
                }
            } else {
                if (k_cnt>=k) {
                    f = false;
                }
            }
        }
        if (f) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
