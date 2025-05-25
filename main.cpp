#include <iostream>
#include <fstream>
#include "generators/StringGenerator.h"
#include "testers/StringSortTester.h"
#include "algorithms/mergesort.h"
#include "algorithms/quicksort.h"
#include "algorithms/msd_radix.h"
#include "algorithms/msd_radix_qs.h"

// Компаратор std::sort с подсчётом сравнений
struct CharComparator {
    size_t& counter;
    CharComparator(size_t& c) : counter(c) {}
    bool operator()(const std::string& a, const std::string& b) {
        size_t len = std::min(a.size(), b.size());
        for (size_t i = 0; i < len; ++i) {
            ++counter;
            if (a[i] != b[i]) return a[i] < b[i];
        }
        ++counter;
        return a.size() < b.size();
    }
};

void run_tests_for_type(const std::string& input_type,
                        const std::vector<std::string>& full,
                        std::ofstream& out,
                        StringSortTester& tester) {
    std::cout << "\n==== ТЕСТ: " << input_type << " ====\n";
    for (int n = 100; n <= 3000; n += 100) {
        std::cout << "Размер: " << n << "\n";
        std::vector<std::string> data(full.begin(), full.begin() + n);

        tester.test_sort(data, [&](auto& a, size_t& cmp, size_t&) {
            std::sort(a.begin(), a.end(), CharComparator(cmp));
        }, "std::sort", 5, out, n, input_type);

        tester.test_sort(data, [&](auto& a, size_t& cmp, size_t&) {
            mergeSort(a, cmp);
        }, "StringMergeSort", 5, out, n, input_type);

        tester.test_sort(data, [&](auto& a, size_t& cmp, size_t&) {
            stringQuickSort(a, cmp);
        }, "StringQuickSort", 5, out, n, input_type);

        tester.test_sort(data, [&](auto& a, size_t& cmp, size_t&) {
            msdSort(a, cmp);
        }, "MSD Radix", 5, out, n, input_type);

        tester.test_sort(data, [&](auto& a, size_t& cmp, size_t&) {
            msdRadixWithQS(a, cmp);
        }, "MSD Radix + QS", 5, out, n, input_type);
    }
}

int main() {
    StringGenerator gen;
    StringSortTester tester;

    std::ofstream out("results_full.csv");
    out << "n,algorithm,time_ms,char_comparisons,input_type\n";

    run_tests_for_type("random", gen.generate_random_array(3000), out, tester);
    run_tests_for_type("reverse", gen.generate_reverse_sorted(3000), out, tester);
    run_tests_for_type("almost_sorted", gen.generate_almost_sorted(3000, 20), out, tester);

    out.close();
    std::cout << "\nЗамеры завершены. Результаты в: results_full.csv\n";
    return 0;
}
