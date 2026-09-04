vvl C(m+1,vl(m+1));
rep(i,m)rep(j,i+1) {
    C[i+1][j] += C[i][j];
    C[i+1][j+1] += C[i][j];
}