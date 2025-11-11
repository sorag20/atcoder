#include <bits/stdc++.h>
#include <atcoder/all>
#include <map>
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
    ll n, q;
    string s;
    cin >> n >> s >> q;
    string exam_before = "abcdefghijklmnopqrstuvwxyz";
    string exam = "abcdefghijklmnopqrstuvwxyz";
    rep(i, q)
    {
        char c, d;
        cin >> c >> d;
        for (int j = 0; j < exam.size();j++)
        {
            if (exam[j] == c) {
                exam[j]=d;
            }
        }
    }
    rep(i,n){
        rep(j,exam_before.size()) {
            if (s[i] == exam_before[j]) {
                s[i]=exam[j];
                break;
            }
        }
    }
    cout << s << endl;
    return 0;
}
