
long long mod = 2147483647;
long long T[200009], H[200009];
long long Power100[200009];

long long Hash_value(int l, int r) {
	long long val = H[r] - (H[l - 1] * Power100[r - l + 1] % mod);
	if (val < 0) val += mod;
	return val;
}

int main() {
	int N,Q; cin>>N>>Q;
	string S; cin>>S;
	for (int i = 1; i <= N; i++) T[i] = (S[i - 1] - 'a') + 1;
	Power100[0] = 1;
	for (int i = 1; i <= N; i++) Power100[i] = 100LL * Power100[i - 1] % mod;
	H[0] = 0;	
    for (int i = 1; i <= N; i++) H[i] = (100LL * H[i - 1] + T[i]) % mod;
    return 0;
}