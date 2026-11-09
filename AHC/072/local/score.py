# Python port of tools/src/lib.rs evaluate()
import sys
def score(inp, out):
    L = open(inp).read().split()
    n, k = int(L[0]), int(L[1]); g = L[2:2+n]
    floor = [c != '#' for row in g for c in row]
    st = [[] for _ in range(n*n)]; plate = {}; total = 0
    for i in range(n):
        for j in range(n):
            c = g[i][j]
            if 'a' <= c <= 'l': st[i*n+j] = [ord(c)-97]; total += 1
            elif 'A' <= c <= 'L': plate[i*n+j] = ord(c)-65
    toks = open(out).read().split(); T = 0; rec = 0
    D = {'U':(-1,0),'D':(1,0),'L':(0,-1),'R':(0,1)}
    for t in range(0, len(toks), 5):
        r, c, kk, d, l = int(toks[t]), int(toks[t+1]), int(toks[t+2]), toks[t+3], int(toks[t+4])
        p = r*n+c; h = len(st[p])
        if not floor[p] or kk >= h: return f"op {T+1}: source empty / k>=h"
        if l > kk+1: return f"op {T+1}: l>k+1"
        for s in range(1, l+1):
            rr, cc = r+D[d][0]*s, c+D[d][1]*s
            if not (0 <= rr < n and 0 <= cc < n) or not floor[rr*n+cc]: return f"op {T+1}: wall/out"
        q = rr*n+cc
        if len(st[q]) + h - kk > 8: return f"op {T+1}: height>8"
        blk = st[p][kk:]; del st[p][kk:]; st[q].extend(reversed(blk))
        for x in (p, q):
            if x in plate:
                while st[x] and st[x][-1] == plate[x]: st[x].pop(); rec += 1
        T += 1
    return T + 100000*(total-rec)
if __name__ == '__main__':
    print(score(sys.argv[1], sys.argv[2]))
