#include <bits/stdc++.h>
#include <atcoder/all>
#include <random>
using namespace std;
using namespace atcoder;

#define ll long long
#define rep(i,x) for(ll i=0;i<x;i++)
using lP = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vl>;
template<typename T> using vc = vector<T>;

vl dx = {1, 0, -1, 0};
vl dy = {0, 1, 0, -1};

mt19937 rng(42);

// 評価関数
ll calc_score(ll n, ll u, vvl& v, vvl& o, vvl& l) {
    ll score = 0;
    ll territory_count = 0;
    ll max_level_count = 0;
    ll high_value_territory = 0;
    ll cluster_bonus = 0;

    rep(i, n) {
        rep(j, n) {
            if (o[i][j] == 0) {
                ll base = v[i][j] * l[i][j];
                score += base;

                // レベルの3乗でボーナス
                score += base * l[i][j] * l[i][j] / 15;

                territory_count++;

                if (v[i][j] >= 8) {
                    high_value_territory++;
                    score += base / 2;
                }

                if (l[i][j] == u) {
                    score += v[i][j] * 25;
                    max_level_count++;
                }

                // 連結性ボーナス
                ll adjacent_own = 0;
                rep(d, 4) {
                    ll ni = i + dx[d];
                    ll nj = j + dy[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                        if (o[ni][nj] == 0) adjacent_own++;
                    }
                }
                cluster_bonus += adjacent_own * v[i][j] / 2;
            }
        }
    }

    score += territory_count * 125;
    score += max_level_count * 360;
    score += high_value_territory * 210;
    score += cluster_bonus;

    return score;
}

void simulate_move(ll player, ll ni, ll nj, ll u, vvl& o, vvl& l) {
    ll owner = o[ni][nj];
    ll level = l[ni][nj];

    if (owner == -1) {
        o[ni][nj] = player;
        l[ni][nj] = 1;
    } else if (owner == player) {
        if (level < u) l[ni][nj] = level + 1;
    } else {
        if (level == 1) {
            o[ni][nj] = player;
            l[ni][nj] = 1;
        } else {
            l[ni][nj] = level - 1;
        }
    }
}

// モンテカルロシミュレーション
ll monte_carlo_eval(ll n, ll m, ll u, vvl& v, vvl o, vvl l, lP start_pos, vc<lP>& exy, ll depth) {
    ll total_score = 0;
    const ll simulations = 4;  // シミュレーション回数

    rep(sim, simulations) {
        vvl o_sim = o;
        vvl l_sim = l;
        lP pos = start_pos;

        rep(step, depth) {
            // ランダムに有効な移動を選択
            vector<ll> valid_dirs;
            rep(di, 4) {
                ll ni = pos.first + dx[di];
                ll nj = pos.second + dy[di];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    bool occupied = false;
                    rep(k, m) {
                        if (k == 0) continue;
                        if (exy[k].first == ni && exy[k].second == nj) {
                            occupied = true;
                            break;
                        }
                    }
                    if (!occupied) valid_dirs.push_back(di);
                }
            }

            if (valid_dirs.empty()) break;

            ll di = valid_dirs[rng() % valid_dirs.size()];
            ll ni = pos.first + dx[di];
            ll nj = pos.second + dy[di];

            simulate_move(0, ni, nj, u, o_sim, l_sim);
            pos = {ni, nj};
        }

        total_score += calc_score(n, u, v, o_sim, l_sim);
    }

    return total_score / simulations;
}

int main() {
    ll n, m, t, u;
    cin >> n >> m >> t >> u;
    vvl v(n, vl(n));
    rep(i, n) rep(j, n) cin >> v[i][j];

    vc<lP> exy(m);
    rep(i, m) {
        ll row, col;
        cin >> row >> col;
        exy[i] = {row, col};
    }

    lP me = exy[0];

    vvl o(n, vl(n, -1));
    vvl l(n, vl(n, 0));

    rep(i, m) {
        o[exy[i].first][exy[i].second] = i;
        l[exy[i].first][exy[i].second] = 1;
    }

    ll turn_count = 0;

    while(t--) {
        if (turn_count > 0) {
            vector<pair<ll,ll>> tx(m);
            rep(i, m) {
                cin >> tx[i].first >> tx[i].second;
            }

            rep(i, m) {
                cin >> exy[i].first >> exy[i].second;
            }
            me = exy[0];

            rep(i, n) {
                rep(j, n) {
                    cin >> o[i][j];
                }
            }

            rep(i, n) {
                rep(j, n) {
                    cin >> l[i][j];
                }
            }
        }

        ll best_dir = -1;
        ll best_score = -1e18;

        // ビームサーチ：各方向についてモンテカルロ評価
        rep(di, 4) {
            ll ni = me.first + dx[di];
            ll nj = me.second + dy[di];

            if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

            bool occupied = false;
            rep(k, m) {
                if (k == 0) continue;
                if (exy[k].first == ni && exy[k].second == nj) {
                    occupied = true;
                    break;
                }
            }
            if (occupied) continue;

            // 1手目をシミュレート
            vvl o1 = o;
            vvl l1 = l;
            simulate_move(0, ni, nj, u, o1, l1);

            ll score1 = calc_score(n, u, v, o1, l1);

            // 敵との距離ペナルティ
            ll enemy_penalty = 0;
            rep(k, m) {
                if (k == 0) continue;
                ll dist = abs(ni - exy[k].first) + abs(nj - exy[k].second);
                if (dist <= 2) {
                    enemy_penalty += 5000 / (dist + 1);
                }
            }

            // モンテカルロで深く評価（4手先まで）
            ll mc_score = monte_carlo_eval(n, m, u, v, o1, l1, {ni, nj}, exy, 4);

            // 即時スコアとモンテカルロスコアを組み合わせ
            ll combined = score1 * 5 / 10 + mc_score * 5 / 10 - enemy_penalty;

            if (combined > best_score) {
                best_score = combined;
                best_dir = di;
            }
        }

        ll nrow = me.first, ncol = me.second;
        if (best_dir != -1) {
            nrow = me.first + dx[best_dir];
            ncol = me.second + dy[best_dir];
        } else {
            rep(di, 4) {
                ll ni = me.first + dx[di];
                ll nj = me.second + dy[di];

                if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

                bool occupied = false;
                rep(k, m) {
                    if (k == 0) continue;
                    if (exy[k].first == ni && exy[k].second == nj) {
                        occupied = true;
                        break;
                    }
                }
                if (occupied) continue;

                nrow = ni;
                ncol = nj;
                break;
            }
        }

        cout << nrow << " " << ncol << endl;
        cout.flush();
        me = {nrow, ncol};
        turn_count++;
    }

    return 0;
}
