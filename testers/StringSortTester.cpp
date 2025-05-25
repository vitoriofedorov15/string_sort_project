#include "StringSortTester.h"
#include <chrono>
#include <iostream>
#include <iomanip>

void StringSortTester::test_sort(const std::vector<std::string>& data,
                                 SortFunction sort_fn,
                                 const std::string& name,
                                 int repeats,
                                 std::ofstream& output_csv,
                                 int n,
                                 const std::string& input_type) {
    double total_time = 0;
    size_t total_comparisons = 0;

    for (int i = 0; i < repeats; ++i) {
        auto copy = data;
        size_t comparisons = 0, dummy = 0;
        auto start = std::chrono::high_resolution_clock::now();
        sort_fn(copy, comparisons, dummy);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        total_time += elapsed.count();
        total_comparisons += comparisons;
    }

    double avg_time = total_time / repeats;
    size_t avg_cmp = total_comparisons / repeats;

    std::cout << std::fixed << std::setprecision(3);
    std::cout << name << " (n=" << n << "): "
              << "время = " << avg_time << " мс, "
              << "сравнений = " << avg_cmp << "\n";

    output_csv << n << "," << name << ","
               << std::fixed << std::setprecision(3) << avg_time << ","
               << avg_cmp << "," << input_type << "\n";
}
