#include "mergesort.h"
#include <algorithm>

int lcp(const std::string& a, const std::string& b, size_t& cmp, int start = 0) {
    int len = std::min(a.size(), b.size());
    for (int i = start; i < len; ++i) {
        ++cmp;
        if (a[i] != b[i]) return i;
    }
    ++cmp;
    return len;
}

void merge(std::vector<std::string>& a, int l, int m, int r, size_t& cmp) {
    std::vector<std::string> left(a.begin() + l, a.begin() + m);
    std::vector<std::string> right(a.begin() + m, a.begin() + r);
    int i = 0, j = 0, k = l;

    while (i < left.size() && j < right.size()) {
        int pref = lcp(left[i], right[j], cmp);
        ++cmp;
        if (left[i].compare(pref, std::string::npos, right[j], pref, std::string::npos) <= 0)
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }
    while (i < left.size()) a[k++] = left[i++];
    while (j < right.size()) a[k++] = right[j++];
}

void mergeSort(std::vector<std::string>& a, int l, int r, size_t& cmp) {
    if (r - l <= 1) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m, cmp);
    mergeSort(a, m, r, cmp);
    merge(a, l, m, r, cmp);
}

void mergeSort(std::vector<std::string>& a, size_t& cmp) {
    mergeSort(a, 0, a.size(), cmp);
}
