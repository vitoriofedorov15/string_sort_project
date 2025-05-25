//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//const int ALPHABET = 74;
//
//void stringQuickSort(std::vector<std::string>& a, int l, int r, int d) {
//    if (r <= l + 1) return;
//    int lt = l, gt = r - 1, i = l + 1;
//    char v = d < a[l].size() ? a[l][d] : 0;
//    while (i <= gt) {
//        char t = d < a[i].size() ? a[i][d] : 0;
//        if (t < v) std::swap(a[lt++], a[i++]);
//        else if (t > v) std::swap(a[i], a[gt--]);
//        else ++i;
//    }
//    stringQuickSort(a, l, lt, d);
//    if (v != 0) stringQuickSort(a, lt, gt + 1, d + 1);
//    stringQuickSort(a, gt + 1, r, d);
//}
//
//void msd_radix_qs(std::vector<std::string>& a, int l, int r, int d) {
//    if (r - l <= ALPHABET) {
//        stringQuickSort(a, l, r, d);
//        return;
//    }
//    std::vector<std::vector<std::string>> buckets(257);
//    for (int i = l; i < r; ++i) {
//        int c = d < a[i].size() ? (unsigned char)a[i][d] + 1 : 0;
//        buckets[c].push_back(a[i]);
//    }
//    int idx = l;
//    for (int i = 0; i <= 256; ++i)
//        for (auto& s : buckets[i])
//            a[idx++] = s;
//
//    idx = l;
//    for (int i = 0; i <= 256; ++i) {
//        int sz = buckets[i].size();
//        if (sz > 0)
//            msd_radix_qs(a, idx, idx + sz, d + 1);
//        idx += sz;
//    }
//}
//
//void msdRadixWithQS(std::vector<std::string>& a) {
//    msd_radix_qs(a, 0, a.size(), 0);
//}
//
//int main() {
//    int n;
//    std::cin >> n;
//    std::vector<std::string> a(n);
//    for (int i = 0; i < n; ++i) std::cin >> a[i];
//    msdRadixWithQS(a);
//    for (const auto& s : a) std::cout << s << '\n';
//}
