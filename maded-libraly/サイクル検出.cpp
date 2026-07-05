// サイクル検出
vl flag(N);
bool ok = false;
rep(sv, N) {
    if (flag[sv] == 0) {
        auto dfs = [&](auto dfs, ll v) -> bool {
            if (flag[v]) {
                return flag[v] == 1;
            }
            flag[v] = 1;
            for (ll u:to[v]) {
                if (dfs(dfs,u)) return true;
            }
            flag[v] = 2;
            return false;
        };
        if (dfs(dfs,sv)) {
            out("Yes")
            ok = true;
            break;
        }
    }
}
if (!ok)out("No")