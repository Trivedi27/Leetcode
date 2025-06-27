// Matrix exponentiation (MSBF)
static matrix pow(const matrix& M, unsigned n) {
    if (n==0) return I;
    bitset<32> B(n);
    int bMax=31-countl_zero(n);
    matrix ans = M;
    for (int i=bMax-1; i>=0; i--) {
        ans=ans*ans;
        if (B[i]) ans = ans * M;
    }
    return ans;
}