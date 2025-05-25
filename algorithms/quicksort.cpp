#include "quicksort.h"
#include <algorithm>

bool cmp_strings(const std::string& a, const std::string& b, size_t& cmp) {
    int len = std::min(a.size(), b.size());
    for (int i = 0; i < len; ++i) {
        ++cmp;
        if (a[i] != b[i]) return a[i] < b[i];
    }
    ++cmp;
    return a.size() < b.size();
}

char char_at(const std::string& s, int d) {
    return d < s.size() ? s[d] : 0;
}

void stringQuickSort(std::vector<std::string>& a, int l, int r, int d, size_t& cmp) {
    if (r <= l + 1) return;
    int lt = l, gt = r - 1, i = l + 1;
    char v = char_at(a[l], d);

    while (i <= gt) {
        char t = char_at(a[i], d);
        ++cmp;
        if (t < v) std::swap(a[lt++], a[i++]);
        else if (t > v) std::swap(a[i], a[gt--]);
        else ++i;
    }

    stringQuickSort(a, l, lt, d, cmp);
    if (v != 0)
        stringQuickSort(a, lt, gt + 1, d + 1, cmp);
    stringQuickSort(a, gt + 1, r, d, cmp);
}

void stringQuickSort(std::vector<std::string>& a, size_t& cmp) {
    stringQuickSort(a, 0, a.size(), 0, cmp);
}
