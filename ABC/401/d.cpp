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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll cnt_o = 0;
    string t(n, '.');
    // k < cnt_oであれば、oでもいい
    // s[i-1]がoであれば、s[i]はoではだめ
    // oで確定するのは、全部終わった後にcnt_kがk見たない場合、cnt_o=kになるまで、?がoになる
    // oを確定できるのは？
    //s[i-1]がoであれば、s[i]はoではだめ
    // oで確定するのは、全部終わった後にcnt_kがk見たない場合、cnt_o=kになるまで、?がoになる
    rep(i,n) {
        if (s[i] == '?') {
            if (i >0 && s[i-1] == 'o') {
                t[i] = '.';
            } else {
                t[i] = s[i];
            }
        } else {
            if (s[i] == 'o') {
                cnt_o++;
            }
            t[i] = s[i];
        }
    }
    if (cnt_o == k) {
        cout<< t << endl; 
    }
    int start = -1, ent;
    string tmp= "";
    rep(i,n) {
        if (t[i] == '?' && start == -1) {
            start = i;
        } else {
            if (cnt%2 = 1) {
                t[start]
            }
        }
        start = -1;

        if (cnt_o == k) {
            cout<< t << endl; 
            return 0;
        }
    }
    cout<< t << endl; 

    return 0;
}
