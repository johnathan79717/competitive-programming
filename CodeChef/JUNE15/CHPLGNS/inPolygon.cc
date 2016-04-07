bool inPolygon(int x, int y, const V(PII) &poly) {
    int n = SZ(poly);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        // PIS(i); PI(j);
        int x1 = poly[j].F, y1 = poly[j].S, x2 = poly[i].F, y2 = poly[i].S;
        if (y1 > y2) {
            swap(y1, y2);
            swap(x1, x2);
        }
        if (y == y1) {
            assert(x1 != x);
        } else if (y == y2) {
            assert(x2 != x);
            if (x2 > x) {
                cnt1 = !cnt1;
            } else {
                cnt2 = !cnt2;
            }
        } else if (y1 < y && y < y2) {
            // assert((LL)(x - x1) * (y2 - y1) != (LL)(x2 - x1) * (y - y1));
            if ((long double)(x2 - x1) * (y2 - y) < (long double)(x2 - x) * (y2 - y1)) {
                cnt1 = !cnt1;
            } else {
                cnt2 = !cnt2;
            }
        }
    }
    assert(cnt1 == cnt2);
    return cnt1;
}