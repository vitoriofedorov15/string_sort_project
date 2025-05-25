//#include <iostream>
//#include <vector>
//#include <string>
//
//void msd_sort(std::vector<std::string>& a, int l, int r, int d) {
//    if (r - l <= 1) return;
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
//            msd_sort(a, idx, idx + sz, d + 1);
//        idx += sz;
//    }
//}
//
//void msdSort(std::vector<std::string>& a) {
//    msd_sort(a, 0, a.size(), 0);
//}
//
//int main() {
//    int n;
//    std::cin >> n;
//    std::vector<std::string> a(n);
//    for (int i = 0; i < n; ++i) std::cin >> a[i];
//    msdSort(a);
//    for (const auto& s : a) std::cout << s << '\n';
//}
