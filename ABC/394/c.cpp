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
    int index = -1;
    rep(i, s.size()) {
        if (s[i] == 'W' && index == -1) {
            index = i;
        } else if (s[i] == 'A' && index != -1) {
            s[index] = 'A';
            for (int j = index+1; j <= i; j++) {
                s[j] = 'C';
            }
            index=-1;
    } else if(s[i] != 'W' && s[i] != 'A' && index != -1) {
        index = -1;
    }
    }
    cout<<s<<endl;
    return 0;
}
