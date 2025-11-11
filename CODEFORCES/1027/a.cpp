#include <bits/stdc++.h>
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

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int tmp = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
        bool flag = false;
        rep(i,100){
            rep(j,100) {
                int cnt = i*i + 2*i*j + j*j;
                if (cnt == tmp) {
                    cout << i << " " << j << endl;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag)cout << -1 << endl; 
    }// Output -1 after all test cases

    return 0;
}
