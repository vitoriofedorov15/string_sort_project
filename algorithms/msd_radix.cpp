#include "msd_radix.h"
#include <vector>

void msd_sort(std::vector<std::string>& a, int l, int r, int d, size_t& cmp) {
    if (r - l <= 1) return;

    std::vector<std::vector<std::string>> buckets(257);
    for (int i = l; i < r; ++i) {
        int c = d < a[i].size() ? (unsigned char)a[i][d] + 1 : 0;
        ++cmp;
        buckets[c].push_back(a[i]);
    }

    int idx = l;
    for (int i = 0; i <= 256; ++i)
        for (auto& s : buckets[i])
            a[idx++] = s;

    idx = l;
    for (int i = 0; i <= 256; ++i) {
        int sz = buckets[i].size();
        if (sz > 0)
            msd_sort(a, idx, idx + sz, d + 1, cmp);
        idx += sz;
    }
}

void msdSort(std::vector<std::string>& a, size_t& cmp) {
    msd_sort(a, 0, a.size(), 0, cmp);
}
