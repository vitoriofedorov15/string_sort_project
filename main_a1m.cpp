//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//int lcp(const std::string& a, const std::string& b, int start = 0) {
//    int len = std::min(a.size(), b.size());
//    for (int i = start; i < len; ++i)
//        if (a[i] != b[i]) return i;
//    return len;
//}
//
//void merge(std::vector<std::string>& a, int l, int m, int r) {
//    std::vector<std::string> left(a.begin() + l, a.begin() + m);
//    std::vector<std::string> right(a.begin() + m, a.begin() + r);
//    int i = 0, j = 0, k = l;
//    while (i < (int)left.size() && j < (int)right.size()) {
//        int pref = lcp(left[i], right[j]);
//        if (left[i].compare(pref, std::string::npos, right[j], pref, std::string::npos) <= 0)
//            a[k++] = left[i++];
//        else
//            a[k++] = right[j++];
//    }
//    while (i < (int)left.size()) a[k++] = left[i++];
//    while (j < (int)right.size()) a[k++] = right[j++];
//}
//
//void mergeSort(std::vector<std::string>& a, int l, int r) {
//    if (r - l <= 1) return;
//    int m = (l + r) / 2;
//    mergeSort(a, l, m);
//    mergeSort(a, m, r);
//    merge(a, l, m, r);
//}
//
//void mergeSort(std::vector<std::string>& a) {
//    mergeSort(a, 0, a.size());
//}
//
//int main() {
//    int n;
//    std::cin >> n;
//    std::vector<std::string> a(n);
//    for (int i = 0; i < n; ++i) std::cin >> a[i];
//    mergeSort(a);
//    for (const auto& s : a) std::cout << s << '\n';
//}
