#include <bits/stdc++.h>
#include <atcoder/all>
#define ll long long
using namespace std;
using namespace atcoder;

ll N, M, C;
vector<ll> d;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dirChar[] = {'U', 'D', 'L', 'R'};

bool isValid(int r, int c) { return r >= 0 && r < N && c >= 0 && c < N; }

// Hamiltonian path and index arrays.
vector<pair<int,int>> hamPath;
vector<vector<int>> hamIdx;

// Path A: column boustrophedon (col 0 down, col 1 up, col 2 down, ...)
// Head at path[4] = (4,0). Valid: no wrap-around issues.
vector<pair<int,int>> buildPathA() {
    vector<pair<int,int>> path;
    for (int j = 0; j < N; j++) {
        if (j % 2 == 0) { for (int i = 0; i < N; i++) path.push_back({i, j}); }
        else             { for (int i = N-1; i >= 0; i--) path.push_back({i, j}); }
    }
    return path;
}

// Path B: col 0 down, then row boustrophedon of cols 1..N-1 starting from row N-1.
// col 0: (0,0)..(N-1,0), row N-1: (N-1,1)..(N-1,N-1), row N-2: (N-2,N-1)..(N-2,1), ...
// Head at path[4] = (4,0). Valid: snake only needs indices 4..M-1 (no wrap).
vector<pair<int,int>> buildPathB() {
    vector<pair<int,int>> path;
    for (int i = 0; i < N; i++) path.push_back({i, 0});
    for (int ii = 0; ii < N; ii++) {
        int i = N - 1 - ii;
        if (ii % 2 == 0) { for (int j = 1; j < N; j++) path.push_back({i, j}); }
        else              { for (int j = N-1; j >= 1; j--) path.push_back({i, j}); }
    }
    return path;
}

// Compute expected E for a candidate path. No wrap-around: stop at end of path.
int computeExpectedE(const vector<pair<int,int>>& path,
                     const vector<vector<int>>& idx,
                     const vector<vector<ll>>& f, int curLen) {
    int pathLen = (int)path.size();
    int headIdx = idx[4][0]; // initial head at (4,0)
    int foodPos = curLen;
    int E = 0;
    for (int k = headIdx + 1; k < pathLen && foodPos < (int)d.size(); k++) {
        auto [r, c] = path[k];
        if (f[r][c] != 0) {
            if (f[r][c] != d[foodPos]) E++;
            foodPos++;
        }
    }
    return E;
}

// Select the best Hamiltonian path (A or B) based on expected E.
void buildHamPath(const vector<vector<ll>>& f, int curLen) {
    int bestE = INT_MAX;
    for (int which = 0; which < 2; which++) {
        auto cand = (which == 0) ? buildPathA() : buildPathB();
        vector<vector<int>> idx(N, vector<int>(N, -1));
        for (int k = 0; k < (int)cand.size(); k++)
            idx[cand[k].first][cand[k].second] = k;
        int E = computeExpectedE(cand, idx, f, curLen);
        if (E < bestE) {
            bestE = E;
            hamPath = cand;
            hamIdx = idx;
        }
    }
}

struct State {
    deque<pair<int,int>> ij;
    vector<ll> cv;
    vector<vector<ll>> f;
    ll turn = 0;

    int len() const { return (int)ij.size(); }

    ll computeE() const {
        ll E = 0;
        for (int p = 0; p < len(); p++) if (d[p] != cv[p]) E++;
        return E;
    }

    ll score() const { return turn + 10000LL * (computeE() + 2 * (M - len())); }

    bool canMove(int dir) const {
        int ni = ij[0].first + dx[dir], nj = ij[0].second + dy[dir];
        if (!isValid(ni, nj)) return false;
        if (len() > 1 && ni == ij[1].first && nj == ij[1].second) return false;
        return true;
    }

    void apply(int dir) {
        int ni = ij[0].first + dx[dir], nj = ij[0].second + dy[dir];
        ij.push_front({ni, nj});
        if (f[ni][nj] != 0) {
            cv.push_back(f[ni][nj]);
            f[ni][nj] = 0;
        } else {
            ij.pop_back();
        }
        int sz = len();
        for (int h = 1; h <= sz - 2; h++) {
            if (ij[h] == ij[0]) {
                for (int p = h + 1; p < sz; p++)
                    f[ij[p].first][ij[p].second] = cv[p];
                while (len() > h + 1) { ij.pop_back(); cv.pop_back(); }
                break;
            }
        }
        turn++;
    }
};

// BFS from head toward food, avoiding body (excl. tail).
// targetColor < 0: any food.
// minHamIdx: only accept food cells with hamIdx >= minHamIdx (-1 = no constraint).
int bfsTo(const State& state, ll targetColor, bool avoidWrongFood, int minHamIdx = -1) {
    int sz = state.len();
    auto head = state.ij[0];

    vector<vector<bool>> blocked(N, vector<bool>(N, false));
    for (int i = 1; i < sz - 1; i++)
        blocked[state.ij[i].first][state.ij[i].second] = true;

    vector<vector<int>> prevDir(N, vector<int>(N, -1));
    vector<vector<pair<int,int>>> prevCell(N, vector<pair<int,int>>(N, {-1,-1}));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<int,int>> q;
    q.push(head);
    visited[head.first][head.second] = true;

    pair<int,int> found = {-1, -1};
    while (!q.empty() && found.first == -1) {
        auto [r, c] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dx[dir], nc = c + dy[dir];
            if (!isValid(nr, nc) || blocked[nr][nc] || visited[nr][nc]) continue;
            ll foodHere = state.f[nr][nc];
            if (avoidWrongFood && foodHere != 0 && foodHere != targetColor) continue;
            visited[nr][nc] = true;
            prevDir[nr][nc] = dir;
            prevCell[nr][nc] = {r, c};
            bool isTarget = (targetColor < 0) ? (foodHere != 0) : (foodHere == targetColor);
            if (isTarget && (minHamIdx < 0 || hamIdx[nr][nc] >= minHamIdx))
            { found = {nr, nc}; break; }
            q.push({nr, nc});
        }
    }

    if (found.first == -1) return -1;
    auto cur = found;
    while (prevCell[cur.first][cur.second] != head)
        cur = prevCell[cur.first][cur.second];
    int ret = prevDir[cur.first][cur.second];
    if (sz > 1 && head.first + dx[ret] == state.ij[1].first &&
        head.second + dy[ret] == state.ij[1].second) return -1;
    return ret;
}

// Direct Hamiltonian path step: move to path[(headIdx+1) % N^2].
// Consecutive ham path cells are always adjacent by construction.
// Guaranteed valid when snake body aligns with the ham path.
// After BFS shortcuts, path[headIdx+1] may be in body -> returns -1.
int hamPathDirect(const State& state) {
    auto head = state.ij[0];
    int headIdx = hamIdx[head.first][head.second];
    if (headIdx == -1) return -1;
    int pathLen = (int)hamPath.size();
    int nextIdx = (headIdx + 1) % pathLen;
    auto [nr, nc] = hamPath[nextIdx];
    int sz = state.len();
    if (sz > 1 && nr == state.ij[1].first && nc == state.ij[1].second) return -1;
    for (int i = 1; i < sz - 1; i++)
        if (state.ij[i].first == nr && state.ij[i].second == nc) return -1;
    for (int dir = 0; dir < 4; dir++)
        if (head.first + dx[dir] == nr && head.second + dy[dir] == nc) return dir;
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> C;
    d.resize(M);
    for (int i = 0; i < M; i++) cin >> d[i];

    State state;
    state.ij = {{4,0},{3,0},{2,0},{1,0},{0,0}};
    state.cv = {1,1,1,1,1};
    state.f.assign(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> state.f[i][j];

    // Choose the Hamiltonian path with the best expected E for this input.
    buildHamPath(state.f, state.len());

    vector<int> moves;
    moves.reserve(100000);

    while (state.turn < 100000 && state.len() < M) {
        ll nextColor = d[state.len()];

        int dir = -1;
        // Use BFS shortcuts when: small grid (N<=9), or density <= 50% for N<=12,
        // or density <= 40% for N>=13. At higher density or larger N, BFS shortcuts
        // cause cross-column jumps that skip food cells permanently.
        // N<=12: 2*(M-5) <= N*N   (density <= 50%)
        // N>=13: 5*(M-5) <= 2*N*N (density <= 40%)
        bool useBFS = (N <= 9) ||
                      (N <= 12 && 2*(M-5) <= N*N) ||
                      (N >= 13 && 5*(M-5) <= 2*N*N);
        if (useBFS) {
            dir = bfsTo(state, nextColor, true);
            if (dir == -1) dir = bfsTo(state, nextColor, false);
            if (dir == -1) dir = bfsTo(state, -1, false);
        }
        // Ham path: O(N^2) coverage, guaranteed valid on aligned body.
        if (dir == -1) dir = hamPathDirect(state);
        // 5. Any valid move
        if (dir == -1) {
            for (int d2 = 0; d2 < 4; d2++) {
                if (state.canMove(d2)) { dir = d2; break; }
            }
        }
        if (dir == -1) break;

        moves.push_back(dir);
        state.apply(dir);
    }

    for (int m : moves) cout << dirChar[m] << "\n";
    return 0;
}
