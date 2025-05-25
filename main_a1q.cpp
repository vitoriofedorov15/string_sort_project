//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
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
//void stringQuickSort(std::vector<std::string>& a) {
//    stringQuickSort(a, 0, a.size(), 0);
//}
//
//int main() {
//    int n;
//    std::cin >> n;
//    std::vector<std::string> a(n);
//    for (int i = 0; i < n; ++i) std::cin >> a[i];
//    stringQuickSort(a);
//    for (const auto& s : a) std::cout << s << '\n';
//}
