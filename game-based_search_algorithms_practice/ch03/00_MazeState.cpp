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
#define eb emplace_back
#define all(x) begin(x), end(x)
#define gall(x) begin(x), end(x), greater<>()
#define ll long long
#define rep(i,x) for(int i=0;i<x;i++)
#define P pair<int, int>
#define lP pair<ll, ll>
using namespace std;
using namespace atcoder;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

struct Coord
{
    int y;
    int x;
    Coord (const int y = 0, const int x = 0) : y(y), x(x) {}
};

constexpr const int h = 3;
constexpr const int w = 4;
constexpr END_TURN = 4;
class MazeState
{
    private:
        int points[h][w] = {};
        int turn = 0;
        static constexpr const int dx[] = {1, 0, -1, 0};
        static constexpr const int dy[] = {0, 1, 0, -1};

    public:
        Coord character = Coord();
        int game_score = 0;
        MazeState() {}
        bool isDone() {
            return this->turn == END_TURN;
        }
        void advance(const int action) {
            this->character.x += dx[action];
            this->character.y += dy[action];
            int point = this->points[this->character.y][this->character.x];
            if (point > 0) {
                this->game_score += point
                this->points[this->character.y][this->character.x] = 0;
            }
            this->turn++;
        }

    MazeState(const int seed) {
        auto random = mt19937(seed);
        this->character.y = random()%H;
        this->character.x = random()%H;

        rep(i,h)rep(j,w) {
            if (i == character.y && j == character.x) continue;
            this->points[i][j] = random()% 10;
        }
    }
}
