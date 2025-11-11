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
    int N;
    cin >> N;

    // 入力を受け取って、D[i][j] の形で扱う
    vector<vector<long long>> D(N, vector<long long>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            cin >> D[i][j];
        }
    }

    // bitDP: dp[bit] = bit に対応する頂点集合での最大マッチング重み
    int max_bit = 1 << N;
    vector<long long> dp(max_bit, 0);

    for (int bit = 0; bit < max_bit; ++bit) {
        for (int i = 0; i < N; ++i) {
            if (!(bit & (1 << i))) continue;
            for (int j = i + 1; j < N; ++j) {
                if (!(bit & (1 << j))) continue;

                int prev = bit ^ (1 << i) ^ (1 << j);
                dp[bit] = max(dp[bit], dp[prev] + D[i][j]);
            }
        }
    }

    cout << dp[max_bit - 1] << endl;
    
    return 0;
}
