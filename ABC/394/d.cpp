#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <queue>
#include <stack>
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
    stack<char> st;
    rep(i, s.size()) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '<') {
            st.push(s[i]);
        } else {
            if (st.empty()) {
                cout << "No" << endl;
                return 0;
            }
            char c = st.top();
            if ((c == '(' && s[i] == ')') || (c == '[' && s[i] == ']') || (c == '<' && s[i] == '>')) {
                st.pop();
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}
