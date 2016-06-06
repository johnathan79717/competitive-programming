template<int N>
struct Permutation {
    int p[N];
    int& operator[](int i) {
        return p[i];
    }

    Permutation operator*(const Permutation& other) const {
        Permutation ans;
        for (int i = 0; i < N; i++) {
            ans[i] = p[other[i]];
        }
    }
};
