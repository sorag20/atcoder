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
    string s;
    cin >> s;
    for (int i=s.size()-1; i>0; i--) {
        if (s[i] == '.') {
            s.pop_back();
            break;
        }
        if (s[i] == '0') {
            s.pop_back();
        } else {
            break;
        }
    }
    cout<<s<<endl;

    return 0;
}
